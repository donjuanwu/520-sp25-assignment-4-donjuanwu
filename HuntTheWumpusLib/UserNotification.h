#pragma once

#include <functional>
#include <unordered_map>  // for storing callbacks

namespace HuntTheWumpus
{
    // Inform the user about particular operations happening.
    class UserNotification final
    {
    public:
        /* All game events that can be surfaced to the UI*/
        enum class Notification
        {
            HunterEnteredCave,
            NearbyWumpus,
            NearbyBat,
            NearbyPit,
            PitFall,
            BatGrabbed,
            WumpusBumped,
            WumpusEatsHunter,
            WumpusShot,
            ArrowMissed,
            OutOfArrows,
            IllegalMoves
        };

        UserNotification() = default;
        

        /*
        Add a new entry to m_callbacks
        Add a callback for a given notification category, tell the system what to do later when something happens, but don't do it yet
        */
        void AddCallback(Notification category, std::function<void()>&& callback);

        /*
            Trigger the callback for the event(if one was registered)
            Looks up m_callbacks[event] and runs the function if it exists
        */
        void Notify(Notification category) const;
  
        // Rule of 5
        ~UserNotification() = default;
        UserNotification(const UserNotification&) = default;
        UserNotification(UserNotification&&) = default;
        UserNotification& operator=(const UserNotification&) = default;
        UserNotification& operator=(UserNotification&&) = default;

    private:
        // Hold callbacks.
        std::unordered_map<Notification, std::function<void()>> m_callbacks;
    };
}
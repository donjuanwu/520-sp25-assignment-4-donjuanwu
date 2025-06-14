#include "Pit.h"
#include "Context.h"
#include "GameStateObservation.h"
#include "UserNotification.h"

namespace HuntTheWumpus
{
    Pit::Pit(const int pitInstance, Context& providers)
        : Denizen(
            { .m_category = Category::Pit, .m_instance = pitInstance },
            { .m_carryableByBats = false, .m_fatalToWumpus = false, .m_fatalToHunter = true, .m_isEdible = false, .m_reportMovement = false },
            providers)
    {
    }

    bool Pit::ObserveCaveEntrance(const std::shared_ptr<Denizen>& trigger)
    {
        // Is the Denizen edible (true)
        if (trigger->Properties().m_isEdible)
        {
            // Notify the hunter fell into a pit
            m_providers.m_notification.Notify(UserNotification::Notification::PitFall);

            // End the game
           m_providers.m_change.GameOver(false);

            return true;
        }

        return false;
    }
}

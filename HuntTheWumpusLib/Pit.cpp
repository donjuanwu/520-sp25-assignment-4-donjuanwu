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
        // Check if pit is fatal to hunter and denizen is hunter?
        if (m_properties.m_fatalToHunter && trigger->GetIdentifier().m_category == Category::Hunter)
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

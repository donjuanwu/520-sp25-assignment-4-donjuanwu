#include "UserNotificationPrinter.h"

namespace HuntTheWumpus
{
	HuntTheWumpus::UserNotificationPrinter::UserNotificationPrinter(UserNotification& notifier, std::ostream& output)
		: m_output(output)
	{
		Register(notifier);
	}

	void UserNotificationPrinter::Register(UserNotification& notifier)
	{
		
		Add(notifier, UserNotification::Notification::ArrowMissed, "Your arrow flies through the cave and misses");
		Add(notifier, UserNotification::Notification::BatGrabbed, "The bat picked you up and fly you to another cave");
		Add(notifier, UserNotification::Notification::HunterEnteredCave, "The hunter have entered a cave");
		Add(notifier, UserNotification::Notification::IllegalMoves, "You made an illegal move");
		Add(notifier, UserNotification::Notification::NearbyBat, "There is bat aroma and sound nearby");
		Add(notifier, UserNotification::Notification::NearbyPit, "The air feels chilly a pit must be nearby");
		Add(notifier, UserNotification::Notification::NearbyWumpus, "The air smell foul a Wumpus must be nearby");
		Add(notifier, UserNotification::Notification::OutOfArrows, "You shot your last arrow");
		Add(notifier, UserNotification::Notification::PitFall, "You are free falling into a deep and dark pit");
		Add(notifier, UserNotification::Notification::WumpusBumped, "A felt a furry body bumped into you");
		Add(notifier, UserNotification::Notification::WumpusEatsHunter, "You just become the Wumpus dinner");
		Add(notifier, UserNotification::Notification::WumpusShot, "You hear a scary scream... the Wumpus is dead!");
	}

	void UserNotificationPrinter::Add(UserNotification& notifier, UserNotification::Notification type, const std::string& message)
	{
		notifier.AddCallback(type, [this, message]()
			{
				m_output << message << std::endl;
			});
	}

}

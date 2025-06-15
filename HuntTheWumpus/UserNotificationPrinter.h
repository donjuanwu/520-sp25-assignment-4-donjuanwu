#pragma once

#include "UserNotification.h"
#include <ostream>
namespace HuntTheWumpus
{
	class UserNotificationPrinter
	{
	public:
		explicit UserNotificationPrinter(UserNotification& notifier, std::ostream& output);


	private:
		std::ostream& m_output;

		void Register(UserNotification& notifier);
		void Add(UserNotification& notifier, UserNotification::Notification type, const std::string& message);
	};
}



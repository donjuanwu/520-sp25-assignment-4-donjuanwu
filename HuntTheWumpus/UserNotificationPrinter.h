#pragma once

#include "UserNotification.h"
#include <ostream>
#include <string>
namespace HuntTheWumpus
{
	/**
	 * @brief Outputs user notifications to the provided output stream.
	 */
	class UserNotificationPrinter
	{
	public:
		/**
		 * @brief Constructs the printer and registers callbacks to the given notifier.
		 * @param notifier The UserNotification object to listen to.
		 * @param output The output stream where notifications are printed.
		 */
		UserNotificationPrinter(UserNotification& notifier, std::ostream& output);


	private:
		std::ostream& m_output;

		/**
		 * @brief Registers all notification types with corresponding messages.
		 */
		void Register(UserNotification& notifier);
		/**
		* @brief Adds a callback for a specific notification type.
		* @param notifier The notifier to register with.
		* @param type The specific notification type.
		* @param message The message to output when triggered.
		*/
		void Add(UserNotification& notifier, UserNotification::Notification type, const std::string& message);
	};
}



/*
** Developer : Don Dang
** Date      : 06/13/25
** Class     : C++ Intermediate
** Assignment: Hunt the Wumpus: Assignment 4
** Due Date  : 06/20/25
** Subject   : C++ STL Functions
** Purpose   :
    - Adding a user interface: a console application that accepts user inputs and calls into the game to make moves.
    - Need to add printouts of the text expected when different events happen in the game.
    - A new class, UserNotification, needs to be added.
    - Define a set of possible events with an enumeration, and then support registering callback functions for when those events trigger.
      See the specification for the set of events
    - Insert triggering the events at appropriate pints in the code. E.g. when the Hunters enters the cave, report the caves connected, and report the neighboring caves,
      or when the bat picks up the Hunter.

** Date        Developer     Activities
   06/13/25    Don D         Started implementing UserNotification system
*/


#include "UserNotification.h"

namespace HuntTheWumpus
{
    void UserNotification::AddCallback([[maybe_unused]] const Notification category, [[maybe_unused]] std::function<void()>&& callback)
    {
        m_callbacks[category] = std::move(callback);
    }
    void UserNotification::Notify(Notification category) const
    {
        auto it = m_callbacks.find(category);
        if (it != m_callbacks.end())
        {
            it->second(); // Call the registered callback
        }
    }
}

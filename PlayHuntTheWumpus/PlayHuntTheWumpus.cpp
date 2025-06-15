// PlayHuntTheWumpus.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#include "Context.h"
#include "Dungeon.h"
#include "Hunter.h"
#include "..\HuntTheWumpus\UserNotificationPrinter.h"
#include "RandomProvider.h"
#include "GameStateObserver.h"
#include "UserNotification.h"
#include <iostream>
#include <vector>

int main()
{
    //Create the required core components
    HuntTheWumpus::UserNotification notifier;
    HuntTheWumpus::RandomProvider random;
    HuntTheWumpus::GameStateObserver state;

    // Construct services to teh context
    HuntTheWumpus::Context context{notifier, random, state};

    // Create a printer to display notifications to console
    HuntTheWumpus::UserNotificationPrinter printer(notifier, std::cout);

    // Build the dungeon
    HuntTheWumpus::Dungeon dungeon(context);

    // Add a Hunter to cave 1
    auto hunter = std::make_shared<HuntTheWumpus::Hunter>(context);
    dungeon.AddDenizen(hunter, 1);

    std::cout << "Hunter added to cave 1. (Game setup complete)\n";

    return 0;
}

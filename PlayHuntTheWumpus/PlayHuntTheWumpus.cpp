

#include "Context.h"
#include "Dungeon.h"
#include "Hunter.h"
#include "Arrow.h" // Add this at the top of PlayHuntTheWumpus.cpp
#include "Wumpus.h"
#include "Pit.h"
#include "Bat.h"
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
    HuntTheWumpus::AddDenizenForSetup(dungeon, hunter, 1);

    std::cout << "Hunter added to cave 1.\n";

    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////// Setup additional denizens ////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    auto bat = std::make_shared<HuntTheWumpus::Bat>(1, context);
    HuntTheWumpus::AddDenizenForSetup(dungeon, bat, 3);
    std::cout << "Bat added to cave 3. \n";

    auto pit = std::make_shared<HuntTheWumpus::Pit>(2, context);
    HuntTheWumpus::AddDenizenForSetup(dungeon, pit, 8);
    std::cout << "Pit added to cave 8.\n";


    /*auto wumpus = std::make_shared<HuntTheWumpus::Wumpus>(4, context);
    HuntTheWumpus::AddDenizenForSetup(dungeon, wumpus, 5);
    std::cout << "Wumpus added to cave 5. \n";*/

    

    
   




    return 0;
}

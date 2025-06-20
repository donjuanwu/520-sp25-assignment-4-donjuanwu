

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
#include <memory>

void DisplayCurrentConnectedCaves(const std::shared_ptr<HuntTheWumpus::Hunter>& hunter)
{
    auto currentCave = hunter->GetCurrentCave().lock();
    if (!currentCave)
    {
        std::cout << "Hunter is not currently in a cave.\n";
        return;
    }

    std::cout << "\nHunter is in cave " << currentCave->GetCaveId() << ". Connected caves: ";
    const auto& connected = currentCave->GetConnectedIds();
    for (int id : connected)
    {
        std::cout << id << " ";
    }
    std::cout << "\n";
}

int main()
{
    //Create the required core components
    HuntTheWumpus::UserNotification notifier;
    HuntTheWumpus::RandomProvider random;
    HuntTheWumpus::GameStateObserver state;

    // Construct Context with shared services
    HuntTheWumpus::Context context{notifier, random, state};

    // Create a printer to display notifications to console
    HuntTheWumpus::UserNotificationPrinter printer(notifier, std::cout);

    // Initialize the dungeon
    HuntTheWumpus::Dungeon dungeon(context, false);

    // Add a Hunter to cave 1
    auto hunter = std::make_shared<HuntTheWumpus::Hunter>(context);
    std::cout << "Hunter added to cave 1 " << std::endl;
    HuntTheWumpus::AddDenizenForSetup(dungeon, hunter, 1);
    
    // Add a bat to cave 3
    auto bat = std::make_shared<HuntTheWumpus::Bat>(1, context);
    std::cout << "Bat added to cave 3 " << std::endl;
    HuntTheWumpus::AddDenizenForSetup(dungeon, bat, 3);
    
    // Add Pit to cave 8
    auto pit = std::make_shared<HuntTheWumpus::Pit>(2, context);
    std::cout << "Pit added to cave 8 " << std::endl;
    HuntTheWumpus::AddDenizenForSetup(dungeon, pit, 8);
    
    // Add Wumpus to cave 5
    auto wumpus = std::make_shared<HuntTheWumpus::Wumpus>(4, context);
    std::cout << "Wumpus added to cave 5 " << std::endl;
    HuntTheWumpus::AddDenizenForSetup(dungeon, wumpus, 5);

    // Show current cave info
    DisplayCurrentConnectedCaves(hunter);

    // Trigger interaction: move Hunter into Wumpus' cave
    std::cout << "\nHunter is now moving to cave 5..." << std::endl;
    dungeon.MakeMove(HuntTheWumpus::DungeonMove::Move, { 5 });
    DisplayCurrentConnectedCaves(hunter);

    // Trigger interaction: move Hunter into adjacent cave
    std::cout << "\nHunter is now moving to cave 4..." << std::endl;
    dungeon.MakeMove(HuntTheWumpus::DungeonMove::Move, { 4 });
    DisplayCurrentConnectedCaves(hunter);

    // Trigger interaction: move Hunter into Bat's cave
    std::cout << "\nHunter is now moving to cave 3..." << std::endl;
    dungeon.MakeMove(HuntTheWumpus::DungeonMove::Move, { 3 });
    DisplayCurrentConnectedCaves(hunter);

    // Trigger interaction: move Hunter into a non-connected cave, illegal action
    std::cout << "\nHunter is now moving to cave 9..." << std::endl;
    dungeon.MakeMove(HuntTheWumpus::DungeonMove::Move, { 9 });

    // Trigger interaction: Hunter shoot an error
    std::cout << "\nHunter is now shooting arrow through caves 5, 6, 7..." << std::endl;
    dungeon.MakeMove(HuntTheWumpus::DungeonMove::Shoot, { 5, 6, 7 });

    return 0;
}

#pragma once

#include "Dungeon.h"
#include "Denizen.h"
#include "Cave.h"
#include "Arrow.h"
#include <unordered_map>
#include <memory>
#include <functional>


namespace TestHuntTheWumpus
{
    class TestDungeon final : public HuntTheWumpus::IDungeon
    {
    public:
        TestDungeon() = default;
        //explicit TestDungeon(HuntTheWumpus::Context& context) : m_realDungeon(context) {}

        // Forward the required interface mehtods to the real dungeon
        const std::shared_ptr<HuntTheWumpus::Cave>& FindCave(int) override
        {
            return m_emptyCave;
           // return m_realDungeon.FindCave(caveId);
        }

        void Move(const HuntTheWumpus::DenizenIdentifier& identifier, const int destinationCave) override
        {
            m_thingToMove = identifier;
            m_requestedDestination = destinationCave;
           // m_realDungeon.Move(identifier, destinationCave);
        }

        void MoveDenizenRandomly(const HuntTheWumpus::DenizenIdentifier& identifier) override
        {
            //m_realDungeon.MoveDenizenRandomly(identifier);
             m_moveDenizenRandomlyTriggered = true;
             m_thingToMove = identifier;
        }

        /*  void AddToCavePublic(const std::shared_ptr<HuntTheWumpus::Denizen>& denizen, const int caveId)
          {
              m_caveDenizens.emplace(denizen->GetIdentifier(), denizen);
              auto cave = std::make_shared<HuntTheWumpus::Cave>(caveId, *this);
              denizen->EnterCave(cave);
          }*/

          // Add Hunter or arrow directly to a specific cave
        //void AddToCavePublic(const std::shared_ptr<HuntTheWumpus::Denizen>& denizen, const int caveId)
        //{
        //    m_realDungeon.AddToCaveForTesting(denizen, caveId, /*observeEntrance=*/false);
        //}

        //void MakeMove(HuntTheWumpus::DungeonMove operation, const std::vector<int>& destinationIds)
        //{
        //    //m_realDungeon.MakeMove(operation, destinationIds);
        //     m_lastMoveOperation = operation;
        //     m_lastMovePath = destinationIds;
        //}


        // Members for verifying test behavior
        std::shared_ptr<HuntTheWumpus::Cave> m_emptyCave = {};
        int m_requestedDestination = -1;
        HuntTheWumpus::DenizenIdentifier m_thingToMove = {};
        bool m_moveDenizenRandomlyTriggered = false;

        //Simulates the internal game state by tracking all denizens placed in the dungeon for test purposes.
       // std::unordered_map<HuntTheWumpus::DenizenIdentifier, std::shared_ptr<HuntTheWumpus::Denizen>, HuntTheWumpus::DenizenIdentifierHasher> m_caveDenizens;

        // std::unordered_map<HuntTheWumpus::DenizenIdentifier, std::shared_ptr<HuntTheWumpus::Denizen>> m_caveDenizens;

         // Rule of 5
        ~TestDungeon() override = default;
        TestDungeon(const TestDungeon&) = delete;
        TestDungeon(TestDungeon&&) = delete;
        TestDungeon& operator=(const TestDungeon&) = delete;
        TestDungeon& operator=(TestDungeon&&) = delete;

    //private:
    //    HuntTheWumpus::Dungeon m_realDungeon; // composition over inheritance

    };
}

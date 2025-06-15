#pragma once
#include "IGameStateChange.h"
#include <iostream>

namespace HuntTheWumpus
{
	class GameStateChange : public IGameStateChange
	{
        void GameOver(bool win) override
        {
            std::cout << "[Game Over] You " << (win ? "won!" : "lost!") << "\n";
        }

        void IsPlaying(bool playing) override
        {
            std::cout << "[Game State] Is playing: " << (playing ? "yes" : "no") << "\n";
        }

	};
}

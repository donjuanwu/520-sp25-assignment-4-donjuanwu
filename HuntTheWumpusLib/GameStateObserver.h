#pragma once

#include "GameStateObservation.h"
#include <iostream>

namespace HuntTheWumpus
{
    class GameStateObserver : public IGameStateChange
    {
    public:
        void GameOver(bool won) override
        {
            m_isPlaying = false;
            std::cout << (won ? "You won the game!" : "You lost the game!") << std::endl;
        }

        [[nodiscard]] bool IsPlaying() const override
        {
            return m_isPlaying;
        }

    private:
        bool m_isPlaying = true;
    };
}


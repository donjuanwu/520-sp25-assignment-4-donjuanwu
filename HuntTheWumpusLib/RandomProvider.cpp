#include "RandomProvider.h"
#include <chrono>

namespace HuntTheWumpus
{
    RandomProvider::RandomProvider()
        : m_rng(static_cast<unsigned int>(
            std::chrono::steady_clock::now().time_since_epoch().count())),
        m_caveDist(1, 20),
        m_tunnelDist(0, 2),
        m_floatDist(0.0f, 1.0f)
    {
    }

    int RandomProvider::MakeRandomCave()
    {
        return m_caveDist(m_rng);
    }

    int RandomProvider::MakeRandomTunnel()
    {
        return m_tunnelDist(m_rng);
    }

    float RandomProvider::MakeRandomNumber()
    {
        return m_floatDist(m_rng);
    }
}

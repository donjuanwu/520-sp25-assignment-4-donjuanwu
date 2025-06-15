#pragma once

#include "IRandomProvider.h"
#include <random>


namespace HuntTheWumpus
{
	class RandomProvider : public IRandomProvider
	{
	public:
		RandomProvider();

		int MakeRandomCave() override;
		int MakeRandomTunnel() override;
		float MakeRandomNumber() override;

	private:
		std::mt19937 m_rng;
		std::uniform_int_distribution<int> m_caveDist;
		std::uniform_int_distribution<int> m_tunnelDist;
		std::uniform_real_distribution<float> m_floatDist;

	};

}



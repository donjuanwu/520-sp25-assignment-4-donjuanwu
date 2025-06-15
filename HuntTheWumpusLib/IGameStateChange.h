#pragma once

namespace HuntTheWumpus
{
	class IGameStateChange
	{
	public:
		virtual ~IGameStateChange() = default;

		// Called when the gamne ends: true = win, false = loss
		virtual void GameOver(bool win) = 0;

		// Called to set if the game is currently active
		virtual void IsPlaying(bool playing) = 0;
	};
}

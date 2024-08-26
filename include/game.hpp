#ifndef GAME_HPP
#define GAME_HPP

#include "../include/player.hpp"
#include<iostream>
#include<vector>


class Game
{
	public:
		Game(Player& player_1, Player& player_2);
		void start();
	private:
		Player& player_1;
		Player& player_2;
};



#endif //GAME_HPP

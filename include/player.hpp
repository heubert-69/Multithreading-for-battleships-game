#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "../include/board.hpp"
#include<iostream>
#include<string>
#include<mutex>


class Player
{
	public:
		Player(const std::string& name, Board& board);
		void place_ships();
		void take_turn(Player& player);
		bool has_lost();

		Board& get_board();
	private:
		std::string name;
		Board& board;
		bool lost; //determines the victor of the game
		std::mutex playerMutex;

};


#endif //PLAYER_HPP

#include<iostream>
#include "../include/game.hpp"
#include "../include/player.hpp"
#include<mutex>
#include<string>
#include<thread>




Game::Game(Player& player_1, Player& player_2) : player_1(player_1), player_2(player_2){}

void Game::start()
{

	player_1.place_ships();
	player_2.place_ships();

	std::thread player_1_Thread(&Player::take_turn, &player_1, std::ref(player_2));
	std::thread player_2_Thread(&Player::take_turn, &player_2, std::ref(player_1));

	player_1_Thread.join();
	player_2_Thread.join();
}


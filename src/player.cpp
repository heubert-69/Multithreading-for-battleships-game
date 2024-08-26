#include<iostream>
#include "../include/player.hpp"
#include "../include/board.hpp"

Player::Player(const std::string& name, Board& board) : name(name), board(board), lost(false){}

void Player::place_ships()
{
	board.place_ships(0, 0, 3, 'H');
}

void Player::take_turn(Player& player)
{

	int x, y;

	std::cout << name << "'s turn. Enter Coordinates to fire at (x, y): ";
	std::cin >> x >> y;

	if(player.get_board().fire_at(x, y)){
		std::cout << name <<  " hit a ship" << std::endl;
	} else {std::cout << "missed" << std::endl;}


	//checks if the opponent has lost
	if(player.has_lost()){
		std::cout << name << " wins!" << std::endl;
		lost = true;
	}

}

bool Player::has_lost()
{
	return lost;
}

Board& Player::get_board()
{
	return board;
}

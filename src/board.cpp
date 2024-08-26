#include "../include/board.hpp"
#include<iostream>
#include<vector>
#include<string>
#include<thread>
#include<mutex>

Board::Board(int size) : size(size), board(size, std::vector<char>(size, '~')) {}

void Board::place_ships(int x, int y, int length, char direction)
{

	std::lock_guard<std::mutex> lock(Boardmutex);
	for(int i=0; i<length; i++){
		if(direction == 'H'){
			board[x][y+i] = 'S';
		} else {board[x+i][y] = 'S';}
	}
}

bool Board::fire_at(int x, int y)
{

	std::lock_guard<std::mutex> lock(Boardmutex);
	if(board[x][y] == 'S'){
		board[x][y]='X'; return true;
	} else {board[x][y] = 'O'; return false;}

}

void Board::display()
{
	std::lock_guard<std::mutex> lock(Boardmutex);

	for(const auto& row: board){
		for(const auto& cell: row){
			std::cout << cell << " ";
		}
		std::cout << std::endl;
	}
}


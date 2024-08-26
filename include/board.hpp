#ifndef BOARD_HPP
#define BOARD_HPP

#include<iostream>
#include<vector>
#include<mutex>

class Board
{
	public:
		Board(int size=10); //predetermined size of the board is 10x10
		void place_ships(int x, int y, int length, char direction);
		bool fire_at(int x, int y);
		void display();

	private:
		int size;
		std::vector<std::vector<char>> board;
		std::mutex Boardmutex; //esentially  represents your board and enemys board

};



#endif //BOARD_HPP

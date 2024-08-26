#include "../include/game.hpp"
#include "../include/board.hpp"
#include "../include/player.hpp"


int main()
{

	Board board_1;
	Board board_2;


	Player player_1("Player 1", board_1);
	Player player_2("Player 2", board_2);

	Game game(player_1, player_2);
	game.start();

	return 0;

}

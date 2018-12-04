#include "amazons.h"

#include <array>
#include <iostream>
#include <string>

// Print the board in human-readable form.
void print_board(
	std::array<std::array<int, COL_COUNT>, ROW_COUNT> const& board
)
{
	for (auto x = 0; x < ROW_COUNT; ++x)
	{
		for (auto y = 0; y < COL_COUNT; ++y)
		{
			switch (board[x][y])
			{
			case amazons::blank:
				std::cout << '_';
				break;
			case amazons::killed:
				std::cout << 'X';
				break;
			default:
				std::cout << board[x][y];
			}
			std::cout << ' ';
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

// Print the help page,
void print_help()
{
	std::cout << "h for help (this page)" << std::endl;
	std::cout << "l (lowercase L) for listing moves" << std::endl;
	std::cout << "m to input a move" << std::endl;
	std::cout << "Making move: Target, Move & Shoot Coordinates" << std::endl;
	std::cout
		<< "ie. \"Move a player at (7, 6) to (7, 7) and shoot to (7, 6)\""
		<< std::endl;
	std::cout << "your input choices:" << std::endl;
	std::cout << "7 6  7 7  7 6" << std::endl;
	std::cout << "76 77 76" << std::endl;
	std::cout << "767776" << std::endl;
}

// Print the list of moves.
void print_moves(const std::list<move> li)
{
	std::cout << "Possible Target, Move & Shoot Coordinates:" << std::endl;
	for (auto && move : li)
	{
		std::cout << "(" << move.curr[X] << ", " << move.curr[Y] << "), ("
			<< move.mvCoor[X] << ", " << move.mvCoor[Y] << "), ("
			<< move.shoot[X] << ", " << move.shoot[Y] << ")"
			<< std::endl;
	}
	std::cout << std::endl;
}

int main()
{
	while (true)
	{
		amazons a1;

		// Input board.
		while (true)
		{
			std::cout << std::endl;
			std::cout << "Use StartBoard.txt/TestBoard.txt?" << std::endl;
			std::cout << "type s for sb" << std::endl;
			std::cout << "type t for tb" << std::endl;

			const auto boardInput = getchar();
			if (boardInput == 's')
			{
				a1.read_from_file("StartBoard.txt");
				std::cout << std::endl;
				print_board(a1.prevMat);
				break;
			}
			else if (boardInput == 't')
			{
				a1.read_from_file("TestBoard.txt");
				std::cout << std::endl;
				print_board(a1.prevMat);
				break;
			}
		}

		// Input player.
		while (true)
		{
			std::cout << std::endl;
			std::cout << "Use black(1)/white(2)?" << std::endl;
			std::cout << "type b or w" << std::endl;

			const auto playerInput = getchar();
			amazons::coord_status player;
			amazons::coord_status opponent;
			if (playerInput == 'b')
			{
				player = amazons::black;
				opponent = amazons::white;
				break;
			}
			else if (playerInput == 'w')
			{
				player = amazons::white;
				opponent = amazons::black;
				break;
			}
		}

		// Input the turn.
		while (true)
		{
			std::cout << std::endl;
			std::cout << "Go first/second when starting?" << std::endl;
			std::cout << "type 1 or 2" << std::endl;

			const auto turnInput = getchar();
			bool isFirstTurn;
			if (turnInput == '1')
			{
				isFirstTurn = true;
				break;
			}
			else if (turnInput == '2')
			{
				isFirstTurn = false;
				break;
			}
		}

		// Input AI.
		while (true)
		{
			std::cout << std::endl;
			std::cout << "AI?" << std::endl;
			std::cout << "1 for min/max" << std::endl;
			std::cout << "2 for max/min" << std::endl;

			const auto AIInput = getchar();
			amazons::AI ai;
			if (AIInput == '1')
			{
				ai = amazons::minMax;
				break;
			}
			else if (AIInput == '2')
			{
				ai = amazons::maxMin;
				break;
			}
		}

		//// game loop
		//auto plmvli = amazons::list_all_moves(player, a1.prevMat);
		//auto oppomvli = amazons::list_all_moves(player, a1.prevMat);
		//while ()
		//{

		//}


		//const auto tmp = a1.next_move(amazons::white, amazons::maxMin);

		//print_moves(a1.list_moves(amazons::black));
		//print_moves(a1.list_moves(amazons::white));

	}

	return 0;
}

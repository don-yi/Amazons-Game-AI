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
	// Input board.
	std::cout << "Use StartBoard.txt/TestBoard.txt?" << std::endl;
	std::cout << "type s for sb" << std::endl;
	std::cout << "type t for tb" << std::endl;

	amazons a1;
	const auto boardInput = getchar();
	if (boardInput == 's')
	{
		a1.read_from_file("StartBoard.txt");
	}
	else if (boardInput == 't')
	{
		a1.read_from_file("TestBoard.txt");
	}
	std::cout << std::endl;
	print_board(a1.prevMat);

	// Input player.
	std::cout << std::endl;
	std::cout << "Use black(1)/white(2)?" << std::endl;
	std::cout << "type b or w" << std::endl;

	const auto playerInput = getchar();
	amazons::coord_status player;
	if (boardInput == 'b')
	{
		player = amazons::black;
	}
	else if (boardInput == 'w')
	{
		player = amazons::white;
	}
	std::cout << std::endl;

	// Input AI.
	std::cout << std::endl;
	std::cout << "AI?" << std::endl;
	std::cout << "1 for min/max" << std::endl;
	std::cout << "2 for max/min" << std::endl;

	const auto AIInput = getchar();
	amazons::AI ai;
	if (AIInput == '1')
	{
		ai = amazons::minMax;
	}
	else if (AIInput == '2')
	{
		ai = amazons::maxMin;
	}
	std::cout << std::endl;

	// input instruction
	//std::cout << std::endl;
	//std::cout << "AI?" << std::endl;
	//std::cout << "1 for min/max" << std::endl;
	//std::cout << "2 for max/min" << std::endl;

	//const auto tmp = a1.next_move(amazons::white, amazons::maxMin);

	//print_moves(a1.list_moves(amazons::black));
	//print_moves(a1.list_moves(amazons::white));

	std::getchar();

	return 0;
}

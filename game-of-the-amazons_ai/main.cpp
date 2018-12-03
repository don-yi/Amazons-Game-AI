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
void print_possible_moves(const std::list<move> li)
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

int main(void)
{
	/////////////////////////////////
	// TEST
	/////////////////////////////////
	//auto const& tmpBoard = generate_new_board();

	amazons a1;
	a1.read_from_file("TestBoard.txt");
	print_board(a1.prevMat);

	const auto tmp = a1.next_move(amazons::black, amazons::minMax);

	//const move m1 = { {7, 6}, {9, 6}, {7, 6} };
	//std::cout << a1.validate_move(m1);

	//if (a1.validate_move(m1))
	//{
	//	print_board(a1.afterMat);
	//	a1.prevMat = a1.afterMat;

	//	//print_board(a1.afterMat);
	//}

	//print_possible_moves(a1.list_possible_moves(amazons::black));
	//print_possible_moves(a1.list_possible_moves(amazons::white));
	/////////////////////////////////

	std::getchar();

	return 0;
}

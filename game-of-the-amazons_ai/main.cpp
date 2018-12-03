#include <array>
#include <iostream>
#include <string>

#include "amazons.h"

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
}

int main(void)
{
	/////////////////////////////////
	// TEST
	/////////////////////////////////
	//auto const& tmpBoard = generate_new_board();

	amazons a1;
	a1.read_from_file("TestBoard.txt");
	//print_board(a1.prevMat);
	const move m1 = { {9, 7}, {7, 7}, {9, 7} };
	std::cout << a1.validate_move(m1);
	/////////////////////////////////

	std::getchar();

	return 0;
}

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

int main(void)
{
	/////////////////////////////////
	// TEST
	/////////////////////////////////
	//auto const& tmpBoard = generate_new_board();

	amazons a1;
	a1.read_from_file("TestBoard.txt");
	print_board(a1.prevMat);
	// todo: print mv list
	std::cout << a1.list_moves().size() << std::endl;

	const move m1 = { {7, 6}, {9, 6}, {7, 6} };
	//std::cout << a1.validate_move(m1);
	if (a1.validate_move(m1))
	{
		print_board(a1.afterMat);
		a1.prevMat = a1.afterMat;

		//print_board(a1.afterMat);
	}
	/////////////////////////////////

	std::getchar();

	return 0;
}

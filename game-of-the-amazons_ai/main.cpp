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
			case amazons::black:
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
	//auto const& tmpBoard = generate_new_board();
	//auto const& tmpBoard = read_from_file("TestBoard.txt");
	//print_board(tmpBoard);

	std::getchar();

	return 0;
}

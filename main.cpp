#include <array>
#include <iostream>

#define ROW_COUNT 10
#define COL_COUNT 10

// Make a new board.
std::array<std::array<int, COL_COUNT>, ROW_COUNT> generate_new_board(void)
{
	std::array<std::array<int, COL_COUNT>, ROW_COUNT> newBoard{};

	// Assign player values at the default starting positions.
	newBoard[0][3] = 1;
	newBoard[0][6] = 1;
	newBoard[3][0] = 1;
	newBoard[3][9] = 1;

	newBoard[6][0] = 2;
	newBoard[6][9] = 2;
	newBoard[9][3] = 2;
	newBoard[9][6] = 2;

	return newBoard;
}

// Print the board.
void print_board(
	std::array<std::array<int, COL_COUNT>, ROW_COUNT> const& board
)
{
	for (auto x = 0; x < ROW_COUNT; ++x)
	{
		for (auto y = 0; y < COL_COUNT; ++y)
		{
			std::cout << board[x][y] << " ";
		}
		std::cout << std::endl;
	}
}

int main(void)
{
	auto const& tmpBoard = generate_new_board();
	print_board(tmpBoard);

	std::getchar();

	return 0;
}

#include <array>
#include <iostream>

#define ROW_COUNT 10
#define COL_COUNT 10

// Not used.
// Make a new board.
std::array<std::array<int, COL_COUNT>, ROW_COUNT> generate_new_board(void)
{
	//std::array<std::array<int, COL_COUNT>, ROW_COUNT> newBoard{};

	//// Assign player values at the default starting positions.
	//newBoard[0][3] = 1;
	//newBoard[0][6] = 1;
	//newBoard[3][0] = 1;
	//newBoard[3][9] = 1;

	//newBoard[6][0] = 2;
	//newBoard[6][9] = 2;
	//newBoard[9][3] = 2;
	//newBoard[9][6] = 2;

	// temp testing board
	std::array<std::array<int, COL_COUNT>, ROW_COUNT> newBoard;

	for (auto&& eachCol : newBoard)
	{
		eachCol.fill(3);
	}

	// Assign testing values.
	newBoard[7][6] = 1;
	newBoard[8][6] = 0;
	newBoard[9][6] = 0;

	newBoard[7][7] = 0;
	newBoard[9][7] = 2;

	return newBoard;
}

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
			case 0:
				std::cout << "_";
				break;
			case 3:
				std::cout << "X";
				break;
			default:
				std::cout << board[x][y];
			}
			std::cout << " ";
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

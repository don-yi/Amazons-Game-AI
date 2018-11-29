#include <array>

#define ROW_COUNT 10
#define COL_COUNT 10

// Create new board.
std::array<std::array<int, COL_COUNT>, ROW_COUNT> create_new_board(void)
{
	//const auto newBoard = new int*[ROW_COUNT];
	//for (auto i = 0; i < ROW_COUNT; ++i)
	//{
	//	newBoard[i] = new int[COL_COUNT];
	//}

	const std::array<std::array<int, COL_COUNT>, ROW_COUNT> newBoard{};

	return newBoard;
}

int main(void)
{

	return 0;
}

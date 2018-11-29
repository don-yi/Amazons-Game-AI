#include <fstream>
#include <cassert>

#include "amazons.h"

// Read a board from a text file and convert it into a two dimensional array.
std::array<std::array<int, COL_COUNT>, ROW_COUNT> amazons::read_from_file(
	const std::string& fileName
)
{
	std::ifstream file(fileName);

	// Check the file was opened.
	const auto open = file.is_open();
	assert(open);

	std::array<std::array<int, COL_COUNT>, ROW_COUNT> board{};
	std::string line;

	// Extract from the file and assign to a board.
	for (size_t x = 0; x < COL_COUNT; ++x)
	{
		std::getline(file, line);
		size_t y = 0;
		for (auto ch : line)
		{
			if (ch == ' ')
			{
				continue;
			}
			else
			{
				board[x][y++] = atoi(&ch);
			}
		}
	}

	prevMat = board;

	// Close the file and return.
	file.close();
	return board;
}

#include <fstream>
#include <cassert>

#include "amazons.h"
#include <complex>

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

// Checks to see if a move is valid,
// returning 1 for a valid move, and 0 for an invalid move.
#define X 0
#define Y 1
bool amazons::validate_move(move mv) const
{
	// Check for the availity of the position.
	if (prevMat[mv.mvCoor[X]][mv.mvCoor[Y]] != 0 ||
		(prevMat[mv.shoot[X]][mv.shoot[Y]] != 0 &&
		!(mv.curr[X] == mv.shoot[X] && mv.curr[Y] == mv.shoot[Y]))
		)
	{
		return false;
	}

	// Check the movable space from the starting position.
	// Check the position to move.
	if ((mv.curr[X] - mv.mvCoor[X] != 0 && mv.curr[Y] - mv.mvCoor[Y] != 0) &&
		(std::abs(mv.curr[X] - mv.mvCoor[X])
			!= std::abs(mv.curr[Y] - mv.mvCoor[Y]))
		)
	{
		// Check the position to shoot.
		if ((mv.shoot[X] - mv.mvCoor[X] != 0
			&& mv.shoot[Y] - mv.mvCoor[Y] != 0) &&
			(std::abs(mv.shoot[X] - mv.mvCoor[X])
				!= std::abs(mv.shoot[Y] - mv.mvCoor[Y]))
			)
		{
			return false;
		}
	}

	// Check if there's an obstacle while moving.
	if (mv.curr[X] - mv.mvCoor[X] == 0)
	{
		if (mv.mvCoor[Y] < mv.curr[Y])
		{
			for (auto i = 1; i < mv.curr[Y] - mv.mvCoor[Y]; ++i)
			{
				if (prevMat[mv.curr[X]][mv.curr[Y] - i] != blank)
				{
					return false;
				}
			}
		}
		else if (mv.mvCoor[Y] > mv.curr[Y])
		{
			for (auto i = 1; i < mv.mvCoor[Y] - mv.curr[Y]; ++i)
			{
				if (prevMat[mv.curr[X]][mv.curr[Y] + i] != blank)
				{
					return false;
				}
			}
		}
	}
	else if (mv.curr[Y] - mv.mvCoor[Y] == 0)
	{
		if (mv.mvCoor[X] < mv.curr[X])
		{
			for (auto i = 1; i < mv.curr[X] - mv.mvCoor[X]; ++i)
			{
				if (prevMat[mv.curr[X] - i][mv.curr[Y]] != blank)
				{
					return false;
				}
			}
		}
		else if (mv.mvCoor[X] > mv.curr[X])
		{
			for (auto i = 1; i < mv.mvCoor[X] - mv.curr[X]; ++i)
			{
				if (prevMat[mv.curr[X] + i][mv.curr[Y]] != blank)
				{
					return false;
				}
			}
		}
	}

	return true;
}

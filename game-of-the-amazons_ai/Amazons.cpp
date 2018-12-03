#include "amazons.h"

#include <fstream>
#include <cassert>
#include <complex>

#define X 0
#define Y 1

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
	afterMat = board;

	// Close the file and return.
	file.close();
	return board;
}

// Check the movable space from the starting position.
bool amazons::is_in_range(int const* from, int const* dest)
{
	return !(
		(from[X] - dest[X] != 0 && from[Y] - dest[Y] != 0)
			&& (std::abs(from[X] - dest[X])
				!= std::abs(from[Y] - dest[Y]))
		);
}

// Checks if there's an obstacle while moving or shooting.
bool amazons::is_blocked(
	const int* from,
	const int* dest,
	std::array<std::array<int, 10>, 10> prevMat
)
{
	// Check vertical and horizontal moves.
	// horizontal moves
	if (from[X] - dest[X] == 0)
	{
		// to horizontally left
		if (dest[Y] < from[Y])
		{
			for (auto i = 1; i < from[Y] - dest[Y]; ++i)
			{
				if (prevMat[from[X]][from[Y] - i] != blank)
				{
					return true;
				}
			}
		}
		// to horizontally right
		else if (dest[Y] > from[Y])
		{
			for (auto i = 1; i < dest[Y] - from[Y]; ++i)
			{
				if (prevMat[from[X]][from[Y] + i] != blank)
				{
					return true;
				}
			}
		}
	}
	// vertical moves
	else if (from[Y] - dest[Y] == 0)
	{
		// to vertically up
		if (dest[X] < from[X])
		{
			for (auto i = 1; i < from[X] - dest[X]; ++i)
			{
				if (prevMat[from[X] - i][from[Y]] != blank)
				{
					return true;
				}
			}
		}
		// to vertically down
		else if (dest[X] > from[X])
		{
			for (auto i = 1; i < dest[X] - from[X]; ++i)
			{
				if (prevMat[from[X] + i][from[Y]] != blank)
				{
					return true;
				}
			}
		}
	}

	// Check diagonal moves.
	else
	{
		// to top-right destination
		if (from[X] > dest[X] && from[Y] < dest[Y])
		{
			for (auto i = 1; i < dest[Y] - from[Y]; ++i)
			{
				if (prevMat[from[X] - i][from[Y] + i] != blank)
				{
					return true;
				}
			}
		}
		// to bottom-right destination
		else if (from[X] < dest[X] && from[Y] < dest[Y])
		{
			for (auto i = 1; i < dest[Y] - from[Y]; ++i)
			{
				if (prevMat[from[X] + i][from[Y] + i] != blank)
				{
					return true;
				}
			}
		}
		// to bottom-left destination
		else if (from[X] < dest[X] && from[Y] > dest[Y])
		{
			for (auto i = 1; i < dest[X] - from[X]; ++i)
			{
				if (prevMat[from[X] + i][from[Y] - i] != blank)
				{
					return true;
				}
			}
		}
		// to top-left destination
		else if (from[X] > dest[X] && from[Y] > dest[Y])
		{
			for (auto i = 1; i < from[X] - dest[X]; ++i)
			{
				if (prevMat[from[X] - i][from[Y] - i] != blank)
				{
					return true;
				}
			}
		}
	}

	return false;
}

// Checks to see if a move is valid,
// returning 1 for a valid move, and 0 for an invalid move.
bool amazons::validate_move(const move mv)
{
	const auto currx = mv.curr[X];
	const auto curry = mv.curr[Y];
	const auto mvx = mv.mvCoor[X];
	const auto mvy = mv.mvCoor[Y];
	const auto shootx = mv.shoot[X];
	const auto shooty = mv.shoot[Y];

	// Check for the availity of the position.
	if (prevMat[mvx][mvy] != 0 ||
		(prevMat[shootx][shooty] != 0 &&
			!(currx == shootx && curry == shooty)) ||
			(mvx == shootx && mvy == shooty)
		)
	{
		return false;
	}

	// Check the movable space from the starting position.
	// Check the position to move.
	if (!is_in_range(mv.curr, mv.mvCoor))
	{
		return false;
	}
	// Check the position to shoot.
	if (!is_in_range(mv.shoot, mv.mvCoor))
	{
		return false;
	}

	// Check for obstacle in player movement.
	if (is_blocked(mv.curr, mv.mvCoor, prevMat))
	{
		return false;
	}
	// Check for obstacle in shooting.
	if (is_blocked(mv.mvCoor, mv.shoot, prevMat))
	{
		return false;
	}

	afterMat[mv.mvCoor[X]][mv.mvCoor[Y]] = prevMat[mv.curr[X]][mv.curr[Y]];
	afterMat[mv.curr[X]][mv.curr[Y]] = blank;
	afterMat[mv.shoot[X]][mv.shoot[Y]] = killed;

	return true;
}

std::list<move> amazons::list_moves()
{
	std::list<move> res;

	// Look for the player.
	for (auto i = 0; i < ROW_COUNT; ++i)
	{
		for (auto j = 0; j < COL_COUNT; ++j)
		{
			if (prevMat[i][j] == black)
			{
				// current player position
				move mv = { {i, j} };

				// every possible moveable coordinates
				for (auto k = 0; k < ROW_COUNT; ++k)
				{
					for (auto l = 0; l < COL_COUNT; ++l)
					{
						mv.mvCoor[X] = k;
						mv.mvCoor[Y] = l;

						// every possible shootable coordinates
						for (auto m = 0; m < ROW_COUNT; ++m)
						{
							for (auto n = 0; n < COL_COUNT; ++n)
							{
								mv.shoot[X] = m;
								mv.shoot[Y] = n;

								// Validate move.
								if (validate_move(mv))
								{
									res.push_back(mv);
								}
							}
						}
					}
				}
			}
		}
	}

	return res;
}
#pragma once

#include <array>
#include <string>
#include <vector>

#define ROW_COUNT 10
#define COL_COUNT 10

struct move
{
	int curr[2];
	int mvCoor[2];
	int shoot[2];
};

struct amazons
{
	enum coord_status
	{
		blank,
		black,
		white,
		killed
	};

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
		std::array<std::array<int, COL_COUNT>, ROW_COUNT> newBoard{};

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

	// Read a board from a text file and convert it into a two dimensional array.
	std::array<std::array<int, COL_COUNT>, ROW_COUNT> read_from_file(
		const std::string& fileName
	);

	// Checks to see if a move is valid,
	// returning 1 for a valid move, and 0 for an invalid move.
	bool validate_move(move) const;

	std::array<std::array<int, COL_COUNT>, ROW_COUNT> prevMat = {};
	std::array<std::array<int, COL_COUNT>, ROW_COUNT> afterMat = {};
};

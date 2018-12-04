#pragma once

#include <array>
#include <string>
#include <vector>
#include <list>

#define ROW_COUNT 10
#define COL_COUNT 10
#define X 0
#define Y 1

struct move
{
	int curr[2];
	int mvCoor[2];
	int shoot[2];
};

typedef std::array<std::array<int, COL_COUNT>, ROW_COUNT> board;

struct amazons
{
private:
	static bool is_blocked(const int* from, const int* dest, board mat);
	static bool is_in_range(int const* from, int const* dest);
	static std::list<move> list_moves(int const* currpos, board mat);
	static board make_tmp_board(move mv, board mat);

public:
	enum coord_status
	{
		blank,
		black,
		white,
		killed
	};

	enum AI
	{
		minMax,
		maxMin
	};

	board prevMat = {};
	board afterMat = {};

	// Not used.
	// Make a new board.
	board generate_new_board(void)
	{
		//board newBoard{};

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
		board newBoard{};

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

	// Read a board from a text file and convert it
		// into a two dimensional array.
	board read_from_file(
		const std::string& fileName
	);

	// Checks to see if a move is valid,
	// returning 1 for a valid move, and 0 for an invalid move.
	static bool validate_move(move mv, board mat);

	static std::list<move> list_all_moves(
		coord_status player, board mat
	);

	// Returns a move on the given board that can be played
	// by the specified player.
	move next_move(coord_status player, AI ai) const;
};

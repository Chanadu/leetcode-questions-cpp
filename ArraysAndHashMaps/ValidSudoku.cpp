#include <unordered_set>
#include <vector>

class Solution {
   public:
	bool isValidSudoku(std::vector<std::vector<char>>& board) {
		for (int i = 0; i < board.size(); i++) {
			std::unordered_set<char> vals;
			for (int j = 0; j < board[i].size(); j++) {
				if (board[i][j] == '.')
					continue;
				if (vals.count(board[i][j]) != 0)
					return false;

				vals.insert(board[i][j]);
			}
		}

		for (int i = 0; i < board[0].size(); i++) {
			std::unordered_set<char> vals;
			for (int j = 0; j < board.size(); j++) {
				if (board[j][i] == '.')
					continue;
				if (vals.count(board[j][i]) != 0)
					return false;

				vals.insert(board[j][i]);
			}
		}

		// if (board.size() % 3 != 0 && board[0].size() % 3 != 0)
		// 	return false;

		for (int i = 0; i < board.size(); i += 3) {
			for (int j = 0; j < board[i].size(); j += 3) {
				std::unordered_set<char> vals;
				for (int bi = 0; bi < 3; bi++) {
					for (int bj = 0; bj < 3; bj++) {
						int ni = bi + i;
						int nj = bj + j;
						if (board[ni][nj] == '.')
							continue;
						if (vals.count(board[ni][nj]) != 0)
							return false;
						vals.insert(board[ni][nj]);
					}
				}
			}
		}

		return true;
	}

	bool moreReadable(std::vector<std::vector<char>>& board) {
		std::unordered_set<char> rows[9];
		std::unordered_set<char> cols[9];
		std::unordered_set<char> squares[9];

		for (int i = 0; i < board.size(); i++) {
			for (int j = 0; j < board.size(); j++) {
				char val = board[i][j];
				if (val == '.')
					continue;

				if (rows[i].count(val) != 0)
					return false;
				if (cols[j].count(val) != 0)
					return false;
				if (squares[(i / 3) * 3 + (j / 3)].count(val) != 0)
					return false;

				rows[i].insert(val);
				cols[j].insert(val);
				squares[(i / 3) * 3 + (j / 3)].insert(val);
			}
		}
		return true;
	}
};
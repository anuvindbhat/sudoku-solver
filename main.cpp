#include <bits/stdc++.h>

using namespace std;

bool valid(vector<string> &ans, int r, int c) {
	char cand = ans[r][c];
	for(int i = 0; i < 9; ++i) {
		if(i == r) {
			continue;
		}
		if(ans[i][c] == cand) {
			return false;
		}
	}
	for(int j = 0; j < 9; ++j) {
		if(j == c) {
			continue;
		}
		if(ans[r][j] == cand) {
			return false;
		}
	}
	int rl = r / 3 * 3;
	int cl = c / 3 * 3;
	for(int i = rl; i < rl + 3; ++i) {
		for(int j = cl; j < cl + 3; ++j) {
			if(i == r and j == c) {
				continue;
			}
			if(ans[i][j] == cand) {
				return false;
			}
		}
	}
	return true;
}

bool solve(vector<string> &ans, vector<string> &board, int r, int c) {
	if(r == 9) {
		return true;
	}
	int nr = r, nc = c + 1;
	if(nc == 9) {
		++nr;
		nc = 0;
	}
	if(board[r][c] != '.') {
		return solve(ans, board, nr, nc);
	}
	for(int i = 1; i <= 9; ++i) {
		ans[r][c] = i + '0';
		if(!valid(ans, r, c)) {
			continue;
		}
		if(solve(ans, board, nr, nc)) {
			return true;
		}
	}
	ans[r][c] = '.';
	return false;
}

void solveSudoku(vector<string> &sud) {
	vector<string> board = sud;
	solve(sud, board, 0, 0);
}

int main() {
	vector<string> sud = {
		"53..7....",
		"6..195...",
		".98....6.",
		"8...6...3",
		"4..8.3..1",
		"7...2...6",
		".6....28.",
		"...419..5",
		"....8..79"
	};
	cout << "Initial board\n";
	for(string s : sud) {
		cout << s << '\n';
	}
	cout << '\n';
	solveSudoku(sud);
	cout << "Solved board\n";
	for(string s : sud) {
		cout << s << '\n';
	}
	cout << '\n';
	return 0;
}
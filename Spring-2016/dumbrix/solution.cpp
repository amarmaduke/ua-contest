#include <bits/stdc++.h>

using namespace std;

int start_row, start_col, board[9][9], solved, dx[] = { -1, 0, 1, 0 }, dy[] = { 0, -1, 0, 1 };
pair<int, int> loc[82];
vector<int> next_vals;

bool valid_index(int row, int col) {
  return row > -1 && col > -1 && row < 9 && col < 9;
}

void solve_puzzle(int row, int col, int current_val, int next_val_index) {
  if (current_val == 81) solved = 1;
  if (solved) return;

  int next_val = next_vals[next_val_index];

  while (next_val <= current_val) {
    next_val = next_vals[++next_val_index];
  }

  for (int i = 0; i < 4; ++i) {
    if (valid_index(row + dx[i], col + dy[i])) {
      if (next_val - current_val == 1) {
        if (board[row + dx[i]][col + dy[i]] == next_val) {
          solve_puzzle(row + dx[i], col + dy[i], current_val + 1, next_val_index);
        }
      }
      else if (!board[row + dx[i]][col + dy[i]]) {
        board[row + dx[i]][col + dy[i]] = current_val + 1;
        solve_puzzle(row + dx[i], col + dy[i], current_val + 1, next_val_index);
        if (!solved) board[row + dx[i]][col + dy[i]] = 0;
      }
    }
  }
}

int main() {
  for (int i = 0; i < 9; ++i) {
    for (int j = 0; j < 9; ++j) {
      cin >> board[i][j];
      if (board[i][j]) {
        loc[board[i][j]] = make_pair(i, j);
        next_vals.push_back(board[i][j]);
      }
      if (board[i][j] == 1) {
        start_row = i;
        start_col = j;
      }
    }
  }

  sort(next_vals.begin(), next_vals.end());
  solve_puzzle(start_row, start_col, 1, 1);

  for (int i = 0; i < 9; ++i) {
    cout << board[i][0];
    for (int j = 1; j < 9; ++j) {
      cout << " " << board[i][j];
    }
    cout << "\n";
  }
}

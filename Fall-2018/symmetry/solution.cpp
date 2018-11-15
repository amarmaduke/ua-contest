#include <iostream>

using namespace std;

int main() {
    char board[8][8];

    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            char c;
            cin >> c;
            board[i][j] = c;
        }
    }

    bool result = true;

    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            char top_left = board[i][j];
            char top_right = board[7 - i][j];
            char bottom_left = board[i][7 - j];
            char bottom_right = board[7 - i][7 - j];

            if ((top_left != top_right) || (top_left != bottom_left) || (bottom_left != bottom_right)) {
                result = false;
                break;
            }
        }
    }

    if (result) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}

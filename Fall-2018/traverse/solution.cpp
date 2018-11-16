#include <iostream>
#include <map>
#include <queue>

using namespace std;

typedef map<int, map<int, char> > Board;

struct Cell {
    int i;
    int j;
    int level;

    Cell(int i, int j, int level) : i(i), j(j), level(level) { }
};

void set(int move, int i, int j, Board &board, queue<Cell> &q) {
    if (board[i][j] != 'X' && board[i][j] == '.') {
        if (move > 9) {
            board[i][j] = '*';
        } else {
            board[i][j] = '0' + move;
        }
        q.push(Cell(i, j, move + 1));
    }
}

void knight(int move, int i, int j, Board &board, queue<Cell> &q) {
    set(move, i + 1, j + 2, board, q);
    set(move, i + 1, j - 2, board, q);
    set(move, i - 1, j + 2, board, q);
    set(move, i - 1, j - 2, board, q);

    set(move, i + 2, j + 1, board, q);
    set(move, i - 2, j + 1, board, q);
    set(move, i + 2, j - 1, board, q);
    set(move, i - 2, j - 1, board, q);
}

void rook(int move, int i, int j, Board &board, queue<Cell> &q) {
    int k = 0;
    while (board[i][j + k] != 'X') {
        set(move, i, j + k, board, q);
        ++k;
    }
    k = 0;
    while (board[i][j - k] != 'X') {
        set(move, i, j - k, board, q);
        ++k;
    }
    k = 0;
    while (board[i + k][j] != 'X') {
        set(move, i + k, j, board, q);
        ++k;
    }
    k = 0;
    while (board[i - k][j] != 'X') {
        set(move, i - k, j, board, q);
        ++k;
    }
}

void bishop(int move, int i, int j, Board &board, queue<Cell> &q) {
    int k = 0;
    while (board[i + k][j + k] != 'X') {
        set(move, i + k, j + k, board, q);
        ++k;
    }
    k = 0;
    while (board[i - k][j - k] != 'X') {
        set(move, i - k, j - k, board, q);
        ++k;
    }
    k = 0;
    while (board[i + k][j - k] != 'X') {
        set(move, i + k, j - k, board, q);
        ++k;
    }
    k = 0;
    while (board[i - k][j + k] != 'X') {
        set(move, i - k, j + k, board, q);
        ++k;
    }
}

void queen(int move, int i, int j, Board &board, queue<Cell> &q) {
    rook(move, i, j, board, q);
    bishop(move, i, j, board, q);
}

void print_board(Board &board) {
    for (int i = 0; i < 8; ++i) {
        cout << board[i][0];
        for (int j = 1; j < 8; ++j) {
            cout << " " << board[i][j];
        }
        cout << endl;
    }
}

void traverse(char kind, Board &board, queue<Cell> &q) {
    while (!q.empty()) {
        Cell c = q.front();
        int i = c.i, j = c.j, level = c.level;
        q.pop();

        switch (kind) {
            case 'Q':
                queen(level, i, j, board, q);
                break;
            case 'R':
                rook(level, i, j, board, q);
                break;
            case 'B':
                bishop(level, i, j, board, q);
                break;
            case 'K':
                knight(level, i, j, board, q);
                break;
        }
    }
}

int main() {
    Board board;

    char piece;
    int u, v;
    cin >> piece >> u >> v;

    for (int i = -3; i < 11; ++i) {
        for (int j = -3; j < 11; ++j) {
            board[i][j] = 'X';
        }
    }

    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            char c;
            cin >> c;
            board[i][j] = c;
        }
    }

    board[u][v] = '0';
    queue<Cell> q;
    q.push(Cell(u, v, 1));
    traverse(piece, board, q);
    print_board(board);
}

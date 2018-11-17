#include <iostream>

using namespace std;

int main()
{
    int rook1x = -1;
    int rook1y = -1;
    int rook2x = -1;
    int rook2y = -1;
    char board[8][8];
    for (int y = 0; y < 8; ++y)
    {
        for (int x = 0; x < 8; ++x)
        {
            cin >> board[x][y];
            if (board[x][y] == 'R')
            {
                if (rook1x == -1)
                {
                    rook1x = x;
                    rook1y = y;
                    continue;
                }
                rook2x = x;
                rook2y = y;
            }
        }
    }

    for(int x = rook1x - 1; x > -1; --x){
        if (board[x][rook1y] == 'K' || board[x][rook1y] == 'R')
            break;
        if (board[x][rook1y] == '$')
            cout << rook1x << " " << rook1y << " L " << rook1x - x << endl;
    }
    for(int x = rook1x + 1; x < 8; ++x){
        if (board[x][rook1y] == 'K' || board[x][rook1y] == 'R')
            break;
        if (board[x][rook1y] == '$')
            cout << rook1x << " " << rook1y << " R " << x - rook1x << endl;
    }
    for(int y = rook1y - 1; y > -1; --y){
        if (board[rook1x][y] == 'K' || board[rook1x][y] == 'R')
            break;
        if (board[rook1x][y] == '$')
            cout << rook1x << " " << rook1y << " U " << rook1y - y << endl;
    }
    for(int y = rook1y + 1; y < 8; ++y){
        if (board[rook1x][y] == 'K' || board[rook1x][y] == 'R')
            break;
        if (board[rook1x][y] == '$')
            cout << rook1x << " " << rook1y << " D " << y - rook1y << endl;
    }

    for(int x = rook2x - 1; x > -1; --x){
        if (board[x][rook2y] == 'K' || board[x][rook2y] == 'R')
            break;
        if (board[x][rook2y] == '$')
            cout << rook2x << " " << rook2y << " L " << rook2x - x << endl;
    }
    for(int x = rook2x + 1; x < 8; ++x){
        if (board[x][rook2y] == 'K' || board[x][rook2y] == 'R')
            break;
        if (board[x][rook2y] == '$')
            cout << rook2x << " " << rook2y << " R " << x - rook2x << endl;
    }
    for(int y = rook2y - 1; y > -1; --y){
        if (board[rook2x][y] == 'K' || board[rook2x][y] == 'R')
            break;
        if (board[rook2x][y] == '$')
            cout << rook2x << " " << rook2y << " U " << rook2y - y << endl;
    }
    for(int y = rook2y + 1; y < 8; ++y){
        if (board[rook2x][y] == 'K' || board[rook2x][y] == 'R')
            break;
        if (board[rook2x][y] == '$')
            cout << rook2x << " " << rook2y << " D " << y - rook2y << endl;
    }
    return 0;

}

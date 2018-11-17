#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

int allDirs[8][2];
int knightDirs[8][2];

enum Type
{
    emptySquare = ' ',
    queen = 'q',
    knight = 'n',
    king = 'k'
};

enum Color
{
    white,
    black,
    none
};

Color oppositeColor(Color color)
{
    return color == white ? black : white;
}

struct Position
{
    Position(int row_, int col_)
        : row(row_),
        col(col_)
    {

    }

    Position() { }

    void print()
    {
        printf("(%d, %d)\n", row, col);
    }

    int row;
    int col;
};


struct Piece
{
    bool isEmpty()
    {
        return type == emptySquare;
    }

    bool isCapturablePiece(Color attackColor)
    {
        return isEmpty() || (color == oppositeColor(attackColor) && type != king);
    }

    void print()
    {
        if(type == emptySquare)
        {
            cout << ". ";
        }
        else if(color == white)
        {
            if(type == queen) cout << "Q ";
            if(type == king) cout << "K ";
            if(type == knight) cout << "N ";;
        }
        else
        {
            cout << "$ ";
        }
    }

    Type type;
    Color color;
    Position pos;
};

struct Move
{
    Move(Position from_, Position to_)
        : from(from_),
        to(to_)
    {

    }

    Move() { }

    void print()
    {
        printf(
            "(%d, %d) to (%d, %d)\n",
            from.row,
            from.col,
            to.row,
            to.col);
    }

    Position from;
    Position to;
};

using Moves = vector<Move>;

struct Board
{
    Board()
    {
        for(int i = 0; i < 8; ++i)
        {
            for(int j = 0; j < 8; ++j)
            {
                board[i][j].type = emptySquare;
                board[i][j].pos = Position(i, j);
                board[i][j].color = none;
            }
        }
    }

    void print()
    {
        for(int i = 0; i < 8; ++i)
        {
            for(int j = 0; j < 8; ++j)
            {
                board[i][j].print();
            }

            cout << endl;
        }
    }

    bool checkmateInOne(Color attackColor)
    {
        auto attacks = buildAttackSet(attackColor);
        auto moves = filterToValidMoves(attacks, attackColor);

        for(auto move : moves)
        {
            Board board = *this;
            board.performMove(move);

            if(board.inCheckMate(oppositeColor(attackColor)))
            {
                return true;
            }
        }

        return false;
    }

    Moves filterToValidMoves(Moves& moves, Color color)
    {
        Moves validMoves;

        for(Move move : moves)
        {
            Piece pieceAtTo = getPiece(move.to);

            if(!pieceAtTo.isCapturablePiece(color))
            {
                continue;
            }

            Board newBoard = *this;
            newBoard.performMove(move);

            if(newBoard.inCheck(color))
            {
                continue;
            }

            validMoves.push_back(move);
        }

        return validMoves;
    }

    Moves buildAttackSet(Color color)
    {
        Moves moves;

        for(int i = 0; i < 8; ++i)
        {
            for(int j = 0; j < 8; ++j)
            {
                movesForPiece(getPiece(Position(i, j)), color, moves);
            }
        }

        return moves;
    }

    void movesForPiece(Piece piece, Color color, Moves& moves)
    {
        if(piece.color != color)
        {
            return;
        }

        switch(piece.type)
        {
            case emptySquare:   return;
            case queen:         movesForQueen(piece, moves);    return;
            case knight:        movesForKnight(piece, moves);   return;
            case king:          movesForKing(piece, moves);     return;
        }
    }

    void movesForKing(Piece piece, Moves& moves)
    {
        moveInDirs(piece, allDirs, 8, moves);
    }

    void movesForKnight(Piece piece, Moves& moves)
    {
        moveInDirs(piece, knightDirs, 8, moves);
    }

    void moveInDirs(Piece piece, int dirs[][2], int totalDirs, Moves& moves)
    {
        for(int i = 0; i < totalDirs; ++i)
        {
            Position pos(
                piece.pos.row + dirs[i][0],
                piece.pos.col + dirs[i][1]);

            if(validPosition(pos))
            {
                moves.push_back(Move(piece.pos, pos));
            }
        }
    }

    void movesForQueen(Piece piece, Moves& moves)
    {
        for(int i = 0; i < 8; ++i)
        {
            Board newBoard = *this;
            newBoard.movePieceInLine(piece, allDirs[i][0], allDirs[i][1], moves);
        }
    }

    void movePieceInLine(Piece piece, int dr, int dc, Moves& moves)
    {
        Move move;
        move.from = piece.pos;
        move.to = piece.pos;

        do
        {
            move.to.row += dr;
            move.to.col += dc;

            if(!validPosition(move.to))
            {
                return;
            }

            Piece capturedPiece = getPiece(move.to);
            movePiece(piece, move.to);

            moves.push_back(move);

            if(capturedPiece.type != emptySquare)
            {
                return;
            }
        } while(true);
    }

    bool inCheckMate(Color color)
    {
        if(!inCheck(color))
        {
            return false;
        }

        Piece king = findKing(color);

        vector<Move> kingMoves;
        movesForKing(king, kingMoves);

        for(Move move : kingMoves)
        {
            Board newBoard = *this;

            newBoard.performMove(move);

            if(!newBoard.inCheck(color))
            {
                return false;
            }
        }

        return true;
    }

    bool inCheck(Color color)
    {
        Piece king = findKing(color);

        bool attackMap[8][8];
        buildAttackMap(oppositeColor(color), attackMap);

        return attackMap[king.pos.row][king.pos.col];
    }

    void buildAttackMap(Color color, bool canAttack[8][8])
    {
        for(int i = 0; i < 8; ++i)
        {
            for(int j = 0; j < 8; ++j)
            {
                canAttack[i][j] = false;
            }
        }

        auto moves = buildAttackSet(color);

        for(auto move : moves)
        {
            canAttack[move.to.row][move.to.col] = true;
        }
    }

    void movePiece(Piece& piece, Position newPos)
    {
        Position oldPos = piece.pos;

        board[newPos.row][newPos.col] = piece;
        piece.pos = newPos;

        board[oldPos.row][oldPos.col].type = emptySquare;
    }

    void performMove(Move move)
    {
        board[move.to.row][move.to.col] = getPiece(move.from);
        board[move.from.row][move.from.col].type = emptySquare;

        board[move.to.row][move.to.col].pos = move.to;
    }

    bool validPosition(Position pos)
    {
        return pos.row >= 0 && pos.row < 8 && pos.col >= 0 && pos.col < 8;
    }

    Piece& getPiece(Position pos)
    {
        return board[pos.row][pos.col];
    }

    Piece& findKing(Color color)
    {
        for(int i = 0; i < 8; ++i)
        {
            for(int j = 0; j < 8; ++j)
            {
                Piece& piece = getPiece(Position(i, j));

                if(piece.type == king && piece.color == color)
                {
                    return piece;
                }
            }
        }

        printf("Can't find king for %s\n", color == white ? "white" : "black");
        abort();
    }

    void addPiece(int row, int col, Type type, Color color)
    {
        Piece& piece = getPiece(Position(row, col));

        piece.type = type;
        piece.color = color;
    }

    Piece board[8][8];
};

void buildDirs()
{
    int index = 0;

    for(int i = -1; i <= 1; ++i)
    {
        for(int j = -1; j <= 1; ++j)
        {
            if(i != 0 || j != 0)
            {
                allDirs[index][0] = i;
                allDirs[index][1] = j;
                ++index;
            }
        }
    }

    index = 0;

    for(int i = -2; i <= 2; ++i)
    {
        for(int j = -2; j <= 2; ++j)
        {
            if(i != 0 && j != 0 && abs(i) != abs(j))
            {
                knightDirs[index][0] = i;
                knightDirs[index][1] = j;

                ++index;
            }
        }
    }
}

void printMoves(Moves& moves)
{
    printf("===================\n");
    for(Move m : moves)
    {
        m.print();
    }
    printf("===================\n");
}

Board readBoard()
{
    Board board;

    for(int i = 0; i < 8; ++i)
    {
        string line;
        getline(cin, line);

        for(int j = 0; j < 8; ++j)
        {
            char c = line[j * 2];
            Color color = white;
            Type type;

            if(c == 'K')        type = king;
            else if(c == 'Q')   type = queen;
            else if(c == 'N')   type = knight;
            else if(c == '.')   continue;
            else if(c == '$')
            {
                type = king;
                color = black;
            }

            board.addPiece(i, j, type, color);
        }
    }

    return board;
}

int main()
{
    buildDirs();
    Board board = readBoard();

    cout << (board.checkmateInOne(white) ? "yes" : "no") << endl;
}


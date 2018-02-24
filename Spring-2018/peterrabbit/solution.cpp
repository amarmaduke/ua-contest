#include <iostream>
#include <stack>

using namespace std;

struct PieceOfLand{
	char value;
	bool visited;
	PieceOfLand *up;
	PieceOfLand *down;
	PieceOfLand *left;
	PieceOfLand *right;
};

PieceOfLand *piecesOfLand[10][10];
stack<PieceOfLand*> st;
int carrotCount = 0;
string answer = "";


void visit(PieceOfLand *rabbitPos){
	st.push(rabbitPos);
	rabbitPos->visited = true;
	if(rabbitPos->value == 'C'){
		rabbitPos->value = 'G';
		--carrotCount;
	}
	if(carrotCount && rabbitPos->left)
		if(!rabbitPos->left->visited){
			answer+="L";
			visit(rabbitPos->left);
			if(carrotCount)
				answer+="R";
		}
	if(carrotCount && rabbitPos->right)
		if(!rabbitPos->right->visited){
			answer+="R";
			visit(rabbitPos->right);
			if(carrotCount)
				answer+="L";
		}
	if(carrotCount && rabbitPos->up)
		if(!rabbitPos->up->visited){
			answer+="U";
			visit(rabbitPos->up);
			if(carrotCount)
				answer+="D";
		}
	if(carrotCount && rabbitPos->down)
		if(!rabbitPos->down->visited){
			answer+="D";
			visit(rabbitPos->down);
			if(carrotCount)
				answer+="U";
		}
}


int main(){
	PieceOfLand *rabbitPos;
	int x, y;
	cin >> x >> y;
	for(int i = 0; i < x; ++i){
		for(int j = 0; j < y; ++j){
			char pieceOfLand;
			cin >> pieceOfLand;
			if(pieceOfLand != 'H'){
				piecesOfLand[i][j] = new PieceOfLand;
				piecesOfLand[i][j]->visited = false;
				piecesOfLand[i][j]->value = pieceOfLand;
			}
			else piecesOfLand[i][j] = NULL;
			if(pieceOfLand == 'C')
				++carrotCount;
			if(pieceOfLand == 'R')
				rabbitPos = piecesOfLand[i][j];

		}
	}
	for(int i = 0; i < x; ++i){
		for(int j = 0; j < y; ++j){
			if(!piecesOfLand[i][j])
				continue;
			if(i == 0)
				piecesOfLand[i][j]->up = NULL;
			else
				piecesOfLand[i][j]->up = piecesOfLand[i-1][j];
			if(j == 0)
				piecesOfLand[i][j]->left = NULL;
			else
				piecesOfLand[i][j]->left = piecesOfLand[i][j-1];
			if(i + 1 == x)
				piecesOfLand[i][j]->down = NULL;
			else
				piecesOfLand[i][j]->down = piecesOfLand[i+1][j];
			if(j + 1 == y)
				piecesOfLand[i][j]->right = NULL;
			else
				piecesOfLand[i][j]->right = piecesOfLand[i][j+1];
		}
	}

	visit(rabbitPos);
	cout << answer << endl;

	return 0;
}

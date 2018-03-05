#include <iostream>
#include <fstream>

using namespace std;

char land[10][10];

int fail(string failure){
	cout << failure << endl;
	return 43;
}

int main(int argc, char *argv[])
{
	int x, y, rabbitX, rabbitY;
	int carrotCount = 0;
	ifstream problemInput;
	problemInput.open(argv[1]);
	problemInput >> x;
	problemInput >> y;
	for(int i = 0; i < x; ++i){
		for(int j = 0; j < y; ++j){
			problemInput >> land[i][j];
			if(land[i][j] == 'C')
				++carrotCount;
			if(land[i][j] == 'R'){
				rabbitX = i;
				rabbitY = j;
			}
		}
	}
	problemInput.close();

	int solutionCount = 0;
	string solution;
	string partialSolution;
	while(cin >> partialSolution){
		++solutionCount;
		solution+= partialSolution;
	}

	if(solutionCount > 1){
		return fail("Excessive output.");
	}

	for(int i = 0; i < solution.length(); ++i){
		char current = solution[i];
		if(current == 'U' || current == 'D' || current == 'L' || current == 'R'){
			if(carrotCount == 0){
				return fail("Still hopping after all carrots have been picked up.");
			}
		}
		if(current == 'U'){
			if(rabbitX - 1 < 0){
				return fail("Hopped Up off the map.");
			}
			land[rabbitX][rabbitY] = 'G';
			--rabbitX;
			if(land[rabbitX][rabbitY] == 'H'){
				return fail("Hopped Up into a hole.");
			}
			if(land[rabbitX][rabbitY] == 'C'){
				--carrotCount;
			}
		}
		else if(current == 'D'){
			if(rabbitX + 1 >= x ){
				return fail("Hopped Down off the map.");
			}
			land[rabbitX][rabbitY] = 'G';
			++rabbitX;
			if(land[rabbitX][rabbitY] == 'H'){
				return fail("Hopped Down into a hole.");
			}
			if(land[rabbitX][rabbitY] == 'C'){
				--carrotCount;
			}
		}
		else if(current == 'L'){
			if(rabbitY - 1 < 0){
				return fail("Hopped Left off the map.");
			}
			land[rabbitX][rabbitY] = 'G';
			--rabbitY;
			if(land[rabbitX][rabbitY] == 'H'){
				return fail("Hopped Left into a hole.");
			}
			if(land[rabbitX][rabbitY] == 'C'){
				--carrotCount;
			}
		}
		else if(current == 'R'){
			if(rabbitY + 1 >= y){
				return fail("Hopped Right off the map.");
			}
			land[rabbitX][rabbitY] = 'G';
			++rabbitY;
			if(land[rabbitX][rabbitY] == 'H'){
				return fail("Hopped Right into a hole.");
			}
			if(land[rabbitX][rabbitY] == 'C'){
				--carrotCount;
			}
		}

		else{
			return fail("Found a character that was not a valid move U, D, L, or R.");
		}
	}
	if(carrotCount != 0)
		return fail("Failed to collect all carrots.");
	cout << "Accepted" << endl;
	return 42;
}


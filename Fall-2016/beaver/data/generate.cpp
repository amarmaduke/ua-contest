#include <iostream>
#include <string>
#include <ctime>
#include <fstream>
using namespace std;

// Make bias towards moving right
int TOTAL_ACTIONS = 5;
char actions[] = { 'L', 'R', 'R', 'T', 'X' };

string makeDam(int size) {
	string str;

	for (int i = 0; i < size; ++i) {
		str += (rand() % 2 ? "0" : "1");
	}

	return str;
}

int main() {
	int NUM_TESTS = 100;
	
	srand(time(NULL));

	// Generate tests by getting a dam config, then applying transforms while recording the actions

	for (int test = 4; test <= NUM_TESTS; ++test) {
		ofstream in("test" + to_string(test) + ".in");
		ofstream ans("test" + to_string(test) + ".ans");
		
		string startDam = "0" + makeDam(rand() % 100 + 1) + "0";
		string goalDam = startDam;
		string actionList = "";

		int numActions = rand() % 900 + 99;

		bool shouldTestPass = rand() % 10; 

		int position = 1;
		for (int actionNum = 0; actionNum < numActions; ++actionNum) {
			char action = actions[rand() % TOTAL_ACTIONS];

			// if illegal action panic
			if ((action == 'L' && position == 1) || (action == 'R' && position == startDam.size() - 2)) {
				--actionNum;
				continue;
			} 

			actionList += action;

			if (action == 'L') {
				--position;				
			} else if (action == 'R') {
				++position;
			} else if (action == 'T') {
				goalDam[position] = (goalDam[position] == '0' ? '1' : '0');
			} else if (action == 'X') {
				goalDam[position] = (goalDam[position-1] == goalDam[position+1] ? '0' : '1');
			} else {
				cout << "wtf is going on" << endl;
			}
		}

		// If the test shouldn't pass just cut the action list in half and assum it won't break anything
		if (!shouldTestPass) {
			actionList = actionList.substr(0, actionList.size()/2 + 1);
		}

		in << startDam << endl << goalDam << endl << actionList << endl;
		ans << (shouldTestPass ? "YES" : "NO");
	}

	return 0;
}


#include <iostream>
#include <string>
using namespace std;

int main() {
        string myDam;
        string goalDam;
        string actions;

        cin >> myDam >> goalDam >> actions;

        myDam = "0" + myDam + "0";
        goalDam = "0" + goalDam + "0";

	for (int i = 0, myPos = 1; i < actions.size() - 1 && myDam != goalDam; ++i) {

		if (actions[i] == 'R') {
                        ++myPos;
                } else if (actions[i] == 'L') {
                        --myPos;
                } else if (actions[i] == 'T') {
                        myDam[myPos] = (myDam[myPos] == '0' ? '1' : '0');
                } else if  (actions[i] == 'X') {
                        myDam[myPos] = (myDam[myPos - 1] != myDam[myPos + 1] ? '1' : '0');
                }
	}

        cout << (myDam == goalDam ? "Yes." : "No.") << "\r\n";

        return 0;
}

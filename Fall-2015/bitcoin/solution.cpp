#include <iostream>

using namespace std;

int main() {
	while (true) {
		int n;
		cin >> n;

		if (n == 0) {
			break;
		}

		int lowest = 0;
		int diff = 0;
		for (int i = 0; i < n; ++i) {
			int in;
			cin >> in;
			if (i == 0) {
				lowest = in;
			}
			else {
				if (in < lowest) {
					lowest = in;
				}

				if (diff < in - lowest) {
					diff = in - lowest;
				}
			}
		}

		cout << diff << endl;
	}

	return 0;
}

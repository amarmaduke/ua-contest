#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	int cases;
	cin >> cases;

	for (int c = 0; c < cases; ++c) {
		vector<int> a;
		vector<int> b;

		for (int i = 0; i < 3; ++i) {
			int in;
			cin >> in;
			a.push_back(in);
		}
		
		for (int i = 0; i < 3; ++i) {
			int in;
			cin >> in;
			b.push_back(in);
		}

		sort(a.begin(), a.end());
		sort(b.begin(), b.end());

		bool works = true;
		if (a[0] < b[0]) {
			for (int i = 0; i < 3; ++i) {
				if (a[i] >= b[i]) {
					works = false;
					break;
				}
			}
		}
		else if (b[0] < a[0]) {
			for (int i = 0; i < 3; ++i) {
				if (b[i] >= a[i]) {
					works = false;
					break;
				}
			}
		}
		else {
			works = false;
		}

		cout << (works ? "YES" : "NO") << endl;
	}

	return 0;
}

#include <iostream>
#include <vector>

using namespace std;

int main() {
   while (true) {
      int n;
      cin >> n;
      if (n == 0) break;

      vector<int> input(n);
      for (int i = 0; i < n; ++i) {
         int x;
         cin >> x;
         input[i] = x;
      }

      vector<int> result;
      result.push_back(input[0]);
      for (int i = 1; i < input.size(); ++i) {
         int r;
         if (input[i] == 1) {
            r = (input[i] & input[i-1]);
         } else {
            r = (input[i] | input[i-1]);
         }
         result.push_back(r);
      }

      bool troll = true;
      for (int i = 0; i < result.size(); ++i) {
         if (result[i] == 1) {
            troll = false;
            break;
         }
      }

      if (troll) {
         cout << "Yes." << endl;
      } else {
         cout << "No." << endl;
      }
   }
}

#include <iostream>

using namespace std;

int main() {
   srand(time(0));

   for (int i = 0; i < 20; ++i) {
      int n = (rand() % ((100) - 1)) + 1;
      int h = (rand() % ((1000) - 1)) + 1;
      int b = (rand() % 25);

      if (i > 14) b = 0, n = 100, h = 1000;

      cout << n << endl;
      cout << h << " " << b << endl;
      for (int i = 0; i < n; ++i) {
         cout << rand() % 1000;
         if (i + 1 != n)
            cout << " ";
      }
      cout << endl;
      for (int i = 0; i < n; ++i) {
         cout << rand() % h;
         if (i + 1 != n)
            cout << " ";
      }
      cout << endl;
   }
}

#include <iostream>

using namespace std;

int main()
{
   int kases = 10;
   for (int k = 0; k < kases; ++k)
   {
      int n = 20 + (rand() % 80);
      cout << n << endl;
      for (int i = 0; i < n; ++i)
      {
         for (int j = 0; j < n; ++j)
         {
            int x = rand() % 20;
            cout << (char)('A' + x);
         }
         cout << endl;
      }

      int layers = n / 2;
      if (n % 2 != 0) ++layers;

      for (int i = 0; i < layers; ++i)
      {
         int rot = -10 + rand() % 20;
         cout << rot << endl;
      }
   }
}

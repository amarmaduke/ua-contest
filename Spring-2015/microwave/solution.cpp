#include <iostream>

int main()
{
   using namespace std;
   int kases;
   cin >> kases;

   for (int k = 0; k < kases; ++k)
   {
      int display_time;
      cin >> display_time;
      int seconds = 60*(display_time / 100) + display_time % 100;
      cout << seconds << endl;
   }
   return 0;
}

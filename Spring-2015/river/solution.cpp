#include <iostream>
#include <cstdio>
#include <cmath>

int main()
{
   using namespace std;

   int kases;
   cin >> kases;
   for (int k = 0; k < kases; ++k)
   {
      double rate;
      cin >> rate;

      double height = sqrt(24.0*sqrt(3)*rate);
      printf("%.4f\n", height);
   }
   return 0;
}

#include <iostream>

int main()
{
   using namespace std;

   cout << "30" << endl;
   cout << "1" << endl;
   cout << "50" << endl;

   for (int i = 0; i < 30 - 2; ++i)
   {
      int x = (rand() % 50) + 1;
      cout << x << endl;
   }
   return 0;
}

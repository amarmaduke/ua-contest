#include <iostream>

int main()
{
   using namespace std;

   cout << "14" << endl;

   cout << "0" << endl;
   cout << "100" << endl;
   cout << "59" << endl;
   cout << "9959" << endl;

   for (int i = 0; i < 10; ++i)
   {
      int hours = rand() % 99;
      int minutes = rand() % 59;
      cout << (100*hours + minutes) << endl;
   }
}

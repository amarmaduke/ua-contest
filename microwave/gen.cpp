#include <iostream>

int main()
{
   using namespace std;

   cout << "15" << endl;

   cout << "10" << endl;
   cout << "100" << endl;
   cout << "0" << endl; 
   cout << "59" << endl;
   cout << "9999" << endl;

   for (int i = 0; i < 10; ++i)
   {
      int hours = rand() % 99;
      int minutes = rand() % 99;
      cout << (100*hours + minutes) << endl;
   }
}

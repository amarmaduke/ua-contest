#include <iostream>

int main()
{
   using namespace std;

   cout << "15" << endl;

   cout << "0010" << endl;
   cout << "0100" << endl;
   cout << "0000" << endl; 
   cout << "0059" << endl;
   cout << "9999" << endl;

   for (int i = 0; i < 10; ++i)
   {
      int hours = rand() % 99;
      int minutes = rand() % 99;
      cout << (100*hours + minutes) << endl;
   }
}

#include <iostream>

using namespace std;

string hello = "Hello World!";

int main()
{
   int n;
   int len = hello.size();

   do
   {
      cin >> n;
      if (n == 0)
         break;

      for (int i = 0; i < len; ++i)
         cout << hello[(i + n) % len];
      cout << endl;

   } while (n != 0);
   return 0;
}

#include <iostream>

using namespace std;

int main()
{
#ifndef SINGLE_FILE
   int n;
   cin >> n;

   for (int i = 0; i < n; ++i)
   {
#endif
      int x, y, result;
      char op;
      cin >> x >> op >> y;
      switch (op)
      {
         case '+':
            result = x + y;
            break;
         case '-':
            result = x - y;
            break;
         case '*':
            result = x * y;
            break;
         case '/':
            result = x / y;
            break;
      }
      cout << result << endl;
#ifndef SINGLE_FILE
   }
#endif
   return 0;
}

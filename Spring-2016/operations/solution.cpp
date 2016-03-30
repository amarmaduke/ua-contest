#include <iostream>

using namespace std;

int main()
{
   int n;
   cin >> n;

   for (int i = 0; i < n; ++i)
   {
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
   }
   return 0;
}

#include <iostream>
#include <vector>

using namespace std;

char matrix[101][101];

void rotate(int layer, int amount, int n)
{
   vector<char> list;

   for (int i = layer; i < n - layer; ++i)
      list.push_back(matrix[layer][i]);
   for (int i = layer + 1; i < n - layer; ++i)
      list.push_back(matrix[i][n - layer - 1]);
   for (int i = n - layer - 2; i >= layer; --i)
      list.push_back(matrix[n - layer - 1][i]);
   for (int i = n - layer - 2; i > layer; --i)
      list.push_back(matrix[i][layer]);

   int k = 0;
   int N = list.size();
   for (int i = layer; i < n - layer; ++i)
      matrix[layer][i] = list[(amount + k++ + N) % N];
   for (int i = layer + 1; i < n - layer; ++i)
      matrix[i][n - layer - 1] = list[(amount + k++ + N) % N];
   for (int i = n - layer - 2; i >= layer; --i)
      matrix[n - layer - 1][i] = list[(amount + k++ + N) % N];
   for (int i = n - layer - 2; i > layer; --i)
      matrix[i][layer] = list[(amount + k++ + N) % N];
}

int main()
{
   int n;
   do
   {
      cin >> n;
      if (n == 0) break;

      for (int i = 0; i < n; ++i)
      {
         for (int j = 0; j < n; ++j)
         {
            char x;
            cin >> x;
            matrix[i][j] = x;
         }
      }

      int layers = n / 2;
      if (n % 2 != 0) ++layers;

      for (int i = 0; i < layers; ++i)
      {
         int x;
         cin >> x;
         rotate(i, x, n);
      }

      for (int i = 0; i < n; ++i)
      {
         for (int j = 0; j < n; ++j)
         {
            cout << matrix[i][j];
         }
         cout << endl;
      }

   } while (n != 0);
}

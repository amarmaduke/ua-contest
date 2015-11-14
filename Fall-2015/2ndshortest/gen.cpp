#include <iostream>
#include <sstream>
#include <map>

using namespace std;

int main()
{
   int kases = 5;
   for (int k = 0; k < kases; ++k)
   {
      int v = 20 + rand() % 80, e = rand() % ((v*(v-1))/2);
      map<int, map<int, int> > edges;
      int t = 2 + rand() % (v - 1);

      cout << v << " " << e << endl;
      cout << t << endl;

      int ec = 0, vc = v;;
      while (ec < e)
      {
         for (int i = vc; i > 1 and ec < e; --i)
         {
            int x = 1 + rand() % (i - 1);
            if (edges[x][vc] == 1) continue;
            edges[x][vc] = 1;

            int d = 1 + rand() % 99;
            ++ec;

            cout << x << " " << vc << " " << d << endl;
         }
         vc = (vc - 1 + v) % v;
      }
   }
}

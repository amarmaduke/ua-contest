#include <iostream>
#include <vector>
#include <utility>
#include <cmath>

using namespace std;

vector<int> offsets(vector<string> &v)
{
   vector<int> result;
   int pos = 0;
   for (int i = 0; i < v.size(); ++i)
   {
      result.push_back(pos);
      pos += (v[i].size() + 1);
   }
   return result;
}

pair<int, int> bounds(vector<string> &v, int idx)
{
   int pos = 0, i = 0;
   while (pos <= idx)
   {
      pos += (v[i].size() + 1);
      ++i;
   }
   return make_pair(i - 1, i);
}

int main()
{
#ifndef SINGLE_FILE
   int n;
   cin >> n;
   for (int i = 0; i < n; ++i)
   {
#endif
      int w, t;
      cin >> w >> t;
      vector<string> words;
      for(int j = 0; j < w; ++j)
      {
         string x;
         cin >> x;
         words.push_back(x);
      }
      int l, r;
      pair<int, int> temp;
      temp = bounds(words, t);
      l = temp.first; r = temp.second;
      vector<int> off = offsets(words);
      int lidx = abs(off[l] - t);
      int ridx = abs(off[r] - t);
      if (l + lidx < r + ridx)
      {
         cout << (l + lidx) << " " << words[l][lidx] << endl;
      } else
      {
         cout << (r + ridx) << " " << words[r][ridx] << endl;
      }
#ifndef SINGLE_FILE
   }
#endif
   return 0;
}

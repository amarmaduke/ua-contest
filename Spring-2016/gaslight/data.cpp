#include <fstream>
#include <sstream>
#include <iostream>

using namespace std;

int main()
{
   fstream input("input", fstream::in);
   fstream output("output", fstream::in);
   int k;
   input >> k;
   string junk;
   getline(input, junk);
   for (int i = 1 ; i <= k; ++i)
   {
      int n, e, m;
      input >> n >> e >> m;
      getline(input, junk);

      stringstream ss_in;
      stringstream ss_out;
      ss_in << "data/test" << i << ".in";
      ss_out << "data/test" << i << ".ans";
      fstream in_target(ss_in.str(), fstream::out);
      fstream out_target(ss_out.str(), fstream::out);

      in_target << n << " " << e << " " << m << '\n';
      for (int j = 0; j < e; ++j)
      {
         string line;
         getline(input, line);
         in_target << line << '\n';

      }
      string out_line;
      getline(output, out_line);
      out_target << out_line << '\n';
      in_target.close(); out_target.close();
   }
   input.close(); output.close();
}

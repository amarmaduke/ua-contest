#include <fstream>
#include <sstream>
#include <iostream>

using namespace std;

int main()
{
   fstream input("input", fstream::in);
   fstream output("output", fstream::in);
   int n;
   input >> n;
   string junk;
   getline(input, junk);
   for (int i = 1 ; i <= n; ++i)
   {
      string in_line;
      string out_line;
      getline(input, in_line);
      getline(output, out_line);
      stringstream ss_in;
      stringstream ss_out;
      ss_in << "data/test" << i << ".in";
      ss_out << "data/test" << i << ".ans";
      fstream in_target(ss_in.str(), fstream::out);
      fstream out_target(ss_out.str(), fstream::out);
      in_target << in_line << '\n';
      out_target << out_line << '\n';
      in_target.close(); out_target.close();
   }
   input.close(); output.close();
}

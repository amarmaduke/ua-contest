#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
	fstream input("input", fstream::in);
	fstream output("output", fstream::in); 

	int n;
	input >> n;

	for (int i = 1; i <= n; ++i)
	{
		fstream outIn("data/test" + to_string(i) + ".in", fstream::out);
		fstream outOut("data/test" + to_string(i) + ".ans", fstream::out);

		int in1, out1, out2, out3;
		input >> in1;
		output >> out1 >> out2 >> out3;

		outIn << in1 << endl;
		outOut << out1 << ' ' << out2 << ' ' << out3 << endl;
	
		outIn.close();
		outOut.close();
	}

	input.close();
	output.close();
}
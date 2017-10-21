#include <iostream>
#include <string>
using namespace std;

int main()
{
	string s;
	
	cin >> s;
	
	int middle = s.length() / 2;
	for (int i = 0; i < s.length(); ++i)
	{
	    if (i == 0)
	    {
	        cout << s[middle];
	    }
	    else if (i % 2 == 0)
	    {
	        cout << s[middle + (i / 2)];
	    }
	    else 
	    {
	        cout << s[middle - ((i + 1) / 2)];
	    }
	}
	
	cout << endl;
}

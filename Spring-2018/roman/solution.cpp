#include <iostream>
#include <map>

using namespace std;

int main()
{
  map<char,int> rVal;

  rVal['I']=1;
  rVal['V']=5;
  rVal['X']=10;
  rVal['L']=50;
  rVal['C']=100;
  rVal['D']=500;
  rVal['M']=1000;

  string in;
  cin >> in;
  int answer = 0;
  for(int i = 0; i < in.length() - 1; ++i){
    int value = rVal[in[i]];
    int next = rVal[in[i+1]];
    if (next > value)
      answer -= value;
    else
      answer += value;
  }
  answer += rVal[in[in.length()-1]];
  cout << answer << endl;
  return 0;
}

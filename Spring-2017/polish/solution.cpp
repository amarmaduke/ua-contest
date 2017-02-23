#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector<char> program;
stack<int> nums;

int main()
{
    int n;
    cin >> n;

    for (int i = 0; i < n; ++i)
    {
        char x;
        cin >> x;
        program.push_back(x);
    }

    for (int i = n - 1; i >= 0; i--)
    {
        char c = program[i];
        if (c >= '0' && c <= '9')
        {
            int x = c - '0';
            nums.push(x);
        }
        else
        {
            int a = nums.top(); nums.pop();
            int b = nums.top(); nums.pop();
            switch (c)
            {
                case '+':
                    nums.push(a + b);
                    break;
                case '-':
                    nums.push(a - b);
                    break;
                case 'x':
                    nums.push(a * b);
                    break;
                case '/':
                    nums.push(a / b);
                    break;
            }
        }
    }

    int result = nums.top();
    cout << result << endl;
}
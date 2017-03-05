#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

set<int> sneks;
int input, n, size_increase, indexes[300002];
long long current_size = 0;

int main()
{
    cin >> n >> size_increase;

    for (int i = 0; i < n; ++i) {
        cin >> input;
        sneks.insert(input);
        indexes[input] = i + 1;
    }

    string result = "";
    auto snek_to_eat = sneks.upper_bound(current_size);
    
    while (snek_to_eat != sneks.end()) {
        result += (result != "" ? " " : "") + to_string(indexes[*snek_to_eat]);
        sneks.erase(snek_to_eat);
        current_size += size_increase;
        snek_to_eat = sneks.upper_bound(current_size);
    }

    cout << result << "\n";
}
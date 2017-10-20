#include <iostream>
#include <cmath>

using namespace std;

int cal[3002], enj[3002], calorie_limit, num_snacks, snacksack[3002][3002];

int main() {
    cin >> num_snacks >> calorie_limit;
    for (int i = 0; i < num_snacks; ++i) {
        cin >> cal[i] >> enj[i];
    }

    for (int i = 1; i <= num_snacks; ++i) {
        for (int j = 1; j <= calorie_limit; ++j) {
            snacksack[i][j] = cal[i-1] > j ? snacksack[i-1][j] : max(snacksack[i-1][j], enj[i-1] + snacksack[i-1][j-cal[i-1]]);
        }
    }
    cout << snacksack[num_snacks][calorie_limit] << "\n";
}
#include <iostream>
#include <cmath>

using namespace std;


int main() {
    int child_limit, num_nodes, current_level = 0, nodes_at_current_level = 1, current_nodes = 1;
    cin >> child_limit >> num_nodes;

    if (child_limit == 1) {
        cout << (num_nodes - 1) << "\n";
    }
    else {
        while (current_nodes < num_nodes) {
            nodes_at_current_level *= child_limit;
            current_nodes += nodes_at_current_level;
            ++current_level;
        }
        cout << current_level << "\n";
    }
}
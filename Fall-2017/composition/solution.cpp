#include <iostream>
#include <map>

using namespace std;

int main() {
    int n, q;
    cin >> n >> q;

    map<char, pair<int, int> > functions;
    for (int i = 0; i < n; ++i) {
        char f;
        int a, b;
        cin >> f >> a >> b;
        functions[f] = make_pair(a, b);
    }

    for (int i = 0; i < q; ++i) {
        int m;
        cin >> m;
        int in_, out_;
        bool checks = true;
        for (int j = 0; j < m; ++j) {
            char x;
            pair<int, int> parity;
            cin >> x;
            if (checks && j == 0) {
                parity = functions[x];
                in_ = parity.first;
                out_ = parity.second;
            } else if (checks) {
                if (x == ';') {
                    char y;
                    cin >> y;
                    parity = functions[y];
                    in_ += parity.first;
                    out_ += parity.second;
                    j += 1;
                } else {
                    parity = functions[x];
                    //cout << x << "  " << in_ << " " << out_ << " " << parity.first << " " << parity.second << endl;
                    if (parity.first == out_) {
                        out_ = parity.second;
                    } else {
                        checks = false;
                    }
                }
            }
        }

        if (checks) {
            cout << in_ << " " << out_ << endl;
        } else {
            cout << "-1" << endl;
        }
    }
}
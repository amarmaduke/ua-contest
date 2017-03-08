#include <iostream>
#include <vector>

using namespace std;

int dp[1001][1001];

void print_vec(vector<int> &vec)
{
    for (int i = 0; i < vec.size(); ++i)
    {
        cout << vec[i] << " ";
    }
    cout << endl;
}

void print_dp(int n, int m)
{
    for (int i = 0; i <= n; ++i)
    {
        for (int j = 0; j <= m; ++j)
        {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
}

void build(vector<int> &fst_seq, vector<int> &snd_seq, vector<int> &seq, int i, int j)
{
    if (i == 0 || j == 0) return;
    else if (fst_seq[i-1] == snd_seq[j-1])
    {
        build(fst_seq, snd_seq, seq, i-1, j-1);
        seq.push_back(fst_seq[i-1]);
    }
    else
    {
        if (dp[i][j-1] > dp[i-1][j])
        {
            build(fst_seq, snd_seq, seq, i, j-1);
        }
        else
        {
            build(fst_seq, snd_seq, seq, i-1, j);
        }
    }
}

int main()
{
    vector<int> fst_formula;
    vector<int> snd_formula;
    vector<int> fst_seq;
    vector<int> snd_seq;
    int terms_n, terms_m, n, m;
    cin >> terms_n >> n;

    for (int i = 0; i < terms_n; ++i)
    {
        int x;
        cin >> x;
        fst_formula.push_back(x);
    }

    for (int i = 0; i < terms_n; ++i)
    {
        int x;
        cin >> x;
        fst_seq.push_back(x);
    }

    cin >> terms_m >> m;

    for (int i = 0; i < terms_m; ++i)
    {
        int x;
        cin >> x;
        snd_formula.push_back(x);
    }

    for (int i = 0; i < terms_m; ++i)
    {
        int x;
        cin >> x;
        snd_seq.push_back(x);
    }

    for (int i = terms_n; i < n; ++i)
    {
        int x = 0;
        for (int j = i - terms_n, k = 0; k < terms_n; ++j, ++k)
        {
            x += fst_formula[k]*fst_seq[j];
        }
        fst_seq.push_back(x);
    }

    for (int i = terms_m; i < m; ++i)
    {
        int x = 0;
        for (int j = i - terms_m, k = 0; k < terms_m; ++j, ++k)
        {
            x += snd_formula[k]*snd_seq[j];
        }
        snd_seq.push_back(x);
    }

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            if (fst_seq[i-1] == snd_seq[j-1])
            {
                dp[i][j] = dp[i-1][j-1] + 1;
            }
            else
            {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }

    vector<int> seq;
    build(fst_seq, snd_seq, seq, n, m);

    vector<int> prefix;
    prefix.push_back(0);
    int acc = 0;
    for (int i = 0; i < seq.size(); ++i)
    {
        acc += seq[i];
        prefix.push_back(acc);
    }

    int q;
    cin >> q;

    for (int i = 0; i < q; ++i)
    {
        int l, r;
        cin >> l >> r;
        r = max(min((size_t)r, prefix.size() - 1), (size_t)0);
        l = max(min((size_t)l, prefix.size() - 1), (size_t)0);
        cout << (prefix[r] - prefix[max(l - 1, 0)]) << endl;
    }
}
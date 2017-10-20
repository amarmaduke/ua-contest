#include <iostream>
#include <map>

using namespace std;

typedef long long i64;

i64 Modulus = 7001;

struct Matrix {
    i64 ul;
    i64 ur;
    i64 bl;
    i64 br;
};

void print_matrix(Matrix m) {
    cout << m.ul << " " << m.ur << endl;
    cout << m.bl << " " << m.br << endl;
}

Matrix multiply(Matrix a, Matrix b) {
    i64 ul = (a.ul*b.ul % Modulus + a.ur*b.bl % Modulus) % Modulus;
    i64 ur = (a.ul*b.ur % Modulus + a.ur*b.br % Modulus) % Modulus;
    i64 bl = (a.bl*b.ul % Modulus + a.br*b.bl % Modulus) % Modulus;
    i64 br = (a.bl*b.ur % Modulus + a.br*b.br % Modulus) % Modulus;
    Matrix m;
    m.ul = ul;
    m.ur = ur;
    m.bl = bl;
    m.br = br;
    return m;
}

pair<i64, i64> multiply_by_vector(Matrix m, i64 a, i64 b) {
    i64 fst = (m.ul*a % Modulus + m.ur*b % Modulus) % Modulus;
    i64 snd = (m.bl*a % Modulus + m.br*b % Modulus) % Modulus;
    return make_pair(fst, snd);
}

Matrix identity() {
    Matrix m;
    m.ul = 1;
    m.ur = 0;
    m.bl = 0;
    m.br = 1;
    return m;
}

Matrix pow(Matrix m, i64 n, map<i64, Matrix> &memo) {
    if (n == 0) {
        return identity();
    } else if (n == 1) {
        return m;
    }
    if (memo.count(n) > 0) {
        return memo[n];
    }

    Matrix result;
    if (n % 2 == 0) {
        result = multiply(pow(m, n/2, memo), pow(m, n/2, memo));
    } else {
        result = multiply(m, multiply(pow(m, n/2, memo), pow(m, n/2, memo)));
    }

    memo[n] = result;
    return result;
}

int main() {
    i64 q;
    cin >> q;
    for (i64 j = 0; j < q; ++j) {
        i64 n, c1, c2, a, b;
        cin >> n >> c1 >> c2 >> a >> b;
        
        Matrix m;
        m.ul = c1;
        m.ur = c2;
        m.br = 0;
        m.bl = 1;

        map<i64, Matrix> memo;
        Matrix result_matrix = pow(m, n-2, memo);
        pair<i64, i64> result = multiply_by_vector(result_matrix, a, b);
        cout << result.first << endl;
    }
}

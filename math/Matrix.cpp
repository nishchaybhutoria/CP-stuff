const long long MOD = 1e9 + 7;

struct Matrix {
    vector <vector <int>> mat;
    int rows, cols;
     
    Matrix() {}
     
    Matrix(vector <vector <int>> vals) : mat(vals), rows((int)vals.size()), cols((int)vals.front().size()) {}
     
    static Matrix identity(int n) {
        vector <vector <int>> vals(n, vector <int> (n));
        for (int i = 0; i < n; ++i) {
            vals[i][i] = 1;
        }
        return vals;
    }
     
    Matrix operator * (const Matrix& other) const {
        int n = rows, m = other.cols;
        vector <vector <int>> res(rows, vector <int> (cols));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                long long temp = 0;
                for (int k = 0; k < cols; ++k) {
                    temp += (mat[i][k] * 1LL * other.mat[k][j]);
                    // if (temp >= MOD) temp %= MOD;
                }
                res[i][j] = temp;
            }
        }
        return move(Matrix(move(res)));
    }
};

Matrix power(Matrix a, ll p) {
    Matrix res = Matrix::identity(a.cols);
    while (p) {
        if (p & 1) res = res * a;
        a = a * a;
        p >>= 1;
    }
    return res;
}

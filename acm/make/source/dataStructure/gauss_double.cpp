#define maxn 110
using namespace std;
double const eps = 1e-8;
int n, m;
double mat[maxn][maxn];
inline int sgn(double x) { return x < -eps ? -1 : x < eps ? 0 : 1; }
double x[maxn];

void gauss() {
    int r, c, mr;
    double mx, t;
    for (r = c = 0; r < n && c < m; ++r, ++c) {
        mr = -1, mx = eps;
        for (int i = r; i < n; ++i) {
            if (fabs(mat[i][c]) > mx) {
                mx = fabs(mat[i][c]);
                mr = i;
            }
        }
        if (!~mr) {
            --r;
            continue;
        }
        else {
            for (int i = c; i <= m; ++i) {
                swap(mat[r][i], mat[mr][i]);
            }
        }
        for (int i = r + 1; i < n; ++i) {
            if (sgn(mat[i][c]) == 0) continue;
            t = mat[i][c] / mat[r][c];
            for (int j = c; j <= m; ++j) {
                mat[i][j] -= mat[r][j] * t;
            }
        }
    }

    for (int i = r - 1; i >= 0; --i) {
        t = mat[i][m];
        for (int j = i + 1; j < m; ++j) {
            t -= x[j] * mat[i][j];
        }
        x[i] = t / mat[i][i];
    }
}

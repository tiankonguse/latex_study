#define maxn 22
using namespace std;
int mat[maxn][maxn];
int n, m;

bool fre[maxn]; int fs[maxn], fnt;
int x[maxn];
int cal(int r) {
    for (int i = r - 1, j = m - 1; i >= 0 && j >= 0; --i) {
        while (j >= 0 && fre[j]) --j;
        if (j >= 0) {
            x[j] = mat[i][m];
            for (int k = j + 1; k < m; ++k) {
                x[j] ^= (mat[i][k] && x[k]);
            }
            --j;
        }
    }
    int ret = 0;
    for (int i = 0; i < m; ++i) ret += x[i];
    return ret;
}
int solve(int r) {
    int mx = 1 << fnt;
    int ret = inf;
    for (int i = 0; i < mx; ++i) {
        if (__builtin_popcount(i) >= ret) continue;
        for (int j = 0; j < fnt; ++j) {
            if (i & (1 << j)) x[fs[j]] = 1;
            else x[fs[j]] = 0;
        }
        ret = min(ret, cal(r));
    }
    return ret;
}
int gauss() {
    memset(fre, false, sizeof fre); fnt = 0;
    int r, c, mr, mx;
    for (r = c = 0; r < n && c < m; ++r, ++c) {
        mx = 0, mr = -1;
        for (int i = r; i < n; ++i) {
            if (abs(mat[i][c]) > mx) {
                mx = abs(mat[i][c]);
                mr = i;
            }
        }
        if (!~mr) {
            fre[c] = true;
            fs[fnt++] = c;
            --r;
            continue;
        }
        else if (mr != r) {
            for (int j = c; j <= m; ++j) {
                swap(mat[r][j], mat[mr][j]);
            }
        }
        for (int i = r + 1; i < n; ++i) {
            if (!mat[i][c]) continue;
            for (int j = c; j <= m; ++j) {
                mat[i][j] ^= mat[r][j];
            }
        }
    }
    return solve(r);
}

ll x[maxn];
void gauss() {
    int r, c, mr;
    ll mx;
    ll g, ta, tb;
    for (r = c = 0; r < n && c < m; ++r, ++c) {
        mr = -1, mx = 0;
        for (int i = r; i < n; ++i) {
            if ( _abs(mat[i][c]) > mx ) {
                mx = _abs(mat[i][c]);
                mr = i;
            }
        }
        if (!~mr) {
            --r;
            continue;
        }
        else if (mr != r) {
            for (int i = c; i <= m; ++i) {
                swap(mat[mr][i], mat[r][i]);
            }
        }
        for (int i = r + 1; i < n; ++i) {
            if (!mat[i][c]) continue;
            g = gcd(mat[r][c], mat[i][c]);
            ta = mat[r][c] / g;
            tb = mat[i][c] / g;
            for (int j = c; j <= m; ++j) {
                mat[i][j] = mat[r][j] * tb - mat[i][j] * ta;
                mat[i][j] %= mod;
            }
        }
    }
    //must have a solution
    ll t;
    for (int i = m - 1; i >= 0; --i) {
        t = mat[i][m];
        for (int j = i + 1; j < m; ++j) {
            t -= mat[i][j] * x[j];
            t %= mod;
        }
        x[i] = MLES(mat[i][i], t, mod);
      /*  for (ll j = 0; j < mod; ++j) {
            if ((mat[i][i] * j - t) % mod == 0) {
                x[i] = j;
                break;
            }
        }*/
    }
}

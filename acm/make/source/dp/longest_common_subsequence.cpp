int LCS(const char *s1, const char *s2) {
    int m = strlen(s1), n = strlen(s2);
    int i, j;
    a[0][0] = 0;
    for( i=1; i <= m; ++i ) a[i][0] = 0;
    for( i=1; i <= n; ++i ) a[0][i] = 0;
    for( i=1; i <= m; ++i )
        for( j=1; j <= n; ++j ) {
            if(s1[i-1]==s2[j-1]) a[i][j] = a[i-1][j-1]+1;
            else if(a[i-1][j]>a[i][j-1])a[i][j]= a[i-1][j];
            else a[i][j] = a[i][j-1];
        }
    return a[m][n];
}

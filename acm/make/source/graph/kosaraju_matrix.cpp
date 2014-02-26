const int MAXV = 1024;
int g[MAXV][MAXV], dfn[MAXV], num[MAXV], n,
scc, cnt;
void dfs(int k) {
    num[k] = 1;
    for(int i=1; i<=n; i++)
        if(g[k][i] && !num[i])
            dfs(i);
    dfn[++cnt] = k;//`记录第cnt个出栈的顶点为k`
}
void ndfs(int k) {
    num[k] = scc;
    for(int i=1; i<=n; i++)
        if(g[i][k] && !num[i])
            ndfs(i);
}
void kosaraju() {
    int i, j;
    for(i=1; i<=n; i++)
        if(!num[i])
            dfs(i);
    memset(num, 0, sizeof num);
    for(i=n; i>=1; i--)
        if(!num[dfn[i]]) {
            scc++;
            ndfs(dfn[i]);
        }
    cout<<"Found: "<<scc<<endl;
}

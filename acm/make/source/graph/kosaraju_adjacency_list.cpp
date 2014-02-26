const int MAXN = 100;
vector<int> adj[ MAXN ] ; //`正向邻接表`
vector<int> radj[ MAXN ] ; //`反向邻接表`
vector<int> ord; //`后序访问顺序`
int vis[MAXN],cnt,n;
void dfs ( int v ) {
    vis[v]=1;
    for (int i = 0, u, _size = adj[v].size(); i< _size; i++ )
        if ( !vis[u=adj[v][i]] )
            dfs(u);
    ord.push_back(v);
}
void ndfs ( int v ) {
    vis[v]=cnt;
    for (int i = 0, u, _size = radj[v].size(); i < _size; i++ )
        if ( !vis[u=radj[v][i]] )
            ndfs(u);
}
void kosaraju () {
    int i;
    memset(vis,0,sizeof(vis));
    ord.clear();
    for ( i=0 ; i<n ; i++ )
        if ( !vis[i] )
            dfs(i);
    memset(vis,0,sizeof(vis));
    for ( cnt=0,i=ord.size()-1 ; i>=0 ; i-- )
        if ( !vis[ord[i]] ) {
            ndfs(ord[i]);
            cnt++;
        }
}

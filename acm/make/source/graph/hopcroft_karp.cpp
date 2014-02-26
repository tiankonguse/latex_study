`Hopcroft–Karp 算法是匈牙利算法的改进，时间复杂度 0(E*V\^{}1/2).`
`算法实质其实还是匈牙利算法求增广路，改进的地方是在深度搜索增广路前，先通过广度搜索，查找多条可以增广的路线，从而不再让 dfs“一意孤行”。其中算法用到了分层标记防止多条增广路重叠，这里是精髓`
typedef long long ll;
#define inf (int)1e10
#define maxn 50005
vector<int>vec[maxn];
int headU[maxn],headV[maxn];
int du[maxn],dv[maxn];
int uN,vN;
bool bfs() {
    queue<int>q;
    int dis=inf;
    memset(du,0,sizeof(du));
    memset(dv,0,sizeof(dv));
    for(int i=1; i<=uN; i++)
        if(headU[i]==-1)q.push(i);
    while(!q.empty()) {
        int u=q.front();
        q.pop();
        if(du[u]>dis)break;
        for(int i=0; i<vec[u].size(); i++)
            if(!dv[vec[u][i]]) {
                dv[vec[u][i]]=du[u]+1;
                if(headV[vec[u][i]]==-1)dis=dv[vec[u][i]];
                else {
                    du[headV[vec[u][i]]]=dv[vec[u][i]]+1;
                    q.push(headV[vec[u][i]]);
                }
            }
    }
    return dis!=inf;
}
bool dfs(int u) {
    for(int i=0; i<vec[u].size(); i++)
        if(dv[vec[u][i]]==du[u]+1) {
            dv[vec[u][i]]=0;
            if(headV[vec[u][i]]==-1||dfs(headV[vec[u][i]])) {
                headU[u]=vec[u][i];
                headV[vec[u][i]]=u;
                return 1;
            }
        }
    return 0;
}
int Hopcroft() {
    memset(headU,-1,sizeof(headU));
    memset(headV,-1,sizeof(headV));
    int ans=0;
    while(bfs())
        for(int i=1; i<=uN; i++)
            if(headU[i]==-1&&dfs(i))ans++;
    return ans;
}
int main() {
    int u,v,w;
    while(~scanf("%d%d%d",&u,&v,&w)) {
        for(int i=0; i<maxn; i++)vec[i].clear();
        uN=u;
        int tu,tv;
        while(w--) {
            scanf("%d%d",&tu,&tv);
            vec[tu].push_back(tv);
        }
        printf("%d\n",Hopcroft());
    }
    return 0;
}

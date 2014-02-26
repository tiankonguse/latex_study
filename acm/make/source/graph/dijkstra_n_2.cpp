const int N = 100;
const int INF = 0x3ffff;
int cost[N][N];//`两点之间的代价`
int path[N];//`当前节点的父亲`
int lowcost[N];//`当前节点到根的代价`
//`n 个节点，st 为源点`
void dijkstra(int n,int st) {
    int i, j, _min, pre;
    bool vis[N];
    memset(vis,0,sizeof(vis));
    vis[st] = 1;
    for(i=0; i<n; i++) {
        lowcost[i] = cost[st][i];
        path[i] = st;
    }
    lowcost[st] = 0;
    path[st] = -1;
    pre = st;
    for(i = 0; i < n; i++) {
        for(j=0; j<n; j++)
            if(vis[j]==0&&lowcost[pre]+cost[pre][j]<lowcost[j])
                lowcost[j]=lowcost[pre]+ lost[pre][j], path[j] = pre;
 
        _min = INF;
        for(j=0; j<n; j++)
            if(vis[j] == 0 && lowcost[j] < _min)
                _min = lowcost[j] , pre = j;
 
        vis[pre] = 1;
    }
    return ;
}

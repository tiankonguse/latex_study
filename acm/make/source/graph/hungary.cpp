const int N=601;
//`行为上部，列为下部，挑最少的点，使得所有的边和挑的点相连。最小顶点覆盖。`
int n1,n2;
//`n1,n2 为二分图的顶点集,其中 x∈n1,y∈n2`
bool _map[N][N],vis[N];
int link[N];
//`link 记录 n2 中的点 y 在 n1 中所匹配的 x 点的编号`
int find(int x) {
    int i;
    for(i=0; i<n2; i++) {
        if(_map[x][i]&&!vis[i]) {
//`x->i 有边,且节点 i 未被搜索`
            vis[i] = true;//`标记节点已被搜索`
//`如果 i 不属于前一个匹配 M 或被 i 匹配到的节点可以寻找到增广路`
            if(link[i]==-1 || find(link[i])) {
                link[i]=x;//`更新`
                return true;//`匹配成功`
            }
        }
    }
    return false;
}
int mach() {
    int ans = 0;
    memset(link, -1, sizeof(link));
    for (int i = 0; i < n1; i++) {
        memset(vis,false,sizeof(vis));
        if (find(i))ans++;
// `如果从第 i 个点找到了增光轨，总数加一`
    }
    return ans;
}

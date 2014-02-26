const int N=10000;
const int M=100;
int fir[N],toV[M],len[M],next[M],cnt;
void addedge(int u, int v, int w) {
    toV[cnt] = v;
    len[cnt] = w;
    next[cnt] = fir[u];
    fir[u] = cnt++;
}
void init(int nv, int ne) {
    memset(fir, -1, sizeof(fir));
    cnt=0;
    int u,v,w;
    for (int i = 0; i < ne; ++i) {
        scanf("%d%d%d", &u, &v, &w);
        addedge(u, v, w); //` 不加下面的为有向图`
        addedge(v u, w); //` 加下面额为无向图`
    }
}

`欧拉通路:图连通；除 2 个端点外其余节点入度=出度；1 个端点入度比出度大 1；一个端点入度比出度小 1`
`欧拉回路:图连通；所有节点入度=出度`
\end{lstlisting}

\subsection{网络流}
\begin{lstlisting}
const int N = 100;
const int E = 1000;
#define typec int // type of cost
const typec inf = 0x3f3f3f3f; // max of cost
struct edge {
    int x, y, nxt;
    typec c;
} bf[E];
int ne, head[N], cur[N], ps[N], dep[N];
void init() {
    ne = 2;
    memset(head,0,sizeof(head));
}
void addedge(int x, int y, typec c) {
//`无向图需调用两次 addedge`
// add an arc(x -> y, c); vertex: 0 ~ n-1;
    bf[ne].x = x;
    bf[ne].y = y;
    bf[ne].c = c;
    bf[ne].nxt = head[x];
    head[x] = ne++;
    bf[ne].x = y;
    bf[ne].y = x;
    bf[ne].c = 0;
    bf[ne].nxt = head[y];
    head[y] = ne++;
}
typec flow(int n, int s, int t) {
    typec tr, res = 0;
    int i, j, k, f, r, top;
    while (1) {
        memset(dep, -1, n * sizeof(int));
        for (f = dep[ps[0] = s] = 0, r = 1; f != r; )
            for (i = ps[f++], j = head[i]; j; j = bf[j].nxt) {
                if (bf[j].c && -1 == dep[k = bf[j].y]) {
                    dep[k] = dep[i] + 1;
                    ps[r++] = k;
                    if (k == t) {
                        f = r;
                        break;
                    }
                }
            }
        if (-1 == dep[t]) break;
        memcpy(cur, head, n * sizeof(int));
        for (i = s, top = 0; ; ) {
            if (i == t) {
                for (k = 0, tr = inf; k < top; ++k)
                    if (bf[ps[k]].c < tr)
                        tr = bf[ps[f = k]].c;
                for (k = 0; k < top; ++k)
                    bf[ps[k]].c -= tr, bf[ps[k]^1].c += tr;
                res += tr;
                i = bf[ps[top = f]].x;
            }
            for (j=cur[i]; cur[i]; j = cur[i] = bf[cur[i]].nxt)
                if (bf[j].c && dep[i]+1 == dep[bf[j].y]) break;
            if (cur[i]) {
                ps[top++] = cur[i];
                i = bf[cur[i]].y;
            } else {
                if (0 == top) break;
                dep[i] = -1;

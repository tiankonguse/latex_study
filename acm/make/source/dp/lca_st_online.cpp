`(思想是：将树看成一个无向图，u 和 v 的公共祖先一定在 u 与 v 之间的最短路径上)：\\
（1）DFS：从树 T 的根开始，进行深度优先遍历（将树 T 看成一个无向图），并记录下每次到达的顶点。\\
第一个的结点是 root(T)，每经过一条边都记录它的端点。由于每条边恰好经过 2 次，因此一共记录了2n-1 个结点，用 E[1, ... , 2n-1]来表示。\\
（2）计算 R：用 R[i]表示 E 数组中第一个值为 i 的元素下标，即如果 R[u] < R[v]时，DFS 访问的顺序是E[R[u], R[u]+1, …, R[v]]。\\
虽然其中包含 u 的后代，但深度最小的还是 u 与 v 的公共祖先。\\
（3）RMQ：当 R[u] ≥ R[v]时，LCA[T, u, v] = RMQ(L, R[v], R[u])；否则 LCA[T, u, v] = RMQ(L, R[u], R[v])，计算 RMQ。\\
由于 RMQ 中使用的 ST 算法是在线算法，所以这个算法也是在线算法。`

//`代码实现`

const int N = 10001; // 1<<20;
int pnt[N], next[N], head[N]; //` 邻接表`
int e; //` 边数`
bool visited[N]; // `初始为 0，从根遍历`
int id;
int dep[2*N+1], E[2*N+1], R[N]; //` dep:dfs 遍历节点深度, E:dfs 序列, R:第一次被遍历的下标`
void DFS(int u, int d);
int d[20], st[2*N+1][20];
int n;
void InitRMQ(const int &id) {
    int i, j;
    for( d[0]=1, i=1; i < 20; ++i ) d[i] = 2*d[i-1];
    for( i=0; i < id; ++i ) st[i][0] = i;
    int k = int( log(double(n))/log(2.0) ) + 1;
    for( j=1; j < k; ++j )
        for( i=0; i < id; ++i ) {
            if( i+d[j-1]-1 < id ) {
                st[i][j] = dep[ st[i][j-1] ] > dep[ st[i+d[j-1]][j-1]] ? st[i+d[j-1]][j-1] : st[i][j-1];
            } else break; // st[i][j] = st[i][j-1];
        }
}

int Query(int x, int y) {
    int k; //` x, y 均为下标:0...n-1`
    k = int( log(double(y-x+1))/log(2.0) );

    return dep[ st[x][k] ] > dep[ st[y-d[k]+1][k] ] ? st[y-d[k]+1][k] : st[x][k];
}
void Answer(void) {
    int i, Q;
    scanf("%d", &Q);
    for( i=0; i < Q; ++i ) {
        int x, y;
        scanf("%d%d", &x, &y); //` 查询 x,y 的 LCA`
        x = R[x];
        y = R[y];
        if( x > y ) {
            int tmp = x;
            x = y;
            y = tmp;
        }
        printf("%d\n", E[ Query(x, y) ]);
    }
}
void DFS(int u, int d) {
    visited[u] = 1;
    R[u] = id;
    E[id] = u;
    dep[id++] = d;
    for( int i=head[u]; i != -1; i=next[i] )
        if( visited[ pnt[i] ] == 0 ) {
            DFS(pnt[i], d+1);
            E[id] = u;
            dep[id++] = d;
        }
}

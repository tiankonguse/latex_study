//`左偏树(Leftist Tree)是一种可并堆的实现。`
const int MAXN = 100010;
struct Node {
    int key, dist, lc, rc;
    void init(int _dist = 0, int _key = 0) {
        key = _key;
        dist = _dist;
        lc = rc = 0;
    }
} nodes[MAXN];
int memeryNode[MAXN];
int allocNode,allocMemery;
void initNode() {
    nodes[0].init(-1);//0 作为 NULL 节点
    allocNode = 1;
    allocMemery = 0;
}
int newNode(int x) {
    int tmp;
    if(allocMemery) {
        tmp = memeryNode[--allocMemery];
    } else {
        tmp = allocNode++;
    }
    nodes[tmp].init(0, x);
    return tmp;
}
void deleteNode(int A) {
    memeryNode[allocMemery++] = A;
}
int merge(int A, int B) {
    if (A != 0 && B != 0) {
        if (nodes[A].key < nodes[B].key) {
            swap(A, B);
        }
        nodes[A].rc = merge(nodes[A].rc, B);
        int &lc = nodes[A].lc;
        int &rc = nodes[A].rc;
        if (nodes[lc].dist < nodes[rc].dist) {
            swap(lc, rc);
        }
        nodes[A].dist = nodes[rc].dist + 1;
    } else {
        A = A == 0 ? B : A;
    }
    return A;
}
int pop(int A) {
    int t = merge(nodes[A].lc, nodes[A].rc);
    deleteNode(A);
    return t;
}
void insert(int v) {
    merge(0, newNode(v));
}

\subsection{DLX}
\begin{lstlisting}
`双向十字链表用 LRUD 来记录，LR 来记录左右方向的双向链表，UD 来记录上下方向的双向链表。\\
head 指向总的头指针，head 通过 LR 来贯穿的列指针头。\\
LRUD 的前 m 个一般作为其列指针头的地址。\\
rowHead[x]是指向其列指针头的地址。\\
colNum[x]录列链表中结点的总数。\\
selectRow[x]用来记录搜索结果。\\
col[x]代表 x 的列数\\
row[x]代表 x 的行数`

//`一般需要使用 A*或 IDA*优化。`
//`以 exact cover problem 的代码为例子`
const int N = 1005;
const int M = 1005;
const int maxn = N*M;
int R[maxn], L[maxn], U[maxn], D[maxn];
int col[maxn], row[maxn];
int rowHead[M], selectRow[N],colNum[N];
int size,n,m;
bool flag;
//`初始化`
void init() {
    memset(rowHead,-1,sizeof(rowHead));
    for(int i=0; i<=m; i++) {
        colNum[i]=0;
        D[i]=U[i]=i;
        L[i+1]=i;
        R[i]=i+1;
        row[i] = 0;
        col[i] = i;
    }
    R[m]=0;
    size=m+1;
}
//`插入一个点`
void insert(int r,int c) {
    colNum[c]++;
    U[size]=U[c];
    D[size]=c;
    D[U[size]]=size;
    U[D[size]]=size;
    if(rowHead[r]==-1) {
        rowHead[r]=L[size]=R[size]=size;
    } else {
        L[size]=L[rowHead[r]];
        R[size]=rowHead[r];
        R[L[size]]=size;
        L[R[size]]=size;
    }
    row[size] = r;
    col[size] = c;
    size++;
}

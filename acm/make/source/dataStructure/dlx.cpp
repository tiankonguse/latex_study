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
//`删除一列`
void remove(int const& c) { //`删除列`
    int i,j;
    L[R[c]]=L[c];
    R[L[c]]=R[c];
    for(i=D[c]; i!=c; i=D[i]) {
        for(j=R[i]; j!=i; j=R[j]) {
            U[D[j]]=U[j],D[U[j]]=D[j];
            colNum[col[j]]--;
        }
    }
}
//`恢复一列`
void resume(int c) {
    int i,j;
    for(i=U[c]; i!=c; i=U[i]) {
        for(j=L[i]; j!=i; j=L[j]) {
            U[D[j]]=j;
            D[U[j]]=j;
            colNum[col[j]]++;
        }
    }
    L[R[c]]=c;
    R[L[c]]=c;
}
//`搜索`
void dfs(int k) {
    int i,j,Min,c;
    if(R[0] == 0) {
        flag = true;//`标记有解`
        printf("%d",k);//`输出有 k 行`
        for(i=0; i<k; i++) {
            printf(" %d",selectRow[i]);
        }
        printf("\n");
        return;
    }
//select a col that has min 1
    for(Min=N,i=R[0]; i; i=R[i]) {
        if(colNum[i]<Min) {
            Min=colNum[i],c=i;
        }
    }
    remove(c);//`删除该列`
//select a row in the delete col
    for(i=D[c]; i!=c; i=D[i]) {
        selectRow[k] = row[i];
        for(j=R[i]; j!=i; j=R[j]) {
            remove(col[j]);
        }
        dfs(k+1);
        if(flag) return;//`只要一组解`
        for(j=L[i]; j!=i; j=L[j]) {
            resume(col[j]);
        }
    }
    resume(c);
}
int main() {
    int i,j,num;
    while(scanf("%d%d",&n,&m)!=EOF) {
        init();
        for(i=1; i<=n; i++) {
            scanf("%d",&num);
            while(num--) {
                scanf("%d",&j);
                insert(i,j);//`向第 i 行第 j 列插入 1`
            }
        }
        flag = false;
        dfs(0);
        if(!flag) {
            printf("NO\n");
        }
    }
    return 0;
}
 

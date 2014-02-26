const int N=10001;
int k,a[101]; //`k 为节点数,a 数组为减数集合`
int f[N]; //`f 数组用来存储所有节点的 sg 值,初值为-1`
int mex(int p) { //`mex 为求 sg 的函数`
    int i,t;
    bool g[101]= {0}; //`定义布尔数组，初值为 0`
    for(i=0; i<k; i++) {
        t=p-a[i]; //`t 为 p 当前遍历的后继`
        if(t<0) break; //`后继最小是 0`
        if(f[t]==-1)f[t]=mex(t);
        g[f[t]]=1; //`布尔数组中赋这个 SG 值为`
    }
    for(i=0;; i++) {
        if(!g[i]) return i;
    }
}

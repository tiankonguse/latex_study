`给 n 个数，求着 n 个数划分成互不相交的 m 段的最大m 子段和。`
`经典的动态规划优化问题。`
`设 f(i,j)表示前 i 个数划分成 j 段，且包括第 i 个数的最大 j 段和，那么 dp 方程为：`
`f(i,j)=max(f(i-1,j),max {f(k,j-1)})+v[i];``分析：第 i 个数要么和前一个数一起划分到第 j 段里，要么独自划分到第 j 段,也就是我们要找到 i 之前的数划分为 j-1 段的最优值，这个可以只需一个变量标记最大值岂可。`
`转移复杂度：O(1),总复杂度 O(n*m)`
int g[N];
int max_m_sum(int* str,int n,int m) {
    memset(g,0,sizeof(g));
    int i,j,_max,tmp;
    for(i=1; i<=m; i++) {
        _max = g[i-1];
        for(j=i; j<=n; j++) {
            tmp = _max;
            _max = max(_max,g[j]);
            g[j] = max(g[j-1],tmp) + str[j];
        }
    }
    _max = g[m];
    for(i=m; i<=n; i++) {
        _max = max(_max,g[i]);
    }
    return _max;
}

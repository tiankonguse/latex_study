\subsection{容斥原理}
\begin{lstlisting}
`容斥可以用 dfs 搜索实现`
`用一个例子来看怎么实现容斥`
`给定一个集合和一个数 n，求小于 n 的数中，满足可以被集合中的其中一个数整除的个数。`

TT arr[N]，ans;
TT gcd(TT a,TT b) {
    return (!b)?a:gcd(b,a%b);
}
void dfs(int i,int cnt,TT lcm) {
    lcm=lcm/gcd(lcm,arr[i])*arr[i];
    if(cnt&1)ans+=(n-1)/lcm;
    else ans-=(n-1)/lcm;
    for(int j=i+1; j<m; j++)
        dfs(j,cnt+1,lcm);
}
void rongchi() {
    for(int i=0; i<m; i++)

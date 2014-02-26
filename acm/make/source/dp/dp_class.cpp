`f(i,j) =min{f(i,k) + f(k,j) + g(i,k,j) },(i<=k<=j)\\
 一般，g(i,k,j)为一常数\\
 分析：从 f(0,0)到 f(n,n)需要双重循环，在每次循环时又要花费 O(n)的时间去找最小值，故总复杂度O(n\^{}3)\\
例如：矩阵连乘`



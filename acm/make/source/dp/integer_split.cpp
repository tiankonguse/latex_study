`1.整数拆分成不同整数的和的拆分数等于拆分成奇数的拆分数。\\
2.N 被拆分成一些重复次数不超过 k 次的整数的和，棋拆分数等于被拆分成不被 k+1 除尽的数的和的拆分数。\\
3.整数 n 拆分成 k 个数的和的拆分数等于 n 拆分成最大数为 k 的拆分数。\\
4.整数 n 拆分成最多不超过 m 个数的和的拆分数等于n 拆分成最大不超过 m 的拆分数。\\
5.正整数 n 拆分成不超过 k 个数的和的拆分数，等于将 n+k 拆分成恰好 k 个数的拆分数。`
//`两种方法`
//`fun1(n,m)定义为整数 m 拆分的数最小为 n`
int fun1(int n,int m) {
    if(str1[n][m]!=-1)return str1[n][m];
    if(n==m)return str1[n][m]=1;
    if(n>m)return str1[n][m]=0;
    return str1[n][m]=fun1(n,m-n)+fun1(n+1,m);
    return str1[n][m];
}

//` fun2(n,m)定义为整数 m 拆分的数最大为 n`
int fun2(int n,int m) {
    if(str2[n][m]!=-1)return str2[n][m];
    if(m==0)return str2[n][m]=1;
    if(n==0)return str2[n][m]=0;

    if(n>m)return str2[n][m]=fun2(m,m);
    return str2[n][m]=fun2(n,m-n)+fun2(n-1,m);
}


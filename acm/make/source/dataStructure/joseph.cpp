/*
`N 个人，从 1 开始报数，报到 m 的人退出
模拟方法就不说了，这里主要说数学方法
令 f 表示 i 个人玩游戏报 m 退出最后胜利者的编号，
最后的结果自然是 f[n].
 递推公式:
 f[1]=0;
 f[i]=(f[i-1]+m)\%i; (i$>$1)`
*/
int fun(int n,int m) {
    int ans=0;
    for(int i=2; i<=n; i++)ans=(ans+m)%i;
    return ans+1;
}

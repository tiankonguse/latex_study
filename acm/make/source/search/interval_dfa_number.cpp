`一个 10 进制 number 称为 balanced 的，如果存在一个digit 关于这个 digit 的力矩和为 0.`
`例如 4209 关于 0 的力矩和是 4*2+2*1-9*1=0.题目要求在区间[a,b]内的 balanced number 的个数。（ZJU 3416）`

typedef long long LL ;
LL dp[19][19][2000];
int digit[19],o;
LL dfs(int L,int sum,int yes) {
    if(L == -1) return sum==0;
    if(!yes && dp[L][o][sum]!=-1)
        return dp[L][o][sum];
    int mymax = yes?digit[L]:9;
    LL ans = 0;
    for(int i=0; i<=mymax; i++)
        ans+=dfs(L-1,sum+(L-o)*i,yes&(i==mymax));
    if(!yes)dp[L][o][sum]=ans;
    return ans;
}
LL call(LL x) {
    int pos=0;
    LL ans=0;
    while(x)digit[pos++]=x%10,x/=10;
    for(o=0; o<pos; o++)ans+=dfs(pos-1,0,1);
    return ans-pos+1;
}
int main() {
    printf("%lld\n",call(b)-call(a-1));
}

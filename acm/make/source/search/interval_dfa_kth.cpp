`区间（P,Q）之间第 K 大的 Nya 数（含 x 个 4，y 个7）`

typedef __int64 LL;
LL dp[21][21][21][2];
LL p,q,ans;
int x,y;
int dig[32],len;
LL cnt(int d,int n4,int n7,bool yes) {
    if(n4 > x || n7>y)return 0;
    if(d==-1)return n4==x && n7==y;
    LL &ret = dp[d][n4][n7][yes];
    if(ret!=-1)return ret;
    ret = 0;
    int t = yes?dig[d]:9;
    for(int i=0; i<=t; i++)
        ret+=cnt(d-1,n4+(i==4),n7+
                 (i==7),yes&&i==t);
    return ret;
}
LL count(LL a) {
    memset(dp,-1,sizeof(dp));
    len=0;
    if(a==0)dig[len++]=0;
    else {
        while(a)dig[len++]=a%10,a/=10;
    }
    return cnt(len-1,0,0,1);
}
void findK(int d,int n4,int n7,bool yes,LL k) {
    if(d<0)return ;
    int t=yes?dig[d]:9,i;
    for(i=0; i<=t; i++) {
        LL tmp=cnt(d-1,n4+(i==4),n7+
                   (i==7),yes&&i==t);
        if(tmp>=k) {
            ans = ans*10+i;
            findK(d-1,n4+(i==4),n7+
                  (i==7),yes&&i==t,k);
            return ;
        } else {
            k-=tmp;
        }
    }
}
int main() {
    int T ,cas=0;
    for(scanf("%d",&T); T--;) {
        scanf("%I64d%I64d%d%d",&p,&q,&x,&y);
        LL l = count(p),r=count(q);
        int n;
        scanf("%d",&n);
        printf("Case #%d:\n",++cas);
        while(n--) {
            int k;
            scanf("%d",&k);
            if(k>r-l)puts("Nya!");
            else {
                ans=0;
                findK(len,0,0,1,l+k);
                printf("%I64d\n",ans);
            }
        }
    }
    return 0;
}


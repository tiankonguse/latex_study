INT dp(int n,int m) {
    if(str1[n][m]!=-1)return str1[n][m];
    if(m==0)return str1[n][m]=1;
    if(n==0)return str1[n][m]=0;
    INT ans=0;
    int end=min(str0[n],m);
    for(int i=0; i<=end; i++) {
        ans+=dp(n-1,m-i)*fun(m,i);
    }
    return str1[n][m]=ans;
}

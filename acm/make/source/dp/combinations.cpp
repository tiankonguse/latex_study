const int N=100;
int str[N][N];//`初始化为-1`
int fun(int m,int n) {
    if(str[m][n]!=-1)return str[m][n];
    if(m==n || n==0)return str[m][n]=1;
    if(m<n)return str[m][n]=0;
    return str[m][n]=fun(m-1,n-1)+fun(m-1,n);
}

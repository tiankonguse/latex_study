bornState();
sz = _map_num;
Matrix matrix,ans;
int n,m;
matrix.init(str);//`矩阵需要添加这个函数`
while(scanf("%d%d",&n,&m),n) {
    MOD = m;
    ans = matrix.pow(n);
    printf("%d\n",ans.a[0][0]);
}

//`调用 count(n)`
int d[11];//`初始化为 0`
void count(int n,int value=1) {
    if(n<=0)return ;
    int one=n%10;
    int ten=n;
    for(int i=0; i<=one; i++)d[i]+=value;
    one++;
    while(ten/=10)d[ten%10]+=one*value;
    n/=10;
    for(int i=0; i<10; i++)d[i]+=value*n;
    d[0]-=value;
    count(n-1,value);
}

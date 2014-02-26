//` 得到一个因数.返回N时为一个没有找到 `
LL Pollard_rho(LL x,LL c){
    LL i=1,x0=rand()%x,y=x0,k=2;
    while (1){
        i++;
        x0=(muti_mod(x0,x0,x)+c)%x;
        LL d=gcd(y-x0,x);
        if (d!=1 && d!=x)return d;
        if (y==x0) return x;
        if (i==k)y=x0,k+=k;
    }
}

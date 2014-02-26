//`因子个数:d(n)=(a1+1)*(a2+1)...(an+1)`
int DFun(int n){
    int res=1;
    for(int i = 2,t; i * i <= n; i += 2){
        if(!(n%i)){
            t = 1;
            for(t=1;!(n%i);++t,n/=i);
            res *= t;
        }
        if(i==2){
            i--;
        }
    }
    if(n>1){
        res *= 2;
    }
    return res;
}

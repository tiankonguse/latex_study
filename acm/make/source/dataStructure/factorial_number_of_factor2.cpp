//`N!的素数因子分解中的素数p的幂为[n/p]+[n/$p^2$]+[n/$p^3$]+…`
int cnt(int n,int y){
    int cn=0;
    int tmp=y;
    while(n>=tmp){
        cn+=n/tmp;
        tmp*=y;
    }
    return cn;
}

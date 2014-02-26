`P保证是素数，com代表组合数模P`
`也可以用乘法逆元做，C(n,m)=n!/(m!*(n-m)!)`
LL Lucas(LL n, LL m,LL p){
    if(m ==0)  return 1;
    return  (Com(n%p, m%p,p)*Lucas(n/p, m/p))%p;
}

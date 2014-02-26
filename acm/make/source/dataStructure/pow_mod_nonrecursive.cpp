LL pow_mod(LL x,LL n,LL mod){     
if (n==1) return x%mod;
    int bit[64],k=0;
    while (n){
        bit[k++]=n&1;n>>=1;
    }
    LL ret=1;
    for (k=k-1;k>=0;k--){
        ret=muti_mod(ret,ret,mod);
        if (bit[k]==1) ret=muti_mod(ret,x,mod);
    }
    return ret;
}

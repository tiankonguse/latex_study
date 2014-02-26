LL pow_mod(LL a,LL b,LL c){
    LL ret = 1;
    for(a%=c;b;b>>=1,a=muti_mod(a,a,c)){
        if(b&1)ret = muti_mod(ret,a,c);
    }
    return ret;
}

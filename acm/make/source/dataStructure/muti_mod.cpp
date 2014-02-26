LL muti_mod(LL a,LL b,LL c) {
    LL ret=0;
    for(a%=c,b%=c; b; a =(a<<1)%c,b>>=1) {
        if (b&1) {
            ret = (ret + a)%c;
        }
    }
    return ret;
}

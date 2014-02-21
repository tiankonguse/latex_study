bool _is[N];
int _prm[N], _num;
void rangePrime(LL L, LL U) {
    LL i,k,size=U-L,tmp;
    _num = 0;
    memset(_is,1,sizeof(_is));

    for(i=0; i <= num && prm[i]*prm[i]<=U; ++i) {
        k = (L + prm[i] - 1)/prm[i];
        while(k <= 1) {
            k++;
        }
        tmp = k*prm[i];
        while(tmp <= U) {
            _is[tmp - L] = 0;
            tmp += prm[i];
        }
    }

    for(i = 0; i <= size; ++i) {
        if(_is[i]) {
            _prm[_num++]=i+L;
        }
    }
}

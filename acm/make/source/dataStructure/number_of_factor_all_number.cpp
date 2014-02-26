//`O(n*log(n))的复杂度`
int const maxn = 1e6;
int num[maxn];
void sieve_factor(){
    int i,j;
    for(i=1;i<maxn;++i){
        for(j=i;j<maxn;j+=i){
            ++num[j];
        }
    }
}

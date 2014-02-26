//`O(n)的复杂度`
int const maxn = 1e6;
int pri[maxn],e[maxn],divs[maxn],cnt;
void sieve_factor() {
    int i,j,k;
    cnt = 0;
    for(i=2; i<maxn; ++i) {
        if(!divs[i]) {
            divs[i] = 2;
            e[i] = 1;
            pri[cnt++] = i;
        }
        for(j=0; (k=i*pri[j]) < maxn; ++j) {
            if(i%pri[j] == 0) {
                e[k] = e[i] + 1;
                divs[k] = divs[i] / (e[i] +1)*(e[i] + 2);
                break;
            } else {
                e[k] = 1;
                divs[k] = divs[i]<<1;
            }
        }
    }
}

//or java.BigInteger -> nextProbablePrime();
typedef long long ll;
int const maxn = 4e6;
ll const start = 1e12, end = start + 3e6;

int pri[maxn], cnt; bool mark[maxn];
ll pl[maxn]; int pnt; bool markl[maxn];

void __sieve_large() {
    cnt = 0, mark[0] = mark[1] = true;
    for (int i = 2; i < maxn; ++i) {
        if (!mark[i]) pri[cnt++] = i;
        for (int j = 0; i * pri[j] < maxn; ++j) {
            mark[i * pri[j]] = true;
            if (!(i % pri[j])) break;
        }
    }
    ll pos;
    for (int i = 0; i < cnt; ++i) {
        if (start % pri[i] == 0) pos = start;
        else pos = start - start % pri[i] + pri[i];
        for (; pos <= end; pos += pri[i]) {
            markl[pos - start] = true;
        }
    }
    pnt = 0;
    for (int i = 0; i <= end - start; ++i) {
        if (!markl[i]) pl[pnt++] = start + i;
    }
}

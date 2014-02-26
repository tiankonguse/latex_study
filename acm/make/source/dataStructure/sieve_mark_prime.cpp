//cnt[1e7] = 664579, cnt[1e6] = 78498
//mark[i] : the minimum factor of i (when i is a prime, mark[i] == i)
int const maxn = 1e7;
int pri[maxn], mark[maxn], cnt;
void sieve() {
	cnt = 0, mark[0] = mark[1] = 1;
	for (int i = 2; i < maxn; i++) {
		if (!mark[i]) pri[cnt++] = mark[i] = i;
		for (int j = 0; pri[j] * i < maxn; j++) {
			mark[ i * pri[j] ] = pri[j];
			if (i % pri[j] == 0) break;
		}
	}
}

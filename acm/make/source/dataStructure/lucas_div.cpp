typedef long long ll;
int const maxn = 1000100;
int const maxm = 100100; //cnt ~ maxn / 10
ll const mod = 1000000007;
int pri[maxm], cnt; bool mark[maxn];
int p1[maxm], p2[maxm], p3[maxm];

void sieve() {
	cnt = 0, mark[0] = mark[1] = true;
	for (int i = 2; i < maxn; ++i) {
		if (!mark[i]) pri[cnt++] = i;
		for (int j = 0; i * pri[j] < maxn; ++j) {
			mark[i * pri[j]] = true;
			if (!(i % pri[j])) break;
		}
	}
}

int div(int *p, int n) {
	for (int i = 0, t; ; ++i) {
		if (pri[i] > n) return i;
		for (p[i] = 0, t = n; t; t /= pri[i]) {
			p[i] += t / pri[i];
		}
	}
}

ll C(int a, int b) { // a >= b, sieve() first!
	int l1 = div(p1, a);
	int l2 = div(p2, a - b);
	int l3 = div(p3, b);
	ll ret = 1LL;
	for (int i = 0; i < l1; ++i) {
		if (i < l2) p1[i] -= p2[i];
		if (i < l3) p1[i] -= p3[i];
		if (p1[i]) {
			ll r = 1LL, t = pri[i];
			while (p1[i]) {
				if (p1[i] & 1) r = r * t % mod;
				t = t * t % mod;
				p1[i] >>= 1;
			}
			ret = ret * r % mod;
		}
	}
	return ret;
}

int const maxn = 1e6;
int pri[maxn], cnt;
int phi[maxn];
void __sieve_phi() {
    cnt = 0, phi[1] = 1;
    for (int i = 2; i < maxn; ++i) {
        if (!phi[i]) {
            pri[cnt++] = i;
            phi[i] = i - 1;
        }
        for (int j = 0; pri[j] * i < maxn; ++j) {
            if (!(i % pri[j])) {
                phi[i * pri[j]] = phi[i] * pri[j];
                break;
            }
            else {
                phi[i * pri[j]] = phi[i] * (pri[j] - 1);
            }
        }
    }
}

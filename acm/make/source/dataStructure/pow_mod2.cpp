typedef long long ll;
ll powMod(ll a, ll b, ll c){
	 ll res = 1LL;
	while (b) {
		if(b & 1) res = res * a % c;
		a = a * a % c;
		b >>= 1;
	}
	return res;
}

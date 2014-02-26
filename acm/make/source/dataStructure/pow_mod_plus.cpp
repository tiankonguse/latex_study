ll powMod(ll a, ll b, ll c){
	ll res = 1LL;
	for (; b; b >>= 1, a = mulMod(a, a, c) ) {
		if (b & 1) res = mulMod(res, a, c);
	}
	return res;
}

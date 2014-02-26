//`迭代幂是指求：a\^{}b\^{}c\^{} .. mod p。`
//`通用公式：`
`	a\^{}b ≡ a\^{}(b mod ϕ(p)+ϕ(p)) (mod p)(b≥ϕ(p))。`
//`若p是素数，则`
`	a\^{}b≡a\^{}(b mod ϕ(p)) (mod p)。`
//`需要模板：`
	LL gcd(LL a, LL b);
	LL euler(LL x);
	LL pow_mod(LL a,LL  b,LL c);
//`证明：略`
typedef long long LL;
LL str[30];
int n;

LL getPowTop(int pos, LL mod) {
	LL a, b = 1;
	for(int i = n-1; i >= pos; i--) {
		a = str[i];
		LL ret = 1;
		for(; b; a *= a, b >>= 1) {
			if(b & 1)
				ret *= a;
			if(ret >= mod || a >= mod){
				return -1;
			}
		}
		b = ret;
	}
	return b;
}

LL powMod(int pos,LL mod) {
    if(pos == n)return 1;
    //LL tmp = mod/gcd(str[pos],mod);
    LL phi_mod = euler(mod);
    LL b = getPowTop(pos+1,phi_mod);
    if(b == -1){
        b = powMod(pos+1, phi_mod) % phi_mod + phi_mod;
    }
    return powMod(str[pos], b , mod);
}


int main() {
    LL p;
    cin>>n>>p;
    bool ok = false;
    for(int i=0; i<n; i++) {
        cin>>str[i];
		if(str[i] == 1)ok = true;
		f(ok)i--,n--;
    }
    cout<<powMod(0,p)<<endl;

    return 0;
}

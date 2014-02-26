`满足b*k=1 (mod p)的k值就是b关于p的乘法逆元`
`当我们要求(a/b)mod p的值，且a很大，无法直接求得a/b的值时，我们就要用到乘法逆元`
`前提a\%b=0,gcd(b,p)=1.`
`我们可以通过求b关于p的乘法逆元k，将a乘上k再模p，即(a*k) mod p。其结果与(a/b)mod p等价。`
`证明：根据b*k=1 (mod p) 有b*k=p*x+1`
`k=(p*x+1)/b。把k代入(a*k) \% p，得`
(a*(p*x+1)/b) % p
=((a*p*x)/b + a/b) %p
=[(p*(a*x)/b)%p + a/b] %p
=(a/b)%p
//(p*(a*x)/b)%p=0;
LL div_mod(LL a,LL b,LL c){
	int x,y;
	exgcd(b,c,x,y);
	return ((a%c)*(x%c))%c; 
} 

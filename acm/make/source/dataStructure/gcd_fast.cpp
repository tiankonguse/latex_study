int kgcd(int a,int b){
	if(!a || !b)return a?a:b;
	if(!(a&1) && !(b&1))return kgcd(a>>1,b>>1)<<1;
	if(!(b&1))return kgcd(a,b>>1);
	if(!(a&1))return kgcd(a>>1,b);
	return kgcd(b,a%b);
}

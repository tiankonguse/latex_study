unsigned __countbits(unsigned x){
	unsigned n=0;
	while(n+=(x&1) , x>>=1);
	return n;
}

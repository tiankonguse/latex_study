//`从最低位扫描'1',每次扫描一个`
unsigned _countbits(unsigned x){
	unsigned n=0;
	while(++n , x&=x-1);
	return n;
} 

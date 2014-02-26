`对于 a*x=b(\%n)，则存在整数y,使a*x - n*y = b.`
`如果有解，则有d个解，设最小正数解为x0,则解为x0+d*i,i=0,1,2,…d-1. 返回最小正数解 无解时返回-1`
LL modeq(LL a,LL b,LL n){
	LL d,x,y;
	d=extgcd(a,n,x,y);
	if(b%d)return -1;
	return (b/d*x%n + n)%(n/d);
}

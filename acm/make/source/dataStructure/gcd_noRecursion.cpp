LL gcd(LL x,LL y){
	if(!x || !y)return x?x:y;
	for(LL t;t=x%y;x=y,y=t);
	return y;
}

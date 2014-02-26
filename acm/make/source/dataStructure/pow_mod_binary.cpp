int pow_mod(int a,int b,int c){
	if(b==0)return 1%c;
	a%=c;
	if(c<=2 || a<2)return a;
	int ans=1;
	while(b){
		if(b&1)ans=(ans*a)%c;
		a=(a*a)%c;
		b>>=1; 
	} 
	return ans; 
} 

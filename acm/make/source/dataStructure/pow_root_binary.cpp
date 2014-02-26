int mytreeroot(int a,int b){
	a=root(a);
	int t=a,ans=1;
	while(b){
		if(b&1)ans=root(ans*t);
		b>>=1;
		t=root(t*t);
	}
	return ans;
}

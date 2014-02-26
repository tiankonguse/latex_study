`str[n].count为n的质数因子的个数`
`Str[n].prim[]中存的就是质数因子`
`这个不能用简单的容斥，因为这里的除法不是全部能整除，用简单的容斥是错的。`
LL myrongchi(int index,int a,int n){
	LL r=0,t;
	for(int i=index;i<str[n].count;i++){
		t=a/str[n].prim[i];
		r+=t-myrongchi(i+1,t,n);
	}
	return r;	
}

int _treeroot(int a,int b){
	a=root(a);
	int ans=1;
	while(b--)ans=root(ans*a);
	return ans;
}

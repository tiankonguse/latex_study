` 应用：`
`1. 求解不定方程`
`2. 求解模的逆元`
`3. 求解同余方程`
int extgcd(int a,int b,int &x,int &y){
	if(b==0){x=1,y=0;return a;}
	int d=extgcd(b,a%b,x,y);
	int t=x;x=y;y=t-a/b*y;
	return d;
}

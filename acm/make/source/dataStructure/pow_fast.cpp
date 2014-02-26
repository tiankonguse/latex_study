int qkpower(int a,int k){
	int ans=1,temp=a;
	while(k){
		if(k&1)ans*=temp;
		temp*=temp;
		k>>=1; 
	} 
	return ans; 
} 

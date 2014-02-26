int __root(char *p){
	int n=0;
	for(int i=0;p[i];i++)n+=p[i]-'0';
	return n?(n+8)%9+1:0;
} 

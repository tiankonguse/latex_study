__int64 search_bit(__int64 n,__int64 m){
	__int64 sum=0;
	while(n)sum+=(n/=m);
	return sum;
}

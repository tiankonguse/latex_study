//`其实0的个数至于5的个数有关，因此需要分解n!中5的个数`
__int64 count_zero(__int64 m){
	__int64 sum=0;
	while(m)
		sum+=(m/=5);
	return sum;
}

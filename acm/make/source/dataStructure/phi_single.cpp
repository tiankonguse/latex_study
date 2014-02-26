int euler(int x){//` 就是公式`
	int i, res=x;
	int max= (int)sqrt(x * 1.0) + 1; 
	for (i = 2; i <max; i++)
		if(x%i==0) {
		res = res / i * (i - 1);
		while (x % i == 0) x /= i; //` 保证i一定是素数`
		}
	if (x > 1) res = res / x * (x - 1);
	return res;
}

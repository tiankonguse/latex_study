//pku 1423 HDU 1018
double e=2.7182818284590452354;
double pi=atan2(0.0,-1.0);

int count_number_bit(int n){
	double sum=0;
	if(n<100000){
	for(int i=1;i<=n;i++)
		sum+=log10(i*1.0);
	}else{
	sum=log10(sqrt(2*pi*n))+n*log10(n/e);
	}
	int ans=(int)sum;
	if(ans<=sum)ans++;
	return ans;
} 

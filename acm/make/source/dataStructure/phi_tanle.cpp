`这个表存的是小于N的数的欧拉函数`
const int N=10000; 
int phi[N+1]; 
void ruler(){ 
	int i,j; 
	for (i = 1; i <= N; i++) phi[i] = i;
	for (i = 2; i <= N; i += 2) phi[i] /= 2;
	for (i = 3; i <= N; i += 2) 
		if(phi[i] == i) {
			for (j = i; j <= N; j += i)
				phi[j] = phi[j] / i * (i - 1);
		}
} 

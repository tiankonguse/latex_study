Matrix Matrix::pow(TT k){
	Matrix ret;
	Matrix A=*this;
	ret._union();
	while(k){
		if(k&1)ret=ret*A;
		A=A*A;
		k>>=1; 
	}
	return ret; 
}

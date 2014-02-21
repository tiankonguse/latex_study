typedef long long LL;
LL NN = 2147483647LL;
const int N= (2147483647>>3)+1;
const int M=14630853;
char is[N];
LL prm[M];
void setIs(int pos){
    is[pos>>3] &= ~(1<<(pos%8));
}

bool getIs(int pos){
    return is[pos>>3] & (1<<(pos%8));
}

int getprm(){
	int e = (int)(sqrt(0.0 + NN) + 1),k=0,i;
	memset(is, 0XFF, sizeof(is));

	prm[k++] = 2;
	setIs(0);
	setIs(1);
	for (i = 4; i < NN; i += 2){
        setIs(i);
	}

	for(i=3;i<e;i+=2){
		if(getIs(i)){
			prm[k++]=i;
			for(int s=i+i,j=i*i;j<NN;j+=s){
                setIs(j);
			}
		}
	}
	for (; i < NN; i += 2)
		if (getIs(i))prm[k++] = i;
	return k;
}

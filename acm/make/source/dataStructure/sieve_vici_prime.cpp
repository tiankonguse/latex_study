const int N=1000000;
const int M=300000;
int mark[N];//`最小因子`
int prm[M];
int cnt;

int getprm(){
	int j,i;
	memset(mark, 0, sizeof(mark));

    cnt = 0;
    mark[0] = mark[1] = 1;

    for(i = 2; i < N; ++i){
        if(!mark[i]){
            prm[cnt++] = mark[i] = i;
        }
        for(j=0;prm[j]*i<N;++j){
            mark[i*prm[j]] = prm[j];
            if(i%prm[j] == 0)break;
        }
    }
    return cnt;
}

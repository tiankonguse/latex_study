bool Lucse(int N){
    int r[64];r[1]=4;
    int mod=1; mod=mod<<N; mod-=1;
    for(int i=2;i<=N-1;i++){
         temp=mul(r[i-1],r[i-1],mod);
         r[i]=(temp-2)%mod;
    }
    if( N==2||r[N-1]==0 ) return 1;
    else return 0;
}

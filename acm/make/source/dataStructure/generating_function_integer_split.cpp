while(~scanf("%d",&n)) {
    memset(second,0,sizeof(second));
    first[0]=1;
    _max=0;
    for(i=1; i<=n; i++) {
        _maxtmp=_max;
        for(j=0; j<=_max; j++) {
            for(k=0; k+j<=n; k+=i) {
                second[k+j]+=first[j];
                if(k+j>_maxtmp && k+j<=n)_maxtmp=k+j;
            }
        }
        _max=_maxtmp;
        for(j=0; j<=_max; j++) {
            first[j]=second[j];
            second[j]=0;
        }
    }
    printf("%d\n",first[n]);
}

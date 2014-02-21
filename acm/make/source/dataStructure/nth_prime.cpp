int euler(int n,int m){
    memset(map,true,sizeof(map));
    int i=0,num=n;
    for(;num!=1; i++;){
        if(num%prim[i]==0){
            while(num%prim[i]==0)num/=str[i];
            for(int j=prim[i];j<=n;j+=prim[i]){
                map[j]=false;
            }
        }
    }
    num=0;
    for(i=1;i<n;i++){
        if(map[i]){
            ans[++num]=i;
        }
    }
    ans[0]=ans[num];
    return ans[m%num]+(m-1)/num * n;
}

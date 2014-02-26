bool check(ll res,ll p){
    for(int i=0;i<divi.size();i++)
        if(mypow(res,(p-1)/divi[i],p)==1) return 0;
    return 1;
}
ll Primitive_Root(ll p){
    ll res=1;
    divi.clear();
    ll tmp=p-1;
    for(ll i=2;i*i<=tmp;i++){
        if(tmp%i==0){
            divi.push_back(i);
            while(tmp%i==0) tmp/=i;
        }
    }
    if(tmp!=1) divi.push_back(tmp);
    while(!check(res,p)) res++;
    return res;
}

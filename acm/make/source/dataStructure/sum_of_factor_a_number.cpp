//`因子和  :f(n)=[(p1\^{}(a1+1)-1)/(p1-1)]*[(p2\^{}(a2+1)-1)/(p2-1)]...`
int DsFun(int n){
    int res=1;
    for(int i = 2,t; i * i <= n; i += 2){
        if(!(n%i)){
            for(t=i*i,n/=i;!(n%i);t*=i,n/=i);
            res *= (t-1)/(i-1);
        }
        if(i==2){
            i--;
        }
    }
    if(n>1){
        res *= (n+1);
    }
    
    return res;
}

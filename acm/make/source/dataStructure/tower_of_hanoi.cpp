`给你初始状态start[]和最终状态finish[]，求最少移动步数。`
`start[]和finish[]表示第i个盘子在那个位置.`
`下标从1开始`
LL f(int *p, int i, int final){
    if(i == 0){
        return 0;
    }else if(p[i] == final){
        return f(p,i-1,final);
    }else{
        return f(p,i-1,6-p[i]-final) + (1LL<<(i-1));
    }
}

LL getAns(int *start, int *finish,int n){
    LL ans = 0;
    int k = n;
    while(k>=1 && start[k] == finish[k])k--;
    if(k>=1){
        int tmp = 6 - start[k] - finish[k];
        ans = f(start, k-1,tmp) + f(finish,k-1,tmp) + 1;
    }
    return ans;
}


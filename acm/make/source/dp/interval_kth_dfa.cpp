//`按位查找，从最高位开始确定应该是那个数字`
//`调用前 ans = 0;`
//`调用 dfs(len-1,0,0,false,query(left-1) + k);`
void dfs(int pos, int x_num, int y_num, bool yes, LL k) {
    if(pos < 0)return ;
    int _max = yes ? 9 : str[pos];
    LL tmp;
    for(int i=0; i<=_max; i++) {
        tmp = dfs(pos-1, x_num+(i == 4), y_num + (i == 7), yes
                  || i<str[pos]);
        if(tmp>=k) {
            ans = ans*10+i;
            dfs(pos-1,x_num + (i == 4), y_num + (i == 7),
                yes || i<str[pos],k);
            return;
        } else {
            k -= tmp;
        }
    }
}

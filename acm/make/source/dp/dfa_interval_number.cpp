//`对于一个数字，首先把这个数字存在数组中`
typedef long long LL;
int str[100];
LL _sum[100][30][30];
int len;
int x,y;
LL dfs(int pos, int x_num, int y_num, bool yes) {
    if(pos < 0) {//`判断是否结束`
        return x_num == x && y_num == y;
    }
    if(x_num > x || y_num > y) {
        return 0;//`判断是否已经不满足条件`
    }
//`判断是否已经是 999 且已经计算过。`
    if(yes && _sum[pos][x_num][y_num] != -1) {
        return _sum[pos][x_num][y_num];
    }
//`没计算过，开始计算`
    LL ans = 0;
    int _max = yes ? 9 : str[pos];
    for(int i=0; i<=_max; i++) {
        ans += dfs(pos-1, x_num + (i == 4), y_num +
                   (i == 7), yes || i<str[pos]);
    }
//`保存计算过的`
    if(yes) {
        _sum[pos][x_num][y_num] = ans;
    }
    return ans;
}
//`查询，一般是用[0, val]`
LL query(LL val) {
    if(val < 0) {
        return 0;
    }
    len = 0;
    if(val == 0) {
        str[len++] = val;
    } else {
        while(val) {
            str[len++] = val%10;
            val /= 10;
        }
    }
    return dfs(len-1,0,0,false);
}

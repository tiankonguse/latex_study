`用 n 个盘子，最后全放在第二个,调用 hanio(2,n-1)`

int pos[66];
__int64 hanio(int b,int m) {
    if(m==0) return pos[m]!=b;
    if(pos[m] == b)return hanio(b,m-1);
    return hanio(6-b-pos[m],m-1)+((__int64)1<<m);
}

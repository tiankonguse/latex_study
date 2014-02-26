//`求区间和`
int Sum(int i, int j) {
    int tempj, sum = 0;
    while( i > 0 ) {
        tempj = j;
        while( tempj > 0 ) {
            sum += c[i][tempj];
            tempj -= Lowbit(tempj);
        }
        i -= Lowbit(i);
    }
    return sum;
}
//`更新一个点`
void Update(int i, int j, int num) {
    int tempj;
    while( i <= Row ) {
        tempj = j;
        while( tempj <= Col ) {
            c[i][tempj] += num;
            tempj += Lowbit(tempj);
        }
        i += Lowbit(i);
    }
}

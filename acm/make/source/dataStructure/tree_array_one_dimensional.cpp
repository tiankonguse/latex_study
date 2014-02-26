//`求区间和`
int musum(int end) { //` 复杂度 O(logn)`
    int sum = 0;
    while (end > 0) {
        sum += m[end];
        end -= Lowbit(end);
    }
    return sum;
}
 
//`修改一个位置的值`
void myplus(int pos) { //` 复杂度 O(logn)`
    while(pos <= mx) {
        m[pos] ++;
        pos += Lowbit(pos);
    }
}
 
//`得到某一个位置的值`
int readSingle(int idx) {
    int sum = tree[idx];
    int z = idx - (idx & -idx);
    idx--;
    while (idx != z) {
        sum -= tree[idx];
        idx -= (idx & -idx);
    }
 
    return sum;
}

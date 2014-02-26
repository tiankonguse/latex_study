`设当前位置为子段的最后一个，答案有两种情况：`
`1.如果当前位置的上一个为子段的最后一个的最优值小于等于 0，则当前位置单独为一个子段会更优。`
`2.否则，当前位置加上前一个的最优值就是当前的最优值。`
int MSS(int*a,int n) {
    int tmp ,sum;
    tmp = sum = a[1];
    for(i = 2; i<=n; i++) {
        if(tmp >= 0) {
            tmp += a[i];
        } else {
            tmp = a[i];
        }
        if(tmp > sum) {
            sum = tmp;
        }
    }
    return sum;
}

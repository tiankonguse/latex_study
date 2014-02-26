`主要用于求解最长回文子串。`
`这个算法有一个很巧妙的地方，它把奇数的回文串和偶数的回文串统一起来考虑了。`
`这个算法还有一个很好的地方就是充分利用了字符匹配的特殊性，避免了大量不必要的重复匹配。`

const int MAX = 110003 << 2;
char oldstr[MAX];//`原字符串`
char str[MAX];
int p[MAX];//`表示以 i 为中心的回文半径，`
/*
`p[i]-1 刚好是原字符串以第 i 个为中心的回文串长度。`
*/
void Manacher(int n) {
    int mx=0;
    int id;//`最长影响串的位置;`
    p[0]=0;
    for(int i = 1; i < n; i++) {
        p[i]=1;//`至少是 1`
        if(mx>i) {
            p[i] = p[2 * id - i];
            if(mx - i < p[i]) p[i] = mx - i;
        }
//`向两端配匹`
        while(str[i - p[i]] == str[i + p[i]]) p[i]++;
        if(i + p[i] > mx) {
            mx = i + p[i];
            id = i;
        }
    }
}
/*
`预处理字符串`
*/
int pre(char head='$', char middle='#', char end = '?') {
    int n=0;
    str[n++]=head;
    str[n++]=middle;
    for(int i = 0; oldstr[i]; i++) {
        str[n++] = oldstr[i];
        str[n++] = middle;
    }
    str[n]=end;
    return n;
}
int main() {
    int n;
    while(scanf("%s", oldstr) != EOF) {
        n = pre();
        Manacher(n);
        int ans=0;
        for(int i = 1; i < n; i++) {
            if(p[i] > ans) ans = p[i];
        }
        printf("%d\n", ans - 1);
    }
    return 0;
}


`这里以一个例子来讲解 IDA*.`
`问题：n 个数互不相同，可以对相邻的连续区间进行交换，最终使 n 个数达到升序。求最少交换次数。`
`这里假设是 1 到 n 的 n 个数。不是话可以进行映射。`


int n,str[20], _maxDepth;
int hfunc() {//`估计函数：还有多少个断点`
    int depth = 0;
    for(int i=1; i<n; i++) {
        if(str[i] != str[i-1]+1) {
            depth++;
        }
    }
    return depth;
}
//`交换区间`
void move(int left, int mid, int right) {
    int i, j, tmp[20];;
    for(i=mid+1,j=0; i<=right; i++,j++) {
        tmp[j] = str[i];
    }
    for(i=left; i<=mid; i++,j++) {
        tmp[j] = str[i];
    }
    for(i=left,j=0; i<=right; i++,j++) {
        str[i] = tmp[j];
    }
}
//`迭代加深搜索`
//`三个 while 是我加的优化，我们只能从断点开始划分交换区间，一个连续区间分开后显然答案不忧。`
//`一次交换最优情况下可以减少三个断点。`
int dfs(int depth) {
    int left,mid,right,h;
    for(left=0; left<n-1; left++) {
        while(left && str[left] == str[left-1]+1)left++;
        for(mid = left; mid<n-1; mid++) {
            while(mid<n-1 && (str[mid]+1 == str[mid+1]))mid++;
            for(right = mid+1; right < n; right++) {
                while(right<n-1&&(str[right]+1 == str[right+1]))right++;
                move(left, mid,right);
                if((h = hfunc()) == 0)return 1;
                if(depth*3 + h <= _maxDepth*3) {
                    if(dfs(depth+1)) {
                        return 1;
                    }
                }
                move(left,left + (right-mid-1),right);
            }
        }
    }
    return 0;
}
int main() {
    int cas,i;
    scanf("%d",&n);
    for(i=0; i<n; i++) {
        scanf("%d",&str[i]);
    }
    _maxDepth = (hfunc()+2)/3;
    if(_maxDepth) {
        while(dfs(1) == 0) {
            _maxDepth++;
        }
    }
    printf("%d\n",_maxDepth);
    return 0;
}

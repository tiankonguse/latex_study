int k,a[101]; //`k 为节点数，a 为减数集合`
int f[N],num[N]; //`f 存储 sg 值,num 标记 sg 值是否存在`
sg[0]=0;
for(i=1; i<k; i++) {
    for(j=0; a[j]<=i; j++)num[sg[i-a[j]]]=i;
    for(j=0; j<=i; j++)
        if(num[j]!=i) {
            sg[i]=j;
            break;
        }
}

//`最最基础的线段树,只更新叶子节点,然后把信息用`
//`PushUP(int r)这个函数更新上来`
//1.bulid();
//2.query(a,b)
//3.update(a,b)
#define lson l , m , rt << 1
#define rson m + 1 , r , rt << 1 | 1
const int maxn = 55555;
int sum[maxn<<2];
int n;
//`根据题意做相关修改，询问时的操作`
int operate(int a,int b) {
    return a+b;
}
void PushUp(int rt) {
    sum[rt]=operate(sum[rt<<1],sum[rt<<1|1]);
}
void bulid(int l=1,int r=n,int rt=1) {
    if(l==r) { // `据题意做相关修改`
        scanf("%d",&sum[rt]);
        return ;
    }
    int m=(l+r)>>1;
    bulid(lson);
    bulid(rson);
    PushUp(rt);
}
void update(int p,int add,int l=1,int r=n,int rt=1) {
    if(l==r) { //` 据题意做相关修改`
        sum[rt]+=add;
        return ;
    }
    int m=(l+r)>>1;
    if(p<=m)update(p,add,lson);
    else update(p,add,rson);
    PushUp(rt);
}
int query(int L,int R,int l=1,int r=n,int rt=1) {
    if(L<=l && r<=R) {
        return sum[rt];
    }
    int m=(l+r)>>1;
    int ret=0;
    if(L<=m)ret=operate(ret,query(L,R,lson));
    if(R> m)ret=operate(ret,query(L,R,rson));
    return ret;
}

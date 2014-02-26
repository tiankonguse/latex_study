const int MAXSIZE=10000;
class MaxHeap {
public:
    MaxHeap() {
        size=0;
    }
    void push(int val) {
        a[++size]=val;
        pushup(size);
    }
    void pop() {
        a[1]=a[size--];
        pushdown(1);
    }
    int top() {
        return a[1];
    }
    bool empty() {
        return !size;
    }
private:
    int a[MAXSIZE];
    int size;
    void pushdown(int now) {
        int l=now<<1;
        int r=l+1;
        if(l==size) {
            if(com(a[now],a[l]))
                swap(a[now],a[l]);
        } else if(r<=size) {
            int tmp=a[l]>a[r]?l:r;
            if(com(a[now],a[tmp])) {
                swap(a[now],a[tmp]);
                pushdown(tmp);
            }
        }
    }
    void pushup(int now) {
        int pre=now>>1;
        if(pre && com(a[pre],a[now])) {
            swap(a[pre],a[now]);
            pushup(pre);
        }
    }
    bool com(int aa,int bb) {
        return aa<bb;
    }
};

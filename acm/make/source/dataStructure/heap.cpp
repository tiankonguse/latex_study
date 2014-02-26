
const int maxn = 10000;

struct Heap {
    int size;
    int array[maxn];
    void bulid();
    void insert(int val);
    int top();
    void pop();
    bool empty();
    void push_down(int pre);
    void push_up(int son);
    bool compare(int pre,int son);
};
void Heap::bulid() {
    size = 0;
}
void Heap::insert(int val) {
    array[++size] = val;
    push_up(size);
}
int Heap::top() {
    return array[1];
}
void Heap::pop() {
    array[1] = array[size--];
    push_down(1);
}
bool Heap::empty() {
    return size == 0;
}
void Heap::push_down_loop(int pre) {
    while(true) {
        if((pre<<1|1)<= size && compare(pre<<1|1,pre)
                && compare(pre<<1|1,pre<<1)) {
//判断右儿子是否是父亲
            swap(array[pre],array[pre<<1|1]);
            pre = pre<<1|1;
        } else if((pre<<1) <= size && compare(pre<<1,pre)) {
//判断左儿子是否是父亲
            swap(array[pre],array[pre<<1]);
            pre = pre<<1;
        } else {
            break;
        }
    }
}
void Heap::push_up(int son) {
    if(son == 1)return ;
    int pre = son>>1;
    if(!compare(pre,son)) {
        swap(array[pre],array[son]);
        push_up(pre);
    }
}
//堆的性质返回 true
//也就是儿子不大于父亲返回 true
bool Heap::compare(int pre,int son) {
    return array[pre] >= array[son];//最大堆
// return array[pre] <= array[son];//最小堆
}

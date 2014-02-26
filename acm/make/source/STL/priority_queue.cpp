`头文件：\#include<queue>`
`优先队列，也就是原来我们学过的堆，按照自己定义的优先级出队时。默认情况下底层是以 Vector 实现的heap。`
`既然是队列，也就只有入队、出队、判空、大小的操作，并不具备查找功能。`

`函数列表：`
`empty() 如果优先队列为空，则返回真 `
`pop() 删除第一个元素 `
`push() 加入一个元素 `
`size() 返回优先队列中拥有的元素的个数 `
`top() 返回优先队列中有最高优先级的元素`

`一：最基本的功能`
`优先队列最基本的功能就是出队时不是按照先进先出的规则，而是按照队列中优先级顺序出队。`
`知识点：`
`1、一般存放实型类型，可比较大小`
`2、默认情况下底层以 Vector 实现`
`3、默认情况下是大顶堆，也就是大者优先级高，后面可以自定义优先级比较规则`

`二：次基本的功能`
`可以将一个存放实型类型的数据结构转化为优先队列，这里跟优先队列的构造函数相关。`
`上面那个默认构造一个空的优先队列，什么都使用默认的。`
`而这里使用的是 Priority\_{}queue(InputIterator first,InputIterator last)`
`我理解的就是给出了一个容器的开口和结尾，然后把这个容器内容拷贝到底层实现(默认 vector)中去构造出优先队列。`
`这里也使用了一个默认的比较函数，也是默认大顶堆`
`例如： `
int a[5]={3,4,5,2,1};
priority_queue<int> Q(a,a+5);

`三 应该掌握的功能:`
`这个里面定义了一个制定存放元素(Node),底层实现以vector 实现（第二个参数）,优先级为小顶堆(第三个参数)。`
`前两个参数没什么说的，很好理解，其中第三个参数，`
`默认有三写法：`
`小顶堆：greater<TYPE>`
`大顶堆：less<TYPE>`
`如果想自定义优先级而 TYPE 不是基本类型，而是复杂类型，例如结构体、类对象，则必须重载其中的operator().`

`见下面的例子。`
typedef struct {int a,b;}Node; //`自定义优先级类型`
struct cmp{
	bool operator()(const Node &t1,const Node &t2){
		return t1.b<t2.b;//`相当于 less,大顶堆 `
	}
};
priority_queue<Node,vector<Node>,cmp> Q;

`或者直接重载小于号`

struct Node{
    int a;
    Node(int a=0):a(a){}
    bool operator<(const Node &t2)const {
        return this->a < t2.a;// < : 大堆 ； < : 小堆
    }
}; //`自定义优先级类型`
priority_queue<Node> Q;

`sort 对给定区间所有元素进行排序`
`stable\_sort 对给定区间所有元素进行稳定排序`
`partial\_sort 对给定区间所有元素部分排序`
`partial\_sort\_copy 对给定区间复制并排序`
`nth\_element 找出给定区间的某个位置对应的元素`
`is\_sorted 判断一个区间是否已经排好序`
`partition 使得符合某个条件的元素放在前面`
`stable\_partition 相对稳定的使得符合某个条件的元素放在前面`

`sort`
`sort 函数需包含\#include <algorithm>`
`sort(begin,end)，表示一个范围，默认升序，基本类型`
`可以这样写`
`sort(begin,end,compare) 可实现自定义的排序，主要用于自定义类型`

bool compare(T a,T b){
	return a-b;
} 
bool operator < (const T &m)const {
 return num > m.num;
}
`对于基本类型，可以不编写 compare`
`升序：sort(begin,end,less<data-type>());`
`降序：sort(begin,end,greater<data-type>()).`

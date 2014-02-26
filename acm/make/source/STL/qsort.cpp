`原型:`
_CRTIMP void __cdecl qsort (void*, size_t, size_t,int (*)(const void*, const void*));
`解释: qsort ( 起始地址,元素个数,元素大小，比较函数) `
`比较函数是一个自己写的函数 `
`遵循 int com(const void *a,const void *b) 的格式。`
`当 a b 关系为 > < = 时，分别返回正值 负值 零 （或者相反）。`
`使用 a b 时要强制转换类型，从 void * 转换回应有的类型后，进行操作。 `
`数组下标从零开始,个数为 N, 下标 0-(n-1)。`
int compare(const void *a,const void *b){
	return *(int*)b-*(int*)a; 
}

`n 个不同的元素，重新排列，使的每个元素不在原来的位置。\\
分析：当 n 个编号元素放在 n 个编号位置，元素编号与位置编号不相同时，方法数记为 M(n).\\
第一步：把第 n 个元素放在一个位置，比如位置 k，共有 n-1 中方法；\\
第二步，放编号为 k 的元素，这是有两种情况：1.放到位置 n,那么，剩下的 n-2 个元素的方法数为 M(n-2)；\\
2.不把它放在位置 n，这是，对于这 n-2 个元素，有M(n-1)中方法。\\
故:M(n) = (n-1)( M(n-2) +M(n-1) ),M(1)=0,M(2)=1;`

`适用条件`
`	单源最短路径(从源点 s 到其它所有顶点 v); `
`	可以存在负边权`

`原始算法`
`（1）初始化：将除源点外的所有顶点的最短距离估计值 d[v] ←+∞, d[s] ←0;`
`（2）迭代求解：反复对边集 E 中的每条边进行松弛操作，使得顶点集 V 中的每个顶点 v 的最短距离估计值逐步逼近其最短距离；（运行|v|-1 次）`
`（3）检验负权回路：判断边集 E 中的每一条边的两个端点是否收敛。如果存在未收敛的顶点，则算法返回 false，表明问题无解；否则算法返回 true，并且从源点可达的顶点 v 的最短距离保存在 d[v]中。`
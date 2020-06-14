#include "test15_ADTOfGraph.h"
#include <iostream>
#include <string>


// 图 - 图的定义及其使用
// 分类
// 有向图，无向图，简单图，多重图，完全图，子图
// 连通图
// 生成树，生成森林，顶点的入度/出度


void test15_ADTOfGraph::classMain()
{
	std::cout << "test15_ADTOfGraph" << "\n";

	// 普通无向图
	Graph* g = new Graph;
	this->initOrdinaryGraph(g);
	this->visitOrdinaryGraph(g);
}



// 图的存储

// 邻接矩阵法


// **图的基本操作**
// 普通的无向图
void test15_ADTOfGraph::initOrdinaryGraph(Graph* g)
{
	// 初始化无向图g
	char tempChar;
	for (int i = 0; i < N; ++i)
	{
		std::cout << "输入一个顶点：" << "\n";
		std::cin >> tempChar;
		g->vdxs[i] = tempChar;
	}
	// 初始化邻接矩阵
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; i < N; ++i)
		{
			g->adjs[i][j] = 0;
		}
	}
	// 写入邻接矩阵
	int vex1, vex2;
	float w; // 权值
	for (int k = 0; k < E; ++k)
	{
		std::cout << "输入每个顶点序号(从0开始)和权值：如1，2，5;表示第二和第三个顶点之间的是否相连以及权值" << "\n";
		scanf_s("%d%d%f", &vex1, &vex2, &w);
		g->adjs[vex1][vex2] = w;
		g->adjs[vex2][vex1] = w;
		// 若建立有向图，则将最后一个赋值语句去掉，可以将w的值设为1，变为无向图
	}
}

// 普通无向图的访问
void test15_ADTOfGraph::visitOrdinaryGraph(Graph* g)
{
	int visit[N]; // 辅助数组，标记点是否已经被访问
	std::cout << "图g的顶点为：" << "\n";
	for (int i = 0; i < N; ++i)
	{
		std::cout << g->vdxs[i] << " ";
	}
	//delete g; // 释放内存
	std::cout << "图打印完毕" << "\n";
}

// 参考
// https://blog.csdn.net/misayaaaaa/article/details/72528686

// 向图中加入节点
bool test15_ADTOfGraph::addNodeOfOrdinaryGraph()
{
	return true;
}

// 重置所有顶点为未访问



// 参考
// https://blog.csdn.net/shangguanyunlan/article/details/52900579


// 判断图G是否存在边<x,y>

// 列出图g中与节点x邻接的边

// 在图g中插入顶点x

// 从图g中删除顶点x

// 向图中添加边<x,y>

// 删除边<x,y>

// 求图g中顶点y是顶点x的一个邻接点



// **图的遍历**
// BFS - (Breadth-First-Search,广度优先)


// DFS - (Depth-Firest-Search,深度优先)








// **图的应用**
// 最小生成树

// Prim算法

// Krushal算法

// 单源最短路径
// Dijkstra算法

// Floyd算法

// 拓扑排序
// AOV网
// DAG图
// 实现

// 关键路径
// AOE网

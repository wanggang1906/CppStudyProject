#include "test15_ADTOfGraph.h"
#include <iostream>
#include <string>


// 图
//		图的定义
//		存储 - 完整，准确反映顶点集和边集的信息，有向/无向图主要有两种存储方式：
//			邻接矩阵 - 顺序存储，用一个一维数组存储图中顶点信息，用一个二维数组存储图中边的信息(邻接矩阵)
//			邻接表 - 链式存储，结合了顺序存储和链式存储，顶点表(顶点域，边表头指针-以该顶点为尾的弧，连接次序任意，取决于输入次序)，边表(邻接点域，指针域)
//			十字链表法 - 有向图的链式存储，弧节点(尾域-指示弧尾，头域-指示弧头，头链域-弧头相同的下一条弧，尾链域-弧尾相同的下一条弧，信息域-指向该弧的相关信息。
//				此时弧头相同的弧在同一个链表上，弧尾相同的弧也在同一个链表上)，顶点节点(数据域，第一个头，第一个尾-指向以该顶点为弧尾的第一个结点)
//			邻接多重表 - 无向图的链式存储，每一条边用一个结点表示(mark-标记位，)
// 分类
//		有向图，无向图，简单图，多重图，完全图，子图
//		连通图
//		生成树，生成森林，顶点的入度/出度
// 遍历
//		深度优先
//		广度优先
// 应用
//		最小生成树 - prim，kruskal
//		最短路径 - Dijkstra，Floyd
//		拓扑排序 - AOV
//		关键路径 - AOE


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


// **图的基本操作 - 独立于图的存储结构，不同的存储结构，影响操作的性能**
// 普通的无向图
void test15_ADTOfGraph::initOrdinaryGraph(Graph* g)
{
	// 初始化无向图g
	char tempChar;
	for (int i = 0; i < N; ++i)
	{
		std::cout << "输入一个顶点：" << "\n";
		std::cin >> tempChar;
		g->vdxs[i] = tempChar; // 顶点表
	}
	// 初始化邻接矩阵
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; i < N; ++i)
		{
			g->adjs[i][j] = 0; // 边表全置0
		}
	}
	// 写入邻接矩阵
	int vex1, vex2; // 接收两个顶点的值
	float w; // 权值
	for (int k = 0; k < E; ++k)
	{
		std::cout << "\n输入每个顶点序号(从0开始)和权值：如1，2，5;表示第二和第三个顶点之间的是否相连以及权值" << "\n";
		int i = scanf_s("%d,%d,%f", &vex1, &vex2, &w); // （加缓存区边界值）,逗号(英文状态下)分割要在格式化符上有所体现
		std::cout << "输入格式化为：" << i << "\n"; // 0-全没格式化，1-一个格式化，2-两个格式化，3-3个格式化
		std::cout << "\n输入的数据为" << "\n";
		printf_s("%d %d %f", vex1, vex2, w);
		g->adjs[vex1][vex2] = w;
		g->adjs[vex2][vex1] = w; // 二维矩阵对称存储顶点的边权
		// 若建立有向图，则将最后一个赋值语句去掉，可以将w的值设为1，变为无向图
	}
}

// 普通无向图*顶点*的访问
void test15_ADTOfGraph::visitOrdinaryGraph(Graph* g)
{
	int visit[N]; // 辅助数组，标记点是否已经被访问
	std::cout << "\n图g的顶点为：" << "\n";
	for (int i = 0; i < N; ++i)
	{
		std::cout << g->vdxs[i] << " ";
	}
	//delete g; // 释放内存
	std::cout << "图打印完毕" << "\n";
}


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
void test15_ADTOfGraph::BFSTraverseOfGraph()
{

}

// BFS求单源最短路
void test15_ADTOfGraph::BFSMinDistance()
{

}


// DFS - (Depth-Firest-Search,深度优先)
void test15_ADTOfGraph::DFSTraverseOfGraph()
{

}


// 广度优先搜索
bool test15_ADTOfGraph::BFSSearchOfGraph()
{
	bool visited[MaxVertexNum]; // 访问标记数组，标记顶点是否被访问，初始为false，在图的遍历过程中，若vi被访问，则在visited中置vi为true，防止多次访问
	this->BFSTraverseOfGraph();
	return true;
}

// 深度优先搜索
bool test15_ADTOfGraph::DFSSearchOfGraph()
{
	return true;
}



// **图的应用**
// MST - 最小生成树

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

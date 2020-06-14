#pragma once
class test15_ADTOfGraph
{
#define MaxVertexNum 100 // 顶点数目的最大值
	typedef char VertexType; // 顶点的数据类型
	typedef int EdgeType; // 带权图中边上权值的数据类型

	// 邻接矩阵法
	typedef struct MGraph {
		VertexType Vex[MaxVertexNum]; // 顶点表
		EdgeType Edge[MaxVertexNum][MaxVertexNum]; // 邻接矩阵，边表
		int vexNum, arcNum; // 图的当前顶点数和弧数
	};


	// 邻接表法
	typedef struct AdjoinArcNode { // 边表节点
		int adjvex; // 该弧所指向顶点的位置
		struct AdjoinArcNode* next; // 指向下一条弧的指针
		//InfoType info; // 网的边权
	}ArcNode;
	typedef struct VNode { // 顶点表节点
		VertexType data; // 顶点信息
		AdjoinArcNode* first; // 指向第一条依附该顶点的弧的指针
	}VNode, AdjList[MaxVertexNum];
	typedef struct ALGraph { // ALGraph是以邻接表存储的图类型
		AdjList vertices; // 邻接表
		int vexNum, arcNum; // 图的顶点数和弧数
	};

	// 十字链表法
	typedef struct CrossArcNode { // 边表节点
		int tailvex, headvex; // 该弧的头尾节点
		struct CrossArcNode* hlink, * tlink; // 分别指向弧头相同和弧尾相同的节点
		// InfoType info // 相关信息指针
	}CrossArcNode;
	typedef struct VerNode { // 顶点表节点
		VertexType data; // 顶点信息
		CrossArcNode* firestIn, * firestOut; // 指向第一条入弧和出弧
	}VerNode;
	typedef struct GLGraph { // GLGraph是以十字邻接存储的图类型
		VerNode xList[MaxVertexNum]; // 邻接表
		int vexNum, arcNum; // 图的顶点数和弧数
	};

	// 邻接多重表存储
	typedef struct AdjMuArcNode { // 边表节点
		bool mark; // 访问标记
		int iVex, jVex; // 分别指向给弧的两个顶底
		struct AdjMuArcNode* iLink, * jLink; // 分别指向两个顶底的下一条边
		// InfoType info; // 相关指针信息
	};
	typedef struct VeNode { // 顶点表节点
		VertexType data; // 顶底信息
		AdjMuArcNode* firstEdge; // 指向第一条依附该顶点的边
	}VeNode;
	typedef struct AdjoinMultipleListGraph { // AMLGraph是以邻接多重表存储的图类型
		VeNode adjMuList[MaxVertexNum]; // 邻接表
		int vexNum, arcNum; // 图的顶点数和弧数
	};



public:
	void classMain();

	// 邻接矩阵法


};

#include "test17_AlgOfSort.h"
#include <iostream>
#include <string>


// 排序算法
// 插入排序
//		直接插入排序
//		折半插入排序
//		希尔排序
// 交换排序
//		冒泡排序
//		快速排序
// 选择排序
//		简单选择排序
//		堆排序
// 外部排序 - 多路归并排序
//		二路归并排序
// 基数排序
// 外部排序
//		多路平衡归并 - 减少平衡归并中外存读写次数
//		败者树 - 增大归并路数
//		置换/选择排序 - 增大归并段长度来减少归并段个数
//		最佳归并树 - 由长度不等的归并段，进行多路平衡归并
//		
// 各种算法的比较
// 排序算法的应用



void test17_AlgOfSort::classMain()
{
	std::cout << "test17_AlgOfSort" << "\n";

	ElemType comingSortArray[] = { 000,1,4,2,6,3,9,2,5,8 }; // 9个有效数

	int elemNum = 9;
	//this->sirectInsertSort(comingSortArray, elemNum);
	//this->binaryInsertSort(comingSortArray, elemNum);
	this->shellInsertSort(comingSortArray, elemNum);





	std::cout << "排序后元素" << "\n";
	for (int i = 1; i <= 9; i++)
	{
		std::cout << comingSortArray[i].key << " ";
	}

}


// 直接插入排序
// #1 - 找排好的序列中的位置
// #2 - 移动排好的序列
// #3 - 复制元素到排好的序列中
void test17_AlgOfSort::sirectInsertSort(ElemType a[], int n)
{
	int i, j;
	for (i = 2; i <= n; i++) // 依次将 2 到 n 元素 比较/插入到前面已经排序好的序列
	{ // 无序表中
		// 判断相邻两元素是否递增
		if (a[i].key < a[i - 1].key) // 若a[i]小于其前驱，将a[i]插入有序表中(此时插入的位置未知)，不小于表示这两个元素有序
		{
			// 在有序表中查找要插入的位置，插入a[i]
			a[0] = a[i]; // a[0]不存放元素，是哨兵(用来监视需比较元素的相对大小)
			for (j = i - 1; a[0].key < a[j].key; --j) // 从后往前查找待插入的位置(从有序表的尾开始，元素若大于哨兵，则进行移动)
			{ // 有序表中
				a[j + 1] = a[j]; // 向后挪位
			}
			a[j + 1] = a[0]; // 复制到要插入的位置
		}

	}
}

// 折半插入排序
// 在直接插入排序的基础上减少(每趟)比较元素的此时
// #1 - 折半查找排好序列中的位置
// #2 - 移动元素
// #3 - 复制到目标位置
void test17_AlgOfSort::binaryInsertSort(ElemType a[], int n)
{
	int i, j, low, high, mid;
	for (i = 2; i <= n; i++) // 依次将2`n插入到前面拍好的有序递增的序列中
	{ // 无序表中
		a[0] = a[i]; // 哨兵
		low = 1; // 折半查找的范围
		high = i - 1;
		while (low <= high) { // 在有序表中折半查找要插入的位置(high所指向的位置,高 > 低时退出，高(high)为所找位置)
			mid = (low + high) / 2; // 取中间点
			if (a[mid].key > a[0].key)
				high = mid - 1; // 查找左半子表
			else
				low = mid + 1; // 查早右半子表
		}
		for (j = i - 1; j >= high + 1; --j) // 排好的序列统一后移元素(从有序表尾开始到目标位置-1之间的)，空出插入位置
		{
			a[j + 1] = a[j];
		}
		a[high + 1] = a[0]; // 插入操作
	}
}

// 希尔排序
// #1 - 把无需表按照增量分为若干有序表(增量每趟减小)，每个子表内进行直接插入排序
// #2 - 最后对全表进行直接插入排序
void test17_AlgOfSort::shellInsertSort(ElemType a[], int n)
{// 对顺序表，希尔排序可以在直接插入排序的基础上修改而来：
	// @1 - 前后记录位置的增量是dk，不是1
	// @2 - r[0]只是暂存单元，不是哨兵，当j<=0时，表示插入位置已到

	int dk, i, j;
	for (dk = n / 2; dk >= 1; dk = dk / 2) // 步长变化(比如为dk = 5，3，1)
	{
		for (i = dk + 1; i <= n; ++i)
		{ // 构建无序子表(随着dk的减少，无序表元素在增多)
			// 子表为递增
			if (a[i].key < a[i - dk].key) // 无需表间距为dk，找到一个不符合递增的元素，需将a[i]插入到有序增量子表中
			{
				a[0] = a[i]; // 暂存在a[0]中
			}
			// **********？？
			for (j = i - dk; j > 0 && a[0].key < a[j].key; j -= dk) // 从子表的最后一个位置开始向前找要插入 i 的位置，j(寻找指针) <= 0时，插入位置已找到
			{ // 有序子表
				a[j + dk] = a[j]; // 记录后移，查找插入的位置
			}
			a[j + dk] = a[0]; // 插入
		}
	}
}

// 冒泡排序
// #1 - 从前往后相邻的元素两两比较，逆序则交换
// #2 - 最多进行 n - 1 趟，无交换时退出
void test17_AlgOfSort::bubbleSort(ElemType a[], int n)
{
	int i, j;
	bool flag;
	for (i = 0; i < n - 1; i++)
	{
		flag = false; // 表示本趟冒泡是否发生过交换的标记
		for (j = n - 1; j > i; j--) // 一趟冒泡过程(从后往前)
		{
			if (a[j - 1].key > a[j].key) // 若为逆序
			{
				std::swap(a[j - 1], a[j]); // 交换
				flag = true;
			}
		}
		if (flag == false)
			return; // 本趟遍历后没有发生交换，说明表已经有序
	}
}

// 快速排序 - 递归法
// #1 - 取枢轴，把无序表划分为两部分，前部分表所有元素小于枢轴，后部分所有元素大于枢轴
// #2 - 分别对两个子表进行快速排序
void test17_AlgOfSort::quickSort(ElemType a[], int low, int high)
{
	if (low < high) {
		int pivotpos = this->quickSortOfPartition(a, low, high); // 以首元素划分表为两部分子表low,high
		this->quickSort(a, low, pivotpos - 1);
		this->quickSort(a, pivotpos + 1, high);
	}

}


// 快排划分
int test17_AlgOfSort::quickSortOfPartition(ElemType a[], int low, int high)
{
	// 一趟快排的划分算法
	 //ElemType pivot = a[low]; // 当前表中第一个元素设为枢轴值，对表进行划分
	int pivot = a[low].key;
	while (low < high) // 循环跳出条件
	{ // 依次从high，low，high，low交替同枢轴进行比较
		// 先从高位(high)开始比较
		while (low < high && a[high].key >= pivot) {
			--high;
		}
		a[low] = a[high]; // 将比枢轴值小的元素移动到右端
		// 再从低位(low)比较
		while (low < high && a[low].key <= pivot)
		{
			++low;
		}
		a[low].key = pivot; // 枢轴元素存放到最终位置
		return low; // 返回存放枢轴的最终位置
	}
}

// 简单选择排序 - a[]从0开始存放元素
// #1 - 每次从无序表中选最小的，
// #2 - 插入有序表末尾
// #3 - 无序表元素个数为1时结束(为最大)
void test17_AlgOfSort::simpleSelectSort(ElemType a[], int n)
{
	int i, j, min;
	for (i = 0; i < n - 1; i++) // 一共进行 n - 1 趟
	{
		min = i; // 记录最小元素位置
		for (j = i + 1; j < n; j++) // 在无需表a[i...n-1]中选择最小的元素，从头开始
		{
			if (a[j].key < a[min].key) // 比开始的最小元素小，则更新最小元素
			{
				min = j;
			}
			if (min != i) // 最小元素与第i个位置交换(0 - i-1 为有序表)，第一小，第二小，第三小......
			{
				std::swap(a[i].key, a[min].key);
			}
		}
	}
	std::cout << "排序完毕" << "\n";
}

// 堆排序
// #1 - 建立初始堆
// #2 - 输出堆顶元素后，调整堆

// 建立大根堆
void test17_AlgOfSort::buildMaxRootHeap(ElemType a[], int len)
{
	for (int i = len / 2; i > 0; i--) // 从i=[n/2] 到 1，反复调整所有的非终端(叶子)节点
	{
		this->adjustDownOfHeap(a, i, len);
	}
}

// (小元素)向下调堆 - 将元素k为根的子树进行调整为堆
// 子树		    k
//			 /    \
//			2k	  2k+1
void test17_AlgOfSort::adjustDownOfHeap(ElemType a[], int k, int len)
{
	int i;
	a[0] = a[k]; // a[0]暂存根元素
	for (i = 2 * k; i <= len; i *= 2) // 沿key较大的子节点向下筛选()
	{
		if (i < len && a[i].key < a[i + 1].key) // 左孩子 < 右孩子
		{
			i++; // i取key较大的子节点的下标
		}
		if (a[0].key >= a[i].key) // 根元素 > 子节点的最大者(根 > 左右子树)，筛选结束
			break;
		else
		{ // 根不为最大，继续以子树最大节点为根进行调整
			a[k] = a[i]; // 将a[i]调整到双亲(父/根)结点上
			k = i; // 修改k值，以便继续向下筛选
		}
	}
	a[k] = a[0]; // 被筛选结点的值放入最终位置
}

// 插入，删除

// 向上调整堆 - k为向上调整的结点，也是堆的元素个数
void test17_AlgOfSort::adjustUpOfHeap(ElemType a[], int k)
{
	a[0] = a[k];
	int i = k / 2; // 若结点值大于双亲结点，则将双亲结点下调，并继续向上比较
	while (i > 0 && a[i].key < a[0].key) // 循环跳出条件
	{
		a[k] = a[i]; // 双亲结点下调
		k = i;
		i = k / 2; // 继续向上比较
	}
	a[k] = a[0]; // 复制到最终位置
}

// 堆排序
void test17_AlgOfSort::heapSort(ElemType a[], int len)
{
	this->buildMaxRootHeap(a, len); // 建立初始大根堆
	for (int i = len; i > 1; i--) // n-1趟的交换和建堆过程
	{
		std::swap(a[i], a[1]); // 输出堆顶元素(和堆低元素交换)
		this->adjustDownOfHeap(a, 1, i - 1); // 整理，把剩余的i-1个元素整理成堆
	}
	std::cout << "排序结束" << "\n";
}

// 归并排序
// #1 - 分为两个子序列
// #2 - 选择子序列中较大者插入
void test17_AlgOfSort::mergeSort(ElemType a[], int low, int high)
{
	if (low < high)
	{
		int mid = (low + high) / 2; // 从中间划分
		this->mergeSort(a, low, mid); // 对左半部分归并排序
		this->mergeSort(a, mid + 1, high); // 对右半部分归并排序
		this->merge(a, low, mid, high); // 归并
	}
	std::cout << "归并排序完成" << "\n";
}

// 合并
void test17_AlgOfSort::merge(ElemType a[], int low, int mid, int high)
{
	int n = high - low; // 原数组中元素个数
	ElemType* b = (ElemType*)malloc((n + 1.0) * sizeof(ElemType)); // 辅助数组b，大小同原数组
	int i, j, k;
	for (k = low; k <= high; k++)
	{
		b[k] = a[k]; // 将原数组a复制到辅助数组b中
	}
	for (i = low, j = mid + 1, k = i; i < mid && j <= high; k++)
	{
		if (b[i].key < b[j].key)
			a[k] = b[i++]; // 将较小者复制到a中(排序后a中数组为有序的，b会被回收)
		else
			a[k] = b[j++];
	}
	while (i < mid)
		a[k++] = b[i++]; // 若第一个表(前/左半部分)未检测完，其余部分复制到a中
	while (j < high)
		a[k++] = b[j++]; // 若第二个表未检测完，复制到a中
}

// 基数排序
void test17_AlgOfSort::radixSort(ElemType a[], int n)
{

}



// 各内部排序的比较


// 排序的应用

// 外部排序
// 多路归并排序

// 败者树

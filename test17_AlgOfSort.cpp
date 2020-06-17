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

	ElemType comingSortArray[] = { 1,4,2,6,3,9,0,5,8,2 };
	int elemNum = 25;
	this->sirectInsertSort(comingSortArray, elemNum);
	std::cout << "排序后元素" << "\n";
	for (int i = 0; i < elemNum; i++)
	{
		std::cout << comingSortArray[i].key << " ";
	}

}


// 直接插入排序
void test17_AlgOfSort::sirectInsertSort(ElemType a[], int n)
{
	int i, j;
	for (i = 2; i <= n; i++)
	{
		if (a[i].key < a[i - 1].key)
		{
			a[0] = a[i]; // a[0]不存放元素，是哨兵
			for (j = i - 1; a[0].key < a[j].key; --j)
			{
				a[j + 1] = a[j]; // 向后挪位
			}
			a[j + 1] = a[0];
		}

	}
}

// 折半插入排序
void test17_AlgOfSort::binaryInsertSort(ElemType a[], int n)
{
	int i, j, low, high, mid;
	for (i = 2; i <= n; i++)
	{
		a[0] = a[i];
		low = 1;
		high = i - 1;
		while (low <= high) {
			mid = (low + high) / 2;
			if (a[mid].key > a[0].key)
				high = mid - 1;
			else
				low = mid + 1;
		}
		for (j = i - 1; j >= high + 1; --j)
		{
			a[j + 1] = a[j];
		}
		a[high + 1] = a[0];
	}
}

// 希尔排序
void test17_AlgOfSort::shellInsertSort(ElemType a[], int n)
{
	int dk, i, j;
	for (dk = n / 2; dk >= 1; dk = dk / 2)
	{
		for (i = dk + 1; i <= n; ++i)
		{
			if (a[i].key < a[i - dk].key)
			{
				a[0] = a[i];
			}
			for (j = i - dk; j > 0 && a[0].key < a[j].key; j -= dk)
			{
				a[j + dk] = a[j];
			}
			a[j + dk] = a[0];
		}
	}
}

// 冒泡排序
void test17_AlgOfSort::bubbleSort(ElemType a[], int n)
{
	int i, j;
	bool flag;
	for (i = 0; i < n - 1; i++)
	{
		flag = false; // 表示本趟冒泡是否发生过交换的标记
		for (j = n - 1; j > i; j--) // 一趟冒泡过程
		{
			if (a[j - 1].key > a[j].key) // 若位逆序
			{
				std::swap(a[j - 1], a[j]); // 交换
				flag = true;
			}
		}
		if (flag == false)
			return; // 本趟遍历后没有发生交换，说明表已经有序
	}
}

// 快速排序
void test17_AlgOfSort::quickSort(ElemType a[], int n)
{

}

// 快排划分
int test17_AlgOfSort::quickSortOfPartition(ElemType a[], int low, int high)
{
	// 一趟快排的划分算法
	// ElemType pivot = a[low]; // 当前表中第一个元素设为枢轴值，对表进行划分
	int pivot = a[low].key;
	while (low < high)
	{
		while (low < high && a[high].key >= pivot) {
			--high;
		}
		a[low] = a[high];
		while (low < high && a[low].key <= pivot)
		{
			++low;
		}
		a[low].key = pivot;
		return low;
	}
}

// 简单选择排序
void test17_AlgOfSort::simpleSelectSort(ElemType a[], int n)
{
	int i, j, min;
	for (i = 0; i < n - 1; i++)
	{
		min = i;
		for (j = i + 1; j < n; j++)
		{
			if (a[j].key < a[min].key)
			{
				min = j;
			}
			if (min != i)
			{
				std::swap(a[i].key, a[min].key);
			}
		}
	}
	std::cout << "排序完毕" << "\n";
}

// 堆排序
// 建立大根堆
void test17_AlgOfSort::buildMaxRootHeap(ElemType a[], int len)
{
	for (int i = len / 2; i > 0; i--) // 从i=[n/2] ~1，反复调整堆
	{
		this->adjustDownOfHeap(a, i, len);
	}
}

// 向下调堆
void test17_AlgOfSort::adjustDownOfHeap(ElemType a[], int k, int len)
{
	int i;
	a[0] = a[k];
	for (i = 2 * k; i <= len; i *= 2)
	{
		if (i < len && a[i].key < a[i + 1].key)
		{
			i++;
		}
		if (a[0].key >= a[i].key)
			break;
		else
		{
			a[k] = a[i];
			k = i;
		}
	}
	a[k] = a[0]; // 被筛选结点的值放入最终位置
}

// 向上调整堆
void test17_AlgOfSort::adjustUpOfHeap(ElemType a[], int k)
{
	a[0] = a[k];
	int i = k / 2;
	while (i > 0 && a[i].key < a[0].key)
	{
		a[k] = a[i];
		k = i;
		i = k / 2; // 继续向上比较
	}
	a[k] = a[0];
}

// 堆排序
void test17_AlgOfSort::heapSort(ElemType a[], int len)
{
	this->buildMaxRootHeap(a, len);
	for (int i = len; i > 1; i--)
	{
		std::swap(a[i], a[1]);
		this->adjustDownOfHeap(a, 1, i - 1);
	}
	std::cout << "排序结束" << "\n";
}

// 归并排序
void test17_AlgOfSort::mergeSort(ElemType a[], int low, int high)
{
	if (low < high)
	{
		int mid = (low + high) / 2;
		this->mergeSort(a, low, mid);
		this->mergeSort(a, mid + 1, high);
		this->merge(a, low, mid, high);
	}
	std::cout << "归并排序完成" << "\n";
}

// 合并
void test17_AlgOfSort::merge(ElemType a[], int low, int mid, int high)
{
	int n = high - low;
	ElemType* b = (ElemType*)malloc((n + 1) * sizeof(ElemType)); // 辅助数组b
	int i, j, k;
	for (k = low; k <= high; k++)
	{
		b[k] = a[k];
	}
	for (i = low, j = mid + 1, k = i; i < mid && j <= high; k++)
	{
		if (b[i].key < b[j].key)
			a[k] = b[i++];
		else
			a[k] = b[j++];
	}
	while (i < mid)
		a[k++] = b[i++]; // 若第一个表未检测完，复制
	while (j < high)
		a[k++] = b[j++]; // 若第二个表未检测完，复制
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

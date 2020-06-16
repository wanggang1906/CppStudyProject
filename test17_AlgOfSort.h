#pragma once
class test17_AlgOfSort
{

	typedef struct ElemType {
		int key;
	};


public:
	void classMain();

	void sirectInsertSort(ElemType a[], int n);
	void binaryInsertSort(ElemType a[], int n);
	void shellInsertSort(ElemType a[], int n);
	void bubbleSort(ElemType a[], int n);
	void quickSort(ElemType a[], int n);
	int quickSortOfPartition(ElemType a[], int low, int high);
	void simpleSelectSort(ElemType a[], int n);
	void buildMaxRootHeap(ElemType a[], int len);
	void adjustDownOfHeap(ElemType a[], int k, int len);
	void adjustUpOfHeap(ElemType a[], int k);
	void heapSort(ElemType a[], int len);
	void mergeSort(ElemType a[], int low, int high);
	void merge(ElemType a[], int low, int mid, int high);
	void radixSort(ElemType a[], int n);
};

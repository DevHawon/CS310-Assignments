/**
 * For each of the five algorithms, this program will use different input sizes
 * @author : Hawon Oh
 * @version: 1.0
 */
#include <iostream>
#include <time.h>

using namespace std;

void printArray(int array[], int length);
void insertionSort(int array[], int length);
void selectionSort(int array[], int length);
void heapSort(int array[], int length);

void mergeSort(int array[], int begin, int end);
void merge(int array[], int left, int mid, int right);

void quickSort(int array[], int begin, int end);
int partition(int array[], int begin, int end);

unsigned int countQuick = 0;
unsigned int countMerge = 0;

int main()
{
	int numSize = 50000;
	int nums[numSize] ={};
	
	/*
	// already sorted
	for (int i = 0; i < numSize; i++)
	{
		nums[i] = i;
	}
	*/
	
	///*
	// descending order
	for (int i = 0; i < numSize; i++)
	{
		nums[i] = numSize - i;
	}
	//*/
	
	/*
	srand((unsigned int)time(NULL));
	
	for(int i = 0; i < numSize; i++)
	{
		nums[i] = rand();
	}
	*/
	
	
	// printArray(nums, numSize);
	
	//insertionSort(nums, numSize);
	//selectionSort(nums, numSize);
	//heapSort(nums, numSize);
	
	//mergeSort(nums, 0, numSize - 1);
	//cout << countMerge << endl;
	
	quickSort(nums, 0, numSize - 1);
	cout << countQuick << endl;

	// printArray(nums, numSize);
}

// 
void printArray(int array[], int length)
{
	for(int i = 0; i < length; i++)
	{
		cout << array[i] << ' ';
		
		
	}
}

// 
void insertionSort(int array[], int length)
{
	int count = 0;
	int key;
	int j;
	
	for(int i = 1; i < length; i++)
	{
		key = array[i];
		j = i - 1;
		
		while(j > -1 && key < array[j])
		{
			array[j + 1] = array[j];
			
			j--;
			count++;	// step counter, doesn't do anything for the algorithm
		}
		
		
		array[j + 1] = key;
	}
	
	cout << endl << count << endl;
}

// 
void selectionSort(int array[], int length)
{
	int count = 0;
	
	for(int i = 0; i < length - 1; i++)
	{
		int minIndex = i;
		
		// find minimum rom unsorted part of array
		for(int j = i; j < length; j++)
		{
			if(array[j] < array[minIndex])
			{
				minIndex = j;
			}
			
			count++;	// step counter, doesn't do anything for the algorithm
		}
		
		swap(array[i], array[minIndex]);
	}
	
	cout << endl << count << endl;
}

// 
void heapSort(int array[], int length)
{
	int count = 0;
	
	// use Floyd's algorithm to build heap
	for(int i = length - 1; i >= 0; i--)
	{
		// move root to end if needed
		if(array[0] > array[i])
		{
			swap(array[0], array[i]);
		}
		
		int parentIndex = 0;
		int targetIndex = 0;
		
		// re-heapify
		while((2 * parentIndex + 1) < i)
		{
			int leftIndex = 2 * parentIndex + 1;
			int rightIndex = leftIndex + 1;	// 2 * parent + 2
			
			// find index of bigger one out of two children
			if(rightIndex >= i || array[leftIndex] >= array[rightIndex])
			{
				targetIndex = leftIndex;
			}
			else
			{
				targetIndex = rightIndex;
			}
			
			// swap if needed
			if(array[targetIndex] > array[parentIndex])
			{
				swap(array[parentIndex], array[targetIndex]);
				parentIndex = targetIndex;
			}
			else
			{
				break;
			}
			
			count++;
		}
	}
	
	cout << endl << count << endl;
}

// 
void mergeSort(int array[], int begin, int end)
{
	/*
	if(begin >= end)
	{
		return;
	}
	
	int mid = (begin + end) / 2;
	
	mergeSort(array, begin, mid);
	mergeSort(array, mid + 1, end);
	merge(array, begin, end); */
	
	
	
	
	
	// base case
	if (begin >= end)
	{
		
 		return;
	}
 
 	int mid = begin + (end - begin) / 2;
	mergeSort(array, begin, mid);
 	mergeSort(array, mid + 1, end);
 	merge(array, begin, mid, end);
	
}

// 
void merge(int array[], int left, int mid, int right)
{
	int lenL = mid - left + 1;
 	int lenR = right - mid;
 
 	// temp arrays
 	int *arrayLeft = new int[lenL], *arrayRight = new int[lenR];
 
 	// copy data to temp array (left)
 	for(int i = 0; i < lenL; i++)
	{
		arrayLeft[i] = array[left + i];
	}
 	
 	// copy data to temp array (right)
 	for(int j = 0; j < lenR; j++)
	{
		arrayRight[j] = array[mid + 1 + j];
	}
	
	
 	// main merge part
 	int idexSubArrL = 0;
 	int idexSubArrR = 0;
 	int indexMergedArr = left;	
	
 	while(idexSubArrL < lenL && idexSubArrR < lenR)
	{
		// copy temp array (left or right) to the original array
		// element in right array is bigger than left one
 		if (arrayLeft[idexSubArrL] < arrayRight[idexSubArrR]) 
		{
 			array[indexMergedArr] = arrayLeft[idexSubArrL];
 			idexSubArrL++;
			
			countMerge++;
 		}
		// element in left array is bigger than right one
 		else
 		{
 			array[indexMergedArr] = arrayRight[idexSubArrR];
 			idexSubArrR++;
			
			countMerge++;
 		}
		
 		indexMergedArr++;
 	}
	
	// copy left array's remaining element
 	while(idexSubArrL < lenL)
	{
 		array[indexMergedArr] = arrayLeft[idexSubArrL];
 		idexSubArrL++;
 		indexMergedArr++;
 	}
	
 	// copy right array's remaining element
 	while(idexSubArrR < lenR)
	{
 		array[indexMergedArr] = arrayRight[idexSubArrR];
 		idexSubArrR++;
 		indexMergedArr++;
 	}
	
	// delete allocated memories
 	delete[] arrayLeft;
 	delete[] arrayRight;
}

// 
void quickSort(int array[], int begin, int end)
{
	if(begin < end)
	{
		// sort left
		quickSort(array, begin, partition(array, begin, end) - 1);

		// sort right
		quickSort(array, partition(array, begin, end) + 1, end);
	}
}

// partition function is used for quickSort function only
int partition(int array[], int begin, int end)
{
	// first element is the partition value
	int pivot = array[begin];

	int temp = 0; // counter
	for (int i = begin + 1; i <= end; i++)
	{
		if (array[i] <= pivot)
			temp++;
	}

	int pivotIndex = begin + temp;
	
	swap(array[pivotIndex], array[begin]);
	
	// temp (do nothing for the sorting, just to count steps)
	countQuick++;
	
	int i = begin;
	int j = end;

	while (i < pivotIndex && pivotIndex < j)
	{
		while (array[i] <= pivot)
		{
			i++;
		}
		
		while (pivot < array[j])
		{
			j--;
		}

		if (i < pivotIndex && pivotIndex < j)
		{
			swap(array[i], array[j]);
			
			// temp (do nothing for the sorting, just to count steps)
			countQuick++;
		}
		
		i++;
		j--;
	}
	
	return pivotIndex;
}



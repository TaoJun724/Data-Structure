#include<stdio.h>
#include<stdlib.h>
#include<assert.h>



int main()
{
	int arr[] = { 4, 1,6,8,5,2 };  
	int length = sizeof(arr) / sizeof(arr[0]);  
	printf("≈≈–Ú«∞:");   
	for (int i = 0; i<length; i++)   
	{ 
		printf(" %d", arr[i]);
	}	

	//InsertSort(arr, length);  	 
	//ShellSort(arr, length);
	/*Select(arr, length);*/
	/*Select_OP(arr, length);*/
	/*HeapSort(arr, length);*/
	/*RadixSort(arr,length);*/
	/*MergeSort(arr, length);*/
	QuickSort(arr, 0, 5);
	printf("\n≈≈–Ú∫Û:"); 
	for (int i = 0; i<length; i++)    
	{ 
		printf(" %d", arr[i]); 
	}   
	printf("\n");
	system("pause");
	return 0;
}


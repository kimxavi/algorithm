#ifndef __SORT_H_
#define __SORT_H_
#include <stdio.h>

namespace Sort{
	template <class T>
	static void swap(T& a, T& b){
		T tmp = a;a = b;b = tmp;
	};
	template <class T> static void 
	selectionSort(T* array, int size ){
		T min;
		int index;
		for(int i=0;i<size;i++){
			min = array[i];
			index = i;
			for(int j=i; j<size;j++){
				if(min > array[j]){
					index = j;
					min = array[j];
				}
			}
			swap(array[i], array[index]);
		}
	};
	template <class T> static void 
	insertionSort(T* array, int size){
		for(int i = 1; i<size;i++){
			int j = i;
			do{	
				if( array[j] < array[j-1])
					swap(array[j], array[j-1]);
				else
					break;
			}while(--j);
		}
	};
	template <class T> static void 
	bubbleSort(T* array, int size){
		for(int i =0;i <size-1;i++){
			for(int j=0; j<size-1 -i;j++){
				if( array[j] > array[j+1]){
					swap(array[j], array[j+1]);
				}
			}
		}
	};
	template <class T> static void 
	quickSort(T* array, int size){
		if(size > 0){
			int left = 0;
			int right = size;
/*
			int mid = (left + right )/2;
			if(array[mid] < array[left]){
			}else if(array[mid] > array[left]){
			}else{
			}
*/

			T pivot = array[left];

			while(1){
				do{
					left++;
				}while(array[left] < pivot  && left < size );
				do{
					right--;
				}while(array[right] > pivot && right > 0);
				if(left > right) break;
				swap(array[left], array[right]);
			}
			swap(array[0],array[right]);

			quickSort(array,right);
			quickSort(array+right+1 , size -right -1 );
		}
	};
	/*
	static bool mergeSort(){};
	static bool heapSort(){};
	static bool shellSort(){};
	static bool radixSort(){};
	*/
};
#endif

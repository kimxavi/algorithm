#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "Sort.h"

const int size = 1000;
int* array;

#define RANDOM	(0)
#define SORTED	(1)
#define REVERSE (2)

#define SELECTION_SORT 	(0)
#define INSERTION_SORT 	(1)
#define BUBBLE_SORT		(2)
#define QUICK_SORT		(3)

void generateArray(int array_mode){
	array = new int[size];

	for(int i =0; i< size;i++){
		if(array_mode == RANDOM)
			array[i] = random()%100;
		else if(array_mode == SORTED)
			array[i] = i;
		else if(array_mode == REVERSE)
			array[size - i] = i;
	}
}
bool checkSort(){
	for(int i = 0; i<size-1;i++){
		if( array[i] > array[i+1]){
			printf("%d %d %d\n",i,array[i],array[i+1]);
			return false;
		}
	}
	return true;
}
void sortArray(int mode,int array_mode){
	generateArray(array_mode);
	clock_t stime = clock();
	switch(mode){
		case SELECTION_SORT:
			Sort::selectionSort(array,size);
		break;
		case INSERTION_SORT:
			Sort::insertionSort(array,size);
		break;
		case BUBBLE_SORT:
			Sort::bubbleSort(array,size);
		break;
		case QUICK_SORT:
			Sort::quickSort(array,size);
		break;
	}
	clock_t etime = clock();
	
	if(!checkSort())
		printf("-------Sort Fail\n");
	else
		printf("%f]\n",difftime(etime,stime));
	delete [] array;
}

void test(int mode){
	printf("RANDOM[");
	sortArray(mode, RANDOM);
	printf("SORTED[");
	sortArray(mode, SORTED);
	printf("REVERSE[");
	sortArray(mode, REVERSE);
}
void printArray(){
	for(int i=0; i<size; i++)
		printf("%d\n",array[i]);
}

int main(int argc,char** argv){
	/*
	printf("\nSELECTION_SORT\n");
	test(SELECTION_SORT);
	printf("\nBUBBLE_SORT\n");
	test(BUBBLE_SORT);
	*/
	printf("\nINSERTION_SORT\n");
	test(INSERTION_SORT);
	printf("\nQUICK_SORT\n");
	test(QUICK_SORT);

	return 0;
}

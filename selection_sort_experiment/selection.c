#include<stdio.h>
#include<stdlib.h>

#define length(x) (int)(sizeof(x)/sizeof(int))

void swap(int *num1,int *num2){

	int temp;
	temp = *num1;
	*num1 = *num2;
	*num2 = temp;
	
}

void selection(int arr[],int len){

	for(int outerloop = len  - 1;outerloop > 0;outerloop--){


	int position = 0;

	for(int innerloop = 1;innerloop <= outerloop;innerloop++)
		if(arr[innerloop]  > arr[position])
			position = innerloop;

	swap(&arr[position],&arr[outerloop]);
		
	}
	
}

void printArray(int arr[],int len){

	for(int index = 0;index < len ;index++)
		printf("index[%d] = %d\n",index,arr[index]);

	
}

int main(void){

	int array[] = {9,90,40,60,12,34,56};

	printf("before\n");
	printArray(array,length(array));

	selection(array,length(array));

	printf("after\n");
	printArray(array,length(array));

	return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void mergesort(int* arr, int* reg, int start, int end){
	// reg: save the sorted num sub-array
	if (start == end) return;
	int mid = (start+end)/2;
	int start1 = start, end1 = mid;
	int start2 = mid + 1, end2 = end;
	mergesort(arr, reg, start1, end1);
	mergesort(arr, reg, start2, end2);

	int k = start;
	while (start1 <= end1 && start2 <= end2){ 
		// compare two array, save smaller int to reg[], 'till one of them is done
		if (arr[start1] < arr[start2])
			reg[k++] = arr[start1++];
		else
			reg[k++] = arr[start2++];
	}
	// finish the remaining part
	while (start1 <= end1)
		reg[k++] = arr[start1++];
	while (start2 <= end2)
		reg[k++] = arr[start2++];
	// copy the sorted array to the original one
	for (int i = start; i <= end; i++){
		arr[i] = reg[i];
	}
}

int main(int argc, char* argv[]){
	int len = atoi(argv[1]);
	//int len;
	if (len <= 0) return 1;
	int* arr = malloc(sizeof(int) * len);
	//int arr[] = {83, 86, 77, 15, 93}; 
	//len = sizeof(arr)/sizeof(arr[0]);
	srand(time(0));
	for (int i = 0; i < len; i++){
		arr[i] = rand() % 100;
		printf("%d ", arr[i]);
	}
	putchar('\n');
	int* reg = malloc(sizeof(int)*len);
	mergesort(arr, reg, 0, len-1);	
	for (int i = 0; i < len; i++){
		printf("%d ", arr[i]);
	}
	putchar('\n');
}

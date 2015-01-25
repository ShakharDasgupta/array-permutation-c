#include <stdio.h>

void permute(int *, int, int);
void swap(int *, int *);
void printArray(int *, int);

int main() {
	int n, i;
	printf("Enter limit: ");
	scanf("%d", &n);
	int arr[n];
	for(i=0; i<n; i++) {
		printf("Enter number: ");
		scanf("%d", arr+i);
	}
	printf("\nPermutations:\n");
	permute(arr, 0, n);
}

void permute(int *arr, int i, int length) {
	if(i==length) {
		printArray(arr, length);
		return;
	}
	int j;
	for(j=i; j<length; j++) {
		swap(arr+i, arr+j);
		permute(arr, i+1, length);
		swap(arr+i, arr+j);
	}
}

void swap(int *a, int *b) {
	int t = *a;
	*a = *b;
	*b = t;
}

void printArray(int *arr, int length) {
	printf("[%d", *arr);
	int i;
	for(i=1; i<length; i++)
		printf(", %d", *(arr+i));
	printf("]\n");
}

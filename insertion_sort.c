#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void insertionSort(int * a, int n) {
	int i, j, k;
	for(i=1; i<n; i++) {
		k = a[i];
		j=i-1;
		while(j>=0 && a[j] > k) {
			a[j+1] = a[j];
			j= j-1;
		}
		a[j+1] = k;
	}
}

int * generateArray(int n) {
	int * t = malloc( n * sizeof(int) );
	if(t) {
		for(int i=0; i<n; i++) {t[i] = rand()%1000;}
	}
	return t;
}

void printArray(int *a, int n) {
	printf("Array = ");
	for(int i=0; i<n; i++) {
		printf( i?", %d":"%d", a[i]);
	}
	printf(".\n");
}

void printArray1(int *a, int n) {
	for(int i=0; i<n; i++) {
		printf(" %d ", a[i]);
	}
}

int main(int argc, char **argv) {
	int * a;
	int n = 10;

	srand(time(NULL));

	a = generateArray(n);
	printArray(a,n);
	insertionSort(a,n);
	printArray(a,n);
	getch();
	free(a);
	return 0;
}
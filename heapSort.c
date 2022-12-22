#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 1000

typedef struct heap{ 
    int data[MAX];
    int n;
} heap;

void swap(int *a, int *b){ 
    int t = *a; 
    *a = *b;
    *b = t; 
}
void siftdown(heap *maxHeap, int x){
    int maxkid;
    int i = x;
    while((i*2 < maxHeap->n)){ 
        if(i*2 == maxHeap->n-1){ 
            maxkid = i*2;
        }
        else if(maxHeap->data[i*2] > maxHeap->data[i*2+1]){
            maxkid = i*2;
        }
        else
        { 
            maxkid = i*2+1;
        }

        if(maxHeap->data[i] < maxHeap->data[maxkid])
        {
            swap(&maxHeap->data[i], &maxHeap->data[maxkid]);
            i = maxkid;
        }
        else{
            break;
        }
    }
}


int * generateArray(int n) {
    int * t = malloc( n * sizeof(int) );
    if(t) { 
        for(int i=0; i<n; i++) {t[i] = rand()%50;
        }
    }
    return t;
}

void printArray(int *a, int n) {
	for(int i=0; i<n; i++) {
		printf(" %d ", a[i]);
	}
}

void createHeap(heap *maxHeap, int *a, int n){
    if(n > MAX){
        printf("array is very big");
        return;
    }
    for(int i=0; i<n; i++){
        maxHeap->data[i+1] = a[i];
    }
    maxHeap->n = n;
    for(int i=n/2; i>=1; i--){
        siftdown(maxHeap, i);
    }
}

void heapsort(heap *maxHeap, int *a, int n){
    for (int i = n - 1; i > 0; i--) {
        swap(&maxHeap->data[0], &maxHeap->data[i]);
        siftdown(maxHeap, 1);
        a[i] = maxHeap->data[i];
    }
    a[0] = maxHeap->data[0];
}

int main(){
    int n = 30;
    srand(time(NULL)); 
    int *a  = generateArray(n); 
    heap *maxHeap = malloc(sizeof(heap)); 
    createHeap(maxHeap, a, n); 
    heapsort(maxHeap, a, n);
    printArray(a, n);
    free(maxHeap);
    free(a);
getchar();
    return 0; 
}

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct heap{ 
    int data[MAX];
    int n;
}heap;

void swap(int *a, int *b){ 
    int t = *a; 
    *a = *b;
    *b = t; 
}

void siftdown(heap *maxHeap, int x){
    int t; 
    int d = 0;
    int maxkid;
    int i;
    while((i*2 <= maxHeap->n) && (!d)){ 
        if(i*2 == maxHeap->n){ 
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
            t = maxHeap->data[i];
            maxHeap->data[i] = maxHeap->data[maxkid];
            maxHeap->data[maxkid] = t;
            i = maxkid;
        }
        else{
            d = 1;
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
    for(int i=n/2; i>0; i--){
        siftdown(maxHeap, i);
    }
}

void heapsort(heap *maxHeap, int *a, int n){
    for (int i = n - 1; i >= 0; i--) {
        swap(&maxHeap->data[0], &maxHeap->data[i]);
        siftdown(maxHeap, 1);
        }
}

int main(){
    int n = 30;
    srand(time(NULL)); 
    int *a  = generateArray(n); 
    heap *maxHeap = malloc(sizeof(heap)); 
    createHeap(maxHeap, a, n); 
    heapsort(maxHeap, a, n);
printArray(a, n);
    return 0; 
}

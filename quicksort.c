#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}


int partition(int a[], int low, int high)
{
    int pivot = a[low];
    int i = low;
    for (int j = low+1; j <= high; j++) {
        if (a[j] < pivot) {
            i++; // increment index of smaller element
            swap(&a[i], &a[j]);
        }
    }
    swap(&a[i], &a[low]);
    return (i + 1);
}


void quickSort(int a[], int low, int high)
{
    if (low < high) {
        int p = partition(a, low, high);
        quickSort(a, low, p - 1);
        quickSort(a, p + 1, high);
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

int main(int argc, char **argv) {
    int * a;
    int n = 10;

    srand(time(NULL));

    a = generateArray(n);
    if (a == NULL) {
        printf("Error: memory allocation failed.\n");
        return 1;
    }

    printArray(a,n);
    quickSort(a, 0, n-1);
    printArray(a,n);

    printf("Press any key to continue...\n");
    getchar();

    free(a);
    return 0;
}

#include <iostream>
#include <time.h>
#include "Merge.h"
int main() {
    srand(time(NULL));
    clock_t t1;
    int size = rand()%1000;
    printf("%d\n", size);
    int* array=(int*)malloc(size*sizeof(int));
    for (int i=0; i<size; i++){
        array[i] = rand()%1000;
    }
    printf("\n");
    t1=clock();
    int* newarr = Merge(array,size);
    t1=clock()-t1;
    printf("It took the Merge algorithm %f seconds\n", ((float)t1)/CLOCKS_PER_SEC);
    printf("\n");

    for (int i=0; i<size; i++) printf("%d ", newarr[i]);
    free(newarr);
    return 0;
}
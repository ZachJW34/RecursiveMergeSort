//
// Created by ZachJ on 10/19/2017.
//
#include "Merge.h"
int* Merge(int* array, int size){
    if (size == 0 | size == 1) return array;
    int* newarr = (int*)malloc(size*sizeof(int));
    int* ptr = Mergealg(array, newarr, size);
    if (ptr == array) free(newarr);
    else if (ptr == newarr) free(array);
    return ptr;
}

int* Mergealg(int* array, int* newarr, int size){
    int* ptr1;
    int* ptr2;
    int mod=0;
    if (size == 3){
        int temp;
        int* ptr = array;
        for (int i=0; i<2; i++){
            if (ptr[i] > ptr[i+1]){
                temp = ptr[i];
                ptr[i] = ptr[i+1];
                ptr[i+1] = temp;
            }
        }
        if (ptr[0] > ptr[1]){
            temp = ptr[0];
            ptr[0] = ptr[1];
            ptr[1] = temp;
        }
        return ptr;
    }
    else if (size <=2){
        if (array[0] > array[1]){
            int temp1;
            temp1 = array[0];
            array[0] = array[1];
            array[1] = temp1;
            return array;
        }
        else {
            return array;
        }
    }
    else{
        ptr1 = Mergealg(array, newarr, size/2);
        if (size%2 == 1) {
            ptr2 = Mergealg(&array[size / 2], &newarr[size / 2], size / 2 +1);
            mod=1;
        }
        else ptr2 = Mergealg(&array[size / 2], &newarr[size / 2], size / 2);

    }
    int j=0;
    int k=0;
    if (ptr1 == array && ptr2 == &newarr[size/2]) {
        for (int i=0; i<size/2; i++) newarr[i] = ptr1[i];
        ptr1 = newarr;
    }
    if (ptr1 == newarr && ptr2 == &array[size/2]) {
        for (int i=0; i<size/2; i++) array[i] = ptr1[i];
        ptr1 = array;
    }
    if (ptr1 == array && ptr2 == &array[size/2]){
        for (int i = 0; i < size; i++) {if (((ptr1[j] < ptr2[k]) | (k==(size/2+mod))) & j<(size/2)) {
                newarr[i] = ptr1[j];
                j++;
            }
            else{
                newarr[i] = ptr2[k];
                k++;
            }
        }
        return newarr;
    }
    else if (ptr1 == newarr && ptr2 == &newarr[size/2]){
        for (int i = 0; i < size; i++) {
            if (((ptr1[j] < ptr2[k]) | (k==(size/2+mod))) & j<(size/2)) {
                array[i] = ptr1[j];
                j++;
            }
            else{
                array[i] = ptr2[k];
                k++;
            }
        }
        return array;
    }
}
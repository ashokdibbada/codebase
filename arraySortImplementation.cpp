#include <iostream>
#include <stdlib.h>
#include <new>
/*** C++ arrays and pointers can be used vice versa ****/
using namespace std;

void insertionSort(int* ptr, int number);
void bubbleSort(int* ptr, int number);
void selectionSort(int* ptr, int number);
void mergeSort(int* ptr,int low,int high);
void mergeBoth(int* ptr,int low,int mid,int high);
int pivotIndexGen(int* ptr,int low,int high);
void quickSort(int* ptr,int low,int high);

int number;
int main(){

    int* ptr;
    cout<<"Enter No. of Numbers: ";
    cin>>number;
    int arr[number];
    for(int i=0;i<number;i++){
        cin>>arr[i];
    }
    quickSort(arr,0,number-1);
//    mergeSort(arr,0,number-1);
//    selectionSort(arr,number);
//   bubbleSort(arr,number);
//    insertionSort(arr,number);
    for(int element:arr){
        cout<<element<<endl;
    }
    return 0;
}

void insertionSort(int* ptr,int number){
    cout<<"Insertion Sort"<<endl;
    for(int i=0;i<number-1;i++){
        for(int j=i+1;j<number;j++){
            if(*(ptr+i) > *(ptr+j)){
                *(ptr+i) = *(ptr+i) + *(ptr+j);
                *(ptr+j) = *(ptr+i) - *(ptr+j);
                *(ptr+i) = *(ptr+i) - *(ptr+j);
            }
        }
    }
}

void bubbleSort(int* ptr, int number){
    cout<<"Bubble Sort"<<endl;
    int j=0;
    while(j<number){
    for(int i=0;i<number-1;i++){
        if(*(ptr+i) > *(ptr+i+1)){
            *(ptr+i) = *(ptr+i) + *(ptr+i+1);
            *(ptr+i+1) = *(ptr+i) - *(ptr+i+1);
            *(ptr+i) = *(ptr+i) - *(ptr+i+1);
            }
    }
    j++;
    }
}

void selectionSort(int* ptr,int number){
    int swapper =0,place;
    cout<<"Selection Sort"<<endl;
    for(int i=0;i<number-1;i++){
        place = 0;
        swapper = *(ptr+i);
        for(int j=i+1;j<number;j++){
            if(*(ptr+j) < swapper){
                swapper = *(ptr+j);
                place = j;
            }
        }
        if(place > 0){
            *(ptr+place) = *(ptr+i);
            *(ptr+i) = swapper;
        }
    }
}

void mergeSort(int* ptr,int low,int high){
    if(high>low){
        int mid = (low+high-1)/2;
        mergeSort(ptr,low,mid);
        mergeSort(ptr,mid+1,high);
        mergeBoth(ptr,low,mid,high);
    }
}

void mergeBoth(int* ptr,int low,int mid,int high){
    int n1 = (mid-low) +1;
    int n2 = (high-mid);
    int left[n1];
    int right[n2];
    for(int i=0;i<n1;i++){
        left[i] = ptr[low+i];
    }
    for(int i=0;i<n2;i++){
        right[i] = ptr[mid+1+i];
    }
    int i=0,j=0,k=low;
    while(i<n1 && j< n2){
        if(left[i] < right[j]){
            ptr[k] = left[i];
            k++;
            i++;
        }
        else{
            ptr[k] = right[j];
            k++;
            j++;
        }
    }
    while(i<n1){
        ptr[k] = left[i];
        i++;
        k++;
    }
    while(j <n2){
        ptr[k] = right[j];
        j++;
        k++;
    }
}

void quickSort(int* ptr,int low,int high){
    if(high>low){
        int pIndex = pivotIndexGen(ptr,low,high);
        quickSort(ptr,low,pIndex-1);
        quickSort(ptr,pIndex+1,high);
    }
}

int pivotIndexGen(int* ptr,int low,int high){
    int pivot = ptr[high];
    int i = low;
    int j = high -1;
    while(j >= i){
        if(pivot > ptr[j]){
            int swapper = ptr[j];
            ptr[j] = ptr[i];
            ptr[i] = swapper;
            i++;
        }
        else{
        j--;
        }
    }
    ptr[high] = ptr[i];
    ptr[i] = pivot;
    return i;
}


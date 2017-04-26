#include <iostream>
#include <stdlib.h>
#include <new>
#include <math.h>
/*** C++ arrays and pointers can be used vice versa ****/
using namespace std;

void insertionSort(int* ptr, int number);
void bubbleSort(int* ptr, int number);
void selectionSort(int* ptr, int number);
void mergeSort(int* ptr, int low, int high);
void mergeBoth(int* ptr, int low, int mid,int high);
int Partition(int* ptr,int low,int high);
void quickSort(int* ptr, int low,int high);


// Search Algorithms
void binarySearch(int* ptr,int low,int high,int element);

int main(){
    int number,method,element;
    int* ptr;
    cout<<"Enter No. of Numbers: ";
    cin>>number;
    int arr[number];
    for(int i=0;i<number;i++){
        cin>>arr[i];
    }
    cout<<"Enter Sorting Method: \n 1: Insertion Sort \n 2: BubbleSort \n 3: SelectionSort \n 4: MergeSort \n 5: QuickSort \n"<<endl;
    cin>>method;
    if(method == 1){
        cout<<"Sorting using InsertionSort:"<<endl;
        insertionSort(arr,number);
    }
    if (method == 2){
    cout<<"Sorting using BubbleSort:"<<endl;
        bubbleSort(arr,number);
    }
    if (method == 3){
         cout<<"Sorting using SelectionSort:"<<endl;
        selectionSort(arr,number);
    }
    if(method == 4){
        cout<<"Sorting using MergeSort:"<<endl;
        mergeSort(arr,0,number-1);
    }
    if(method == 5){
        cout<<"Sorting using QuickSort:"<<endl;
        quickSort(arr,0,number-1);
    }
    for(int element:arr){
        cout<<element<<endl;
    }
    cout<<"Enter an element to search: ";
    cin>>element;
    binarySearch(arr,0,number,element);
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
    int n1 = mid-low+1;
    int n2 = high-mid;
    int L[n1] ,R[n2];
    for(int i=0;i<n1;i++){
        L[i] = *(ptr+low+i);
    }
    for(int i=0;i<n2;i++){
        R[i] = *(ptr+mid+1+i);
    }
    int i=0,j=0,k=low;
    while(i < n1 && j < n2){
        if(L[i] < R[j]){
            *(ptr+k) = L[i];
            i++;
        }
        else{
            *(ptr+k) = R[j];
            j++;
        }
        k++;
    }
    while(i<n1){
        *(ptr+k) = L[i];
        i++;
        k++;
    }
    while(j<n2){
        *(ptr+k) = R[j];
        j++;
        k++;
    }
}

void quickSort(int* ptr,int low,int high){
    int pIndex =0;
    if(high>low){
        pIndex = Partition(ptr,low,high);
        quickSort(ptr,low,pIndex-1);
        quickSort(ptr,pIndex+1,high);
    }
}

int Partition(int* ptr,int low,int high){
    int pilot = *(ptr+high);
    int pIndex = low;
    for(int i=low;i<high;i++){
        if(*(ptr+i) < pilot){
            int swapper = *(ptr+pIndex);
            *(ptr+i) = swapper;
            *(ptr+pIndex) = *(ptr+i);
            pIndex ++;
        }
    }
    int swapper = *(ptr+pIndex);
    *(ptr+pIndex) = ptr[high];
    *(ptr+high) = swapper;
    return pIndex;
}

void binarySearch(int* ptr,int low,int high,int element){
    if(high > low){
        int mid = (low+high-1)/2;
        if(ptr[mid] == element){
            cout<<"Element found at :";
            cout<<mid;
            return;
        }
        else if(ptr[mid] < element){
            binarySearch(ptr,mid+1,high,element);
        }
        else{
            binarySearch(ptr,0,mid-1,element);
        }
    }
    else{
        cout<<"Not found";
    }
};

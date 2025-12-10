#include <iostream>
using namespace std;

void Merge(int arr[5], int big, int mid, int End){
    int temp[5];
    int i=big;
    int j=mid+1;
    int index=0;
    while((i<=mid)&&(j<=End)){
    if (arr[i]<arr[j]){
        temp[index]=arr[i];
        i++;
    }
    else{
        temp[index]=arr[j];
        j++;
    }
    index++;
    }
    if (i>mid){
        while (j<=End){
            temp[index]=arr[j];
            index++;
            j++;
        }
    }
    else{
        while (i<=mid){
            temp[index]=arr[i];
            index++;
            i++;
        }
    }
    int k=0;
    while (k<index){
        arr[big + k]=temp[k];
        k++;
    }
}

void merge_sort(int arr[5],int big, int End){
    int mid;
    if(big<End){
        mid=(big+End)/2;
    
    merge_sort(arr,big,mid);
    merge_sort(arr,mid+1,End);
    Merge(arr,big ,mid, End);
}}


int main(){
    int arr[5]={39,9,23,67,2};
    merge_sort(arr,0,4);
    for(int i=0; i<5;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}

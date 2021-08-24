#include<iostream>

using namespace std;

void fillArr(int arr[], int s);

void printArr(int arr[], int s);

void fillArrs(int arr[][3], int r, int c);

void printArrs(int arr[][3], int r, int c);


int main(){
    int arr[5], arrs[4][3];
    fillArr(arr, 5);
    printArr(arr, 5);
    cout<<endl<<endl;
    fillArrs(arrs, 4, 5);
    printArrs(arrs, 4, 5);

    return 0;
}


void fillArr(int arr[], int s){
    for(int i=0;i<s;i++){
        arr[i] = s;
    }
}
void printArr(int arr[], int s){
    for(int i=0;i<s;i++){
        cout<<arr[i]<<" ";
    }
}

void fillArrs(int arr[][3], int r, int c){
    for(int i=0;i<r;i++){
       for(int j=0;j<c;j++){
            arr[i][j] = 3;
        }
    }
}


void printArrs(int arr[][3], int r, int c){
    for(int i=0;i<r;i++){
       for(int j=0;j<c;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
}

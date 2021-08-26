// *****************************************************
// Name:  Janet Jenkins
// Class: CS 255-01
// Date: August 24,2021
// Assignment: In-class Exercise
// Description: A series of functions
//     to manipulate arrays (1-D and 2-D)
// *****************************************************

#include <iostream>
#include <fstream>

using namespace std;
// *****************************************************
// Constants
// *****************************************************
const int MAX = 10;
const int ROW = 10;
const int COL = 10;

// *****************************************************
// Function Declarations (Prototype, Header)
// *****************************************************
void FillArray(int ar[], int& size);
void PrintArray(int list[], int size);
void FillMatrix(int mat[][COL], int &row, int& col);
void PrintMatrix(int mat[][COL], int row, int col);

// *****************************************************
// Driver
// *****************************************************

int main(){
    int arr[MAX], size=0;

    FillArray(arr, size);
    PrintArray(arr, size);

    int arr2[3][10], r=3, c=10;
    FillMatrix(arr2, r, c);
    PrintMatrix(arr2, r, c);

	return 0;
}


// *****************************************************
// Function Definitions (Implementation)
// *****************************************************

// *****************************************************
// Function Name: FillArray
// Incoming Parameters: NA
// Outgoing Parameters: Modified Integer array
//                      modified array size
// Return Value: NA
// Description: Function to randomly generate the usable
// size of the array and fill the array with items
// randomly in the range of [0..20]
// *****************************************************

void FillArray(int ar[], int& size){
	size = rand()% MAX + 1;
	for (int i = 0; i < size; i++)
		ar[i] = rand()% 21;
}

void PrintArray(int list[], int size){
    for(int i=0;i<size;i++){
        cout<<list[i]<<" ";
    }
    cout<<endl;
}

void FillMatrix(int mat[][COL], int &row, int& col){

    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            mat[i][j] = rand() % 21 + 1;
        }
    }

    ofstream wfile;
    wfile.open("check.txt");
    if(!wfile.fail()){
        wfile<<row<<" "<<col<<endl;
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                wfile<<mat[i][j]<<" ";
            }
            wfile<<"\n";
        }
    }else cout<<"Check";
    wfile.close();
}

void PrintMatrix(int mat[][COL], int &row, int& col){
    ifstream rfile;
    rfile.open("check.txt");
    int temp;
    if(!rfile.fail()){
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                rfile>>temp;
                cout<<temp<<" ";
            }
            cout<<endl;
        }
    }else cout<<"Error"<<endl;
    rfile.close();
}

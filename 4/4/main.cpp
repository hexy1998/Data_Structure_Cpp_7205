//Xinyang He
//001059405
//Notice: use g++ -std=c++11 to compile

#include <iostream>
#include <random>
#include <fstream>//To create .txt
#include <stdexcept>

using namespace std;

int moves = 0;//Global variable
int comps = 0;

void insertionSort(int arr[], int n){//Insertion sort
    moves = 0;//Initialize counter
    comps = 0;
    for (int i = 1; i < n; i++){//Sort every integer
        int tmp = arr[i];
        int j = i - 1;
        while (j >= 0){//Make sure arr[j] exist
            comps ++;
            if (arr[j] > tmp){
                moves++;
                arr[j + 1] = arr[j];//Move larger integer to the later space
                j--;
            }else
                break;
        }
        arr[j + 1] = tmp;//Fill small integer to the right space
    }
}

void heapify(int arr[], int n, int i){//A part of heap sort
    int max = i; //Initialize max as root
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    
    comps ++;
    if (l < n && arr[l] > arr[max])//If left child is larger than root
        max = l;
    
    comps ++;
    if (r < n && arr[r] > arr[max])//If right child is larger than max so far
        max = r;
    
    if (max != i) {//If max is not root
        swap(arr[i], arr[max]);
        moves += 3;
        heapify(arr, n, max);//Recursive
    }
}

void heapSort(int arr[], int n){//Heap sort
    moves = 0;
    comps = 0;
    for (int i = n / 2 - 1; i >= 0; i--)//Build heap
        heapify(arr, n, i);
    
    for (int i = n - 1; i >= 0; i--) {//Extract each element from heap
        swap(arr[0], arr[i]);//Move root to end
        moves += 3;
        heapify(arr, i, 0);//Make max heapify again
    }
}

int partition(int A[], int p, int r) {//Part of quick sort
    int x = A[r];//The last integer
    int i = p - 1;//i start before 0
    for (int j = p; j < r; j++) {
        comps ++;
        if (A[j] <= x) {//Compare each integer with A[r]
            i = i + 1;
            swap(A[i], A[j]);//Make integers larger or smaller than A[r] in different side
            moves += 3;
        }
    }
    swap(A[i + 1], A[r]);//Put A[r] in relatively correct space
    moves += 3;
    return i + 1;

}
void quickSort(int A[], int p, int r) {//Quick sort
    if (p < r){
        int q = partition(A, p, r);
        quickSort(A, p, q - 1);//Recursive
        quickSort(A, q + 1, r);
    }
}

void check(int arr[], int n){//Check if the array is sorted
    int flag = 0;
    for(int i = 0; i < n - 1; i++){
        if(arr[i] > arr[i+1]){
            flag = 1;//Unsorted flag
            cout << "The array is unsorted" << endl;
            break;
        }
    }
    if(flag == 0){//Sorted flag
        cout << "The array is sorted" << endl;
    }
}

int main() {
    random_device e;//Create random number
    mt19937 gen(e());
    uniform_int_distribution<> num(1, 100000);
    
    int n = 1000;//Array size
    int BST[n], AVG[n], WST[n];
    int BST2[n], AVG2[n], WST2[n];
    int BST3[n], AVG3[n], WST3[n];
    BST[0] = 0;//Give initial value
    AVG[0] = num(gen);
    WST[0] = 10000;
    
    BST2[0] = 0;//Give initial value
    AVG2[0] = num(gen);
    WST2[0] = 10000;
    
    BST3[0] = 0;//Give initial value
    AVG3[0] = num(gen);
    WST3[0] = 10000;
    
    for (int i = 1; i < n; i++){//Create arrays
        BST[i] = BST[i - 1] + 10;
        WST[i] = WST[i - 1] - 10;
        AVG[i] = num(gen);
        
        BST2[i] = BST[i];//Copy to ensure same test arrays
        WST2[i] = WST[i];
        AVG2[i] = AVG[i];
        
        BST3[i] = BST[i];//Copy to ensure same test arrays
        WST3[i] = WST[i];
        AVG3[i] = AVG[i];
    }
   
    ofstream outf;//Create txt file
    outf.open("sort.txt");
    if (outf.fail()) {
        cerr << "Error: Could not open output file\n";//Wrong output
        exit(1);
    }
   
    cout << "Insertion Sort:"<< endl;//Output result
    insertionSort(BST, n);
    cout << "Best "<< endl << "moves: " << moves <<" comps: "<< comps << endl;
    check(BST, n);//Check result
    outf << "Insertion Sort:"<< endl;
    outf << "Best "<< endl << "moves: " << moves <<" comps: "<< comps << endl;
    insertionSort(AVG, n);
    cout << "Average "<< endl << "moves: " << moves <<" comps: "<< comps << endl;//Output result
    check(AVG, n);//Check result
    outf << "Average "<< endl << "moves: " << moves <<" comps: "<< comps << endl;
    insertionSort(WST, n);
    cout << "Worst "<< endl << "moves: " << moves <<" comps: "<< comps << endl;//Output result
    check(WST, n);//Check result
    outf << "Worst "<< endl << "moves: " << moves <<" comps: "<< comps << endl;
    outf << endl;
    cout << endl;
    
    cout << "Heap Sort:"<< endl;//Output result
    heapSort(BST2, n);
    cout << "Best "<< endl << "moves: " << moves <<" comps: "<< comps << endl;
    check(BST2, n);//Check result
    outf << "Heap Sort:"<< endl;
    outf << "Best "<< endl << "moves: " << moves <<" comps: "<< comps << endl;
    heapSort(AVG2, n);
    cout << "Average "<< endl << "moves: " << moves <<" comps: "<< comps << endl;//Output result
    check(AVG2, n);//Check result
    outf << "Average "<< endl << "moves: " << moves <<" comps: "<< comps << endl;
    heapSort(WST2, n);
    cout << "Worst "<< endl << "moves: " << moves <<" comps: "<< comps << endl;//Output result
    check(WST2, n);//Check result
    outf << "Worst "<< endl << "moves: " << moves <<" comps: "<< comps << endl;
    outf << endl;
    cout << endl;
    
    cout << "Quick Sort:"<< endl;//Output result
    moves = 0;
    comps = 0;
    quickSort(BST3, 0, n - 1);
    cout << "Best "<< endl << "moves: " << moves <<" comps: "<< comps << endl;//Output result
    check(BST3, n);
    outf << "Quick Sort:"<< endl;
    outf << "Best "<< endl << "moves: " << moves <<" comps: "<< comps << endl;//Output result
    moves = 0;
    comps = 0;
    quickSort(AVG3, 0, n - 1);
    cout << "Average "<< endl << "moves: " << moves <<" comps: "<< comps << endl;//Output result
    check(AVG3, n);
    outf << "Average "<< endl << "moves: " << moves <<" comps: "<< comps << endl;//Output result
    moves = 0;
    comps = 0;
    quickSort(WST3, 0, n - 1);
    cout << "Worst "<< endl << "moves: " << moves <<" comps: "<< comps << endl;//Output result
    check(WST3, n);
    outf << "Worst "<< endl << "moves: " << moves <<" comps: "<< comps << endl;//Output result
    outf << endl;
    cout << endl;
    
    //printA(WST, n);
    //printA(BST, n);
    //printA(AVG, n);
    
    
    outf.close(); //Close the file at the end of program
    
    return 0;
}

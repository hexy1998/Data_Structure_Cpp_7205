////Xinyang He
////001059405
////
////Notice:
////Please compile with -std=c++11 or -std=gnu++11 after g++
//
//#include <iostream>
//#include <random>//For creating random number
//#include <limits>//For using INT_MAX
//#define INT_MAX 2147483647
//using namespace std;
//
////void merge(int A[], int p, int q, int r);
////void mergeSort(int A[], int p, int r);
//
//void merge1(int A[], int p, int q, int r){//To merge two sorted array
//    int n1 = q - p + 1;//Length of left part of array
//    int n2 = r - q;//Length of right part of array
//    int *L = new int[n1 + 1];//Empty left sorted array
//    int *R = new int[n2 + 1];//Empty right sorted array
//
//    for(int i = 0; i < n1; i++){//Fill the value of L[] from A[]'s left part
//        L[i] = A[p + i];
//    }
//    for(int j = 0; j < n2; j++){//Fill the value of R[] from A[]'s right part
//        R[j] = A[q + j + 1];
//    }
//
//    L[n1] = INT_MAX;//In merge1, an extra integer is used at the end of L[] and R[] to avoid the pointer point to null. And because the value is larger than any other integers, it will not bother the sorting logic.
//    R[n2] = INT_MAX;
//
//    int i = 0;//Set the initial value of loop
//    int j = 0;
//
//    for(int k = p; k <= r; k++){
//        if(L[i] <= R[j])
//            A[k] = L[i++];//Fill A[] with smaller integer
//        else
//            A[k] = R[j++];
//    }
//    delete[] L;//Release dynamic array
//    delete[] R;
//}
//
//void merge2(int A[], int p, int q, int r){//To merge two sorted array
//    int n1 = q - p + 1;//Length of left part of array
//    int n2 = r - q;//Length of right part of array
//    int *L = new int[n1];//Empty left sorted array
//    int *R = new int[n2];//Empty right sorted array
//
//    for(int i = 0; i < n1; i++){//Fill the value of L[] from A[]'s left part
//        L[i] = A[p + i];
//    }
//    for(int j = 0; j < n2; j++){//Fill the value of R[] from A[]'s right part
//        R[j] = A[q + j + 1];
//    }
//
//    int i = 0;//Set the initial value of loop
//    int j = 0;
//    int k = p;
//
//    while(i < n1 && j < n2){//Make sure L[i] and R[j] have value
//        if(L[i] <= R[j])
//            A[k++] = L[i++];//Fill A[] with smaller integer
//        else
//            A[k++] = R[j++];
//    }
//
//    while(i < n1)//After comparing, fill A[] with remaining integer
//        A[k++] = L[i++];
//
//    while(j < n2)
//        A[k++] = R[j++];
//
//    delete[] L;//Release dynamic array
//    delete[] R;
//}
//
//void mergeSort(int A[], int p, int r){//Make A[] sorted
//    if(p<r){
//        int q = (p+r)/2;
//        mergeSort(A, p, q);//Make left part sorted
//        mergeSort(A, q + 1, r);//Make right part sorted
//        merge1(A, p, q, r);//Merge two arrays
//    }
//
//}
//

//
//
//
//int main() {
//    int n;//length of A[]
//    cout<<"imput n between (1,50]:";
//    cin>>n;//Input n
//    while(n <= 1 || n > 50){//Input again when input wrong number
//        cout<<"Wrong input!"<<endl;
//        cout<<"imput n between (1,50]:";
//        cin>>n;
//    }
//    int *A = new int[n];//Create dynamic array, A[]
//
//    default_random_engine e;//Create random number
//    uniform_int_distribution<unsigned> u(0, 100);//Random number is between 0 and 100
//
//    for(int i = 0; i < n; i++){//Fill A[] with random number
//        A[i] = u(e);
//    }
//
//    int p = 0;//Left
//    int r = n - 1;//Right
//
//    mergeSort(A,p,r);//Call function
//
//    for(int i = 0; i < n; i++){//Output sorted array
//        cout<<A[i]<<endl;
//    }
//
//    delete []A;//Release A[]
//
//    return 0;
//}


#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <vector>

using namespace std;

long long cache(long long cache1, long long cache2) {
    for (long long i = cache1 * 2; i < cache1 * 2 + cache2 * 3; i ++) {
        if (i / 2 + i / 3 - i / 6 == cache1 + cache2)
            return i;
    }
//    if (cache1 * 2 > cache2 * 3) {
//        long long res = (cache2/2 + cache1) * 2;
//        return res;
//    }
//    else {
//        long long res = cache2 * 3;
//        return res;
//    }
    return -1;
}

int T;

int main() {

    cin >> T; long long n, m;
    while (T--) {
        cin >> n >> m;
        cout << cache(n, m) << endl;
    }

    return 0;
}



//Xinyang He
//001059405
//Problem 3

#include <iostream>
using namespace std;

// INSERTION‐SORT
void insertionSort(int arr[],string name[],int n)
{
    if(arr[0]>100 || arr[0]<0)
        arr[0]=0;
    for (int i = 1; i < n; i++) {//compare every number to the before list
        int j=i;
        if(arr[i]>100 || arr[i]<0)//if score illegal,change it to 0
            arr[i]=0;
        while(j>0 && arr[j-1]<arr[j]){
            int arr_now = arr[j];//intermediate variables for score
            string name_now = name[j];//intermediate variables for name
            arr[j] = arr[j-1];//change the score
            name[j]=name[j-1];
            arr[j-1] = arr_now;//change the name
            name[j-1]= name_now;
            j--;//keep cycle
        }
        
    }
}

int main()//main fuction
{
    int n;//Total Number of Student
    cout << "Total Number of Student：";
    cin >> n;
    int arr[n];//save students' score
    string name[n];//save students' name
    
    cout << "Student name and score(Sample:A 70 B 50 C 90...):"<<endl;
    for (int i = 0; i < n; i++) {
        cin >> name[i] >> arr[i];//input name and score
    }
    
    cout << endl;
    
    insertionSort(arr, name, n);//use fuction
    
    cout << "Final list：" << endl;
    for (int i = 0; i < n; i++){
        cout << name[i] << " "<<arr[i]<<endl;//output name and score
    }
    
    return 0;
}

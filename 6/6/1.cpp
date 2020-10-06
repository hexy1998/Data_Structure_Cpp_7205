//  Xinyang He
//  001059405
//  Notice: Using -std=c++11 to compile

#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <stack>
#include <iterator>
#include <algorithm>
using namespace std;

// To determine if value > 50
template <typename T>

bool larger_50(T value){
    return value > 50;
}

int main() {
    // Initialize vector, list and stack
    vector<int> v10 {14, 18, 6, 16, 8, 20, 4, 10, 12, 2};
    list<int> l10;
    stack<int> s10;
    
    // Copy vector to list
    copy(v10.begin(), v10.end(), back_inserter(l10));
    
    // Copy vector to stack
    for (int i = 0; i < v10.size(); i++){
        s10.push(v10[i]);
    }
    
    // Initialize priority_queue and copy vector to priority_queue
    priority_queue<int> pq10 {less<int>(),v10};
    
    // Add 40 on vector
    for (int i = 0; i < v10.size(); i++){
        v10.at(i) += 40;
    }
    
    // Find 44 in vector
    vector <int>::iterator ele44 = find(v10.begin(), v10.end(), 44);
    if( ele44 != v10.end() ){
        long p44 = distance(v10.begin(),ele44);
        cout << "Value  "<< *ele44 <<"  find in the vector at position: " <<p44 + 1 <<endl;
    }
    
    // Find first element larger than 50
    vector <int>::iterator ele50 = find_if(v10.begin(), v10.end(), larger_50<int>);
    if( ele50 != v10.end() ){
        long p44 = distance(v10.begin(),ele50);
        cout <<"The first element larger than 50 at position: " <<p44 + 1 << endl;
    }
    
    // Determine if every element in vector is larger than 45
    
    bool busy = true;
    for (int i = 0; i < v10.size(); i++){
        if(v10.at(i) <= 45){
            busy = false;
        }
    }
    // Determine if all elements in vector are greater than 45.
    switch(busy)
    {
        case true :
            cout << "All elements in vector are greater than 45." << endl;
            break;
        case false :
            cout << "Not all elements in vector are greater than 45." << endl;
            break;
    }
            
    
    // Pring vector
    cout << "Print vector: "<< endl;
    for (int i = 0; i < v10.size(); i++){
        cout << v10.at(i) << " ";
    }
    
    cout << endl;
    
    // Add and print list
    cout << "Print list: "<< endl;
    while(!l10.empty()){
        l10.front() += 30; // Add
        cout<< l10.front()<<" "; // Print
        l10.pop_front();
    }
    cout << endl;
    
    // Add and print stack
    cout << "Print stack: "<< endl;
    while(!s10.empty()){
        s10.top() += 20; // Add
        cout << s10.top() << " "; // Print
        s10.pop();
    }
    cout << endl;
    
    // Add and print priority_queue
    cout << "Print priority_queue: "<< endl;
    while(!pq10.empty()){
        int tmp = pq10.top();// Add
        tmp += 10;
        pq10.pop();
        pq10.push(tmp);
        cout << pq10.top() << " "; // Print
        pq10.pop();
    }
    cout << endl;
    
    return 0;
}

//  Xinyang He
//  001059405
//  Using -std=c++11 to compile


#include <iostream>
#include <math.h>
#include <limits.h>
#include <time.h>
#include <stdio.h>

using namespace std;

// Recursive function
int cut_rod_recursive(int p[], int n){
    if (n == 0)
        return 0;
    int q = INT_MIN;
    //Save the largest benefit
    for(int i = 1; i <= n; i++){
        q = max(q, p[i] + cut_rod_recursive(p, n - i));
    }
    return q;
}

// DP sub-function
int cut_rod_dp_aux(int p[], int n, int r[]){
    if(r[n] >= 0){
        return r[n];
    }
    //Give 'q' initial value
    int q;
    if(n == 0){
        q = 0;
    }else{
        q = INT_MIN;
    }
    //Save the largest benefit by recursion
    for(int i = 1; i <= n; i++){
        q = max(q, p[i] + cut_rod_dp_aux(p, n - i, r));
    }
    r[n] = q;
    return q;
}

// DP function
int cut_rod_dp(int p[], int n){
    int r[n + 1];
    for(int i = 0; i <= n; i++){
        r[i] = INT_MIN;
    }
    // Using DP sub-fuction
    return cut_rod_dp_aux(p, n, r);
}

int main(){
    // Lengths
    int length[10] = {5, 10, 15, 20, 25, 30, 35, 40, 45, 50};
    for(int j = 0; j < 10; j++){
        int n = length[j];
        // Benefit of each length
        int p[n + 1];
        p[1] = 2;
        for(int i = 2; i < n; i++){
            p[i] = floor(i * 2.5);
        }
        p[n] = n * 2.5 - 1;
        
        // Print for test
        cout << "Rod size: " << length[j] << endl;
        
        // To save running time
        clock_t t;
        
        // Because Recursive inplementation runs more than 3 min at the size of 35, so only use it until size of 30.
        if(j < 6){
            cout << "Use recursion: ";
            t = clock();
            // Use Recursive function
            int res_recur = cut_rod_recursive(p, n);
            t = clock() - t;
            cout << res_recur << endl;
            printf ("It took %d clicks (%f seconds).\n",t,((float)t)/CLOCKS_PER_SEC);
        }
        
        // Use DP
        cout << "Use DP: ";
        t = clock();
        int res_dp = cut_rod_dp(p, n);
        t = clock() - t;
        // Print result
        cout << res_dp << endl;
        printf ("It took %d clicks (%f seconds).\n",t,((float)t)/CLOCKS_PER_SEC);
        cout << endl;
    }
    return 0;
}

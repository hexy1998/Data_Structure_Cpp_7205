//Xinyang He
//001059405
//Problem 2

# include <iostream>
using namespace std;
int main ()
{
    int x = 1, y = 9;
    int *p1, *p2;
    p1 = &x;
    p2 = &y;
    
    int **q1,**q2;//secondary pointer
    q1 = &p1;
    q2 = &p2;
    int *t = *q1;//swap p1 and p2 by change the direction of q1 and q2
    *q1=*q2;
    *q2=t;

    cout << *p1 << " and " << *p2 << endl; // Prints "9 and 1"
    return 0;
}

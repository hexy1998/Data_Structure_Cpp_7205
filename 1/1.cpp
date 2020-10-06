//Xinyang He
//001059405
//Problem 1

# include <iostream>
using namespace std;

void SwapP(int *a,int *b){// pass‐by‐pointer
    int c;
    c=*a;//&c point to *a
    *a=*b;//a point to *b
    *b=c;//b point to c, c=*a
}

void SwapR(int &a,int &b){// pass‐by‐reference
    int c;//intermediate variables
    c=a;
    a=b;
    b=c;
}

int main(){//main fuction
    int m1,n1;
    cout<<"Please print for test SwapP:";
    cin>>m1>>n1;
    SwapP(&m1,&n1);//get value from address
    cout<<m1<<" "<<n1<<endl;
    
    int m2,n2;
    cout<<"Please print for test SwapR:";
    cin>>m2>>n2;
    SwapR(m2,n2);//when a change, m2 change; when b change n2 change
    cout<<m2<<" "<<n2<<endl;
    
    return 0;
}

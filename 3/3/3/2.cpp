//001059405
//Xinyang He
//
//Notice: compile with -std=c++11

#include <iostream>
#include <random>//create random number
#include <string>
using namespace std;

int hresult(int date[1000],int p){//calculation in hash table
    int hash1[p][50];//create hash table
    int key[1000];//key value
    int maxslot = -1;//initial maximum
    int minslot = 51;//initial minimum
    double meanslot = 0;//initial mean
    double varislot = 0;//initial variance
    for(int i = 0; i < 1000; i++){
        key[i] = date [i] % p;//calculate key value
    }
    int slot[p];//storage slot of each key value
    for(int i = 0; i < p; i++){
        slot[i] = 0;//initial value
        for(int j = 0; j < 1000; j++){
            if(key[j] == i){
                hash1[i][slot[i]] = date[j];//put the date into hash table
                slot[i]++;//count slot
            }
        }
        maxslot = max(maxslot, slot[i]);//get maximum
        minslot = min(minslot, slot[i]);//get minimum
        meanslot += slot[i];
    }
    meanslot /= p;//get mean
    
    for(int i = 0; i < p; i++){
        varislot += (slot[i]-meanslot) * (slot[i]-meanslot);
    }
    varislot /= p;//get variance
    
    cout<< "For m = " << p <<endl
    << "MAX:" << maxslot << " MIN:" << minslot
    << " MEAN:" << meanslot << " VARIANCE:" <<varislot
    << endl<<endl;//print result
    return 0;
}

int main(){
    int date[1000];//create date
    string Date[1000];//create string date
    
    //random part
    random_device e;
    mt19937 gen(e());
    uniform_int_distribution<> m(1, 12);//create random month
    uniform_int_distribution<> d(1, 28);//create random day
    uniform_int_distribution<> y(0, 4);//create random year
    
    for (int i=0; i<1000; i++) {//create 1000 date
        date[i] = m(gen) * 10000 + d(gen) * 100 + y(gen);//create date
        Date[i] = to_string(date[i]);
        if(date[i] < 100000){//add '0' in front of date
            Date[i] = "0" + to_string(date[i]);
        }
    }

    hresult(date, 64);//m1
    hresult(date, 66);//m2
    hresult(date, 67);//m3
    hresult(date, 59);//m4

    return 0;
}

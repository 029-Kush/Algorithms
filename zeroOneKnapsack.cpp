#include<iostream>
#include<cmath>
#include<queue>
#include<vector>
#include<climits>
using namespace std;

int cap = 50;
int wt[] = {10,20,50};
int val[] = {60,100,120};
int n = 3;

int find(int ind, int cap){
    if(ind == 0){
        if(wt[0] <= cap)
            return val[0];
        return 0;
    }

    int notinc = 0 + find(ind-1, cap);

    int inc = INT_MIN;
    if(wt[ind] <= cap)
        inc = val[ind] + find(ind-1, cap - wt[ind]);

    return (inc > notinc ? inc : notinc);
}

int main(){
    cout << find(n-1, cap);
    return 0;
}
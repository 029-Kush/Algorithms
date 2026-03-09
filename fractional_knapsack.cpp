#include<iostream>
#include<stdio.h>
#include<cmath>
using namespace std;

typedef struct Node{
    int val, w; // val - Value and w - Weight
    float ratio;
}Item;

void init(Item a[], int n){
    for(int i = 0; i < n; i++){
        a[i].ratio = a[i].val/(float)a[i].w; //In an array of items, start iterating form the first element with its value and weight, then find the ratio between them till all the ratios are found
    }

    for(int i = 0; i < n; i++){ //Arrange the data in decreasing order using selection sort
        int min = i; //Assuming the first selected item is the greatest in weight
        for(int j=i+1; j<n; j++){
            if(a[j].ratio > a[min].ratio)
                min = j;
        }
        Item temp = a[i];
        a[i] = a[min];
        a[min] = temp;
    }
}

void print(Item a[], int n){
    for(int i = 0; i < n; i++)
        cout<<a[i].w<<" With value: "<<a[i].val << "\n";
}

void change(Item a[], int n, int c){
    double amt = 0;

    for(int i = 0; i < n; i++){
        if(c != 0){
            if(a[i].w <= c){        // take full item
                amt += a[i].val;
                c -= a[i].w;        // reduce capacity
            }
            else{                   // take fractional item
                amt += a[i].ratio * c;
                c = 0;
            }
        }
    }

    cout << amt;
}
    

int main(){
    int cap = 50, n = 3;

    Item arr[] = {{60,10},{100,20},{120,30}};

    init(arr,n);
    print(arr,n);
    change(arr, n, cap);
}
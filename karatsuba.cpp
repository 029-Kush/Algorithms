#include<iostream>
#include<cmath>
using namespace std;


//Define a function to store the logic behind karatsuba's algo
int karat(int a, int b){
        string as = to_string(a); //Integer concatination isn't possible hence convert int to string
        string bs = to_string(b);
        int a_len = as.length();
        int b_len = bs.length();
        if(a_len && b_len == 1){ //If its a single digit number then do normal multiplication
            return a*b;
        }
        else{
            int n = a_len>=b_len?a_len:b_len; //Check which number has a bigger length and make the lengths equal for both the numbers if there is such a case

            while(a_len!=n){ //If "a" is shorter than "b" then add  "0" at the start of "a" till its length matches with "b"
                as = "0" + as;
                a_len++;
            }

            
            while(b_len!=n){ //If "b" is shorter than "a" then add "0" at the start of "b" till its length matches with "a"
                bs = "0" + bs;
                b_len++;
            }

            int al = stoi(as.substr(0,n/2)); //First half of "a"
            int ar = stoi(as.substr(n/2,n-n/2)); //Second half of "a"
            int bl = stoi(bs.substr(0,n/2)); // First half of "b"
            int br = stoi(bs.substr(n/2,n-n/2)); // Second half of "b"

            int m = ceil(n/2.0);
            int x1 = karat(al,bl); // al x bl
            int x2 = karat((al+ar),(bl+br)); // (al+ar) x (bl+br)
            int x3 = karat(ar,br); // ar x br

            int product = x1 * pow(10,2*m) + (x2-x1-x3) * pow(10,m) + x3;
            return product;
        }

    }

    int main(){
        cout << karat(1234,5678);
        return 0;
    }
#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;

int cross(int a[], int low, int mid, int high){
    int s = 0, left = INT_MIN;

    for(int i = mid; i >= low; i--){
        s += a[i];
        if(s > left){
            left = s;
        }
    }

    s = 0;
    int right = INT_MIN;

    for(int i = mid + 1; i <= high; i++){
        s += a[i];
        if(s > right){
            right = s;
        }
    }

    return (left + right);
}

int partsum(int a[], int low, int high){
    if(low == high){
        return a[low];
    }

    int mid = (low + high) / 2;

    int ls = partsum(a, low, mid);
    int rs = partsum(a, mid + 1, high);
    int cs = cross(a, low, mid, high);

    return max(max(ls, rs), cs);
}

int main(){
    int a[] = {-3,1,-8,4,-1,2,1,-5,5};

    cout << partsum(a,0,8);

    return 0;
}
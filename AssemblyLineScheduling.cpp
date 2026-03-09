#include<iostream>
using namespace std;

int main(){

    int a[2][5] = {{2,5,9,3,1}, {1,2,9,12,8}};   // station times
    int t[2][5] = {{0,2,3,2,3}, {0,5,3,3,1}};    // transfer times
    int c[2] = {3,2};                            // entry times
    int x[2] = {2,4};                            // exit times

    int n = 5;

    int dp[2][5];
    int path[2][5];

    dp[0][0] = c[0] + a[0][0];
    dp[1][0] = c[1] + a[1][0];

    path[0][0] = 0;
    path[1][0] = 1;

    for(int j = 1; j < n; j++){

        int first = dp[0][j-1] + a[0][j];
        int second = dp[1][j-1] + t[1][j] + a[0][j];

        if(first <= second){
            dp[0][j] = first;
            path[0][j] = 0;
        }
        else{
            dp[0][j] = second;
            path[0][j] = 1;
        }

        first = dp[1][j-1] + a[1][j];
        second = dp[0][j-1] + t[0][j] + a[1][j];

        if(first <= second){
            dp[1][j] = first;
            path[1][j] = 1;
        }
        else{
            dp[1][j] = second;
            path[1][j] = 0;
        }
    }

    int cost1 = dp[0][n-1] + x[0];
    int cost2 = dp[1][n-1] + x[1];

    int finalCost;
    int line;

    if(cost1 <= cost2){
        finalCost = cost1;
        line = 0;
    }
    else{
        finalCost = cost2;
        line = 1;
    }

    cout<<"Minimum cost of assembly = "<<finalCost<<"\n";

    cout<<"Optimal path (line at each station):\n";

    int stations[5];
    stations[n-1] = line;

    for(int j = n-1; j > 0; j--){
        stations[j-1] = path[stations[j]][j];
    }

    for(int j = 0; j < n; j++){
        cout<<"Station "<<j+1<<" -> Line "<<stations[j]+1<<"\n";
    }

    return 0;
}
#include <iostream>
using namespace std;
#define n 5
int adj[n][n] = {
        { 0,1,1,0,0 },
        { 1,0,1,0,1 },
        { 1,1,0,1,1 },
        { 0,0,1,0,1,},
		{ 0,1,1,1,0 },
    };
int color[n];
int m = 3;

bool isSafe(int v, int c)  //v=0,c=1
{
    for (int i = 0; i < n; i++)
        if (adj[v][i] && c == color[i])
            return false;
    return true;
}

bool solve(int v)
{
      if (v == n)
        return true;
    for (int i = 1; i <= m; i++)  //try coloring vertex v with different colors
    {
        if (isSafe(v,i)) {
            color[v] = i;
            if (solve( v + 1) == true) 
                return true;
            color[v] = 0; //backtrack
        }
    }  
    return false;
}
  
void print()
{
    cout << "assigned colors are \n";
    for (int i = 0; i < n; i++)
        cout << "vertex "<<i <<" -> " <<color[i] << "\n "; 
}
int main()
{
    for (int i = 0; i < n; i++)
        color[i] = 0;
    if (solve(0) == false) 
        cout << "Solution does not exist";
    else
      print();
    return 0;
}
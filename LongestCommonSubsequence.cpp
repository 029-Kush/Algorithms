#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    string s1 = "longest";
    string s2 = "stone";

    int m = s1.size();
    int n = s2.size();

    int dp[m+1][n+1];
    int seq[m+1][n+1];

    for(int i = 0; i <= m; i++)
        for(int j = 0; j <= n; j++)
        {
            dp[i][j] = 0;
            seq[i][j] = 0;
        }

    for(int i = 1; i <= m; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            if(s1.at(i-1) == s2.at(j-1))
            {
                dp[i][j] = 1 + dp[i-1][j-1];
                seq[i][j] = 3;   // diagonal
            }
            else
            {
                int first = dp[i][j-1];
                int second = dp[i-1][j];

                dp[i][j] = (first > second ? first : second);
                seq[i][j] = (first > second ? 1 : 2);
                // 1 = left
                // 2 = top
            }
        }
    }

    for(int i = 0; i <= m; i++)
    {
        for(int j = 0; j <= n; j++)
        {
            cout << dp[i][j] << " ";
        }
        cout << "\n";
    }

    cout << "seq\n";

    for(int i = 0; i <= m; i++)
    {
        for(int j = 0; j <= n; j++)
        {
            cout << seq[i][j] << " ";
        }
        cout << "\n";
    }

    int last = seq[m][n];
    string substring = "";

    int i = m, j = n;

    while(i != 0 && j != 0)
    {
        if(last == 3)
        {
            substring.append(s1.substr(i-1,1));
            i--;
            j--;
        }
        else if(last == 1)
            j--;
        else if(last == 2)
            i--;

        last = seq[i][j];
    }

    cout << "common subsequence before reversing is " << substring << "\n";

    reverse(substring.begin(), substring.end());

    cout << "common subsequence after reversing is " << substring;
}
#include <bits/stdc++.h>
#define prime 13
using namespace std;

int main()
{
    string s = "ABCCDDAEFGCDDF";
    string p = "CDD";   // fixed quotes

    int plen = p.length();
    int slen = s.length();

    int ph = 0, sh = 0, h = 1, maxchar = 10;

    for(int i = 0; i < plen - 1; i++)
        h = (h * maxchar) % prime;

    for(int i = 0; i < plen; i++)
    {
        ph = (ph * maxchar + p[i] - 65 + 1) % prime;
        sh = (sh * maxchar + s[i] - 65 + 1) % prime;
    }

    cout << "hash value of the window " << s.substr(0, plen) << " is " << sh << endl;

    for(int i = 0; i <= slen - plen; i++)
    {
        if(ph == sh)
        {
            int count = 0;
            for(int j = 0; j < plen; j++)
            {
                if(s[i + j] == p[j])
                    count++;
                else
                    break;
            }

            if(count == plen)
                cout << "Pattern occurs at index: " << i << endl;
        }

        if(i < slen - plen)
        {
            sh = ((sh - (s[i] - 65 + 1) * h) * maxchar + (s[i + plen] - 65 + 1)) % prime;

            while(sh < 0)
                sh += prime;

            cout << "hash value of the window " << s.substr(i + 1, plen) << " is " << sh << endl;
        }
    }

    return 0;
}
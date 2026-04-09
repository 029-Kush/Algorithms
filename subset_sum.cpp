#include <iostream>
#include <stack>
using namespace std;

bool first = true;
int a[] = {10, 20, 50, 60, 80};
int n = 5, targetsum = 80;
stack<int> stck;
bool found = false;

void print()
{
    stack<int> temp;

    while (!stck.empty())
    {
        temp.push(stck.top());
        stck.pop();
    }

    cout << '\n';

    while (!temp.empty())
    {
        cout << temp.top() << " ";
        stck.push(temp.top());
        temp.pop();
    }
}

void solve(int currsum, int ind)
{
    if (currsum > targetsum)
        return;

    if (currsum == targetsum && first != true)
    {
        found = true;
        print();
        return;
    }

    if (first == true)
        first = false;

    for (int i = ind; i < n; i++)
    {
        stck.push(a[i]);
        solve(currsum + a[i], i + 1);
        stck.pop();
    }
}

int main()
{
    solve(0, 0);

    if (found == false)
        cout << "No Solution";

    return 0;
}
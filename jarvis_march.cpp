#include <iostream>
using namespace std;

struct Point {
    int x, y;
};

int dir(Point i, Point j, Point k)
{
    int result = (j.x - i.x) * (k.y - i.y) - (j.y - i.y) * (k.x - i.x);
    if (result == 0) return 0;
    return (result > 0) ? 1 : 2;
}

void convexhull(Point P[], int n)
{
    if (n < 3) return;

    int left = 0;
    for (int i = 1; i < n; i++) {
        if (P[i].x < P[left].x)
            left = i;
    }

    int Prev = left, curr;

    do {
        cout << "(" << P[Prev].x << ", " << P[Prev].y << ")" << endl;

        curr = (Prev + 1) % n;

        for (int i = 0; i < n; i++) {
            if (dir(P[Prev], P[curr], P[i]) == 2)
                curr = i;
        }

        Prev = curr;

    } while (Prev != left);
}

int main()
{
    cout << "Name: Kush Gupta" << endl;
    cout << "Registration Number: 24BCE2336" << endl;

    Point P[] = {{0,0}, {4,0}, {2,4}, {2,2}};
    int n = 4;

    convexhull(P, n);

    return 0;
}
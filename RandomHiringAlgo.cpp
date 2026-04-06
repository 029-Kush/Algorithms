#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

struct cand
{
    int rank, interview_status;
};

int main()
{
    cout << "Name: Kush Gupta" << endl;
    cout << "Registration Number: 24BCE2336" << endl;

    int n, nr_hired = 0;
    n = 8;

    struct cand c[] = {{6,0}, {4,0}, {12,0}, {11,0}, {13,0}, {10,0}, {15,0}, {8,0}};

    int best = -1;
    srand(time(0));
    int index;

    for(int i = 0; i < n; i++)
    {
        do {
            index = rand() % n;
        } while(c[index].interview_status == 1);

        c[index].interview_status = 1;

        if(best == -1 || c[index].rank > c[best].rank){
            best = index;
            nr_hired += 1;
        }
    }

    cout << nr_hired << endl;
    cout << best << " " << c[best].rank << endl;

    return 0;
}
// Ömer Mesud TOKER
// 21302479 - Section 2

#include "MaxSubsequenceSum.h"
#include <iostream>
#include <ctime>   // time()
#include <cstdlib> // srand(), rand()

using namespace std;

int main() {
    srand( time( NULL));

    const int N = 490000000;   // size of the array

    int *arr = new int[N];
    int sign;
    for( int i = 0; i < N; i++) {
        sign = rand() % 2;    // rand between 0(-) and 1(+)
        if( sign)
            arr[i] = sign * rand();
        else
            arr[i] = -1 * rand();
    }

    // Store the starting time
    double duration;
    clock_t startTime;
/*
    // N^3
    startTime = clock();
    sum_N3_Algorithm( arr, N);
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << "O(N^3) execution took " << duration << " milliseconds." << endl;

    // N^2
    startTime = clock();
    sum_N2_Algorithm( arr, N);
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << "O(N^2) execution took " << duration << " milliseconds." << endl;
*/
    // NlogN
    startTime = clock();
    sum_NlogN_Algorithm( arr, N);
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << "O(NlogN) execution took " << duration << " milliseconds." << endl;

    // N
    startTime = clock();
    sum_N_Algorithm( arr, N);
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << "O(N) execution took " << duration << " milliseconds." << endl;

    return 0;
}

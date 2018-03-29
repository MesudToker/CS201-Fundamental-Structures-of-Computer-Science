#ifndef MAX_SUBSEQUENCE_SUM
#define MAX_SUBSEQUENCE_SUM

#include <iostream>
#include <algorithm> // for max function

using namespace std;

// O(N^3) solution
int sum_N3_Algorithm( int* &arr, int size) {
    int maxSum, sum = 0;
    for( int i = 0; i < size; ++i, sum = 0)
        for( int j = i; j < size; ++j) {
            for( int k = i; k <= j; ++k)
                sum += arr[k];
            if( sum > maxSum)
                maxSum = sum;
        }
    return maxSum;
}

// O(N^2) solution
int sum_N2_Algorithm( int* &arr, int size) {
    int maxSum, sum = 0;
    for( int i = 0; i < size; ++i, sum = 0)
        for( int j = i; j < size; ++j)
        {
            sum += arr[j];
            if( sum > maxSum)
                maxSum = sum;
        }
    return maxSum;
}

// maxSumRec for NlogN solution
int maxSumRec( int* &arr, int left, int right) {
    if( left == right) {

        if( arr[left] > 0)
            return arr[left];
        else
            return 0;
    }
    int center = left / 2 + right / 2;
    int leftMaxSum = maxSumRec( arr, left, center);
    int rightMaxSum = maxSumRec( arr, center + 1, right);

    int leftBorderMaxSum , leftBorderSum = 0;
    for( int i = center; i >= left; --i) {
        leftBorderSum += arr[i];
        if( leftBorderSum > leftBorderMaxSum)
            leftBorderMaxSum = leftBorderSum;
    }

    int rightBorderMaxSum, rightBorderSum = 0;
    for( int i = center + 1; i <= right; ++i) {
        rightBorderSum += arr[i];
        if( rightBorderSum > rightBorderMaxSum)
            rightBorderMaxSum = 0;
    }
    return max( leftMaxSum, max( leftBorderMaxSum + rightBorderMaxSum, rightMaxSum));
}
//O(NlogN) solution
int sum_NlogN_Algorithm( int* &arr, int size) {
    return maxSumRec( arr, 0, size - 1);
}
// O(N) solution
int sum_N_Algorithm( int* &arr, int size) {
    int maxSum, cur;
    maxSum = cur = 0;
    for( int i = 0; i < size; ++i) {
        cur += arr[i];
        if( cur > maxSum)
            maxSum = cur;
        else if( cur < 0)
            cur = 0;
    }
    return maxSum;
}

#endif // MAX_SUBSEQ_SUM

#include <bits/stdc++.h> 
using namespace std;

long long Merge(long long *arr, long long low, long long mid, long long high)
{
    long long i = low;
    long long j = mid + 1;
    vector<long long> temp;

    long long count = 0;

    while(i <= mid && j <= high)
    {
        if(arr[i] < arr[j])
        {
            temp.push_back(arr[i++]);
        }
        else
        {
            temp.push_back(arr[j++]);
            count += mid - i + 1;
        }
    }

    while(i <= mid)
    {
        temp.push_back(arr[i++]);
    }

    while(j <= high)
    {
        temp.push_back(arr[j++]);
    }

    for(long long i = low; i <= high; i++)
    {
        arr[i] = temp[i - low];
    }

    return count;
}

long long MergeSort(long long *arr, long long low, long long high)
{
    long long count = 0;
    if(low < high)
    {
        long long mid = (low + high)/2;

        count += MergeSort(arr, low, mid);
        count += MergeSort(arr, mid + 1, high);
        count += Merge(arr, low, mid, high);
    }

    return count;
}

long long getInversions(long long *arr, int n){
    // Write your code here.
    return MergeSort(arr, 0, n - 1);
}
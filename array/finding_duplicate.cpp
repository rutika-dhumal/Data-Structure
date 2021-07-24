// finding duplicate elements in sorted array

// make changes in it not working
#include <iostream>
using namespace std;

void find_duplicate(int *A, int n)
{
    int i;
    int lastdup = 0;
    for (i = 0; i < n; i++)
    {
        if (A[i] == A[i + 1] && A[i] != lastdup)
        {
            cout << A[i];
            lastdup = A[i];
        }
    }
}

// to count no. of duplicates
void duplicate_count(int A[], int n)
{
    int i;
    int count = 0; // to store the count of element;
    int val;       // to store a element
    for (i = 0; i < n; i++)
    {
        if (A[i] == A[i + 1])
        {
            count++;
            val = A[i];
        }
    }
    count++; // for last element
    cout << "\nrepeated element is : " << val;
    cout << "\ncount is : " << count;
}

//find duplicate element and count it using hashing

void dup_hash(int *A, int n)
{
    int i;
    // int h[];
    for (i = 0; i < n; i++)
    {
    }
    cout << i;
    // for (i = 0; i < n; i++)
    // {
    //     h[A[i]]++;
    // }
    // for (i = 0; i <= n; i++)
    // {
    // }
}
int main()
{
    int n = 5;
    int A[n] = {1, 2, 2, 2, 3, 4};
    duplicate_count(A, n);
    // find_duplicate(A, n);
    // dup_hash(A, n);
    return 0;
}
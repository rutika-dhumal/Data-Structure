#include <iostream>
using namespace std;

void Merge(int A[], int l, int mid, int h)
{
    int i, j, k;
    i = l;
    j = mid + 1;
    k = l;
    int B[h + 1];

    while (i <= mid && j <= h)
    {
        if (A[i] < A[j])
        {
            B[k++] = A[i++];
        }
        else
        {
            B[k++] = A[j++];
        }
    }
    // copying remaining elements
    for (; i <= mid; i++)
        B[k++] = A[i++];
    for (; j <= h; j++)
        B[k++] = A[j++];

    // copying back to orginal array
    for (i = l; i <= h; i++)
    {
        A[i] = B[i];
    }
}
void MergeSort(int A[], int l, int h)
{
    if (l < h)
    {
        int mid = (l + h) / 2;
        MergeSort(A, l, mid);
        MergeSort(A, mid + 1, h);

        Merge(A, l, mid, h);
    }
}

void print(int A[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << A[i] << " ";
    }
}
int main()
{
    int n = 6;
    int A[n] = {4, 6, 8, 2, 1, 54};
    MergeSort(A, 0, n);
    print(A, n);
    return 0;
}

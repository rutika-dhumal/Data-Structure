#include <iostream>
using namespace std;

void Swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
int Partition(int A[], int l, int h)
{
    int pivot = A[l]; // set first element as pivot
    int i, j;
    i = l; // set i to low
    j = h; // set j to high

    do
    {
        do
        {
            i++;
        } while (A[i] <= pivot); // if A[i]<=pivot then increment i
        do
        {
            j--;
        } while (A[j] > pivot); // if A[j]>pivot then increment j

        if (i < j)
        {
            Swap(&A[i], &A[j]);
        }

    } while (i < j);    // while i<j
    Swap(&A[l], &A[j]); // swap pivot and jth element
    return j;
}
void QuickSort(int A[], int l, int h)
{
    int j;
    if (l < h)
    {
        j = Partition(A, l, h);
        QuickSort(A, l, j);
        QuickSort(A, j + 1, h);
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
    int n = 5;
    int A[n] = {4, 6, 8, 2, 1};
    QuickSort(A, 0, 5);
    print(A, n);
    return 0;
}

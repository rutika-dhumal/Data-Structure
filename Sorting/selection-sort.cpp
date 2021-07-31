#include <iostream>
using namespace std;

void Swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void SelectionSort(int A[], int n)
{
    int i, j, k;
    for (i = 0; i < n - 1; i++)
    {
        for (j = k = i; j < n; j++) // make j and k point to i  .. increment j
        {
            if (A[j] < A[k]) // if j < k
            {
                k = j; // then assign j to k
            }
        }
        Swap(&A[i], &A[k]); // and swap value at k to i
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
    SelectionSort(A, n);
    print(A, n);
    return 0;
}

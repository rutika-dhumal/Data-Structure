#include <iostream>
using namespace std;

int findMax(int A[], int n)
{
    int max = 0;
    int i;
    for (i = 0; i < n; i++)
    {
        if (A[i] > max)
            max = A[i];
    }
    return max;
}

void CountSort(int A[], int n)
{
    int max = findMax(A, n);
    int *c = new int[max + 1];

    for (int i = 0; i < max + 1; i++) // initializing count array with 0
        c[i] = 0;

    for (int i = 0; i < n; i++) // counting elements
        c[A[i]]++;

    int i = 0;
    int j = 0;
    while (i < max + 1) // copying elements from count array to original array
    {

        if (c[i] > 0)
        {
            A[j++] = i;
            c[i]--;
        }
        else
            i++;
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
    CountSort(A, n);
    print(A, n);
    return 0;
}

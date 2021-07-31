#include <iostream>
using namespace std;

int Swap(int *a, int *b) // for swapping elements
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void BubbleSort(int A[], int n)
{
    for (int i = 0; i < n - 1; i++) // upto n-1 element
    {
        int flag = 0;
        for (int j = 0; j < n - 1 - i; j++) // in every comparison one pass should be reduce
        {
            if (A[j] > A[j + 1])
            {
                Swap(&A[j], &A[j + 1]);
                flag = 1;
            }
        }
        if (flag == 0) // to check if it is sorted
        {
            break;
        }
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
    BubbleSort(A, n);
    print(A, n);
    return 0;
}

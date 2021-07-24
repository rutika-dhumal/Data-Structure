#include <iostream>
using namespace std;

// missing value for 1 to n natural number
int missing(int A[], int n)
{
    int i, s = 0;
    int sum = 0;
    for (i = 0; i < n; i++)
    {
        sum += A[i];
    }
    s = n * (n + 1) / 2; // formaula to calculte sum of natural numbers
    cout << s - sum;
}
// changes required
int main()
{
    int n = 5;
    int A[n] = {1, 2, 3, 5, 6};
    missing(A, n);
    return 0;
}
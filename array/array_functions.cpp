// menu driven program

#include <iostream>
using namespace std;

void display(int A[], int n)
{
    cout << "\nelements are: ";
    for (int i = 0; i < n; i++)
    {
        cout << " " << A[i];
    }
}

int get_element(int arr[], int index, int n)
{
    if (index >= 0 && index < n)
    {
        return arr[index];
    }
}

int set_element(int arr[], int index, int element, int n)
{
    if (index >= 0 && index < n)
    {
        return arr[index] = element;
    }
}

int max_element(int arr[], int n)
{
    int max = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    return max;
}

int min_element(int arr[], int n)
{
    int min = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] < min)
        {
            min = arr[i];
        }
    }
    return min;
}

int sum(int arr[], int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }
    return sum;
}

int average(int arr[], int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += arr[i];

    return (double)sum / n;
}
int main()
{
    int n, ch, index, element;
    cout << "\nenter size of array: ";
    cin >> n;
    int A[n];
    cout << "\nenter elements";
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }
    do
    {
        cout << "\nMenu";
        cout << " 1.Get Element";
        cout << " 2.Set Element";
        cout << " 3.Max Element";
        cout << " 4.Min Element";
        cout << " 5.Sum ";
        cout << " 6.Average";
        cout << " 7.Display";
        cout << " 8.Exit";

        cout << "\nEnter choice : ";
        cin >> ch;

        switch (ch)
        {
        case 1:
            cout << "enter index: ";
            cin >> index;
            cout << "\nelement get is: " << get_element(A, index, n);
            break;
        case 2:
            cout << "enter index: ";
            cin >> index;
            cout << "enter element: ";
            cin >> element;
            cout << "\nelement set is: " << set_element(A, index, element, n);
            break;
        case 3:
            cout << "\nmax element is: " << max_element(A, n);
            break;
        case 4:
            cout << "\nmin element is: " << min_element(A, n);
            break;
        case 5:
            cout << "\nsum is: " << sum(A, n);
            break;
        case 6:
            cout << "\naverage is: " << average(A, n);
            break;
        case 7:
            display(A, n);
            break;
        }
    } while (ch < 8);

    return 0;
}
// by using pointer type of array to create it inside heap so we can change its size
#include <iostream>
using namespace std;

struct Array
{
    int *p;   // pointer type array
    int size; // size of array
    int l;    // for length of array
};

void display(struct Array arr)
{
    int i;
    cout << "\nelements are: ";
    for (i = 0; i < arr.l; i++)
    {
        cout << " " << arr.p[i];
    }
}

int main()
{
    struct Array arr;
    int n, i;
    cout << "\n enter array size: "; // what size array u want to create inside heap
    cin >> arr.size;
    arr.p = new int[arr.size];
    arr.l = 0;

    cout << "\nenter numbers:"; // inside that array how much size u want to use
    cin >> n;
    cout << "\nenter array elements:";
    for (i = 0; i < n; i++)
    {
        cin >> arr.p[i];
    }
    arr.l = n;
    display(arr);
    return 0;
}
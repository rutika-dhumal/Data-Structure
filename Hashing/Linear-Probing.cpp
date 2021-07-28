#include <iostream>
using namespace std;
#define size 10

// hash function
int Hash(int key)
{
    return key % size;
}

// linear probe
int Probe(int H[], int key)
{
    int index = Hash(key);
    int i = 0;
    while (H[(index + i) % size] != 0) // if there is element then increment i and check that position
        i++;
    return (index + i) % size;
}

// insertion
void insert(int H[], int key)
{
    int index = Hash(key);
    if (H[index] != 0)         // if there is a element
        index = Probe(H, key); // then call probe()
    H[index] = key;            // assign key to that index
}

// searching
int search(int H[], int key)
{
    int index = Hash(key);
    int i = 0;
    while (H[(index + i) % size] != key)
        i++;
    return (index + i) % size;
}

int main()
{
    int HT[10] = {0};
    insert(HT, 20);
    insert(HT, 25);
    insert(HT, 45);
    insert(HT, 70);

    int index = search(HT, 70);
    cout << index;

    return 0;
}
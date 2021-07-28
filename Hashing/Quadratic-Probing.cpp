// Quadratic Probing solves the problem of Linear Probing i.e. problem of primary clustering
// modified hash function is h(x) = (h(x)+f(i)) % SIZE where f(i)=i^2

#include <iostream>
using namespace std;
#define size 10

// hash function
int Hash(int key)
{
    return key % size;
}

int Probe(int H[], int key)
{
    int index = Hash(key);
    int i = 0;
    while (H[(index + i * i) % size] != 0) // if there is element then increment i and check that position
        i++;
    return (index + i * i) % size;
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
    while (H[(index + i * i) % size] != key)
        i++;
    return (index + i * i) % size;
}

int main()
{
    int HT[10] = {0};
    insert(HT, 23);
    insert(HT, 43);
    insert(HT, 13);
    insert(HT, 27);

    int index = search(HT, 13);
    cout << index;

    return 0;
}
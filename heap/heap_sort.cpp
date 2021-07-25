// min heap

#include <iostream>
#include <math.h>
using namespace std;

class MinHeap
{
public:
    int *harr;     // pointer to array of elements in heap
    int capacity;  // maximum size of min heap
    int heap_size; // current size of heap

    // parameterized constructor to get elements fom user
    MinHeap(int cap)
    {
        heap_size = cap;
        capacity = cap;
        harr = new int[cap];
    }

    // linear search
    void linearSearch(int key)
    {
        for (int i = 0; i < heap_size; i++)
        {
            if (harr[i] == key)
            {
                cout << "element found";
                return;
            }
        }
        cout << "not found";
    }

    // display array
    void display()
    {
        for (int i = 0; i < heap_size; i++)
        {
            cout << " " << harr[i];
        }
        cout << endl;
    }

    int height()
    {
        return ceil(log2(heap_size + 1)) - 1; // mathematical formaula te get height of heap
    }

    // get the unsorted array from user
    void getUnsortedArray()
    {
        cout << "Enter " << capacity << " elements";
        for (int i = 0; i < capacity; i++)
        {
            cin >> harr[i];
        }
    }

    // sorting
    void heapSort()
    {
        int temp[capacity];
        for (int j = 0; j < capacity; j++)
        {
            temp[j] = extractMin();
            cout << temp[j] << " ";
        }
    }
    // returns minimum element and delete it
    int extractMin()
    {
        int root;
        // if heap is empty
        if (heap_size <= 0)
        {
            cout << "heap is empty" << endl;
        }
        // if there is only one element
        if (heap_size == 1)
        {
            heap_size--;
            return harr[0];
        }
        // if more than one element
        root = harr[0];
        harr[0] = harr[heap_size - 1];
        heap_size--;
        minHeapify(0);
        return root;
    }

    // extractMin() function extract the root now the tree must be reconstructed
    void minHeapify(int i)
    {
        int l, r, small;
        l = left(i);
        r = right(i);
        small = 0;

        if (l < heap_size && harr[l] < harr[i])
            small = l;
        if (r < heap_size && harr[r] < harr[i])
            small = r;

        if (small != i)
        {
            swap(harr[i], harr[small]);
            minHeapify(small);
        }
    }

    // swapping function
    void swap(int &x, int &y)
    {
        int temp;
        temp = x;
        x = y;
        y = temp;
    }

    // to get the parent of node
    int parent(int i)
    {
        return (i - 1) / 2;
    }
    int left(int i)
    {
        return (2 * i) + 1;
    }
    int right(int i)
    {
        return (2 * i) + 2;
    }
};
int main()
{
    int s;
    cout << "\nenter size of min heap : " << endl;
    cin >> s;
    MinHeap obj(s);
    cout << "\nmin heap created" << endl;

    obj.getUnsortedArray(); // get unsorted array from user
    obj.display();

    for (int i = s / 2 - 1; i >= 0; i--) // heapify all nodes from bottom to top
    {
        obj.minHeapify(i);
    }

    cout << "heap sorted array is : ";
    obj.heapSort();

    return 0;
}
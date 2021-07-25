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
        heap_size = 0;
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

    void insert(int key)
    {
        int i;
        // to check whether heap is full or not
        if (heap_size == capacity)
        {
            cout << "heap is full" << endl;
            return;
        }

        // insert element
        heap_size++;
        i = heap_size - 1;
        harr[i] = key;

        // check the heap property
        while (i != 0 && harr[parent(i)] > harr[i])
        {
            // if both condition are true parent and child
            swap(harr[i], harr[parent(i)]);

            // assign parent's index value to i then again it will check heap property
            i = parent(i);
        }
    }

    // //  to replace deleted value with min value
    void decreaseKey(int i, int new_val)
    {
        harr[i] = new_val;                          // replace deleted value with min value
        while (i != 0 && harr[parent(i)] > harr[i]) // check if parent value greater than min value
        {
            swap(harr[i], harr[parent(i)]); // swap element
            i = parent(i);
        }
    }

    // delete element
    void deleteKey(int i)
    {
        decreaseKey(i, -1); // to replace deleted value with min value
        extractMin();       // now deleted value is at top .. extract that value and reconstruct the tree
        cout << "key is deleted" << endl;
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
    cout << "\nmin heap created";

    int ch, val;

    do
    {
        cout << "\nWhat operation u want to perform select option and enter 0 to exit : " << endl;
        cout << "\n1.Insert 2.Delete 3.Linear Search 4.Display Elements 5.Height 6.Extract Min 0.exit" << endl;

        cin >> ch;

        switch (ch)
        {

        case 1:
            cout << "insert operation  " << endl;
            cout << "enter key to insert : " << endl;
            cin >> val;
            obj.insert(val);
            break;
        case 2:
            cout << "delete operation  " << endl;
            cout << "enter key index to delete : ";
            cin >> val;
            obj.deleteKey(val);
            break;
        case 3:
            cout << "search operation  " << endl;
            cout << "enter key to search : " << endl;
            cin >> val;
            obj.linearSearch(val);
            break;
        case 4:
            cout << "elements are: " << endl;
            obj.display();
            break;
        case 5:
            cout << "height : " << obj.height();
            break;

        case 6:
            cout << "extract min value is : " << obj.extractMin();

            break;

        default:
            cout << "enter proper option";
            break;
        }
    } while (ch != 0);
    return 0;
}
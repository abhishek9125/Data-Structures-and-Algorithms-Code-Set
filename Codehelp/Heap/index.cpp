#include <iostream>
using namespace std;

class heap {
    public:
        int arr[100];
        int size;

        heap() {
            arr[0] = -1;
            size = 0;
        }

        // Time Complexity -> O(log n)
        void insert(int val) {
            size = size + 1;
            int index = size;
            arr[index] = val;

            while(index > 1) {
                int parent = index/2;
                if(arr[parent] < arr[index]) {
                    swap(arr[parent], arr[index]);
                    index = parent;
                } else {
                    return;
                }
            }
        }

        // Time Complexity -> O(log n)
        void deleteFromHeap() {
            if(size == 0) {
                cout << "Heap is already Empty" << endl;
            }

            arr[1] = arr[size];
            size--;

            int i = 1;
            while(i < size) {
                int leftChild = 2*i;
                int rightChild = 2*i + 1;

                if(leftChild <= size && arr[i] < arr[leftChild]) {
                    swap(arr[i], arr[leftChild]);
                    i = leftChild;
                } else if(rightChild <= size && arr[i] < arr[rightChild]) {
                    swap(arr[i], arr[rightChild]);
                    i = rightChild;
                } else {
                    return;
                }
            } 
        }

        void print() {
            for(int i = 1; i <= size; i++) {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
};

// Time Complexity -> O(log n)
void heapify(int arr[], int size, int i) {
    int largest = i;
    int left = 2*i;
    int right = 2*i + 1;

    if(left <= n && arr[largest] < arr[left]) {
        largest = left;
    }
    
    if (right <= n && arr[largest] < arr[right]) {
        largest = right;
    }

    if(largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }

    return;
}

// Time Complexity -> O(n*log n)
void heapsort(int arr[], int n) {

    int size = n;

    while(size > 1) {
        swap(arr[size], arr[1]);
        size--;
        heapify(arr, n, 1);
    }
    return;
}

int main() {    

    heap h;
    h.insert(50);
    h.insert(55);
    h.insert(53);
    h.insert(52);
    h.insert(54);
    h.print();
    h.deleteFromHeap();
    h.print();

    int arr[6] = { -1, 54, 53, 55, 52, 50 };

    // Time Complexity -> O(n)
    for(int i = n/2; i > 0; i--) {
        heapify(arr, n, i);
    }

    return;

}

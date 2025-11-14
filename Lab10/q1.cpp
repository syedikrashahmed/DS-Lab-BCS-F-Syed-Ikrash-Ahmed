//max heap insert delete update heapify
#include <iostream>
using namespace std;

class MaxHeap {
    public: 
    int arr[100];
    int size;

    MaxHeap() {
        size = 0;

    }

    int parent(int i) { return (i - 1) / 2; }
    int leftChild(int i) { return (2 * i) + 1; }
    int rightChild(int i) { return (2 * i) + 2; }

    void insert(int val) {
        if (size == 100) {
            cout << "heap full" << endl;
            return;
        }
        arr[size] = val;
        heapifyUp(size);
        size++;
    }

    void heapifyUp(int i) {
        while (i != 0 && arr[i] > arr[parent(i)]) {
            int temp = arr[i];
            arr[i] = arr[parent(i)];
            arr[parent(i)] = temp;
            i = parent(i);
        }
    }

    void heapifyDown(int i) {
        int largest = i;
        int left = leftChild(i);
        int right = rightChild(i);

        if (left < size && arr[left] > arr[largest]) {
            largest = left;
        }

        if (right < size && arr[right] > arr[largest]) {
            largest = right;
        }

        if (largest != i) {
            int temp = arr[i];
            arr[i] = arr[largest];
            arr[largest] = temp;
            heapifyDown(largest);
        }
    }

    void deleteRoot() {
        if (size == 0) {
            cout << "Heap empty" << endl;
            return;
        }

        arr[0] = arr[size - 1];
        size--;
        heapifyDown(0);
    }

    void update(int i, int newVal) {
        if (i < 0 || i > size - 1) {
            cout << "Invalid index" <<endl;
            return;
        }

        int old = arr[i];
        arr[i] = newVal;
        
        if (newVal > old) {
            heapifyUp(i);
        }
        if (newVal < old) {
            heapifyDown(i);
        }
    }

    void display() {
        for (int i = 0; i < size; i++) {
            cout << arr[i] << ", ";
        }
        cout << endl;
    }
};



int main() {
    MaxHeap heap;
    heap.insert(8);
    heap.insert(7);
    heap.insert(6);
    heap.insert(5);
    heap.insert(4);
    heap.display();

    heap.update(3, 10);
    heap.display();

    heap.deleteRoot();
    heap.display();
}

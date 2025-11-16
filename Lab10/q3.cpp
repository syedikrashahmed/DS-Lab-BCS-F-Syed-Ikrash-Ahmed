/*Task#3: Given an integer array arr[] of size n elements and a positive integer K, the
task is to return the kth largest element in the given array (not the Kth distinct
element).
Examples:
Input: [1, 23, 12, 9, 30, 2, 50], K = 3
Output: 23
Input: [12, 3, 5, 7, 19], K = 2
Output: 12*/

#include <iostream>
using namespace std;

class MaxHeap {
    public: 
    int* arr;
    int size;

    MaxHeap(int n) {
        size = n;
        arr = new int[n];
		for (int i = 0; i < n; i++) {   
			arr[i] = 0;
		}
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

    int deleteRoot() {
        if (size == 0) {
            cout << "Heap empty" << endl;
            return -1;
        }
		int root = arr[0];
        arr[0] = arr[size - 1];
        size--;
        heapifyDown(0);
        return root;
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

int main()
{
	int n = 7;
	MaxHeap heap(n);
	int arr[7] = {1, 23, 12, 9, 30, 2, 50};
	for (int i = 0; i < n; i++) {
		heap.insert(arr[i]);
	}
	
	for (int i = 0; i < n; i++) {
		arr[i] = heap.deleteRoot();
	}
	
	int k = 5;
	if (k >0 && k <= n) {
		cout << arr[k - 1] << endl;
	}
	else {  
		cout << "invalid position" << endl;
	}
}
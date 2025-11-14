bool heapCheck(int arr[], int size) {
    for (int i = (size/2) -1; i >= 0; i--) {
        int left = leftChild(i);
        int right = rightChild(i);

        if (left < size && arr[left] > arr[i]) {
            return false; //if left child is greater than not max heap
        }

        if (right < size && arr[right] > arr[i]) {
            return false; //if right child is greater than not max heap
        }
    }
    return true;
}

void heapSort(int arr[], int size) {
    for (int i = (size/2)-1; i >= 0; i--) {
        int largest = i;
        int left = leftChild(i);
        int right = rightChild(i);
        
        if (left < size && arr[left] > arr[largest])
            largest = left;
        if (right < size && arr[right] > arr[largest])
            largest = right;
            
        if (largest != i) {
            swap(arr[i], arr[largest]);
            i = largest + 1; 
        }
    }
    
    for (int i = size-1; i > 0; i--) {
        swap(arr[0], arr[i]); 
        int root = 0;
        while (true) {
            int largest = root;
            int left = leftChild(root);
            int right = rightChild(root);
            
            if (left < i && arr[left] > arr[largest])
                largest = left;
            if (right < i && arr[right] > arr[largest])
                largest = right;
                
            if (largest == root) break;
                
            swap(arr[root], arr[largest]);
            root = largest;
        }
    }
}

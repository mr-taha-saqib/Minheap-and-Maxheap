#include <iostream>
using namespace std;

class MinHeap {
private:
    int capacity;
    int heap_size;
    int *arr;

public:
    MinHeap(int cap) { //cons
        capacity = cap;
        heap_size = 0;
        arr = new int[capacity];
    }

    ~MinHeap() { //dest
        delete[] arr;
    }

    void insert(int key) {
        if (heap_size == capacity) {
            cout << "Heap is full." << endl;
            return;
        }

        arr[heap_size] = key;
        heapify_up(heap_size);
        heap_size++;
    }
    
    void delete_key(int key) {
        int index = search(key);
        if (index == -1) {
            cout << "Key not found." << endl;
            return;
        }

        arr[index] = arr[heap_size - 1];
        heap_size--;
        heapify_down(index);
    }
    
  int find_min() { 
        if (heap_size == 0) {
            cout << "Heap is empty." << endl;
            return -1;
        }

        return arr[0];
    }
    void make_heap(int *input_array, int array_size) {
        if (array_size > capacity) {
            cout << "Array size full." << endl;
            return;
        }

        heap_size = array_size;
        for (int i = 0; i < heap_size; i++) {
            arr[i] = input_array[i];
        }

        for (int i = (heap_size - 1) / 2; i >= 0; i--) {
            heapify_down(i);
        }
    }

    int search(int key) { //searching
        for (int i = 0; i < heap_size; i++) {
            if (arr[i] == key) {
                return i;
            }
        }

        return -1;
    }

    void display() {
        for (int i = 0; i < heap_size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

private:
    void heapify_down(int index) {
        int left_child = 2 * index + 1;
        int right_child = 2 * index + 2;
        int smallest = index;

        if (left_child < heap_size && arr[left_child] < arr[smallest]) {
            smallest = left_child;
        }

        if (right_child < heap_size && arr[right_child] < arr[smallest]) {
            smallest = right_child;
        }

        if (smallest != index) {
            swap(arr[index], arr[smallest]);
            heapify_down(smallest);
        }
    }
    
        void heapify_up(int index) {
        int parent = (index - 1) / 2;

        while (index > 0 && arr[index] < arr[parent]) {
            swap(arr[index], arr[parent]);
            index = parent;
            parent = (index - 1) / 2;
        }
    }

};

int main() {
    int capacity = 10;
    MinHeap heap(capacity);

    int arr[] = {10, 20, 50, 30, 80,60,70};
    int array_size = sizeof(arr) / sizeof(arr[0]);

    // Convert input array into heap
heap.make_heap(arr, array_size);
heap.display();
cout<<"After insertion : ";
heap.insert(1);
heap.display();
cout<<"After deletion: ";
heap.delete_key(80);
heap.display();
    int min = heap.find_min();
    cout << "Minimum element: " << min << endl;

    // Search an element
    int key = 3;
    int index = heap.search(key);
    if (index == -1) {
        cout << "Element " << key << " not found." << endl;
    } else {
        cout << "Element " << key << " found " << index << endl;
    }
    heap.display();

    return 0;
}

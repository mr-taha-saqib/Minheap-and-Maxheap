#include <iostream>
using namespace std;

class HeapSort{
private:
    int *arr;
    int size;
public:
    HeapSort(int *inputArr, int inputSize){ //cons
        arr = inputArr;
        size = inputSize;
    }

    void minHeapify(int *arr, int n, int i){
        int smallest = i; 
        int left = 2*i + 1; //left traverse
        int right = 2*i + 2;  //right traverse

        if (left < n && arr[left] < arr[smallest]){
            smallest = left;
        }

        if (right < n && arr[right] < arr[smallest]){
            smallest = right;
        }

        if (smallest != i){
            swap(arr[i], arr[smallest]);
            minHeapify(arr, n, smallest);
        }
    }
    
    void maxHeapify(int *arr, int n, int i){ 
        int largest = i; 
        int left = 2*i + 1; 
        int right = 2*i + 2; 

        if (left < n && arr[left] > arr[largest]){
            largest = left;
        }

        if (right < n && arr[right] > arr[largest]){
            largest = right;
        }

        if (largest != i){
            swap(arr[i], arr[largest]);
            maxHeapify(arr, n, largest);
        }
    }

void minHeapSort(){
    // min heap from the input array
    for (int i = size/2 - 1; i >= 0; i--){
        minHeapify(arr, size, i);
    }
    for (int i = size - 1; i >= 0; i--){
        swap(arr[0], arr[i]);
        minHeapify(arr, i, 0);
    }
}

void maxHeapSort(){
    // max heap from the input array
    for (int i = size/2 - 1; i >= 0; i--){
        maxHeapify(arr, size, i);
    }
    for (int i = size - 1; i >= 0; i--){
        swap(arr[0], arr[i]);
        maxHeapify(arr, i, 0);
    }
}



    void display(){
        for (int i = 0; i < size; i++){
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main(){
    int arr[] = {5, 3, 10, 1,6}; //input array
    int n = sizeof(arr)/sizeof(arr[0]);
    HeapSort heapSortMin(arr, n);
    heapSortMin.minHeapSort();
    cout << "Min heap : ";
    heapSortMin.display();

    HeapSort heapSortMax(arr, n);
    heapSortMax.maxHeapSort();
    cout << "Max heap : ";
    heapSortMax.display();

    return 0;
}


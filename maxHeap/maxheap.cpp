#include <iostream>
using namespace std;

// Function to "heapify" a subtree rooted at index i in an array of size n,
// ensuring the subtree satisfies the max-heap property.
void HeapifyMax(int arr[], int n, int i) {
    int largest = i;         // Initialize largest as the root.
    int left = 2 * i + 1;      // Left child index.
    int right = 2 * i + 2;     // Right child index.

    // If left child exists and is greater than root.
    if (left < n && arr[left] > arr[largest])
        largest = left;

    // If right child exists and is greater than the current largest.
    if (right < n && arr[right] > arr[largest])
        largest = right;

    // If the largest is not the root, swap and continue heapifying.
    if (largest != i) {
        swap(arr[i], arr[largest]);
        HeapifyMax(arr, n, largest);
    }
}

// Build a max heap by calling HeapifyMax for all non-leaf nodes.
void BuildMaxHeap(int arr[], int n) {
    // Start from the last non-leaf node (n/2 - 1) and move up to the root.
    for (int i = n / 2 - 1; i >= 0; i--) {
        HeapifyMax(arr, n, i);
    }
}

// Helper function to print the array.
void PrintArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    
    int* arr = new int[n];
    cout << "Enter " << n << " elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }



    
    // Build the max heap.
    BuildMaxHeap(arr, n);
    
    cout << "Max Heap built:\n";
    PrintArray(arr, n);
    
    delete[] arr; // Free allocated memory.
    return 0;
}

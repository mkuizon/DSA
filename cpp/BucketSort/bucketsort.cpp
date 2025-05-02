#include <iostream>
#include <vector>
#include <cmath>       // For floor(), if needed
#include <algorithm>   // For sort()
using namespace std;

void BucketSort(int nums[], int size, int bucketCount) {
    if (size < 1) return;
    
    // Create a vector of buckets (each bucket is a vector of ints)
    vector<vector<int>> buckets(bucketCount);
    
    // Find maximum value in nums to determine bucket range
    int maxVal = nums[0];
    for (int i = 1; i < size; i++) {
        if (nums[i] > maxVal) {
            maxVal = nums[i];
        }
    }
    
    // Distribute numbers into buckets
    for (int i = 0; i < size; i++) {
        int number = nums[i];
        // Compute bucket index; using integer arithmetic:
        int idx = (number * bucketCount) / (maxVal + 1);
        // Alternatively, using floor with floating-point arithmetic:
        // int idx = floor((double)number * bucketCount / (maxVal + 1));
        buckets[idx].push_back(number);
    }
    
    // Sort each bucket and merge back into nums[]
    int index = 0;
    for (auto &bucket : buckets) {
        sort(bucket.begin(), bucket.end());
        for (int num : bucket) {
            nums[index++] = num;
        }
    }
}

void PrintArray(int nums[], int size) {
    for (int i = 0; i < size; i++){
        cout << nums[i] << " ";
    }
    cout << "\n";
}

int main() {
    int arr[8] = {46, 82, 62, 37, 12, 54, 49, 38};
    int arrSize = 8;
    int bucketCount = 3;
    
    BucketSort(arr, arrSize, bucketCount);
    
    cout << "Sorted:\n";
    PrintArray(arr, arrSize);
    
    return 0;
}

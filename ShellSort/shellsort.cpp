#include <iostream>
using namespace std;

void print(int nums[], int size) {
    for (int i =0; i<size; i++) {
        cout << nums[i] << " ";
    }
    cout << "\n";
};

void InsertionSortInterleaved(int nums[], int size, int startIdx, int gapValue) {
    int temp = 0;
    int j;
    int i;

    for ( i = startIdx + gapValue; i< size; i = i+gapValue) {
        j = i;
        // insert nums[i] into sorted part


        while ((j-gapValue>= startIdx) && (nums[j]<nums[j-gapValue]))   {                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                              
            // so making sure that j is less than j-1 so that they can be swapped
            
            temp = nums[j];
            nums[j] = nums[j-gapValue];
            nums[j-gapValue] = temp; 
            j= j - gapValue;
            print(nums, size);
        }
        print(nums, size);
    }
};

void ShellSort(int arr[], int size, int gaps[], int gapSize) {
    // for (int gap : gaps) {
    cout << "Sorting :" << " \n";
    for (int i =0; i < gapSize; i++) {
        int gap = gaps[i];
        for (int j = 0; j <gap; j++) {
            InsertionSortInterleaved(arr, size, j, gap);
        }
    }
    cout << "\n" << "Sorted: " << "\n";
    print(arr, size);
};

int main() {
    int arr[8] = {46,82,62,37,12,54,49,38};
    int arrSize = 8;
    int gapSize = 3;
    int gaps[3] = {5,3,1};
    // testing for each loop
    for (int gap : gaps) {
        cout << gap << " ";
        
    }
    

    ShellSort(arr, arrSize, gaps, gapSize);
}
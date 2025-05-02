#include <iostream>
using namespace std;
/*
SELECTION SORT

taking a smallest smallest value and placing it into sorted from unsorted

BIG O = O(n^2)

basically selects the smallest value using the index through the inner loop
and then swaps it with the current index of the outer loop

outer loop: nums[i]

inner loop: finds the smallest value's idx

outer loop: swaps nums[i] = nums[smallest], 
now nums[i] - ex. index 0 = 6, index 2 = 1, they swap spots
so now array = [1,4,6,]
*/
void SelectionSort(int nums[], int size) {
    int smallestIdx;
    int temp = 0;
    for (int i = 0; i < size - 1; i++) {
        smallestIdx = i; // setting the smallest idx as i for now
        for (int j = i+1; j<size; j++){ // going through unsorted portion for smallest
            // so unsorted is i+1 until the end of the array.
        // checking if current smallest idx is greater than current pos
            if (nums[j] < nums[smallestIdx]) {
                smallestIdx = j;
                 
            }
        }
        cout << " Swapping value " << nums[smallestIdx] << " with " << nums[i] << endl;
        // swap nums[i] with smallest index
        temp = nums[i];
        nums[i] = nums[smallestIdx];
        nums[smallestIdx] = temp;

        for (int i = 0; i < size; i++){
            cout << nums[i] << " ";
        }
        cout << "\n";

    }
        //printing the sorted lsit

    cout << "Sorted: " << "\n";
    for (int i = 0; i < size; i++){
        cout << nums[i] << " ";
    }
}

int main() {
    int size = 7;
    int arr[7] = {54,6,7,8,99,1,23};

    SelectionSort(arr,size);   

}
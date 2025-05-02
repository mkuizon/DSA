#include <iostream>
using namespace std;
/*
INSERTION SORT

algorithm treats input s two ports, sorted and unsorted
- inserts value from unsorted part to correct location in sorted part


*/

void print(int nums[], int size) {
    for (int i =0; i<size; i++) {
        cout << nums[i] << " ";
    }
    cout << "\n";
}


void InsertionSort(int nums[], int size) {
    int temp = 0;
    int j;
    int i;

    for ( i = 1; i< size; i++) {
        j = i;
        // insert nums[i] into sorted part


        while ((j>0) && (nums[j] < nums[j-1])) {
            // so making sure that j is less than j-1 so that they can be swapped
            
            temp = nums[j];
            nums[j] = nums[j-1];
            nums[j-1] = temp;
            j--;
        }

        print(nums,size);

    }
    cout<< "Sorted: " << endl;
    print(nums, size);
    
}


int main() {
    int size = 6;
    int arr[6] = {9,2,5,1,8,6};
    print(arr,size);
    InsertionSort(arr,size);
}
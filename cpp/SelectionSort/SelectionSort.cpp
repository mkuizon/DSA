// Micah Kuizon
/*
SELECTIONS SORT
 - sorted part and unsorted part that repeatedly selects minimum value to
 move from unsorted to sorted

 

*/
#include <iostream>
using namespace std;

// making global variables to use for comparing
int c = 0;
int s = 0;

// Read size numbers from cin into a new array and return the array.
int* ReadNums(int size) {
    int* arr = new int[size]; // creating the array
    // placing values into array
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }
    return arr;
}

// Print the numbers in the array, separated by spaces
// (No space or newline before the first number or after the last.)
void PrintNums(int nums[], int size) {
    for (int i = 0; i < size; i++) {
        cout << nums[i];
        if (i < size - 1) {
            cout << " ";
        }
    }
    cout << "\n";
}

// Exchange nums[j] and nums[k].
void Swap(int nums[], int j, int k) {
    int temp = nums[j];
    nums[j] = nums[k];
    nums[k] = temp;
}

void SelectionSort(int nums[], int size) {
    // iterate through the array (except for the last element)
    for (int i = 0; i < size - 1; i++) {
        // assume the smallest element is at index i
        int min = i;
        // search for the smallest element in the unsorted portion
        for (int j = i + 1; j < size; j++) {
            c++; // count each comparison
            if (nums[j] < nums[min]) {
                min = j;
            }
        }
        // if the smallest element isn't in place, swap it
        if (min != i) {
            Swap(nums, i, min);
            s++; // count the swap
        }
        // output the array after each outer loop iteration
        PrintNums(nums, size);
    }
}

int main() {
    // Step 1: Read numbers into an array
    int sizeVal;
    cin >> sizeVal;
    int* n = ReadNums(sizeVal); // helper function for creating new array

    // Step 2: Output the numbers array
    PrintNums(n, sizeVal);
    cout << "\n";

    // Step 3: Sort the numbers array using selection sort
    SelectionSort(n, sizeVal);
    cout << "\n";

    // Step 4: Output the number of comparisons and swaps
    cout << "comparisons: " << c << endl;
    cout << "swaps: " << s << endl;
    
    // clean up allocated memory
    delete[] n;
    return 0;
}

// Micah Kuizon

#include <iostream>
using namespace std;

// making global variables to use for comparing and swapping count
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

void InsertionSort(int nums[], int size) {
    int j = 0;
    for (int i = 1; i < size; i++) {
        // inserting nums[i] into sort
        j = i;
        while (j > 0) {
            c++;
            if (nums[j - 1] > nums[j]) {
                Swap(nums, j - 1, j);
                s++;
                j--;
            } else {
                break;
            }
        }
        PrintNums(nums, size); // printing after every loop
    }
}

int main() {
    // Step 1: Read numbers into an array
    int size; // size
    cin >> size;
    int* n = ReadNums(size); // helper function for creating new array

    // Step 2: Output the numbers array
    PrintNums(n, size);
    cout << "\n";

    // Step 3: Sort the numbers array
    InsertionSort(n, size);
 
    // Step 4: Output the number of comparisons and swaps
    cout << "\n";
    cout << "comparisons: " << c << endl;
    cout << "swaps: " << s << endl;
    
    return 0;
}

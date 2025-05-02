#include <iostream>
using namespace std;

int Partition(int nums[], int low, int high) {
    int mid = low + (high - low) / 2; 
    // yum yum it could legit just be high /2 but idk CS ig
    // choosing the pivot as the midpoint
    int pivot = nums[mid];

    bool done = false;

    while (!done) {
        // increment low index while nums[low] < pivot
        while (nums[low]< pivot) {
            low++;
        }

        while (pivot < nums[high]) {
            high--;
        }

        // if zero or one element remains, then all numbers are partitioned, return high
        if (low >= high) {
            done = true;
        } else {
            // swap nums[low] and high
            int temp = nums[high];
            nums[high] = nums[low];
            nums[low] = temp;

            low++;
            high--;
        }
    }

    return high;

}

void Quicksort(int numbers[],int lowIndex,int highIndex) {
    // Base case: If the partition size is 1 or zero 
    // elements, then the partition is already sorted
    if (highIndex <= lowIndex) {
       return;
    }
    
    // Partition the data within the array. Value lowEndIndex 
    // returned from partitioning is the index of the low 
    // partition's last element.
   int lowEndIndex = Partition(numbers, lowIndex, highIndex);
    
    // Recursively sort low partition (lowIndex to lowEndIndex) 
    // and high partition (lowEndIndex + 1 to highIndex)
    Quicksort(numbers, lowIndex, lowEndIndex);
    Quicksort(numbers, lowEndIndex + 1, highIndex);
 }
 
int main() {
    int numbers[] = { 10, 2, 78, 4, 45, 32, 7, 11 };
    int NUMBERS_SIZE = 8;
    int i = 0;
    
    cout << "UNSORTED: " << endl;
    for (i = 0; i < NUMBERS_SIZE; ++i) {
       cout << numbers[i] << " ";
    }
    cout<< "\n";
    
    // Initial call to quicksort
    Quicksort(numbers, 0, NUMBERS_SIZE - 1);
    
    cout << "SORTED: " << endl;
    for (i = 0; i < NUMBERS_SIZE; ++i) {
        cout << numbers[i] << " ";
    }
    
 }
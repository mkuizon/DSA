#include <iostream>
using namespace std;
/*
BUBBLE SORT - compares and swaps adjacent pairs

nested loops - 

O(n^2)




*/
void BubbleSort(int numbers[],int numberSize) {
    int temp;
    for (int i=0; i<numberSize-1; i++ ) {
        for (int j = 0; j <numberSize - i - 1; j++) {
            if (numbers[j] > numbers[j+1]) { // comparing adjacent
                temp = numbers[j];
                numbers[j] = numbers[j+1];
                numbers[j+1] = temp;

            }
        }
        // prints after
        for (int i =0; i < numberSize; i++) {
            cout << numbers[i] << " ";
        
            
        }
        cout << "\n"; 
    }



}


int main() {
    int size = 6;
    int nums[6] = {9,2,5,1,8,6};

    for (int i =0; i < size; i++) {
        cout << nums[i] << " ";
    
    }
    cout << "\n";

    BubbleSort(nums, size);
}


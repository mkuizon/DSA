#include <iostream>
#include <sstream>
#include <string>
using namespace std;

int comparisons = 0; // global variable to count comparisons

// reads the number of values and then that many values; returns a dynamic array
int* ReadNums(int& size) {
   cin >> size;
   int *arr = new int[size];
   for (int i = 0; i < size; i++) {
      cin >> arr[i];
   }
   return arr;
}

// prints the array elements from index start to end (inclusive) with a space between numbers; ends with a new line
void PrintNums(int *arr, int start, int end) {
   for (int i = start; i <= end; i++) {
      cout << arr[i];
      if (i < end) {
         cout << " ";
      }
   }
   cout << endl;
}

// merges two sorted subarrays: arr[start..mid] and arr[mid+1..end]
// counts each comparison made during the merge
void Merge(int *arr, int start, int mid, int end){
   int ls = mid - start + 1;
   int rs = end - mid;
   
   int *left = new int[ls];
   int *right = new int[rs];
   
   // copy left part into left array
   for (int i = 0; i < ls; i++) {
      left[i] = arr[start + i];
   }
   // copy right part into right array
   for (int j = 0; j < rs; j++) {
      right[j] = arr[mid + 1 + j];
   }
   
   int i = 0, j = 0, k = start;
   
   // merge left and right arrays back into arr
   while (i < ls && j < rs) {
      comparisons++;
      if (left[i] <= right[j]) {
         arr[k++] = left[i++];
      }
      else {
         arr[k++] = right[j++];
      }
   }
   
   // copy any remaining elements from left array
   while (i < ls) {
      arr[k++] = left[i++];
   }
   
   // copy any remaining elements from right array
   while (j < rs) {
      arr[k++] = right[j++];
   }
   
   delete [] left;
   delete [] right;
}
   
// helper function for merge sort
// label is used to print the side ("left:" or "right:") for non-top-level calls
// istop is true if this is the top-level call
void MergeSortHelper(int* arr, int start, int end, const string &label, bool istop) {
   if (start < end) {
      int mid = (start + end) / 2;
      
      // print the current split of the array
      cout << "Split:" << endl;
      for (int i = start; i <= mid; i++) {
         cout << arr[i];
         if (i < mid)
            cout << " ";
      }
      cout << " | ";
      for (int i = mid + 1; i <= end; i++) {
         cout << arr[i];
         if (i < end)
            cout << " ";
      }
      cout << endl;
      
      // recursively sort the left half with label "Left:" and the right half with label "Right:"
      MergeSortHelper(arr, start, mid, "Left:", false);
      MergeSortHelper(arr, mid + 1, end, "Right:", false);
      
      // merge the two sorted halves
      Merge(arr, start, mid, end);
      
      // if not top-level, print the merged result with the side label
      if (label != "") {
         cout << label << " ";
         PrintNums(arr, start, end);
      }
   }
   else {
      // base case: a single element; if not top-level, print it with the side label
      if (label != "") {
         cout << label << " ";
         PrintNums(arr, start, end);
      }
   }
}
   
// wrapper merge sort function; starts the recursion with top-level flag true
void MergeSort(int* arr, int start, int end) {
   MergeSortHelper(arr, start, end, "", true);
}
   
int main() {
   int size = 0;
   int* numbers = ReadNums(size);

   cout << "Unsorted:" << endl;
   PrintNums(numbers, 0, size - 1);

   MergeSort(numbers, 0, size - 1);

   cout << "Sorted:" << endl;
   PrintNums(numbers, 0, size - 1);

   cout << "Comparisons: " << comparisons << endl;
   
   delete [] numbers;
   return 0;
}

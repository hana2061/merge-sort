#include <iostream>
using namespace std;

void Merge(int arr[], int big, int mid, int End) {
    int temp[End - big + 1];  // Create temp array of correct size
    int i = big;
    int j = mid + 1;
    int index = 0;

    while (i <= mid && j <= End) {
        if (arr[i] < arr[j]) {
            temp[index++] = arr[i++];
        } else {
            temp[index++] = arr[j++];
        }
    }

    // Copy remaining elements from left half
    while (i <= mid) {
        temp[index++] = arr[i++];
    }

    // Copy remaining elements from right half
    while (j <= End) {
        temp[index++] = arr[j++];
    }

    // Copy temp back to original array
    for (int k = 0; k < index; k++) {
        arr[big + k] = temp[k];
    }
}

void merge_sort(int arr[], int big, int End) {
    if (big < End) {
        int mid = big + (End - big) / 2;  // Prevents potential integer overflow

        // Recursively sort first and second halves
        merge_sort(arr, big, mid);
        merge_sort(arr, mid + 1, End);

        // Merge the sorted halves
        Merge(arr, big, mid, End);
    }
}

int main() {
    int arr[5] = {39, 9, 23, 67, 2};
    merge_sort(arr, 0, 4);

    for (int i = 0; i < 5; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}

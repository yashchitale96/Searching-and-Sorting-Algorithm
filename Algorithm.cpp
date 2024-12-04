#include <iostream>
#include <vector>
using namespace std;

// Function to print an array
void printArray(const vector<int>& arr) {
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
}

// Linear Search
void linearSearch(const vector<int>& arr, int key) {
    for (size_t i = 0; i < arr.size(); i++) {
        if (arr[i] == key) {
            cout << "Element found at index: " << i << endl;
            return;
        }
    }
    cout << "Element not found!" << endl;
}

// Binary Search (requires a sorted array)
void binarySearch(const vector<int>& arr, int key) {
    int low = 0, high = arr.size() - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == key) {
            cout << "Element found at index: " << mid << endl;
            return;
        } else if (arr[mid] < key) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    cout << "Element not found!" << endl;
}

// Bubble Sort
void bubbleSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

// Insertion Sort
void insertionSort(vector<int>& arr) {
    for (int i = 1; i < arr.size(); i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

// Selection Sort
void selectionSort(vector<int>& arr) {
    for (int i = 0; i < arr.size() - 1; i++) {
        int minIdx = i;
        for (int j = i + 1; j < arr.size(); j++) {
            if (arr[j] < arr[minIdx]) {
                minIdx = j;
            }
        }
        swap(arr[i], arr[minIdx]);
    }
}

// Merge function for Merge Sort
void merge(vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<int> L(n1), R(n2);
    for (int i = 0; i < n1; i++) L[i] = arr[left + i];
    for (int i = 0; i < n2; i++) R[i] = arr[mid + 1 + i];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
}

// Merge Sort
void mergeSort(vector<int>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

// Partition function for Quick Sort
int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

// Quick Sort
void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Main Function
int main() {
    vector<int> arr = {64, 34, 25, 12, 22, 11, 90};
    int choice, key;
    while (true) {
        cout << "\n--- MENU ---\n";
        cout << "1. Linear Search\n";
        cout << "2. Binary Search\n";
        cout << "3. Bubble Sort\n";
        cout << "4. Insertion Sort\n";
        cout << "5. Selection Sort\n";
        cout << "6. Merge Sort\n";
        cout << "7. Quick Sort\n";
        cout << "8. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter element to search: ";
            cin >> key;
            linearSearch(arr, key);
            break;
        case 2:
            cout << "Enter element to search (array must be sorted): ";
            cin >> key;
            binarySearch(arr, key);
            break;
        case 3:
            bubbleSort(arr);
            cout << "Array after Bubble Sort: ";
            printArray(arr);
            break;
        case 4:
            insertionSort(arr);
            cout << "Array after Insertion Sort: ";
            printArray(arr);
            break;
        case 5:
            selectionSort(arr);
            cout << "Array after Selection Sort: ";
            printArray(arr);
            break;
        case 6:
            mergeSort(arr, 0, arr.size() - 1);
            cout << "Array after Merge Sort: ";
            printArray(arr);
            break;
        case 7:
            quickSort(arr, 0, arr.size() - 1);
            cout << "Array after Quick Sort: ";
            printArray(arr);
            break;
        case 8:
            cout << "Exiting...\n";
            return 0;
        default:
            cout << "Invalid choice! Try again.\n";
        }
    }
    return 0;
}

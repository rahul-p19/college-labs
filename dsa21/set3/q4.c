#include <stdio.h>
#include <stdlib.h>
void bubble(int *arr, int n) {
  int i, j;
  for (i = 0; i < n - 1; i++) {
    for (j = 0; j < n - 1 - i; j++) {
      if (arr[j] > arr[j + 1]) {
        int temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
      }
    }
  }
}

void merge(int *arr, int l, int m, int h) {
  int left = l;
  int right = m + 1;
  int k = 0;
  int temp[100];
  while (left <= m && right <= h) {
    if (arr[left] <= arr[right])
      temp[k++] = arr[left++];
    else
      temp[k++] = arr[right++];
  }
  while (left <= m)
    temp[k++] = arr[left++];
  while (right <= h)
    temp[k++] = arr[right++];
  int i;
  for (i = l; i <= h; i++)
    arr[i] = temp[i - l];
}

void mergeSort(int *arr, int l, int h) {
  if (l >= h)
    return;
  int m = (l + h) / 2;
  mergeSort(arr, 0, m);
  mergeSort(arr, m + 1, h);
  merge(arr, 0, m, h);
}

void insertion(int arr[], int n) {
  int i, j;
  for (i = 0; i < n; i++) {
    int j = i;
    while (j > 0 && arr[j - 1] > arr[j]) {
      int temp = arr[j];
      arr[j] = arr[j - 1];
      arr[j - 1] = temp;
      j--;
    }
  }
}

void selection(int arr[], int n) {
  int i, j;
  int mini;
  for (i = 0; i < n; i++) {
    mini = i;
    for (j = i; j < n; j++) {
      if (arr[j] < arr[mini])
        mini = j;
    }

    int temp = arr[mini];
    arr[mini] = arr[i];
    arr[i] = temp;
  }
}

int partition(int arr[], int low, int high) {
  int pivot = arr[high];
  int i = (low - 1);

  int j;
  for (j = low; j < high; j++) {
    if (arr[j] <= pivot) {
      i++;
      int temp = arr[i];
      arr[i] = arr[j];
      arr[j] = temp;
    }
  }
  int temp = arr[i + 1];
  arr[i + 1] = arr[high];
  arr[high] = temp;
  return (i + 1);
}

void quickSort(int arr[], int low, int high) {
  if (low < high) {
    int pivot = partition(arr, low, high);
    quickSort(arr, low, pivot - 1);
    quickSort(arr, pivot + 1, high);
  }
}

void heapify(int arr[], int n, int i) {
  int largest = i;
  int left = 2 * i + 1;
  int right = 2 * i + 2;

  if (left < n && arr[left] > arr[largest]) {
    largest = left;
  }

  if (right < n && arr[right] > arr[largest]) {
    largest = right;
  }

  if (largest != i) {

    int temp = arr[i];
    arr[i] = arr[largest];
    arr[largest] = temp;

    heapify(arr, n, largest);
  }
}

void heapSort(int arr[], int n) {
  int i, j;
  for (i = n / 2 - 1; i >= 0; i--) {
    heapify(arr, n, i);
  }

  for (i = n - 1; i > 0; i--) {

    int temp = arr[0];
    arr[0] = arr[i];
    arr[i] = temp;

    heapify(arr, i, 0);
  }
}

int main() {
  int n;
  printf("Enter the size of array: ");
  scanf("%d", &n);
  printf("Enter elements of array: ");
  int i;
  int *arr = (int *)malloc(sizeof(int) * n);
  for (i = 0; i < n; i++)
    scanf("%d", &arr[i]);
  int choice;
  printf("Enter 1 for insertion sort, 2 for selection sort, 3 for bubble sort, "
         "4 for quick sort, 5 for merge sort, 6 for heap sort: ");
  scanf("%d", &choice);
  switch (choice) {
  case 1:
    insertion(arr, n);
    break;
  case 2:
    selection(arr, n);
    break;
  case 3:
    bubble(arr, n);
    break;
  case 4:
    quickSort(arr, 0, n - 1);
    break;
  case 5:
    mergeSort(arr, 0, n - 1);
    break;
  case 6:
    heapSort(arr, n);
    break;
  }
  printf("Sorted array: ");
  for (i = 0; i < n; i++)
    printf("%d ", arr[i]);
  printf("\n");
  return 0;
}

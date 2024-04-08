#include <stdbool.h>
#include <stdio.h>

void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

int partition(int low, int high, int *arr) {
  int pivot = arr[high - 1];
  int j = low - 1;

  for (int i = low; i < high - 1; i++) {
    if (arr[i] <= pivot) {
      j++;
      swap(&arr[i], &arr[j]);
    }
  }

  j++;
  swap(&arr[j], &arr[high - 1]);
  return j;
}

void qs(int low, int high, int *arr) {
  if (low >= high || low < 0) {
    return;
  }
  int j = partition(low, high, arr);
  qs(j + 1, high, arr);
  qs(low, j, arr);
}

bool contains_duplicate(int *nums, int numsSize) {
  qs(0, numsSize, nums);
  for (int i = 1; i < numsSize; i++) {
    if (nums[i] == nums[i - 1]) {
      return true;
    }
  }
  return false;
}

int main() {
  const int n = 10;
  int arr[] = {1, 1, 1, 3, 3, 4, 3, 2, 4, 2};
  bool has_duplicate = contains_duplicate(arr, n);
  printf("%d\n", has_duplicate);
}

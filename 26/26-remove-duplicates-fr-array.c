#include <stdio.h>

int removeDuplicates(int *nums, int numSize) {
  int k = 0;
  for (int i = 1; i < numSize; i++) {
    if (nums[i] != nums[k]) {
      k++;
      nums[k] = nums[i];
    }
  }
  k++;
  return k;
}

int main() {
  const int n = 10;
  int arr[n] = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
  int k = removeDuplicates(arr, n);
  printf("k = %d\n", k);
  for (int i = 0; i < k; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
  return 0;
}

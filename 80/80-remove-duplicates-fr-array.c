#include <stdio.h>

int removeDuplicates(int *nums, int numSize) {
  int k = 1;
  int uc = 1;
  for (int i = 1; i < numSize; i++) {
    if (nums[i] == nums[i - 1] && uc < 2) {
      nums[k] = nums[i];
      uc++;
      k++;
    } else if (nums[i] != nums[i - 1]) {
      nums[k] = nums[i];
      uc = 1;
      k++;
    }
  }
  return k;
}

int main() {
  const int n = 9;
  int arr[n] = {0, 0, 1, 1, 1, 1, 2, 3, 3};
  int k = removeDuplicates(arr, n);
  printf("k = %d\n", k);
  for (int i = 0; i < k; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
  return 0;
}

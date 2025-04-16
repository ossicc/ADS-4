// Copyright 2021 NNTU-CS
int countPairs1(int *arr, int len, int value) {
  int count = 0;
  for (int i = 0; i < len - 1; i++) {
    if (i > 0 && arr[i] == arr[i - 1]) continue;
    int j = i + 1;
    while (j < len) {
      if (j > i + 1 && arr[j] == arr[j - 1]) {
        j++;
        continue;
      }
      int sum = arr[i] + arr[j];
      if (sum == value) {
        count++;
        break;
      } else if (sum > value) {
        break;
      }
      j++;
    }
  }
  return count;
}

int countPairs2(int *arr, int len, int value) {
  int count = 0;
  int left = 0, right = len - 1;
  while (left < right) {
    int sum = arr[left] + arr[right];
    if (sum == value) {
      count++;
      int currentLeftValue = arr[left];
      int currentRightValue = arr[right];
      while (left < right && arr[left] == currentLeftValue) {
        left++;
      }
      while (left < right && arr[right] == currentRightValue) {
        right--;
      }
    } else if (sum < value) {
      left++;
    } else {
      right--;
    }
  }
  return count;
}

int countPairs3(int *arr, int len, int value) {
  int count = 0;
  int left = 0, right = len - 1;
  while (left < right) {
    int sum = arr[left] + arr[right];
    if (sum == value) {
      count++;
      left++;
      right--;
      while (left < right && arr[left] == arr[left - 1]) {
        left++;
      }
      while (left < right && arr[right] == arr[right + 1]) {
        right--;
      }
    } else if (sum < value) {
      left++;
    } else {
      right--;
    }
  }
  return count;
}

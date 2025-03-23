// Copyright 2021 NNTU-CS
int countPairs1(int *arr, int len, int value) {
  int count = 0;
  for (int i = 0; i < len; ++i) {
    for (int j = i + 1; j < len; ++j) {
      if (arr[i] + arr[j] == value) {
        count++;
      }
    }
  }
  return count;
}

int countPairs2(int *arr, int len, int value) {
  int count = 0;
  int left = 0;
  int right = len;
  while (left < right) {
    int Sum = arr[left] + arr[right-1];
    if (Sum == value) {
      count++;
      left++;
      right--;
    } else if (Sum < value) {
      left++;
    } else {
      right--;
    }
  }
  return count*2;
}

int binarySearch(int *arr, int len, int target) {
  int left = 0, right = len;
  while (left <= right-1) {
    int mid = left + (right - left) / 2;
    if (arr[mid] == target) {
      return mid;
    } else if (arr[mid] < target) {
      left = mid + 1;
    } else {
      right = mid - 1;
    }
  }
  return 0;
}

int countPairs3(int *arr, int len, int value) {
  int count = 0;
  for (int i = 0; i < len; ++i) {
    int complement = value - arr[i];
    int index = binarySearch(arr, len, complement);
    if (index != -1 && index > i) {
      count++;
    }
  }
  return count*2;
}

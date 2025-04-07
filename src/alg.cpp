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
  int right = len - 1;
  while (left < right) {
    int Sum = arr[left] + arr[right];
    if (Sum == value) {
      int leftCount = 1;
      int rightCount = 1;
      while (left + 1 < right && arr[left] == arr[left + 1]) {
        leftCount++;
        left++;
      }
      while (right - 1 > left && arr[right] == arr[right - 1]) {
        rightCount++;
        right--;
      }
      count += leftCount * rightCount;
      left++;
      right--;
    } else if (Sum < value) {
      left++;
    } else {
      right--;
    }
  }
  return count;
}

int binarySearch(const int arr[], int len, int value) {
  int left = 0;
  int right = len - 1;
  while (left <= right) {
    int mid = left + (right - left) / 2;
    if (arr[mid] == value) {
      return mid;  // Найден элемент
    } else if (arr[mid] < value) {
      left = mid + 1;
    } else {
      right = mid - 1;
    }
  }
  return -1;
}

int countPairs3(int arr[], int len, int value) {
  int count = 0;
  int left = 0;
  int right = len - 1;
  while (left < right) {
    int currentSum = arr[left] + arr[right];
    if (currentSum == value) {
      if (arr[left] == arr[right]) {
        int totalElements = right - left + 1;
        count += (totalElements * (totalElements - 1)) / 2;
        break;
      } else {
        int countLeft = 1;
        while (left + 1 < len && arr[left] == arr[left + 1]) {
          countLeft++;
          left++;
        }
        int countRight = 1;
        while (right - 1 >= 0 && arr[right] == arr[right - 1]) {
          countRight++;
          right--;
        }
        count += countLeft * countRight;
      }
      left++;
      right--;
    } else if (currentSum < value) {
      left++;
    } else {
      right--;
    }
  }
  return count;
}

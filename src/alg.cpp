// Copyright 2021 NNTU-CS
void bubbleSort(int *arr, int len) {
  for (int i = 0; i < len - 1; i++) {
    for (int j = 0; j < len - i - 1; j++) {
      if (arr[j] > arr[j + 1]) {
        int temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
      }
    }
  }
}
int countPairs1(int *arr, int len, int value) {
  int count = 0;
  bubbleSort(arr, len);
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
  bubbleSort(arr, len);
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

int binarySearch(const int *arr, int len, int target) {
  int left = 0, right = len - 1;
  int count = 0;
  while (left <= right) {
    int mid = left + (right - left) / 2;
    if (arr[mid] == target) {
      int temp = mid;
      while (temp >= left && arr[temp] == target) {
        count++;
        temp--;
      }
      temp = mid + 1;
      while (temp <= right && arr[temp] == target) {
        count++;
        temp++;
      }
      break;
    } else if (arr[mid] < target) {
      left = mid + 1;
    } else {
      right = mid - 1;
    }
  }
  return count;
}

int countPairs3(int *arr, int len, int value) {
  int count = 0;
  bubbleSort(arr, len);
  for (int i = 0; i < len; i++) {
    int complement = value - arr[i];
    if (complement > arr[i]) {
      int occurrences = binarySearch(arr, len, complement);
      count += occurrences;
    } else if (complement == arr[i]) {
      int occurrences = binarySearch(arr, len, complement);
      count += (occurrences * (occurrences - 1)) / 2;
    }
  }
  return count;
}

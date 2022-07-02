#include <bits/stdc++.h>
using namespace std;
/* =========================== Function() ======================= */
/*After the first round of the algorithm, the largest element will be in the
correct position, and in general, after k rounds, the k largest elements will be
in the correct positions.*/

/*
void BubbleSort(int *arr, int n) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n - 1; j++) {
      if (arr[j] > arr[j + 1])
        swap(arr[j], arr[j + 1]);
    }
  }
}

void InsertionSort(int *arr, int n) {
  for (int i = 1; i < n; i++) {
    for (int j = i; j > 0; j--) {
      if (arr[j] < arr[j - 1])
        swap(arr[j], arr[j - 1]);
      else
        break;
    }
  }
}

void SelectionSort(int *arr, int n) {
  for (int i = 0; i < n; i++) {
    int min = i;
    for (int j = i + 1; j < n; j++) {
      if (arr[j] < arr[min])
        min = j;
    }
    swap(arr[min], arr[i]);
  }
}
*/

int Partation(int arr[], int low, int high) {
  int pivot, index, i;
  index = low;
  pivot = high;

  for (i = low; i < high; i++) {
    if (arr[i] < arr[pivot]) {
      // swap(&arr[i], &arr[index]);
      swap(arr[i], arr[index]);
      index++;
    }
  }
  // swap(&arr[pivot], &arr[index]);
  swap(arr[index], arr[pivot]);
  return index;
}

int QuickSort(int arr[], int low, int high) {
  // int pindex;
  while (low < high) {
    int pindex = Partation(arr, low, high);
    QuickSort(arr, low, pindex - 1);
    QuickSort(arr, pindex + 1, high);
  }
  return 0;
}

void Merge(int arr[], int start, int mid, int end) {
  int temp[end - start + 1];
  int lcount = start;
  int rcount = mid + 1;
  int bcount = 0;
  while (lcount <= mid and rcount <= end) {
    if (arr[lcount] <= arr[rcount])
      temp[bcount++] = arr[lcount++];
    else
      temp[bcount++] = arr[rcount++];
  }

  if (lcount > mid) {
    while (rcount <= end)
      temp[bcount++] = arr[rcount++];
  } else {
    while (lcount <= mid)
      temp[bcount++] = arr[lcount++];
  }

  for (bcount = 0; bcount < end - start + 1; bcount++)
    arr[start + bcount] = temp[bcount];
}
void MergeSort(int arr[], int start, int end) {
  while (start < end) {
    int mid = (start + end) / 2;
    MergeSort(arr, start, mid);
    MergeSort(arr, mid + 1, end);
    Merge(arr, start, mid, end);
  }
}

void CountSortAlgorithm(int arr[], int n) {
  int maxele = *max_element(arr, arr + n);
  int minele = *min_element(arr, arr + n);
  int range = maxele - minele + 1;
  int freq[range];
  memset(freq, 0, sizeof(freq));
  for (int i = 0; i < n; i++) {
    int idx = arr[i] - minele;
    freq[idx]++;
  }

  for (int i = 1; i < range; i++) {
    freq[i] = freq[i] + freq[i - 1];
  }

  int ans[n];
  for (int i = n - 1; i >= 0; i--) {
    int val = arr[i];
    int pos = freq[val - minele];
    ans[pos - 1] = val;
    freq[val - minele]--;
  }
  for (int i = 0; i < n; i++) {
    arr[i] = ans[i];
  }
}
/* =========================== Main() =========================== */
int main() {
  int arr[] = {9, 6, 3, 5, 3, 4, 3, 9, 6, 4, 6, 5, 8, 9, 9};
  int n = sizeof(arr) / sizeof(arr[0]);
  // int pivot = arr[n - 1];
  // cout << arr[n - 1] << endl;
  // MergeSort(arr, 0, n - 1);
  // cout << *max_element(arr.begin(), arr.end());
  CountSortAlgorithm(arr, n);
  for (int i = 0; i < n; i++)
    cout << arr[i] << " ";
  cout << endl;
  return 0;
}

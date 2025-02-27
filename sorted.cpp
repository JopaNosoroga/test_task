#include <iostream>
#include <mutex>
#include <vector>

class Sorting {
private:
  template <class T> static void swap(T &a, T &b) {
    T temp;
    temp = a;
    a = b;
    b = temp;
  }

  template <class T> static void heapify(T &arr, int n, int i) {
    std::lock_guard<std::recursive_mutex> locker(std::recursive_mutex);
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < n && arr[left] > arr[largest])
      largest = left;
    if (right < n && arr[right] > arr[largest])
      largest = right;
    if (largest != i) {
      swap(arr[i], arr[largest]);
      heapify(arr, n, largest);
    }
  }

public:
  template <class T> static void bubbleSort(T *arr, int count) {
    std::lock_guard<std::recursive_mutex> locker(std::recursive_mutex);
    for (int i = 0; i < count; i++) {
      bool is_swap = false;
      for (int j = 0; j < count - i - 1; j++) {
        if (arr[j] < arr[j + 1]) {
          swap(arr[j], arr[j + 1]);
          is_swap = true;
        }
      }
      if (!is_swap)
        break;
    }

    std::cout << "Сортировка пузырьком закончена\n";
    for (int i = 0; i < count; i++)
      std::cout << arr[i] << " bubble Sort" << '\n';
  }

  template <class T> static void heapSort(T *arr, int count) {
    std::lock_guard<std::recursive_mutex> locker(std::recursive_mutex);
    for (int i = count / 2 - 1; i >= 0; i--)
      heapify(arr, count, i);
    for (int i = count - 1; i > 0; i--) {
      swap(arr[0], arr[i]);

      heapify(arr, i, 0);
    }
    std::cout << "Пирамидальная сортировка выполнилась\n";
    for (int i = 0; i < count; i++)
      std::cout << arr[i] << '\n';
  }

  template <class T> static void insertionSort(T *arr, int count) {
    std::lock_guard<std::recursive_mutex> locker(std::recursive_mutex);
    for (int i = 0; i < count; i++) {
      int ind = i;
      for (int j = i + 1; j < count; j++) {
        if ((arr[i] < arr[j] && arr[ind] < arr[j]))
          ind = j;
      }
      swap(arr[ind], arr[i]);
    }

    std::cout << "Сортировка вставками выполнилась\n";
    for (int i = 0; i < count; i++)
      std::cout << arr[i] << " Insert sort" << '\n';
  }
};

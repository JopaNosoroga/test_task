#include "sorted.h"
#include <compare>
#include <functional>
#include <iostream>
#include <iterator>
#include <mutex>
#include <string>
#include <strstream>
#include <thread>

class RandomObject {
private:
  int value;
  std::string word;

public:
  RandomObject(int temp_value = 0, std::string temp_word = "") {
    value = temp_value;
    word = temp_word;
  }
  int getValue() { return value; }
  void setValue(int val) { value = val; }
  void setWord(std::string wor) { word = wor; }
  std::string getWord() { return word; }
  bool operator==(const RandomObject &b) { return value == b.value; }

  bool operator<(const RandomObject &b) { return value < b.value; }
  bool operator>(const RandomObject &b) { return value > b.value; }
};
std::ostream &operator<<(std::ostream &strm, RandomObject &a) {
  return strm << "[ value: " << a.getValue() << " word: " << a.getWord()
              << " ]";
}

template <class T> void work(T arr, int count) {
  std::thread t1(Sorting::insertionSort<RandomObject>, arr, count);
  std::thread t2(Sorting::bubbleSort<RandomObject>, arr, count);
  std::thread t3(Sorting::heapSort<RandomObject>, arr, count);
  t1.join();
  t2.join();
  t3.join();
}

int main() {

  RandomObject arr[6];
  arr[0] = RandomObject(10, "l");
  arr[1] = RandomObject(12, "fddf");
  arr[2] = RandomObject(3, "Jfve");
  arr[3] = RandomObject(1, "Sbroije");
  arr[4] = RandomObject(52, "ossldfwe");
  arr[5] = RandomObject(12, "dfwefwfwe");
  work(arr, std::size(arr));

  arr[0] = RandomObject(1, "abfere");
  arr[1] = RandomObject(2, "efwvwefw");
  arr[2] = RandomObject(3, "dfwverfve");
  arr[3] = RandomObject(4, "dfwrverw");
  arr[4] = RandomObject(5, "efwfererg");
  arr[5] = RandomObject(7, "dfbrtnter");

  work(arr, std::size(arr));

  arr[0].setValue(10);
  arr[1].setValue(9);
  arr[2].setValue(8);
  arr[3].setValue(7);
  arr[4].setValue(6);
  arr[5].setValue(5);
  arr[6].setValue(4);

  work(arr, std::size(arr));
}

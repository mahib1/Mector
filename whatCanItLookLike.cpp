#include <iostream>
#include <string>
#include <unordered_map>
#define str std::string

typedef struct {
  int a;
  int b;
  std::string c;
  char *d;
} myType;

typedef struct {
  int a;
  int b;
  std::string c;
  char *d;
  myType *mt;
} myType2;



class strArray {
  std::string *_buff;
  size_t _size;
  size_t _cap;
  std::string *_begin;
  std::string *_end;

public:
  strArray(std::string buff[], size_t size) {
    _size = size;
    _cap = _size * 2;
    _buff = new std::string[_cap];
    _begin = _buff;
    _end = _buff + _size;
    for (size_t i = 0; i < _size; i++) {
      _buff[i] = buff[i];
    }
  }
  strArray() {
    _cap = 32;
    _size = 0;
    _buff = new std::string[_cap];
    _begin = _buff;
    _end = _buff;
  }
  strArray(const strArray &other) {
    _size = other._size;
    _cap = other._cap;
    _buff = new std::string[_cap];
    for (size_t i = 0; i < _size; i++) {
      _buff[i] = other._buff[i];
    }
    _begin = _buff;
    _end = _buff + _size;
  }
  strArray(strArray &&other) noexcept {
    _buff = other._buff;
    _size = other._size;
    _cap = other._cap;
    _begin = other._begin;
    _end = other._end;
    other._buff = nullptr;
    other._size = 0;
    other._cap = 0;
    other._begin = nullptr;
    other._end = nullptr;
  }
  void push_back(const std::string &element) {
    if (_size > 0.7 * _cap)
      resize();
    _buff[_size] = element;
    _size++;
    _end = _buff + _size;
  }
  void resize() {
    _cap *= 2;
    std::string *newBuff = new std::string[_cap];
    for (size_t i = 0; i < _size; i++) {
      newBuff[i] = _buff[i];
    }
    delete[] _buff;
    _buff = newBuff;
    _begin = _buff;
    _end = _buff + _size;
  }
  void pop_back() {
    if (_size == 0) {
      throw std::out_of_range("pop_back() called on empty array");
    }
    _size--;
    _end = _buff + _size;
  }
  void reverse() {
    for (size_t i = 0; i < _size / 2; i++) {
      std::string temp = _buff[i];
      _buff[i] = _buff[_size - 1 - i];
      _buff[_size - 1 - i] = temp;
    }
  }
  std::string &operator[](size_t index) {
    if (index >= _size)
      throw std::out_of_range("Index out of range!");
    return _buff[index];
  }
  size_t size() const { return _size; }
  std::string *begin() { return _begin; }
  std::string *end() { return _end; }
  ~strArray() { delete[] _buff; }
};
;
class myTypeArray {
  myType *_buff;
  size_t _size;
  size_t _cap;
  myType *_begin;
  myType *_end;

public:
  myTypeArray(myType buff[], size_t size) {
    _size = size;
    _cap = _size * 2;
    _buff = new myType[_cap];
    _begin = _buff;
    _end = _buff + _size;
    for (size_t i = 0; i < _size; i++) {
      _buff[i] = buff[i];
    }
  }
  myTypeArray() {
    _cap = 32;
    _size = 0;
    _buff = new myType[_cap];
    _begin = _buff;
    _end = _buff;
  }
  myTypeArray(const myTypeArray &other) {
    _size = other._size;
    _cap = other._cap;
    _buff = new myType[_cap];
    for (size_t i = 0; i < _size; i++) {
      _buff[i] = other._buff[i];
    }
    _begin = _buff;
    _end = _buff + _size;
  }
  myTypeArray(myTypeArray &&other) noexcept {
    _buff = other._buff;
    _size = other._size;
    _cap = other._cap;
    _begin = other._begin;
    _end = other._end;
    other._buff = nullptr;
    other._size = 0;
    other._cap = 0;
    other._begin = nullptr;
    other._end = nullptr;
  }
  void push_back(const myType &element) {
    if (_size > 0.7 * _cap)
      resize();
    _buff[_size] = element;
    _size++;
    _end = _buff + _size;
  }
  void resize() {
    _cap *= 2;
    myType *newBuff = new myType[_cap];
    for (size_t i = 0; i < _size; i++) {
      newBuff[i] = _buff[i];
    }
    delete[] _buff;
    _buff = newBuff;
    _begin = _buff;
    _end = _buff + _size;
  }
  void pop_back() {
    if (_size == 0) {
      throw std::out_of_range("pop_back() called on empty array");
    }
    _size--;
    _end = _buff + _size;
  }
  void reverse() {
    for (size_t i = 0; i < _size / 2; i++) {
      myType temp = _buff[i];
      _buff[i] = _buff[_size - 1 - i];
      _buff[_size - 1 - i] = temp;
    }
  }
  myType &operator[](size_t index) {
    if (index >= _size)
      throw std::out_of_range("Index out of range!");
    return _buff[index];
  }
  size_t size() const { return _size; }
  myType *begin() { return _begin; }
  myType *end() { return _end; }
  ~myTypeArray() { delete[] _buff; }
};
;
class myType2Array {
  myType2 *_buff;
  size_t _size;
  size_t _cap;
  myType2 *_begin;
  myType2 *_end;

public:
  myType2Array(myType2 buff[], size_t size) {
    _size = size;
    _cap = _size * 2;
    _buff = new myType2[_cap];
    _begin = _buff;
    _end = _buff + _size;
    for (size_t i = 0; i < _size; i++) {
      _buff[i] = buff[i];
    }
  }
  myType2Array() {
    _cap = 32;
    _size = 0;
    _buff = new myType2[_cap];
    _begin = _buff;
    _end = _buff;
  }
  myType2Array(const myType2Array &other) {
    _size = other._size;
    _cap = other._cap;
    _buff = new myType2[_cap];
    for (size_t i = 0; i < _size; i++) {
      _buff[i] = other._buff[i];
    }
    _begin = _buff;
    _end = _buff + _size;
  }
  myType2Array(myType2Array &&other) noexcept {
    _buff = other._buff;
    _size = other._size;
    _cap = other._cap;
    _begin = other._begin;
    _end = other._end;
    other._buff = nullptr;
    other._size = 0;
    other._cap = 0;
    other._begin = nullptr;
    other._end = nullptr;
  }
  void push_back(const myType2 &element) {
    if (_size > 0.7 * _cap)
      resize();
    _buff[_size] = element;
    _size++;
    _end = _buff + _size;
  }
  void resize() {
    _cap *= 2;
    myType2 *newBuff = new myType2[_cap];
    for (size_t i = 0; i < _size; i++) {
      newBuff[i] = _buff[i];
    }
    delete[] _buff;
    _buff = newBuff;
    _begin = _buff;
    _end = _buff + _size;
  }
  void pop_back() {
    if (_size == 0) {
      throw std::out_of_range("pop_back() called on empty array");
    }
    _size--;
    _end = _buff + _size;
  }
  void reverse() {
    for (size_t i = 0; i < _size / 2; i++) {
      myType2 temp = _buff[i];
      _buff[i] = _buff[_size - 1 - i];
      _buff[_size - 1 - i] = temp;
    }
  }
  myType2 &operator[](size_t index) {
    if (index >= _size)
      throw std::out_of_range("Index out of range!");
    return _buff[index];
  }
  size_t size() const { return _size; }
  myType2 *begin() { return _begin; }
  myType2 *end() { return _end; }
  ~myType2Array() { delete[] _buff; }
};
;
class umiiArray {
  std::unordered_map<int, int> *_buff;
  size_t _size;
  size_t _cap;
  std::unordered_map<int, int> *_begin;
  std::unordered_map<int, int> *_end;

public:
  umiiArray(std::unordered_map<int, int> buff[], size_t size) {
    _size = size;
    _cap = _size * 2;
    _buff = new std::unordered_map<int, int>[_cap];
    _begin = _buff;
    _end = _buff + _size;
    for (size_t i = 0; i < _size; i++) {
      _buff[i] = buff[i];
    }
  }
  umiiArray() {
    _cap = 32;
    _size = 0;
    _buff = new std::unordered_map<int, int>[_cap];
    _begin = _buff;
    _end = _buff;
  }
  umiiArray(const umiiArray &other) {
    _size = other._size;
    _cap = other._cap;
    _buff = new std::unordered_map<int, int>[_cap];
    for (size_t i = 0; i < _size; i++) {
      _buff[i] = other._buff[i];
    }
    _begin = _buff;
    _end = _buff + _size;
  }
  umiiArray(umiiArray &&other) noexcept {
    _buff = other._buff;
    _size = other._size;
    _cap = other._cap;
    _begin = other._begin;
    _end = other._end;
    other._buff = nullptr;
    other._size = 0;
    other._cap = 0;
    other._begin = nullptr;
    other._end = nullptr;
  }
  void push_back(const std::unordered_map<int, int> &element) {
    if (_size > 0.7 * _cap)
      resize();
    _buff[_size] = element;
    _size++;
    _end = _buff + _size;
  }
  void resize() {
    _cap *= 2;
    std::unordered_map<int, int> *newBuff =
        new std::unordered_map<int, int>[_cap];
    for (size_t i = 0; i < _size; i++) {
      newBuff[i] = _buff[i];
    }
    delete[] _buff;
    _buff = newBuff;
    _begin = _buff;
    _end = _buff + _size;
  }
  void pop_back() {
    if (_size == 0) {
      throw std::out_of_range("pop_back() called on empty array");
    }
    _size--;
    _end = _buff + _size;
  }
  void reverse() {
    for (size_t i = 0; i < _size / 2; i++) {
      std::unordered_map<int, int> temp = _buff[i];
      _buff[i] = _buff[_size - 1 - i];
      _buff[_size - 1 - i] = temp;
    }
  }
  std::unordered_map<int, int> &operator[](size_t index) {
    if (index >= _size)
      throw std::out_of_range("Index out of range!");
    return _buff[index];
  }
  size_t size() const { return _size; }
  std::unordered_map<int, int> *begin() { return _begin; }
  std::unordered_map<int, int> *end() { return _end; }
  ~umiiArray() { delete[] _buff; }
};
;

int main() {
  strArray stringArray;
  stringArray.push_back("HEHEHE");

  for (int i = 0; i < 32; i++) {
    stringArray.push_back("hehehe" + std::to_string(i));
  }

  for (int i = 0; i < stringArray.size(); i++) {
    std::cout << stringArray[i] << std::endl;
  }

  for (auto i = stringArray.begin(); i != stringArray.end(); i++) {
    std::cout << *i << std::endl;
  }

  stringArray[0] = "MAHIB";
  std::cout << stringArray[0] << std::endl;

  myTypeArray myType1Array;
  char d[] = "MAHIB";
  myType1Array.push_back({5, 6, "hehehe", d});
  std::cout << myType1Array[0].d << std::endl;

  myType2Array myTypeArray2;
  myType ele = {7, 8, "eheheheh", d};
  myTypeArray2.push_back({5, 6, "HEHEHHEHE", d, &ele});

  std::cout << myTypeArray2[0].mt->d << std::endl;

  umiiArray mapArray;
  std::unordered_map<int, int> hehe1 =
      std::unordered_map<int, int>({{1, 2}, {3, 4}});
  mapArray.push_back(hehe1);
  return 0;
}

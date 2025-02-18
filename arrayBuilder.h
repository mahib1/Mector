#pragma once

#include <iostream>
#include <mutex>
#include <stdexcept>
#include <stdlib.h>

#define DEFAULT_CAP_VALUE 32

#define ArrayClassBuilder_N(type)                                                \
  class type##Array {                                                          \
    type *_buff;                                                               \
    size_t _size;                                                              \
    size_t _cap;                                                               \
    type *_begin;                                                              \
    type *_end;                                                                \
    mutable std::recursive_mutex _mutex;                                       \
                                                                               \
  public:                                                                      \
    type##Array(type buff[], size_t size) {                                    \
      std::lock_guard<std::recursive_mutex> lock(_mutex);                      \
      _size = size;                                                            \
      _cap = _size * 2;                                                        \
      _buff = new type[_cap];                                                  \
      _begin = _buff;                                                          \
      _end = _buff + _size;                                                    \
      for (size_t i = 0; i < _size; i++) {                                     \
        _buff[i] = buff[i];                                                    \
      }                                                                        \
    }                                                                          \
                                                                               \
    type##Array() {                                                            \
      std::lock_guard<std::recursive_mutex> lock(_mutex);                      \
      _cap = DEFAULT_CAP_VALUE;                                                \
      _size = 0;                                                               \
      _buff = new type[_cap];                                                  \
      _begin = _buff;                                                          \
      _end = _buff;                                                            \
    }                                                                          \
                                                                               \
    type##Array(const type##Array &other) {                                    \
      std::lock_guard<std::recursive_mutex> lock(other._mutex);                \
      _size = other._size;                                                     \
      _cap = other._cap;                                                       \
      _buff = new type[_cap];                                                  \
      for (size_t i = 0; i < _size; i++) {                                     \
        _buff[i] = other._buff[i];                                             \
      }                                                                        \
      _begin = _buff;                                                          \
      _end = _buff + _size;                                                    \
    }                                                                          \
                                                                               \
    type##Array &operator=(const type##Array &other) {                         \
      if (this != &other) {                                                    \
        std::lock_guard<std::recursive_mutex> lock1(this->_mutex);             \
        std::lock_guard<std::recursive_mutex> lock2(other._mutex);             \
                                                                               \
        delete[] _buff;                                                        \
                                                                               \
        _size = other._size;                                                   \
        _cap = other._cap;                                                     \
        _buff = new type[_cap];                                                \
        for (size_t i = 0; i < _size; i++) {                                   \
          _buff[i] = other._buff[i];                                           \
        }                                                                      \
        _begin = _buff;                                                        \
        _end = _buff + _size;                                                  \
      }                                                                        \
      return *this;                                                            \
    }                                                                          \
                                                                               \
    type##Array(type##Array &&other) noexcept {                                \
      std::lock_guard<std::recursive_mutex> lock(other._mutex);                \
      _buff = other._buff;                                                     \
      _size = other._size;                                                     \
      _cap = other._cap;                                                       \
      _begin = other._begin;                                                   \
      _end = other._end;                                                       \
      other._buff = nullptr;                                                   \
      other._size = 0;                                                         \
      other._cap = 0;                                                          \
      other._begin = nullptr;                                                  \
      other._end = nullptr;                                                    \
    }                                                                          \
                                                                               \
    void push_back(const type &element) {                                      \
      std::lock_guard<std::recursive_mutex> lock(_mutex);                      \
      if (_size > 0.7 * _cap)                                                  \
        resize();                                                              \
      _buff[_size] = element;                                                  \
      _size++;                                                                 \
      _end = _buff + _size;                                                    \
    }                                                                          \
                                                                               \
    void resize() {                                                            \
      std::lock_guard<std::recursive_mutex> lock(_mutex);                      \
      _cap *= 2;                                                               \
      type *newBuff = new type[_cap];                                          \
      for (size_t i = 0; i < _size; i++) {                                     \
        newBuff[i] = _buff[i];                                                 \
      }                                                                        \
      delete[] _buff;                                                          \
      _buff = newBuff;                                                         \
      _begin = _buff;                                                          \
      _end = _buff + _size;                                                    \
    }                                                                          \
                                                                               \
    void pop_back() {                                                          \
      std::lock_guard<std::recursive_mutex> lock(_mutex);                      \
      if (_size == 0) {                                                        \
        throw std::out_of_range("pop_back() called on empty array");           \
      }                                                                        \
      _size--;                                                                 \
      _end = _buff + _size;                                                    \
    }                                                                          \
                                                                               \
    void reverse() {                                                           \
      std::lock_guard<std::recursive_mutex> lock(_mutex);                      \
      for (size_t i = 0; i < _size / 2; i++) {                                 \
        type temp = _buff[i];                                                  \
        _buff[i] = _buff[_size - 1 - i];                                       \
        _buff[_size - 1 - i] = temp;                                           \
      }                                                                        \
    }                                                                          \
                                                                               \
    type &operator[](size_t index) {                                           \
      std::lock_guard<std::recursive_mutex> lock(_mutex);                      \
      if (index >= _size)                                                      \
        throw std::out_of_range("Index out of range!");                        \
      return _buff[index];                                                     \
    }                                                                          \
                                                                               \
    size_t size() const {                                                      \
      std::lock_guard<std::recursive_mutex> lock(_mutex);                      \
      return _size;                                                            \
    }                                                                          \
                                                                               \
    type *begin() { return _begin; }                                           \
    type *end() { return _end; }                                               \
                                                                               \
    ~type##Array() {                                                           \
      std::lock_guard<std::recursive_mutex> lock(_mutex);                      \
      delete[] _buff;                                                          \
    }                                                                          \
  };

#define ArrayN(type) type##Array


#define ArrayClassBuilder_M(type)                                                \
  class type##Array {                                                          \
    type *_buff;                                                               \
    size_t _size;                                                              \
    size_t _cap;                                                               \
    type *_begin;                                                              \
    type *_end;                                                                \
    mutable std::recursive_mutex _mutex;                                       \
                                                                               \
  public:                                                                      \
    type##Array() {                                                            \
      std::lock_guard<std::recursive_mutex> lock(_mutex);                      \
      _cap = DEFAULT_CAP_VALUE;                                                \
      _size = 0;                                                               \
      _buff = new type[_cap];                                                  \
      _begin = _buff;                                                          \
      _end = _buff;                                                            \
    }                                                                          \
                                                                               \
    type##Array(const type##Array &other) = delete;                            \
    type##Array &operator=(const type##Array &other) = delete;                 \
                                                                               \
    type##Array(type##Array &&other) noexcept {                                \
      std::lock_guard<std::recursive_mutex> lock(other._mutex);                \
      _buff = other._buff;                                                     \
      _size = other._size;                                                     \
      _cap = other._cap;                                                       \
      _begin = other._begin;                                                   \
      _end = other._end;                                                       \
      other._buff = nullptr;                                                   \
      other._size = 0;                                                         \
      other._cap = 0;                                                          \
      other._begin = nullptr;                                                  \
      other._end = nullptr;                                                    \
    }                                                                          \
                                                                               \
    type##Array &operator=(type##Array &&other) noexcept {                     \
      if (this != &other) {                                                    \
        std::lock_guard<std::recursive_mutex> lock1(this->_mutex);             \
        std::lock_guard<std::recursive_mutex> lock2(other._mutex);             \
                                                                               \
        delete[] _buff;                                                        \
        _buff = other._buff;                                                   \
        _size = other._size;                                                   \
        _cap = other._cap;                                                     \
        _begin = other._begin;                                                 \
        _end = other._end;                                                     \
                                                                               \
        other._buff = nullptr;                                                 \
        other._size = 0;                                                       \
        other._cap = 0;                                                        \
        other._begin = nullptr;                                                \
        other._end = nullptr;                                                  \
      }                                                                        \
      return *this;                                                            \
    }                                                                          \
                                                                               \
    void push_back(type element) {                                             \
      std::lock_guard<std::recursive_mutex> lock(_mutex);                      \
      if (_size > 0.7 * _cap)                                                  \
        resize();                                                              \
      _buff[_size] = std::move(element);                                       \
      _size++;                                                                 \
      _end = _buff + _size;                                                    \
    }                                                                          \
                                                                               \
    void resize() {                                                            \
      std::lock_guard<std::recursive_mutex> lock(_mutex);                      \
      _cap *= 2;                                                               \
      type *newBuff = new type[_cap];                                          \
      for (size_t i = 0; i < _size; i++) {                                     \
        newBuff[i] = std::move(_buff[i]);                                      \
      }                                                                        \
      delete[] _buff;                                                          \
      _buff = newBuff;                                                         \
      _begin = _buff;                                                          \
      _end = _buff + _size;                                                    \
    }                                                                          \
                                                                               \
    void pop_back() {                                                          \
      std::lock_guard<std::recursive_mutex> lock(_mutex);                      \
      if (_size == 0) {                                                        \
        throw std::out_of_range("pop_back() called on empty array");           \
      }                                                                        \
      _size--;                                                                 \
      _end = _buff + _size;                                                    \
    }                                                                          \
                                                                               \
    void reverse() {                                                           \
      std::lock_guard<std::recursive_mutex> lock(_mutex);                      \
      for (size_t i = 0; i < _size / 2; i++) {                                 \
        type temp = std::move(_buff[i]);                                       \
        _buff[i] = std::move(_buff[_size - 1 - i]);                            \
        _buff[_size - 1 - i] = std::move(temp);                                \
      }                                                                        \
    }                                                                          \
                                                                               \
    type &operator[](size_t index) {                                           \
      std::lock_guard<std::recursive_mutex> lock(_mutex);                      \
      if (index >= _size)                                                      \
        throw std::out_of_range("Index out of range!");                        \
      return _buff[index];                                                     \
    }                                                                          \
                                                                               \
    size_t size() const {                                                      \
      std::lock_guard<std::recursive_mutex> lock(_mutex);                      \
      return _size;                                                            \
    }                                                                          \
                                                                               \
    type *begin() { return _begin; }                                           \
    type *end() { return _end; }                                               \
                                                                               \
    ~type##Array() {                                                           \
      std::lock_guard<std::recursive_mutex> lock(_mutex);                      \
      delete[] _buff;                                                          \
    }                                                                          \
  };

#define ArrayM(type) type##Array



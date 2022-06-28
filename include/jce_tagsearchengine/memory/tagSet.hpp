#pragma once
#include <jce/binarySearchTree.hpp>
#include <jce/memory.hpp>
#include <vector>
#include <functional>

namespace jce { 
  namespace searchEngine {
    template<typename T>
    class Tag: public jce::BinarySearchTree<T> {
      public: constexpr Tag();
      public: constexpr Tag(const BinarySearchTree<T>& other);
      public: constexpr Tag(const BinarySearchTree<T>&& other);
      public: template <typename Iter> constexpr Tag(Iter& front, Iter& back);
      public: constexpr Tag(std::initializer_list<T> init);

      Tag intersection(const Tag<T>& other) const;
      Tag Union(const Tag<T>& other) const;
    };
  }
}

template<typename T> inline constexpr jce::searchEngine::Tag<T>::Tag(): jce::BinarySearchTree<T>() {};
template<typename T> inline constexpr jce::searchEngine::Tag<T>::Tag(const BinarySearchTree<T>& other):  jce::BinarySearchTree<T>(other) {};
template<typename T> inline constexpr jce::searchEngine::Tag<T>::Tag(const BinarySearchTree<T>&& other): jce::BinarySearchTree<T>(other) {};
template<typename T> template <typename Iter> inline constexpr jce::searchEngine::Tag<T>::Tag(Iter& front, Iter& back):  jce::BinarySearchTree<T>(front, back) {};
template<typename T> inline constexpr jce::searchEngine::Tag<T>::Tag(std::initializer_list<T> init): jce::BinarySearchTree<T>(init) {};


template<typename T> inline jce::searchEngine::Tag<T> jce::searchEngine::Tag<T>::intersection(const Tag<T>& other) const {
  if (other.size() == 0) { return *this; }
  if (this->size() == 0) { return other; }
  auto aFront = this->cbegin();
  auto bFront = other.cbegin();
  Tag<T> out;
  while (aFront != this->end() && bFront != other.end()) {
    if (*aFront == *bFront) {
      out.getBuffer().push_back(*aFront);
    }
    if (*aFront < *bFront) {
      aFront++;
    }
    else {
      bFront++;
    }
  }
  return out;
}
template<typename T> inline jce::searchEngine::Tag<T> jce::searchEngine::Tag<T>::Union(const Tag<T>& other) const {
  if (other.size() == 0) { return *this; }
  if (this->size() == 0) { return other; }
  auto aFront = this->cbegin();
  auto bFront = other.cbegin();
  Tag<T> out({*aFront});
  while (aFront != this->end() && bFront != other.end()) {
    if (*aFront > out.getBuffer().back()) {
      out.getBuffer().push_back(*aFront);
    }
    if (*bFront > out.getBuffer().back()) {
      out.getBuffer().push_back(*bFront);
    }
    if (*aFront < *bFront) {
      aFront++;
    }
    else {
      bFront++;
    }
  }
  return out;
}
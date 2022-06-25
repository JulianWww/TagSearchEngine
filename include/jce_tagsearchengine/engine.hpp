#pragma once
#include <unordered_map>
#include <jce_tagsearchengine/tagSet.hpp>
#include <memory>
#include <mutex>

#define LOCK this->mutex.lock()
#define UNLOCK this->mutex.unlock()

namespace jce {
  template<typename T>
  class TagSearchEngine {
    private: size_t tagIdx = 0;
    private: std::unordered_map<std::string, size_t> tagToIdx;
    private: std::unordered_map<size_t, searchEngine::Tag<T>> tagMap;
    private: std::mutex mutex;

    public: searchEngine::Tag<T> search(const std::vector<size_t> tags);

    public: void removeTag(const std::string& name);
    public: void removeTag(const size_t& idx);
    public: size_t addTag(const std::string& name);
    public: size_t addTag(const std::string& name, searchEngine::Tag<T>& tag);
    public: searchEngine::Tag<T>* getTag(const size_t& idx);
    public: searchEngine::Tag<T>* getTag(const std::string& name);

    private: void removeTag(const std::string& name, const size_t& idx);
  };
}

template<typename T> inline void jce::TagSearchEngine<T>::removeTag(const std::string& name) {
  if (this->tagToIdx.contains(name))
    this->removeTag(name, this->tagToIdx[name]);
}
template<typename T> inline void jce::TagSearchEngine<T>::removeTag(const size_t& key) {
  for (auto const& idx: this->tagToIdx) {
    if (idx.second == key)
      this->removeTag(idx.first, key);
  }
}
template<typename T> inline size_t jce::TagSearchEngine<T>::addTag(const std::string& name) {
  searchEngine::Tag<T> tag;
  return this->addTag(name, tag);
}
template<typename T> inline size_t jce::TagSearchEngine<T>::addTag(const std::string& name, searchEngine::Tag<T>& tag) {
  if (!this->tagToIdx.contains(name)) {
    LOCK;
    this->tagToIdx.insert({name, this->tagIdx});
    this->tagMap.insert({this->tagIdx, tag});
    this->tagIdx++;
    UNLOCK;
    return this->tagIdx-1;
  }
  return -1;
}
template<typename T> inline jce::searchEngine::Tag<T>* jce::TagSearchEngine<T>::getTag(const size_t& idx) { 
  if (this->tagMap.contains(idx))
    return &(this->tagMap[idx]);
  return nullptr;
}
template<typename T> inline jce::searchEngine::Tag<T>* jce::TagSearchEngine<T>::getTag(const std::string& name) {
  if (this->tagToIdx.contains(name))
    return this->getTag(this->tagToIdx[name]);
  return nullptr;
}

template<typename T> inline void jce::TagSearchEngine<T>::removeTag(const std::string& name, const size_t& idx) {
  LOCK;
  this->tagToIdx.erase(name);
  this->tagMap.erase(idx);
  UNLOCK;
}
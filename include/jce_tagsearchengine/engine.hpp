#pragma once
#include <unordered_map>
#include <jce_tagsearchengine/tagSet.hpp>
#include <memory>

namespace jce {
  template<typename T>
  class TagSearchEngine {
    protected: std::unordered_map<std::string, size_t> tagToIdx;
    protected: std::vector<searchEngine::Tag<T>>

    public: searchEngine::Tag<T> search(const std::vector<size_t> tags);
  };
}
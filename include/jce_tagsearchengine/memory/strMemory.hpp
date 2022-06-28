#pragma once
#include <unordered_map>
#include <memory>
#include <jce_tagsearchengine/memory/tagSet.hpp>

#define OPERATOR_AT(idx)                                                                            \
    if (this->indices.contains(idx)) {                                                              \
        return this->indices[idx].get();                                                            \
    }                                                                                               \
    else {                                                                                          \
        jce::StrEngineData<T>* data = new StrEngineData<T>;                                         \
        this->indices.insert({ idx, std::unique_ptr<jce::StrEngineData<T>>(data) });                \
        return data;                                                                                \
    }                                                                                               \

namespace jce {
    template <typename T>
    class StrEngineData {
        public: std::unordered_map<char, std::unique_ptr<StrEngineData>> indices;
        public: jce::searchEngine::Tag<T> tag;

        public: StrEngineData* operator[](const char& idx);
        public: const StrEngineData* operator[](const char& idx) const;

        public: void insert(const std::string& idx, const T& data);
        public: void remove(const std::string& idx, const T& data);

        public: jce::searchEngine::Tag<T> search(const size_t& size) const;
        public: bool searchRecursive(jce::searchEngine::Tag<T>& tag, size_t distance) const;

        public: jce::searchEngine::Tag<T>* getElement(const std::string& str);
        public: jce::searchEngine::Tag<T>* getElement(const std::string::const_iterator& iter, const std::string::const_iterator& end);
    };
}

template <typename T> inline jce::StrEngineData<T>* jce::StrEngineData<T>::operator[](const char& idx) {
    OPERATOR_AT(idx);
}
template <typename T> inline const jce::StrEngineData<T>* jce::StrEngineData<T>::operator[](const char& idx) const {
    OPERATOR_AT(idx);
}

template <typename T> inline void jce::StrEngineData<T>::insert(const std::string& idx, const T& data) {
    this->getElement(idx)->insert(data);
}
template <typename T> inline void jce::StrEngineData<T>::remove(const std::string& idx, const T& data) {
    this->getElement(idx)->remove(data);
}

template <typename T> inline jce::searchEngine::Tag<T> jce::StrEngineData<T>::search(const size_t& size) const {
    jce::searchEngine::Tag<T> _tag = this->tag;
    size_t deapth = 1;
    while (_tag.size() < size) {
        if (!this->searchRecursive(_tag, deapth)) {
            return _tag;
        }
        deapth++;
    }
    return _tag;
}
template <typename T> inline bool jce::StrEngineData<T>::searchRecursive(jce::searchEngine::Tag<T>& _tag, size_t distance) const {
    if (distance == 0) {
        _tag = _tag.Union(this->tag);
        return true;
    }
    else {
        bool success = false;
        for (auto& value: this->indices) {
            success = value.second->searchRecursive(_tag, distance-1) | success;
        }
        return success;
    }
}

template <typename T> inline jce::searchEngine::Tag<T>* jce::StrEngineData<T>::getElement(const std::string& str) {
    return this->getElement(str.begin(), str.end());
}
template <typename T> inline jce::searchEngine::Tag<T>* jce::StrEngineData<T>::getElement(const std::string::const_iterator& iter, const std::string::const_iterator& end) {
    if (iter == end)
        return &(this->tag);
    char val = *iter;

    return (*this)[val]->getElement(std::next(iter), end);
}

#undef OPERATOR_AT
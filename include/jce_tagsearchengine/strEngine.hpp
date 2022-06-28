#pragma once
#include <unordered_map>
#include <jce_tagsearchengine/memory/strMemory.hpp>
#include <jce_tagsearchengine/utils.hpp>

#define LOCK this->mutex.lock()
#define UNLOCK this->mutex.unlock()

namespace jce {
    template <typename T, typename Hash>
    class StrSearchEngine {
        using MemoryType        = jce::StrEngineData<T>;

        private: MemoryType memory;
    };
}
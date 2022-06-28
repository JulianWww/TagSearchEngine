#pragma once
#include <unordered_map>
#include <jce_tagsearchengine/memory/strMemory.hpp>
#include <jce_tagsearchengine/utils.hpp>

#define LOCK this->mutex.lock()
#define UNLOCK this->mutex.unlock()

namespace jce {
    template <typename T>
    class StrSearchEngine: public jce::StrEngineData<T> {
    };
}

#undef LOCK
#undef UNLOCK
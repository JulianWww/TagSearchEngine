#pragma once
#include <string>

namespace jce {
    template <typename T> 
    struct to_string {
        std::string operator()(const T& val);
    };
}

template <typename T>
std::string jce::to_string<T>::operator()(const T& val) {
    return std::to_string(val);
}
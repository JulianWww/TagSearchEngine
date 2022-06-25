#include <iostream>
#include <jce_tagsearchengine/tagSet.hpp>

int main(int argc, char **) {
  jce::searchEngine::Tag<size_t> a({1, 4, 9});
  jce::searchEngine::Tag<size_t> b({2, 4, 8});

  auto c = a.Union(b);
  return 1;
}
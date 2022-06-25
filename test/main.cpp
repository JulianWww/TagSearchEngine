#include <iostream>
#include <jce_tagsearchengine/engine.hpp>

int main(int argc, char **) {
  jce::TagSearchEngine<size_t> engine;
  jce::searchEngine::Tag<size_t> _tag1 = {1, 3, 5, 7};
  jce::searchEngine::Tag<size_t> _tag2 = {0, 3, 6, 8};

  engine.addTag("hello", _tag1);
  engine.addTag("booho", _tag2);

  auto data = engine.search({0, 1});

  return 1;
}
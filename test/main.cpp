#include <iostream>
#include <jce_tagsearchengine/engine.hpp>

int main(int argc, char **) {
  jce::TagSearchEngine<size_t> engine;
  jce::searchEngine::Tag<size_t> tag = {1, 3, 5, 7};

  engine.addTag("hello");
  engine.addTag("booho", tag);

  auto tag1 = engine.getTag("hello");
  auto tag2 = engine.getTag(1);

  return 1;
}
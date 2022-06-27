#include <iostream>
#include <jce_tagsearchengine/engine.hpp>
#include <fstream>

int main(int argc, char **) {
  jce::TagSearchEngine<size_t> engine;
  jce::searchEngine::Tag<size_t> _tag1 = {1, 3, 5, 7};
  jce::searchEngine::Tag<size_t> _tag2 = {0, 3, 6, 8};
  
  engine.addTag("hello", _tag1);
  engine.addTag("booho", _tag2);
  
  std::ofstream out("test.json");
  engine.saveTags(out);
  out.close();

  std::ifstream in("test.json");
  engine.loadTags(in);
  in.close();

  return 1;
}
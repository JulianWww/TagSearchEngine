#include <iostream>
#include <jce_tagsearchengine/engine.hpp>
#include <fstream>

int main(int argc, char **) {
  jce::StrEngineData<size_t> engine;

  engine.insert(std::string("hello"), 128);
  engine.insert(std::string("world"), 128);

  engine.remove(std::string("hello"), 128);

  auto val = engine.search(2);

  return 1;
}
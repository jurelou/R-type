//
// Created by marmus_a on 19/01/18.
//

#include "Papillon.hpp"

Papillon::Papillon(const Vertex &pos, const Vertex &dir) : Monster(pos, dir) {

}

Papillon::~Papillon() {}

extern "C" {
  IEntity*  instanciatePapillon(const Vertex& pos, const Vertex& dir) {
    return new Papillon(pos, dir);
  }
};
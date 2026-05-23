// Copyright 2021 NNTU-CS
#include "train.h"

Train::Train() : countOp(0), first(nullptr) {}
 
void Train::addCar(bool light) {
  Car *node = new Car;
  node->light = light;
  node->next = nullptr;
  node->prev = nullptr;
  if (first == nullptr) {
    first = node;
    node->next = node;
    node->prev = node;
  } else {
    Car *last = first->prev;
    node->prev = last;
    node->next = first;
    last->next = node;
    first->prev = node;
  }
}

int Train::getLength() {
  countOp = 0;
  if (first == nullptr) return 0;
 
  first->light = true;
  Car *p = first;
  int steps = 0;
 
  while (true) {
    p = p->next;
    ++steps;
    ++countOp;
 
    if (p->light) {
      p->light = false;
      for (int i = 0; i < steps; ++i) {
        p = p->prev;
        ++countOp;
      }
      if (!first->light) {
        return steps;
      }
      for (int i = 0; i < steps; ++i) {
        p = p->next;
        ++countOp;
      }
    }
  }
}
 
int Train::getOpCount() {
  return countOp;
}

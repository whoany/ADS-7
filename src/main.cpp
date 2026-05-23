// Copyright 2022 NNTU-CS
#include <iostream>
#include <cstdlib>
#include "train.h"

int main() {
  std::cout << "n,all_off,all_on,random_avg" << std::endl;
  std::srand(1);
  for (int n = 10; n <= 500; n += 10) {
    int count;
    Train tOff;
    count = n;
    while (count--)
      tOff.addCar(false);
    tOff.getLength();
    
    Train tOn;
    count = n;
    while (count--)
      tOn.addCar(true);
    tOn.getLength();
    int sum = 0;
    for (int k = 0; k < 30; k++) {
      Train tRnd;
      count = n;
      while (count--)
        tRnd.addCar(std::rand() % 2 == 1);
      tRnd.getLength();
      sum += tRnd.getOpCount();
    }
    double avg = sum / 30.0;
   
  std::cout << n << "," << tOff.getOpCount() << ","
              << tOn.getOpCount() << "," << avg << std::endl;
  }
  return 0;
}

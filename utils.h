// I wanna make my program well managed so I am creating a utils.h file

#ifndef UTILS_H
#define UTILS_H

#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;



int randInt(int min, int max) {
    return rand() % (max - min + 1) + min;
}

float randFloat(float min, float max) {
    return static_cast<float>(rand()) / RAND_MAX * (max - min) + min;
}

#endif
//
// Created by JoeGollin on 08/01/2021.
//

#ifndef PONGSFML_VECTOR_H
#define PONGSFML_VECTOR_H
#include <iostream>
#include <cmath>
#include <vector>
#include "Game.h"

class Vector
{
  public:
    Vector(int vballx, int vbally);
    void normalise();
    void multiply();


  private:
    int vballx;
    int vbally;
    int vx;
    int vy;
    float magnitude;
    //int ball_velx;
    //int ball_vely;
    //int bvy;
    //}int bvx;
};

#endif // PONGSFML_VECTOR_H

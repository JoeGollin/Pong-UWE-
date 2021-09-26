//
// Created by JoeGollin on 08/01/2021.
//
#include <cmath>
#include <vector>
#include <iostream>
#include "Vector.h"

void Vector::normalise()
{
  magnitude = std::sqrt((vx * vx) + (vy * vy));
  //ball_velx = vballx / magnitude;
  //ball_vely = vbally / magnitude;
  //Vector ball_velocity(ball_velx, ball_vely);
  //bvx = ball_velocity.ball_velx;
  //bvy = ball_velocity.ball_vely;
  return;
}

Vector::Vector(int vballx, int vbally)
{
  Vector ball_direction(2,3);
  vx = ball_direction.vballx;
  vy = ball_direction.vbally;
  ball_direction.normalise();
  return;
}

void Vector::multiply()
{
  //Vector operator* (float scalar);
  return;
}

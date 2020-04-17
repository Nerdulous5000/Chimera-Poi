#ifndef PARTICLE_H
#define PARTICLE_H
#include <Arduino.h>
#include "color.h"

class Particle
{
public:
    Particle();
    Particle(int pos);
    ~Particle();

    void Move(int newPos);
    int Index();
    Color GetColor();

private:
    Color m_color;

    int m_pos;
    float m_velocity;
};

#endif
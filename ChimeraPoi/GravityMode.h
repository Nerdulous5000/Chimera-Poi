#ifndef GRAVITY_MODE_H
#define GRAVITY_MODE_H

#define NUM_PARTICLES 5

#include <Arduino.h>
#include <vector>
#include <Adafruit_LIS3DH.h>
#include "LightMode.h"
#include "Particle.h"


// class GravityMode: public LightMode {
class GravityMode : public LightMode
{
public:
    GravityMode(Adafruit_LIS3DH *sensor);
    ~GravityMode();
    void Simulate();
    void Next();

private:
    Particle m_particles[NUM_PARTICLES];
    std::vector<Particle*> m_world;
    Adafruit_LIS3DH *m_sensor;
};

#endif
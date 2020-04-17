#include "Particle.h"

Particle::Particle() {
    m_color = Color(random(255), random(255), random(255));
    m_pos = -1;
    m_velocity = 0;
}
Particle::Particle(int pos)
{
    m_color = Color(random(255), random(255), random(255));
    m_pos = pos;
    m_velocity = 0;
}
Particle::~Particle()
{
}

void Particle::Move(int newPos)
{
    m_pos = newPos;
}

int Particle::Index()
{
    return m_pos;
}

Color Particle::GetColor()
{
    return m_color;
}

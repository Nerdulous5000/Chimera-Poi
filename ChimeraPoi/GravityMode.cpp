#include "GravityMode.h"


GravityMode::GravityMode(Adafruit_LIS3DH* sensor) {
    m_animated = true;
    m_index = 0;
    m_max_index = -1;
    m_sensor = sensor;
    m_world = std::vector<Particle *>(POILENGTH);

    if (NUM_PARTICLES <= POILENGTH) {
        for (int n = 0; n < NUM_PARTICLES ; n++ ) {
            m_particles[n] = Particle(n);
            m_world[n] = &m_particles[n];
        }
    }
}
GravityMode::~GravityMode() {
    for (int n = 0; n < POILENGTH ; n++) {
        if (m_world[n] != nullptr) {
            delete m_world[n];
        }
    }
}

void GravityMode::Simulate() {
    sensors_event_t event;
    m_sensor->getEvent(&event);
    float grav = event.acceleration.x;
    for(int n = 0; n < NUM_PARTICLES ; n++) {
        Particle* currentParticle = &m_particles[n];
        int checkDir = -1;
        if(grav < 0.0) {
            checkDir = 1;
        }
        int checkIndex = currentParticle->Index() + checkDir;
        if(m_world[checkIndex] == nullptr) {
            currentParticle->Move(checkIndex);
            m_world[checkIndex] = currentParticle;
            m_world[checkIndex - checkDir] = nullptr;
        }

    }
}

void GravityMode::Next() {
    Simulate();
    for(int n = 0; n < POILENGTH ; n++) {
        Particle * currentParticle = m_world[n];
        if (currentParticle != nullptr) {
            Color currentColor = currentParticle->GetColor();
            m_currentStrip[n * 3 + 0] = (char)currentColor.Red();
            m_currentStrip[n * 3 + 1] = (char)currentColor.Green();
            m_currentStrip[n * 3 + 2] = (char)currentColor.Blue();

            // m_currentStrip[n * 3 + 0] = (char)COLOR::MAGENTA.Red();
            // m_currentStrip[n * 3 + 1] = (char)COLOR::MAGENTA.Green();                  
            // m_currentStrip[n * 3 + 2] = (char)COLOR::MAGENTA.Blue();
        }
        else {
            m_currentStrip[n * 3 + 0] = 0x00;
            m_currentStrip[n * 3 + 1] = 0x00;
            m_currentStrip[n * 3 + 2] = 0x00;
        }
    }

    // memcpy(m_currentStrip, m_data + POILENGTH * 3 * m_index, POILENGTH * 3);
}

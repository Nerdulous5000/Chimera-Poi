#ifndef LIGHTMODE_H
#define LIGHTMODE_H

#include <Arduino.h>

#include "Color.h"
#include "conf.h"

// #include "Chimera_Poi.h"
// Data for mode must be at least the length of the poi LED strip

class LightMode
{
public:
    LightMode();
    LightMode(Color color);
    LightMode(char* data);
    LightMode(char* data, int numColumn);
    ~LightMode();

    // void Begin();
    virtual void Next();
    char* GetCurrentStrip();
    void Begin();

protected:
    bool m_animated;
    char* m_data;
    int m_index;
    int m_max_index;
    char m_currentStrip[POILENGTH * 3];
};

#endif
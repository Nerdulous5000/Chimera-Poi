#include "LightMode.h"

LightMode::LightMode()
{
    m_animated = false;
    m_max_index = 1;
    m_index = 0;
}

LightMode::LightMode(Color color) {
    m_animated = false;
    m_max_index = 1;
    char tempData[POILENGTH * 3] ;
    for (int n = 0; n < POILENGTH * 3; n += 3) {
        tempData[n + 0] = (char)color.Red();
        tempData[n + 1] = (char)color.Green();
        tempData[n + 2] = (char)color.Blue();
    }
    m_data = tempData;
    m_index = 0;
    memcpy(m_currentStrip, m_data, POILENGTH * 3);
}
LightMode::LightMode(char* data) {
    m_animated = false;
    m_max_index = 1;
    m_data = data;
    m_index = 0;
    memcpy(m_currentStrip, m_data, POILENGTH * 3);
}
LightMode::LightMode(char* data, int numColumn) {
    m_max_index = numColumn;
    if (numColumn <= 1)
        m_animated = false;
    else {
        m_animated = true;
    }
    m_data = data;
    m_index = 0;
    memcpy(m_currentStrip, m_data, POILENGTH * 3);
}
LightMode::~LightMode() {

}

void LightMode::Begin() {
    m_index = 0;
    memcpy(m_currentStrip, m_data, POILENGTH * 3);
}
void LightMode::Next() {
    if(m_animated) {
        m_index = (m_index + 1) % m_max_index;
        memcpy(m_currentStrip, m_data + POILENGTH * 3 * m_index, POILENGTH * 3);
    }
}
char* LightMode::GetCurrentStrip() {
    return m_currentStrip;
}
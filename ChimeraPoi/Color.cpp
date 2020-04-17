#include "Color.h"

Color::Color()
{
    m_red = 0;
    m_green = 0;
    m_blue = 0;
    m_alpha = 255;
}

Color::Color(int value)
{
    m_red = value;
    m_green = value;
    m_blue = value;
    m_alpha = 255;
}

Color::Color(int red, int green, int blue)
{
    m_red = red;
    m_green = green;
    m_blue = blue;
    m_alpha = 255;
}

Color::Color(int red, int green, int blue, int alpha)
{
    m_red = red;
    m_green = green;
    m_blue = blue;
    m_alpha = alpha;
}

Color::~Color()
{
}

int Color::Red()
{
    return m_red;
}
int Color::Green()
{
    return m_green;
}
int Color::Blue()
{
    return m_blue;
}
int Color::Alpha()
{
    return m_alpha;
}

double Color::R()
{
    return (double)m_red / 255;
}
double Color::G()
{
    return (double)m_green / 255;
}
double Color::B()
{
    return (double)m_blue / 255;
}
double Color::A()
{
    return (double)m_alpha / 255;
}

void Color::Recolor(int red, int green, int blue)
{
    m_red = red;
    m_green = green;
    m_blue = blue;
}

void Color::Recolor(int red, int green, int blue, int alpha)
{
    m_red = red;
    m_green = green;
    m_blue = blue;
    m_alpha = alpha;
}

Color Color::operator+(Color other)
{
    int newRed = m_red + (other.m_red * ((255 - m_red) / 255)) * other.m_alpha / 255;
    int newGreen = m_green + (other.m_green * ((255 - m_green) / 255)) * other.m_alpha / 255;
    int newBlue = m_blue + (other.m_blue * ((255 - m_blue) / 255)) * other.m_alpha / 255;
    return Color(newRed, newGreen, newBlue, m_alpha);
}

Color Color::operator-(Color other)
{
    int newRed = m_red - (other.m_red * ((m_red) / 255)) * other.m_alpha / 255;
    int newGreen = m_green - (other.m_green * ((m_green) / 255)) * other.m_alpha / 255;
    int newBlue = m_blue - (other.m_blue * ((m_blue) / 255)) * other.m_alpha / 255;
    return Color(newRed, newGreen, newBlue, m_alpha);
}
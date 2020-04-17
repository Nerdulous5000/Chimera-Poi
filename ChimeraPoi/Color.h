#ifndef COLOR_H
#define COLOR_H

class Color
{
public:
    Color();
    Color(int value);
    Color(int red, int green, int blue);
    Color(int red, int green, int blue, int alpha);
    ~Color();

    int Red();
    int Green();
    int Blue();
    int Alpha();

    double R();
    double G();
    double B();
    double A();

    void Recolor(int red, int green, int blue);
    void Recolor(int red, int green, int blue, int alpha);

    Color operator+(Color other);
    Color operator-(Color other);

private:
    int m_red;
    int m_green;
    int m_blue;
    int m_alpha;
};

namespace COLOR
{
// Defined Colors

static Color RED = Color(255, 0, 0, 255);
static Color GREEN = Color(0, 255, 0, 255);
static Color BLUE = Color(0, 0, 255, 255);

static Color CYAN = Color(0, 255, 255, 255);
static Color MAGENTA = Color(255, 0, 255, 255);
static Color YELLOW = Color(255, 255, 0, 255);

static Color WHITE = Color(255, 255, 255, 255);
static Color BLACK = Color(0, 0, 0, 255);
static Color BLANK = Color(0, 0, 0, 0);
} // namespace COLOR

#endif
#ifndef BMP_TEST_IMAGE_H
#define BMP_TEST_IMAGE_H

#endif

#include <vector>
#include <string>

struct Color {
    float r, g ,b;

    Color();
    Color(float r, float g, float b);
    ~Color();
};

class Image {
public:
    Image(int width, int height);
    ~Image();

    Color GetColor(int x, int y) const;
    void SetColor(const Color& color, int x, int y);
    void Export(const std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>& path) const;

private:
    int m_width;
    int m_height;
    std::vector<Color> m_colors;
};

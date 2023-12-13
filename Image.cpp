#include "Image.h"
#include <iostream>
#include <fstream>

Color::Color()
        : r(0), g(0), b(0)
{
}

Color::Color(float r, float g, float b)
        : r(r), g(g), b(b)
{
}

Color::~Color() {
}

Image::Image(int width, int height)
        : m_width(width), m_height(height), m_colors(std::vector<Color>(width * height))
{
}

Image::~Image() {
}

Color Image::GetColor(int x, int y) const {
    return m_colors[y * m_width + x];
}

void Image::SetColor(const Color &color, int x, int y) {
    m_colors[y * m_width + x].r = color.r;
    m_colors[y * m_width + x].g = color.g;
    m_colors[y * m_width + x].b = color.b;
}

void Image::Export(const std::basic_string<char, std::char_traits<char>, std::allocator<char>>& path) const {

    std::ofstream f;
    f.open(path, std::ios::out | std::ios::binary);

    unsigned char bmpPad[3] = {0, 0,0};
    const int paddingAmount = ((4 - (m_width * 3) % 4) % 4);

    const int fileSize = 14 + 40 + m_width * m_height * 3 + paddingAmount * m_height;

    unsigned char fileHeader[14] = {'B', 'M', 0,0,0, 0,0, 0,0, 54, 0, 0,0};

    fileHeader[2] = fileSize;
    fileHeader[3] = fileSize >> 8;
    fileHeader[4] = fileSize >> 16;
    fileHeader[5] = fileSize >> 24;

    unsigned char informationHeader[40] = {40, 0,0,0,0,0,0,0,0,0,0,0,1,0,24,0};

    informationHeader[4] = m_width;
    informationHeader[5] = m_width >> 8;
    informationHeader[6] = m_width >> 16;
    informationHeader[7] = m_width >> 24;

    informationHeader[8] = m_height;
    informationHeader[9] = m_height >> 8;
    informationHeader[10] = m_height >> 16;
    informationHeader[11] = m_height >> 24;

    f.write((char*)(fileHeader), 14);
    f.write((char*)(informationHeader), 40);

    for (int y = 0; y < m_height; ++y) {
        for (int x = 0; x < m_width; ++x) {

            unsigned char r = (unsigned char)(GetColor(x,y).r * 255.0f);
            unsigned char g = (unsigned char)(GetColor(x,y).g * 255.0f);
            unsigned char b = (unsigned char)(GetColor(x,y).b * 255.0f);

            unsigned char color[] = { b, g, r};

            f.write((char*)color, 3);
        }

        f.write((char*)bmpPad, paddingAmount);
    }

    f.close();
}

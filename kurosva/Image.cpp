#include "Image.h"

Image::Image(unsigned int width, unsigned int height)
    : width(width), height(height), data(width* height) {}

unsigned int Image::getWidth() const { return width; }
unsigned int Image::getHeight() const { return height; }
std::vector<Pixel>& Image::getData() { return data; }
const std::vector<Pixel>& Image::getData() const { return data; }

void Image::setData(const std::vector<Pixel>& newData) {
    data = newData;
}

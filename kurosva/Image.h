#ifndef IMAGE_H
#define IMAGE_H

#include <vector>
#include <cstdint>

struct Pixel {
    uint8_t b, g, r, a;
};

class Image {
private:
    std::vector<Pixel> data;
    unsigned int width, height;

public:
    Image(unsigned int width, unsigned int height);

    unsigned int getWidth() const;
    unsigned int getHeight() const;
    std::vector<Pixel>& getData();
    const std::vector<Pixel>& getData() const;

    void setData(const std::vector<Pixel>& newData);
};

#endif // IMAGE_H

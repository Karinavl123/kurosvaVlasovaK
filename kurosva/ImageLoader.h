#ifndef IMAGELOADER_H
#define IMAGELOADER_H

#include "Image.h"
#include "BMPHeaders.h"
#include <string>

class ImageLoader {
public:
    static Image loadFromFile(const std::string& filename);
};

#endif // IMAGELOADER_H

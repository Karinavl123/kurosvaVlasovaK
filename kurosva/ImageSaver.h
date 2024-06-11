#ifndef IMAGESAVER_H
#define IMAGESAVER_H

#include "Image.h"
#include "BMPHeaders.h"
#include <string>

class ImageSaver {
public:
    static void saveToFile(const Image& img, const std::string& filename);
};

#endif // IMAGESAVER_H

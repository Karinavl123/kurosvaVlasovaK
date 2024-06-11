#ifndef IMAGETRANSFORMER_H
#define IMAGETRANSFORMER_H

#include "Image.h"

class ImageTransformer {
public:
    static Image scale(const Image& img, double scaleFactor);
    static Image rotateLeft(const Image& img);
    static Image rotateRight(const Image& img);
    static Image flipVertical(const Image& img);
    static Image flipHorizontal(const Image& img);
};

#endif // IMAGETRANSFORMER_H

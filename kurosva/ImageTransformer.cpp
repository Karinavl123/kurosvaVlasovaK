#include "ImageTransformer.h"

Image ImageTransformer::scale(const Image& img, double scaleFactor) {
    unsigned int newWidth = static_cast<unsigned int>(img.getWidth() * scaleFactor);
    unsigned int newHeight = static_cast<unsigned int>(img.getHeight() * scaleFactor);

    Image scaledImg(newWidth, newHeight);
    std::vector<Pixel>& scaledData = scaledImg.getData();
    const std::vector<Pixel>& originalData = img.getData();

    for (unsigned int y = 0; y < newHeight; ++y) {
        for (unsigned int x = 0; x < newWidth; ++x) {
            unsigned int srcX = static_cast<unsigned int>(x / scaleFactor);
            unsigned int srcY = static_cast<unsigned int>(y / scaleFactor);
            scaledData[y * newWidth + x] = originalData[srcY * img.getWidth() + srcX];
        }
    }

    return scaledImg;
}

Image ImageTransformer::rotateLeft(const Image& img) {
    unsigned int newWidth = img.getHeight();
    unsigned int newHeight = img.getWidth();

    Image rotatedImg(newWidth, newHeight);
    std::vector<Pixel>& rotatedData = rotatedImg.getData();
    const std::vector<Pixel>& originalData = img.getData();

    for (unsigned int y = 0; y < newHeight; ++y) {
        for (unsigned int x = 0; x < newWidth; ++x) {
            rotatedData[y * newWidth + x] = originalData[x * img.getWidth() + (img.getWidth() - y - 1)];
        }
    }

    return rotatedImg;
}

Image ImageTransformer::rotateRight(const Image& img) {
    unsigned int newWidth = img.getHeight();
    unsigned int newHeight = img.getWidth();

    Image rotatedImg(newWidth, newHeight);
    std::vector<Pixel>& rotatedData = rotatedImg.getData();
    const std::vector<Pixel>& originalData = img.getData();

    for (unsigned int y = 0; y < newHeight; ++y) {
        for (unsigned int x = 0; x < newWidth; ++x) {
            rotatedData[y * newWidth + x] = originalData[(img.getHeight() - x - 1) * img.getWidth() + y];
        }
    }

    return rotatedImg;
}

Image ImageTransformer::flipVertical(const Image& img) {
    unsigned int width = img.getWidth();
    unsigned int height = img.getHeight();

    Image flippedImg(width, height);
    std::vector<Pixel>& flippedData = flippedImg.getData();
    const std::vector<Pixel>& originalData = img.getData();

    for (unsigned int y = 0; y < height; ++y) {
        for (unsigned int x = 0; x < width; ++x) {
            flippedData[y * width + x] = originalData[(height - y - 1) * width + x];
        }
    }

    return flippedImg;
}

Image ImageTransformer::flipHorizontal(const Image& img) {
    unsigned int width = img.getWidth();
    unsigned int height = img.getHeight();

    Image flippedImg(width, height);
    std::vector<Pixel>& flippedData = flippedImg.getData();
    const std::vector<Pixel>& originalData = img.getData();

    for (unsigned int y = 0; y < height; ++y) {
        for (unsigned int x = 0; x < width; ++x) {
            flippedData[y * width + x] = originalData[y * width + (width - x - 1)];
        }
    }

    return flippedImg;
}

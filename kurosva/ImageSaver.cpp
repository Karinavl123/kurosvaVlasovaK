#include "ImageSaver.h"
#include <fstream>
#include <stdexcept>

void ImageSaver::saveToFile(const Image& img, const std::string& filename) {
    std::ofstream file(filename, std::ios::binary);
    if (!file.is_open()) throw std::runtime_error("Не вдалося зберегти зображення.");

    BMPFileHeader fileHeader;
    BMPInfoHeader infoHeader;

    infoHeader.size = sizeof(BMPInfoHeader);
    infoHeader.width = img.getWidth();
    infoHeader.height = img.getHeight();
    infoHeader.planes = 1;
    infoHeader.bitCount = 32;
    infoHeader.compression = 0;
    infoHeader.sizeImage = img.getWidth() * img.getHeight() * 4;

    fileHeader.fileSize = sizeof(BMPFileHeader) + sizeof(BMPInfoHeader) + infoHeader.sizeImage;
    fileHeader.offsetData = sizeof(BMPFileHeader) + sizeof(BMPInfoHeader);

    file.write(reinterpret_cast<const char*>(&fileHeader), sizeof(fileHeader));
    file.write(reinterpret_cast<const char*>(&infoHeader), sizeof(infoHeader));

    for (int y = 0; y < infoHeader.height; ++y) {
        for (int x = 0; x < infoHeader.width; ++x) {
            const Pixel& pixel = img.getData()[(infoHeader.height - y - 1) * infoHeader.width + x];
            file.write(reinterpret_cast<const char*>(&pixel), sizeof(pixel));
        }
    }

    file.close();
}

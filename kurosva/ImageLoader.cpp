#include "ImageLoader.h"
#include <fstream>
#include <stdexcept>

Image ImageLoader::loadFromFile(const std::string& filename) {
    std::ifstream file(filename, std::ios::binary);
    if (!file.is_open()) throw std::runtime_error("Не вдалося завантажити зображення.");

    BMPFileHeader fileHeader;
    BMPInfoHeader infoHeader;

    file.read(reinterpret_cast<char*>(&fileHeader), sizeof(fileHeader));
    file.read(reinterpret_cast<char*>(&infoHeader), sizeof(infoHeader));

    if (fileHeader.fileType != 0x4D42) {
        throw std::runtime_error("Неправильний формат файлу (не BMP).");
    }

    Image img(infoHeader.width, infoHeader.height);

    const size_t rowStride = ((infoHeader.width * infoHeader.bitCount + 31) / 32) * 4;
    std::vector<uint8_t> rowData(rowStride);

    file.seekg(fileHeader.offsetData, file.beg);

    for (int y = 0; y < infoHeader.height; ++y) {
        file.read(reinterpret_cast<char*>(rowData.data()), rowStride);
        for (int x = 0; x < infoHeader.width; ++x) {
            size_t index = x * (infoHeader.bitCount / 8);
            img.getData()[(infoHeader.height - y - 1) * infoHeader.width + x] = { rowData[index], rowData[index + 1], rowData[index + 2], 255 };
        }
    }

    file.close();
    return img;
}

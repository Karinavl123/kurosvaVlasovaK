#ifndef BMPHEADERS_H
#define BMPHEADERS_H

#pragma pack(push, 1) // Забезпечує точність вирівнювання структур

struct BMPFileHeader {
    uint16_t fileType{ 0x4D42 }; // Тип файлу (BM)
    uint32_t fileSize{ 0 };       // Розмір файлу в байтах
    uint16_t reserved1{ 0 };      // Зарезервовано
    uint16_t reserved2{ 0 };      // Зарезервовано
    uint32_t offsetData{ 0 };     // Зсув до даних зображення
};

struct BMPInfoHeader {
    uint32_t size{ 0 };             // Розмір заголовку
    int32_t width{ 0 };             // Ширина зображення
    int32_t height{ 0 };            // Висота зображення
    uint16_t planes{ 1 };           // Кількість площин (завжди 1)
    uint16_t bitCount{ 0 };         // Кількість біт на піксель
    uint32_t compression{ 0 };      // Тип стиснення
    uint32_t sizeImage{ 0 };        // Розмір зображення в байтах
    int32_t xPixelsPerMeter{ 0 };   // Горизонтальна роздільна здатність
    int32_t yPixelsPerMeter{ 0 };   // Вертикальна роздільна здатність
    uint32_t colorsUsed{ 0 };       // Кількість кольорів
    uint32_t colorsImportant{ 0 };  // Важливі кольори
};

#pragma pack(pop)

#endif // BMPHEADERS_H

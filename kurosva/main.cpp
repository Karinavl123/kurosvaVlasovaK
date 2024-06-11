#include <iostream>
#include <locale.h>
#include <windows.h>
#include <io.h>
#include <fcntl.h>
#include "ImageLoader.h"
#include "ImageSaver.h"
#include "ImageTransformer.h"

int main() {
    // Встановлення локалі для коректного виводу кирилиці
    setlocale(LC_ALL, "uk_UA.utf8");
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    _setmode(_fileno(stdout), _O_U16TEXT);

    try {
        Image img = ImageLoader::loadFromFile("C:/TESTPHOTO/fotoin/302250.bmp");

        std::wcout << L"Оригінальне зображення завантажено." << std::endl;

        std::wcout << L"Оберіть дію: 1 - Масштабування, 2 - Поворот вліво, 3 - Поворот вправо, 4 - Вертикальний переворот, 5 - Горизонтальний переворот" << std::endl;
        int choice;
        std::wcin >> choice;

        Image transformedImg = img;
        switch (choice) {
        case 1: {
            std::wcout << L"Введіть коефіцієнт масштабування: ";
            double scaleFactor;
            std::wcin >> scaleFactor;
            transformedImg = ImageTransformer::scale(img, scaleFactor);
            break;
        }
        case 2:
            transformedImg = ImageTransformer::rotateLeft(img);
            break;
        case 3:
            transformedImg = ImageTransformer::rotateRight(img);
            break;
        case 4:
            transformedImg = ImageTransformer::flipVertical(img);
            break;
        case 5:
            transformedImg = ImageTransformer::flipHorizontal(img);
            break;
        default:
            std::wcout << L"Невірний вибір." << std::endl;
            return 1;
        }

        // Збереження трансформованого зображення у файл
        ImageSaver::saveToFile(transformedImg, "C:/TESTPHOTO/fotoout/output.bmp");

        std::wcout << L"Зображення успішно збережено до C:/TESTPHOTO/fotoout/output.bmp" << std::endl;
    }
    catch (const std::exception& e) {
        std::wcerr << L"Помилка: " << e.what() << std::endl;
    }

    return 0;
}

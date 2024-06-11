#include <iostream>
#include <locale.h>
#include <windows.h>
#include <io.h>
#include <fcntl.h>
#include "ImageLoader.h"
#include "ImageSaver.h"
#include "ImageTransformer.h"

int main() {
    // ������������ ����� ��� ���������� ������ ��������
    setlocale(LC_ALL, "uk_UA.utf8");
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    _setmode(_fileno(stdout), _O_U16TEXT);

    try {
        Image img = ImageLoader::loadFromFile("C:/TESTPHOTO/fotoin/302250.bmp");

        std::wcout << L"���������� ���������� �����������." << std::endl;

        std::wcout << L"������ ��: 1 - �������������, 2 - ������� ����, 3 - ������� ������, 4 - ������������ ���������, 5 - �������������� ���������" << std::endl;
        int choice;
        std::wcin >> choice;

        Image transformedImg = img;
        switch (choice) {
        case 1: {
            std::wcout << L"������ ���������� �������������: ";
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
            std::wcout << L"������� ����." << std::endl;
            return 1;
        }

        // ���������� ���������������� ���������� � ����
        ImageSaver::saveToFile(transformedImg, "C:/TESTPHOTO/fotoout/output.bmp");

        std::wcout << L"���������� ������ ��������� �� C:/TESTPHOTO/fotoout/output.bmp" << std::endl;
    }
    catch (const std::exception& e) {
        std::wcerr << L"�������: " << e.what() << std::endl;
    }

    return 0;
}

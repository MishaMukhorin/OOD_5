//
// Created by mrLogic on 10/17/2024.
//

#ifndef OOD_5_IIMAGE_H
#define OOD_5_IIMAGE_H

#include <string>

class IImage
{
public:
    // Возвращает путь относительно каталога документа
    virtual std::string GetPath()const = 0;
    // Ширина изображения в пикселях
    virtual int GetWidth()const = 0;
    // Высота изображения в пикселях
    virtual int GetHeight()const = 0;
    // Изменяет размер изображения
    virtual void Resize(int width, int height) = 0;

    virtual ~IImage() = default;
};

#endif //OOD_5_IIMAGE_H

//
// Created by mrLogic on 10/17/2024.
//

#ifndef OOD_5_IIMAGE_H
#define OOD_5_IIMAGE_H

#include <string>

class IImage
{
public:

    [[nodiscard]] virtual std::string GetPath()const = 0;

    [[nodiscard]] virtual int GetWidth()const = 0;

    [[nodiscard]] virtual int GetHeight()const = 0;

    virtual void Resize(int width, int height) = 0;

    virtual ~IImage() = default;
};

#endif //OOD_5_IIMAGE_H

//
// Created by mrLogic on 10/17/2024.
//

#include "Image.h"

void Image::Resize(int width, int height)
{
    if (height > 0)
    {
        m_height = height;
    }
    if (width > 0)
    {
        m_width = width;
    }
}

int Image::GetHeight() const
{
    return m_height;
}

int Image::GetWidth() const
{
    return m_width;
}

std::string Image::GetPath() const
{
    return m_path;
}

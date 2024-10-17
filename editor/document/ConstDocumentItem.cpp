//
// Created by mrLogic on 10/17/2024.
//
#include "ConstDocumentItem.h"

std::shared_ptr<const IImage> ConstDocumentItem::GetImage() const
{
    if (m_type != ItemType::Image)
    {
        return nullptr;
    }
    return std::static_pointer_cast<const IImage>(m_image);
}

std::shared_ptr<const IParagraph> ConstDocumentItem::GetParagraph() const
{
    if (m_type != ItemType::Paragraph)
    {
        return nullptr;
    }
    return std::static_pointer_cast<const IParagraph>(m_paragraph);
}

#ifndef OOD_5_CONSTDOCUMENTITEM_H
#define OOD_5_CONSTDOCUMENTITEM_H

#include <memory>
#include <string>
#include "Paragraph.h"
#include "Image.h"

enum class ItemType
{
    Image,
    Paragraph
};

class ConstDocumentItem
{
public:

    ConstDocumentItem(const std::string& imagePath, int height, int width):
            m_image(std::make_shared<Image>(imagePath, height, width)),
            m_type(ItemType::Image)
    {};

    explicit ConstDocumentItem(const std::string& text):
            m_paragraph(std::make_shared<Paragraph>(text)),
            m_type(ItemType::Paragraph)
    {};

	[[nodiscard]] std::shared_ptr<const IImage> GetImage() const;

	[[nodiscard]] std::shared_ptr<const IParagraph> GetParagraph()const;

	virtual ~ConstDocumentItem() = default;

private:
    ItemType m_type;
    std::shared_ptr<Image> m_image {};
    std::shared_ptr<Paragraph> m_paragraph {};

};

#endif //OOD_5_CONSTDOCUMENTITEM_H

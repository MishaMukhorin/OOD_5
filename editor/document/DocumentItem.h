//
// Created by mrLogic on 10/17/2024.
//

#ifndef OOD_5_DOCUMENTITEM_H
#define OOD_5_DOCUMENTITEM_H
#include <memory>
#include "ConstDocumentItem.h"


class DocumentItem: public ConstDocumentItem {
public:

    DocumentItem(const std::string& imagePath, int height, int width):
            ConstDocumentItem(imagePath, height, width)
    {};

    explicit DocumentItem(const std::string& text):
            ConstDocumentItem(text)
    {};

    std::shared_ptr<IImage> GetImage();

    std::shared_ptr<IParagraph> GetParagraph();

};


#endif //OOD_5_DOCUMENTITEM_H

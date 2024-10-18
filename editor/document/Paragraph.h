//
// Created by mrLogic on 10/17/2024.
//

#ifndef OOD_5_PARAGRAPH_H
#define OOD_5_PARAGRAPH_H

#include <utility>
#include "IParagraph.h"

class Paragraph: public IParagraph {
public:
    explicit Paragraph(std::string text): m_text(std::move(text)) {}

    [[nodiscard]] std::string GetText() const override;
    void SetText(const std::string& text) override;

private:
    std::string m_text;
};


#endif //OOD_5_PARAGRAPH_H

//
// Created by mrLogic on 10/17/2024.
//

#ifndef OOD_5_IPARAGRAPH_H
#define OOD_5_IPARAGRAPH_H
#include <string>

class IParagraph
{
public:
    [[nodiscard]] virtual std::string GetText()const = 0;
    virtual void SetText(const std::string& text) = 0;
    virtual ~IParagraph() = default;
};

#endif //OOD_5_IPARAGRAPH_H

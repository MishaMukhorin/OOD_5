//
// Created by mrLogic on 10/17/2024.
//

#ifndef OOD_5_INSERTIMAGECOMMAND_H
#define OOD_5_INSERTIMAGECOMMAND_H

#include <string>
#include <utility>
#include <vector>
#include <optional>
#include <stdexcept>
#include "../../document/DocumentItem.h"
#include "../AbstractCommand/AbstractCommand.h"

class InsertImageCommand: public AbstractCommand
{
public:
    static constexpr const char* name = "InsertImage";

    InsertImageCommand(std::vector<DocumentItem>& documentItems, std::string imagePath,
                       int width, int height, std::optional<size_t> position = std::nullopt)
            : m_documentItems(documentItems)
            , m_imagePath(std::move(imagePath))
            , m_width(width)
            , m_height(height)
            , m_position(position)
    {}

protected:
    void DoExecute() override;

    void DoUnexecute() override;

private:
    std::vector<DocumentItem>& m_documentItems;
    std::string m_imagePath;
    int m_width;
    int m_height;
    std::optional<size_t> m_position;
};

#endif //OOD_5_INSERTIMAGECOMMAND_H

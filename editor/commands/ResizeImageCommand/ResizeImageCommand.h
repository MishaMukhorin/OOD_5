//
// Created by mrLogic on 10/17/2024.
//

#ifndef OOD_5_RESIZEIMAGECOMMAND_H
#define OOD_5_RESIZEIMAGECOMMAND_H

#include <stdexcept>
#include <utility>
#include <vector>
#include <optional>
#include "../AbstractCommand/AbstractCommand.h"
#include "../../document/DocumentItem.h"

class ResizeImageCommand : public AbstractCommand
{
public:
    static constexpr const char* name = "ResizeImage";

    ResizeImageCommand(std::vector<DocumentItem> & documentItems,
                       int newWidth, int newHeight,
                       std::optional<size_t> position)
            : m_documentItems(documentItems), m_newHeight(newWidth), m_newWidth(newHeight), m_position(position) {};
protected:
    void DoExecute() override;
    void DoUnexecute() override;

private:
    std::vector<DocumentItem> & m_documentItems;
    int m_height = 0;
    int m_width = 0;
    int m_newHeight;
    int m_newWidth;
    std::optional<size_t> m_position;
};

#endif //OOD_5_RESIZEIMAGECOMMAND_H

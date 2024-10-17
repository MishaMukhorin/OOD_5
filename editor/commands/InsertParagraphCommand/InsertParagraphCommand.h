//
// Created by mrLogic on 10/17/2024.
//

#ifndef OOD_5_INSERTPARAGRAPHCOMMAND_H
#define OOD_5_INSERTPARAGRAPHCOMMAND_H

#include <string>
#include <utility>
#include <vector>
#include <optional>
#include <stdexcept>
#include "../../document/DocumentItem.h"
#include "../AbstractCommand/AbstractCommand.h"

class InsertParagraphCommand : public AbstractCommand
{
public:
    static constexpr const char* name = "InsertParagraph";

    InsertParagraphCommand(std::vector<DocumentItem>& documentItems,
                           std::string text,
                           std::optional<size_t> position)
            : m_documentItems(documentItems), m_text(std::move(text)), m_position(position) {};
protected:
    void DoExecute() override;
    void DoUnexecute() override;

private:
    std::vector<DocumentItem> & m_documentItems;
    std::string m_text;
    std::optional<size_t> m_position;
};


#endif //OOD_5_INSERTPARAGRAPHCOMMAND_H

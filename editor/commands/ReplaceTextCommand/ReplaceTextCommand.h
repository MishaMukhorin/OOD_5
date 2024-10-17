//
// Created by mrLogic on 10/17/2024.
//

#ifndef OOD_5_REPLACETEXTCOMMAND_H
#define OOD_5_REPLACETEXTCOMMAND_H

#include <stdexcept>
#include <utility>
#include <vector>
#include <optional>
#include "../AbstractCommand/AbstractCommand.h"
#include "../../document/DocumentItem.h"

class ReplaceTextCommand : public AbstractCommand
{
public:
    static constexpr const char* name = "ReplaceText";

    ReplaceTextCommand(std::vector<DocumentItem> & documentItems,
                       std::string  newText,
                       std::optional<size_t> position)
            : m_documentItems(documentItems), m_newText(std::move(newText)), m_position(position) {};
protected:
    void DoExecute() override;
    void DoUnexecute() override;

private:
    std::vector<DocumentItem> & m_documentItems;
    std::string m_text;
    std::string m_newText;
    std::optional<size_t> m_position;
};

#endif //OOD_5_REPLACETEXTCOMMAND_H

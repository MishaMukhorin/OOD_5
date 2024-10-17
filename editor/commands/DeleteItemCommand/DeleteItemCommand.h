//
// Created by mrLogic on 10/17/2024.
//

#ifndef OOD_5_DELETEITEMCOMMAND_H
#define OOD_5_DELETEITEMCOMMAND_H


#include <iostream>
#include <optional>
#include <vector>
#include "../AbstractCommand/AbstractCommand.h"
#include "../../document/DocumentItem.h"

class DeleteItemCommand : public AbstractCommand
{
public:
        static constexpr const char* name = "DeleteItem";

    DeleteItemCommand(std::vector<DocumentItem>& documentItems, size_t position)
            : m_documentItems(documentItems), m_position(position)
    {}

protected:
    void DoExecute() override;
    void DoUnexecute() override;

private:
    std::vector<DocumentItem>& m_documentItems;
    size_t m_position;
    std::unique_ptr<DocumentItem> m_oldDocumentItem = nullptr;
};

#endif //OOD_5_DELETEITEMCOMMAND_H

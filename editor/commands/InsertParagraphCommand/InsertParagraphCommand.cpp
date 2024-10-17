//
// Created by mrLogic on 10/17/2024.
//

#include "InsertParagraphCommand.h"

void InsertParagraphCommand::DoExecute()
{
    DocumentItem documentItem(m_text);

    if (!m_position.has_value())
    {
        m_documentItems.push_back(documentItem);
        return;
    }

    if (m_position.value() > m_documentItems.size())
    {
        throw std::invalid_argument("Not existing position");
    }

    m_documentItems.insert(m_documentItems.begin() + static_cast<std::vector<DocumentItem>::iterator::difference_type>(m_position.value()), documentItem);
}

void InsertParagraphCommand::DoUnexecute()
{
    if (m_documentItems.empty())
    {
        return;
    }

    if (!m_position.has_value())
    {
        m_documentItems.pop_back();
        return;
    }

    if (m_position.value() < m_documentItems.size())
    {
        m_documentItems.erase(m_documentItems.begin() + static_cast<std::vector<DocumentItem>::iterator::difference_type>(m_position.value()));
    }
}

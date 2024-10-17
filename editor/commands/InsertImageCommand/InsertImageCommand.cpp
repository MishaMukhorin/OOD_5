//
// Created by mrLogic on 10/17/2024.
//

#include "InsertImageCommand.h"

void InsertImageCommand::DoExecute()
{
    // Create the image item
    DocumentItem documentItem(m_imagePath, m_height, m_width);

    if (!m_position.has_value())
    {
        m_documentItems.push_back(documentItem);
        return;
    }

    // Check if the position is valid
    if (m_position.value() > m_documentItems.size())
    {
        throw std::invalid_argument("Not existing position");
    }

    // Insert at the specific position
    m_documentItems.insert(m_documentItems.begin() + static_cast<std::vector<DocumentItem>::iterator::difference_type>(m_position.value()), documentItem);
}


void InsertImageCommand::DoUnexecute()
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

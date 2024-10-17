//
// Created by mrLogic on 10/17/2024.
//

#include "ReplaceTextCommand.h"

void ReplaceTextCommand::DoExecute()
{
    if (!m_position.has_value())
    {
        throw std::invalid_argument("This command needs position to operate");
    }

    if (m_position.value() > m_documentItems.size())
    {
        throw std::invalid_argument("Not existing position");
    }

    auto documentItem = m_documentItems.at(m_position.value());
    auto paragraph = documentItem.GetParagraph();
    if (paragraph != nullptr)
    {
        m_text = paragraph->GetText();
        paragraph->SetText(m_newText);
    }
    else
    {
        throw std::invalid_argument("There are no text in this position!");
    }
}

void ReplaceTextCommand::DoUnexecute()
{
    if (!m_position.has_value())
    {
        throw std::invalid_argument("This command needs position to operate");
    }

    if (m_position.value() > m_documentItems.size())
    {
        throw std::invalid_argument("Not existing position");
    }

    auto documentItem = m_documentItems.at(m_position.value());
    auto paragraph = documentItem.GetParagraph();

    if (paragraph != nullptr)
    {
        paragraph->SetText(m_text);
    }
    else
    {
        throw std::invalid_argument("There are no text in this position!");
    }
}

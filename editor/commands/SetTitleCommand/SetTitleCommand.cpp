//
// Created by mrLogic on 10/17/2024.
//

#include "SetTitleCommand.h"
void SetTitleCommand::DoExecute()
{
    std::swap(m_title, m_newTitle);
}

void SetTitleCommand::DoUnexecute()
{
    std::swap(m_newTitle, m_title);
}

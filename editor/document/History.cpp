//
// Created by mrLogic on 10/17/2024.
//

#include "History.h"

bool History::CanUndo() const
{
    return m_nextCommandIndex != 0;
}

bool History::CanRedo() const
{
    return m_nextCommandIndex != m_commands.size();
}

void History::Undo()
{
    if (CanUndo())
    {
        m_commands[m_nextCommandIndex - 1]->Unexecute();
        --m_nextCommandIndex;
    }
}

void History::Redo()
{
    if (CanRedo())
    {
        m_commands[m_nextCommandIndex]->Execute();
        ++m_nextCommandIndex;
    }
}

void History::AddAndExecuteCommand(ICommandPtr && command)
{
    if (m_nextCommandIndex < m_commands.size())
    {
        try
        {
            command->Execute();
            m_commands.back() = std::move(command);
            ++m_nextCommandIndex;
        }
        catch (...)
        {
            m_commands.pop_back();
            throw;
        }
        ++m_nextCommandIndex;
        m_commands.resize(m_nextCommandIndex);
        m_commands.back() = std::move(command);
    }
    else
    {
        m_commands.emplace_back(nullptr);
        try
        {
            command->Execute();
            m_commands.back() = std::move(command);
            ++m_nextCommandIndex;
        }
        catch (...)
        {
            m_commands.pop_back();
            throw;
        }

    }
}


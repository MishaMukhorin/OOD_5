//
// Created by mrLogic on 10/17/2024.
//

#include "CompoundCommand.h"

bool CompoundCommand::CanUndo() const
{
    return AbstractUndoable::CanUndo() && !m_inProgress;
}

bool CompoundCommand::CanRedo() const
{
    return AbstractUndoable::CanRedo() && !m_inProgress;
}

void CompoundCommand::End()
{
    m_inProgress = false;
    EndImpl();
}

bool CompoundCommand::AddEditImpl(const IUndoablePtr& edit)
{
    assert(edit);
    if (!m_inProgress)
    {
        return false;
    }

    if (!m_edits.empty())
    {
        if (auto& lastEdit = m_edits.back();
                !lastEdit->AddEdit(edit))
        {
            if (edit->ReplaceEdit(lastEdit))
            {
                m_edits.pop_back();
            }
            m_edits.emplace_back(edit);
        }
    }
    else
    {
        m_edits.emplace_back(edit);
    }

    return true;
}

void CompoundCommand::DestroyImpl() noexcept
{
    for (auto& edit : std::views::reverse(m_edits))
    {
        edit->Destroy();
    }
    m_edits.clear();
}

void CompoundCommand::UndoImpl()
{
    for (auto& edit : std::views::reverse(m_edits))
    {
        edit->Undo();
    }
}

void CompoundCommand::RedoImpl()
{
    for (auto& edit : m_edits)
    {
        edit->Redo();
    }
}
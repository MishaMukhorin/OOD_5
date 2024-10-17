//
// Created by mrLogic on 10/17/2024.
//

#include <stdexcept>
#include "AbstractUndoable.h"

bool AbstractUndoable::CanUndo() const
{
    return m_isAlive && m_executed;
}

bool AbstractUndoable::CanRedo() const
{
    return m_isAlive && !m_executed;
}

void AbstractUndoable::Undo()
{
    if (!CanUndo())
    {
        throw std::logic_error("Can't undo");
    }
    m_executed = false;
    UndoImpl();
}

void AbstractUndoable::Redo()
{
    if (!CanRedo())
    {
        throw std::logic_error("Can't redo");
    }
    m_executed = true;
    RedoImpl();
}

void AbstractUndoable::Destroy() noexcept
{
    if (!m_isAlive)
    {
        m_isAlive = false;
        DestroyImpl();
    }
}

bool AbstractUndoable::AddEdit(const IUndoablePtr& edit)
{
    if (!edit)
    {
        throw std::invalid_argument("Invalid edit");
    }
    if (!m_isAlive)
    {
        throw std::logic_error("Edit has been already destroyed");
    }
    return AddEditImpl(edit);
}

bool AbstractUndoable::ReplaceEdit(const IUndoablePtr& edit)
{
    if (!edit)
    {
        throw std::invalid_argument("Invalid edit");
    }
    if (!m_isAlive)
    {
        throw std::logic_error("Edit has been already destroyed");
    }
    return ReplaceEditImpl(edit);
}

std::string AbstractUndoable::GetName() const
{
    return m_name;
}

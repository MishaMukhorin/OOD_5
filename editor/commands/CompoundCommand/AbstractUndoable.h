//
// Created by mrLogic on 10/17/2024.
//

#ifndef OOD_5_ABSTRACTUNDOABLE_H
#define OOD_5_ABSTRACTUNDOABLE_H
#include <string>
#include "IUndoable.h"

class AbstractUndoable : public IUndoable
{
public:
    [[nodiscard]] bool CanUndo() const override;

    [[nodiscard]] bool CanRedo() const override;

    void Undo() final;

    void Redo() final;

    void Destroy() noexcept final;

    bool AddEdit(const IUndoablePtr& edit) final;

    bool ReplaceEdit(const IUndoablePtr& edit) override;

    [[nodiscard]] std::string GetName() const override;

private:
    virtual void UndoImpl() {}
    virtual void RedoImpl() {}
    virtual void DestroyImpl() noexcept {}
    virtual bool AddEditImpl([[maybe_unused]] const IUndoablePtr& edit) { return false; }
    virtual bool ReplaceEditImpl([[maybe_unused]] const IUndoablePtr& edit) { return false; }

    std::string m_name;
    bool m_isAlive = true;
    bool m_executed = false;
};


#endif //OOD_5_ABSTRACTUNDOABLE_H

//
// Created by mrLogic on 10/17/2024.
//

#ifndef OOD_5_COMPOUNDCOMMAND_H
#define OOD_5_COMPOUNDCOMMAND_H

#include <ranges>
#include <cassert>
#include <vector>
#include "AbstractUndoable.h"

class CompoundCommand : public AbstractUndoable
{
public:
    bool CanUndo() const override;

    bool CanRedo() const override;

    void End();

private:
    bool AddEditImpl(const IUndoablePtr& edit) override;
    void DestroyImpl() noexcept override;
    void UndoImpl() override;
    void RedoImpl() override;

    virtual void EndImpl() {}

    std::vector<IUndoablePtr> m_edits;
    bool m_inProgress = true;
};

#endif //OOD_5_COMPOUNDCOMMAND_H

//
// Created by mrLogic on 10/17/2024.
//

#ifndef OOD_5_IUNDOABLE_H
#define OOD_5_IUNDOABLE_H
#include <memory>



class IUndoable;
using IUndoablePtr = std::shared_ptr<IUndoable>;

class IUndoable
{
public:
    virtual bool CanUndo() const = 0;
    virtual bool CanRedo() const = 0;

    virtual void Undo() = 0;
    virtual void Redo() = 0;
    virtual void Destroy() noexcept = 0;

    virtual bool AddEdit(const IUndoablePtr& edit) = 0;

    virtual bool ReplaceEdit(const IUndoablePtr& edit) = 0;

    virtual std::string GetName() const = 0;

    virtual ~IUndoable() = default;
};

#endif //OOD_5_IUNDOABLE_H

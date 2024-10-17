//
// Created by mrLogic on 10/17/2024.
//

#ifndef OOD_5_HISTORY_H
#define OOD_5_HISTORY_H
#include <deque>
#include "../commands/ICommand.h"

class History
{
public:
    History() = default;
    ~History() = default;

    [[nodiscard]] bool CanUndo() const;
    [[nodiscard]] bool CanRedo() const;

    void Undo();
    void Redo();

    void AddAndExecuteCommand(ICommandPtr && command);

private:

    std::deque<ICommandPtr> m_commands;
    size_t m_nextCommandIndex = 0;
};


#endif //OOD_5_HISTORY_H

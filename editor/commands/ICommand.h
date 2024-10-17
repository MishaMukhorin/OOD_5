//
// Created by mrLogic on 10/17/2024.
//

#ifndef OOD_5_ICOMMAND_H
#define OOD_5_ICOMMAND_H
#include <memory>

class ICommand
{
public:
    virtual void Execute() = 0;
    virtual void Unexecute() = 0;

    virtual ~ICommand() = default;
};

typedef std::unique_ptr<ICommand> ICommandPtr;

#endif //OOD_5_ICOMMAND_H

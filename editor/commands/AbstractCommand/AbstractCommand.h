//
// Created by mrLogic on 10/17/2024.
//

#ifndef OOD_5_ABSTRACTCOMMAND_H
#define OOD_5_ABSTRACTCOMMAND_H

#include "../ICommand.h"

class AbstractCommand :
        public ICommand
{
public:
    void Execute() final;
    void Unexecute() final;

protected:
    virtual void DoExecute() = 0;
    virtual void DoUnexecute() = 0;

private:
    bool m_executed = false;

};

#endif //OOD_5_ABSTRACTCOMMAND_H

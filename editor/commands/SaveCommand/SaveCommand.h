//
// Created by mrLogic on 10/17/2024.
//

#ifndef OOD_5_SAVECOMMAND_H
#define OOD_5_SAVECOMMAND_H

#include <fstream>
#include <stdexcept>
#include <string>
#include <vector>
#include <vector>
#include <filesystem>
#include "../../document/DocumentItem.h"
#include "../AbstractCommand/AbstractCommand.h"

// todo сделать другим типом команды
class SaveCommand : public AbstractCommand
{
public:
    static constexpr const char* name = "Save";

    SaveCommand(const std::vector<DocumentItem>& documentItems, std::string path, std::string  title)
            : m_documentItems(documentItems), m_path(std::move(path)), m_title(std::move(title)) {}

protected:
    void DoExecute() override;
    void DoUnexecute() override;

private:
    const std::vector<DocumentItem>& m_documentItems;
    std::string m_path;
    std::string m_title;

    static std::string HtmlEncode(const std::string &text);
};


#endif //OOD_5_SAVECOMMAND_H

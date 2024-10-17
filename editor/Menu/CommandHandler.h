//
// Created by mrLogic on 10/17/2024.
//

#ifndef OOD_5_COMMANDHANDLER_H
#define OOD_5_COMMANDHANDLER_H

#include "Menu.h"
#include "editor/document/Document.h"

class CommandHandler
{
public:
    CommandHandler(Menu & menu, Document & document);


private:
    Menu & m_menu;
    Document & m_document;

    typedef void (CommandHandler::*MenuHandler)(std::istream & in);
    void AddMenuItem(const std::string & commandName, const std::string & description, MenuHandler handler);

    void List(std::istream &);

    void InsertParagraph(std::istream & in);

    void InsertImage(std::istream & in);

    void ResizeImage(std::istream & in);

    void SetTitle(std::istream & in);


    void ReplaceText(std::istream & in);


    void DeleteItem(std::istream & in);


    void Undo(std::istream &);


    void Redo(std::istream &);


    void Save(std::istream & in);

};


#endif //OOD_5_COMMANDHANDLER_H

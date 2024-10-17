//
// Created by mrLogic on 10/17/2024.
//
#include "Menu/Menu.h"
#include "document/Document.h"
#include "editor/Menu/CommandHandler.h"


int main(int argc, char* argv[])
{
    try
    {
        Document document;
        Menu menu;
        CommandHandler commandHandler(menu, document);

        menu.Run();
        menu.Exit();
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
        return 1;
    }

    return 0;
}
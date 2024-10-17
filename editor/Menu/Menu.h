//
// Created by mrLogic on 10/17/2024.
//

#ifndef OOD_5_MENU_H
#define OOD_5_MENU_H

#include <sstream>
#include <iostream>
#include <functional>
#include <utility>

class Menu {
public:
    typedef std::function<void(std::istream &args)> Command;
    void AddItem(const std::string & commandName, const std::string & description, const Command & command);

    void Run();

    void ShowInstructions()const;

    void Exit();

private:
    void ExecuteCommand(const std::string & command);

    struct Item
    {
        Item(std::string  commandName, std::string  description, Command  command)
                : commandName(std::move(commandName))
                , description(std::move(description))
                , command(std::move(command))
        {}

        std::string commandName;
        std::string description;
        Command command;
    };
    std::vector<Item> m_items;
    bool m_exit = false;
    bool m_forceExit = false;
};


#endif //OOD_5_MENU_H

//
// Created by mrLogic on 10/17/2024.
//

#include "Menu.h"


void Menu::AddItem(const std::string & commandName, const std::string & description, const Command & command)
{
    m_items.emplace_back(commandName, description, command);
}

void Menu::Run() // todo разобратьс€ кто кем €вл€етс€ в паттерне команда
{
    ShowInstructions();

    std::string command;
    while (getline(std::cin, command))
    {
        try
        {
            ExecuteCommand(command);
        }
        catch (const std::exception& e)
        {
            std::cerr << e.what() << std::endl;
        }
    }
}

void Menu::Exit()
{
    m_exit = true;
}

void Menu::ShowInstructions() const
{
    std::cout << "Commands list:\n";
    for (auto & item : m_items)
    {
        std::cout << "  " << item.commandName << ": " << item.description << "\n";
    }
}
void Menu::ExecuteCommand(const std::string & command)
{
    std::istringstream iss(command);
    std::string name;
    iss >> name;

    auto it = std::find_if(m_items.begin(), m_items.end(), [&](const Item & item) {
        return item.commandName == name;
    });
    if (it != m_items.end())
    {
        it->command(iss);
    }
    else
    {
        std::cout << "Unknown command\n";
    }
}

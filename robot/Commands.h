#pragma once
#include "ICommand.h"
#include "Robot.h"
#include <vector>
#include <memory>




template <typename Commands>
CMenuFP::Command CreateMacroCommand(Commands && commands)
{
    return [=] {
        for (auto & command : commands)
        {
            command();
        }
    };
}


class BeginMacroCommand {
public:
    explicit BeginMacroCommand(CMenuFP &menu)
            : m_menu(menu)
    {}

    void operator()() {
        std::string macroName, description;
        std::vector<CMenuFP::Command> commands;

        std::cout << "Enter macro name: " << std::endl;
        std::getline(std::cin, macroName);

        std::cout << "Enter macro description: " << std::endl;
        std::getline(std::cin, description);

        std::cout << "Entering macro mode. " << std::endl
                  << "Type commands to add them to the macro, 'end_macro' to finish.\n";

        std::string commandName;
        while (true) {
            std::cout << "> ";
            std::getline(std::cin, commandName);
            if (commandName == "end_macro") {
                break;
            }

            auto it = std::find_if(m_menu.m_items.begin(), m_menu.m_items.end(),
                                   [&](const CMenuFP::Item &item) {
                                       return item.shortcut == commandName;
                                   });
            if (it != m_menu.m_items.end()) {
                commands.push_back(it->command);
                std::cout << "Command '" << commandName << "' added to macro.\n";
            } else {
                std::cout << "Unknown command: " << commandName << std::endl;
            }
        }

        m_menu.AddItem(macroName, description, CreateMacroCommand(std::move(commands)));
        std::cout << "Macro '" << macroName << "' created.\n";
    }

private:
    CMenuFP &m_menu;
};

class CTurnOnCommand : public ICommand
{
public:
	explicit CTurnOnCommand(Robot & robot)
		: m_robot(robot)
	{}

	void Execute() override
	{
		m_robot.TurnOn();
	}
private:
	Robot & m_robot;
};

class CTurnOffCommand : public ICommand
{
public:
	explicit CTurnOffCommand(Robot & robot)
		:m_robot(robot)
	{}
	void Execute() override
	{
		m_robot.TurnOff();
	}
private:
	Robot & m_robot;
};

class CWalkCommand : public ICommand
{
public:
	CWalkCommand(Robot & robot, WalkDirection direction)
		: m_robot(robot)
		, m_direction(direction)
	{}
	void Execute() override
	{
		m_robot.Walk(m_direction);
	}
private:
	Robot & m_robot;
	WalkDirection m_direction;
};

class CStopCommand : public ICommand
{
public:
	explicit CStopCommand(Robot & robot)
		: m_robot(robot)
	{}
	void Execute() override
	{
		m_robot.Stop();
	}
private:
	Robot & m_robot;
};

class CMacroCommand : public ICommand
{
public:
	void Execute() override
	{
		for (auto & cmd : m_commands)
		{
			cmd->Execute();
		}
	}
	void AddCommand(std::unique_ptr<ICommand> && cmd)
	{
		m_commands.push_back(std::move(cmd));
	}
private:
	std::vector<std::unique_ptr<ICommand>> m_commands;
};
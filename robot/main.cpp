#include "MenuFP.h"
#include "Commands.h"
	
using namespace std;



void TestMenuWithDynamicMacroCommand()
{
    Robot robot;
    CMenuFP menu;

    menu.AddItem("on", "Turns the Robot on",
                 [&] { robot.TurnOn(); });
    menu.AddItem("off", "Turns the Robot off",
                 [&] { robot.TurnOff(); });
    menu.AddItem("north", "Makes the Robot walk north",
                 [&] { robot.Walk(WalkDirection::North); });
    menu.AddItem("south", "Makes the Robot walk south",
                 [&] { robot.Walk(WalkDirection::South); });
    menu.AddItem("west", "Makes the Robot walk west",
                 [&] { robot.Walk(WalkDirection::West); });
    menu.AddItem("east", "Makes the Robot walk east",
                 [&] { robot.Walk(WalkDirection::East); });
    menu.AddItem("stop", "Stops the Robot", [&] { robot.Stop(); });
    menu.AddItem("patrol", "Patrol the territory",
                 CreateMacroCommand<vector<CMenuFP::Command>>({
                            [&] { robot.TurnOn(); },
                            [&] { robot.Walk(WalkDirection::North); },
                            [&] { robot.Walk(WalkDirection::South); },
                            [&] { robot.Walk(WalkDirection::West); },
                            [&] { robot.Walk(WalkDirection::East); },
                            [&] { robot.TurnOff(); }
                    }));

    menu.AddItem("begin_macro", "Start recording a new macro", [&] {
        BeginMacroCommand beginMacroCommand(menu);
        beginMacroCommand();
    });

    menu.Run();
}

void TestMenuWithFunctionalCommandPattern()
{
	Robot robot;
	CMenuFP menu;

	menu.AddItem("on", "Turns the Robot on", [&] { 
		robot.TurnOn(); 
	});
	menu.AddItem("off", "Turns the Robot off",
		[&] { robot.TurnOff(); });

	menu.AddItem("north", "Makes the Robot walk north", 
		[&] { robot.Walk(WalkDirection::North); });
	menu.AddItem("south", "Makes the Robot walk south", 
		[&] { robot.Walk(WalkDirection::South); });
	menu.AddItem("west", "Makes the Robot walk west", 
		[&] { robot.Walk(WalkDirection::West); });
	menu.AddItem("east", "Makes the Robot walk east", 
		[&] { robot.Walk(WalkDirection::East); });

	menu.AddItem("stop", "Stops the Robot", 
		[&] { robot.Stop(); });

	menu.AddItem("patrol", "Patrol the territory", CreateMacroCommand<vector<CMenuFP::Command>>({
			[&] { robot.TurnOn(); },
			[&] { robot.Walk(WalkDirection::North); },
			[&] { robot.Walk(WalkDirection::South); },
			[&] { robot.Walk(WalkDirection::West); },
			[&] { robot.Walk(WalkDirection::East); },
			[&] { robot.TurnOff(); }
		}));

	menu.AddItem("help", "Show instructions", 
		[&] { menu.ShowInstructions(); });
	menu.AddItem("exit", "Exit from this menu", 
		[&] { menu.Exit(); });

	menu.Run();
}

int main()
{
	CMenuFP menu;
	menu.AddItem("f", "Functional command pattern implementation", [&] {
		TestMenuWithFunctionalCommandPattern(); 
		menu.ShowInstructions();
	});
    menu.AddItem("d", "Functional command pattern with dynamic macro command", [&] {
		TestMenuWithDynamicMacroCommand();
		menu.ShowInstructions();
	});

	menu.AddItem("q", "Exit Program", [robot = &menu] { robot->Exit(); });
	menu.ShowInstructions();
	menu.Run();
	
	return 0;
}
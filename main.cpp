#include <iomanip>
#include <iostream>
#include <memory>
#include <sstream>
#include <string>
#include <vector>

#include "manager/robot_manager.h"
#include "robot/assembly_robot.h"
#include "robot/robot.h"
#include "robot/welding_robot.h"

namespace {

inline auto print_help() -> void
{
    std::cout << "\nCommands:\n"
              << "  list                         - list all robots\n"
              << "  search <id>                  - search robot by id\n"
              << "  remove <id>                  - remove robot by id\n"
              << "  add <id> <name> <state>      - add a general robot\n"
              << "  help                         - show this help\n"
              << "  quit                         - exit\n"
              << "\nStates: 0=idle, 1=active, 2=charging, 3=offline, 4=maintenance, 5=error\n"
              << "Quote names with spaces, for example: add 303 \"Paint Gamma\" 1\n";
}

inline auto print_robot(const RobotInfo& Robot) -> void
{
    std::cout << "ID: " << Robot.Id << ", Name: " << Robot.Name
              << ", State: " << to_state_value(Robot.State) << '\n';
}

inline auto print_robots(const std::vector<RobotInfo>& Robots) -> void
{
    for (const auto& Robot : Robots) {
        print_robot(Robot);
    }
}

} // namespace

auto main() -> int
{
    RobotManager Manager;

    Manager.register_robot(std::make_unique<AssemblyRobot>(101, "Assembly Alpha", RobotState::Idle));
    Manager.register_robot(std::make_unique<WeldingRobot>(202, "Welding Beta", RobotState::Active));

    std::cout << "Registered robots:" << std::endl;
    print_robots(Manager.list_robots());

    const auto RemoveId = 202;
    const auto Removed = Manager.remove_robot(RemoveId);
    std::cout << "\nAttempt to remove robot with ID " << RemoveId
              << (Removed ? " succeeded." : " failed (not found).") << std::endl;

    std::cout << "\nRobots after removal:" << std::endl;
    print_robots(Manager.list_robots());

    const auto MissingId = 999;
    std::cout << "\nAttempt to remove non-existent robot ID " << MissingId
              << ": " << (Manager.remove_robot(MissingId) ? "removed" : "not found") << std::endl;

    print_help();
    std::string Line;
    while (true) {
        std::cout << "\n> ";
        if (!std::getline(std::cin, Line)) {
            break;
        }

        std::istringstream Input(Line);
        std::string Command;
        Input >> Command;

        if (Command == "quit" || Command == "q") {
            break;
        }

        if (Command == "help") {
            print_help();
            continue;
        }

        if (Command == "list") {
            print_robots(Manager.list_robots());
            continue;
        }

        if (Command == "search") {
            int Id = 0;
            if (!(Input >> Id)) {
                std::cout << "usage: search <id>\n";
                continue;
            }

            const auto* Found = Manager.get_robot(Id);
            if (Found) {
                const auto& Info = Found->get_info();
                std::cout << "Found: ID=" << Info.Id << ", Name=" << Info.Name
                          << ", State=" << to_state_value(Info.State) << std::endl;
            } else {
                std::cout << "Robot " << Id << " not found.\n";
            }
            continue;
        }

        if (Command == "remove") {
            int Id = 0;
            if (!(Input >> Id)) {
                std::cout << "usage: remove <id>\n";
                continue;
            }

            const auto Ok = Manager.remove_robot(Id);
            std::cout << (Ok ? "Removed." : "Not found.") << std::endl;
            continue;
        }

        if (Command == "add") {
            int Id = 0;
            std::string Name;
            int StateValue = 0;

            if (!(Input >> Id >> std::ws)) {
                std::cout << "usage: add <id> <name> <state>\n";
                continue;
            }

            if (!(Input >> std::quoted(Name) >> StateValue)) {
                std::cout << "usage: add <id> <name> <state>\n";
                continue;
            }

            Manager.register_robot(std::make_unique<Robot>(Id, Name, to_robot_state(StateValue)));
            std::cout << "Added robot " << Id << ".\n";
            continue;
        }

        if (!Command.empty()) {
            std::cout << "Unknown command '" << Command << "'. Type 'help'.\n";
        }
    }

    return 0;
}

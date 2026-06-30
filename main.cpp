#include <iostream>
#include <memory>

#include "manager/robot_manager.h"
#include "robot/assembly_robot.h"
#include "robot/welding_robot.h"

int main() {
    RobotManager manager;

    manager.registerRobot(std::make_unique<AssemblyRobot>(101, "Assembly Alpha", RobotState::idle));
    manager.registerRobot(std::make_unique<WeldingRobot>(202, "Welding Beta", RobotState::active));

    std::cout << "Registered robots:" << std::endl;
    for (const auto &robot : manager.listRobots()) {
        std::cout << "ID: " << robot.id << ", Name: " << robot.name
                  << ", State: " << static_cast<int>(robot.state) << std::endl;
    }
    // Remove a robot by ID
    int removeId = 202;
    bool removed = manager.removeRobot(removeId);
    std::cout << "\nAttempt to remove robot with ID " << removeId
              << (removed ? " succeeded." : " failed (not found).") << std::endl;

    std::cout << "\nRobots after removal:" << std::endl;
    for (const auto &robot : manager.listRobots()) {
        std::cout << "ID: " << robot.id << ", Name: " << robot.name
                  << ", State: " << static_cast<int>(robot.state) << std::endl;
    }

    // Attempt to remove a non-existent robot
    int missingId = 999;
    std::cout << "\nAttempt to remove non-existent robot ID " << missingId
              << ": " << (manager.removeRobot(missingId) ? "removed" : "not found") << std::endl;

    return 0;
}
#include "../../include/robot/assembly_robot.h"

/**
 * @brief Constructs an AssemblyRobot from an existing RobotInfo structure.
 *
 * Initializes the AssemblyRobot by delegating to the Robot constructor.
 * All robot properties (id, name, state) are set from the info parameter.
 *
 * @param info A const reference to the RobotInfo containing initial data.
 */
AssemblyRobot::AssemblyRobot(const RobotInfo &info)
    : Robot(info) {}

/**
 * @brief Constructs an AssemblyRobot with individual components.
 *
 * Initializes the AssemblyRobot by delegating to the Robot constructor
 * with individual parameters.
 *
 * @param id The unique identifier for the robot.
 * @param name The name of the robot.
 * @param state The initial operational state of the robot.
 */
AssemblyRobot::AssemblyRobot(int id, std::string name, RobotState state)
    : Robot(id, std::move(name), state) {}

/**
 * @brief Retrieves the unique identifier of the assembly robot.
 *
 * @return The robot's ID as an integer.
 */
int AssemblyRobot::getId() const {
    return Robot::getId();
}

/**
 * @brief Retrieves the name of the assembly robot.
 *
 * @return A const reference to the robot's name string.
 */
const std::string &AssemblyRobot::getName() const {
    return Robot::getName();
}

/**
 * @brief Retrieves the current operational state of the assembly robot.
 *
 * @return The current RobotState enumeration value.
 */
RobotState AssemblyRobot::getState() const {
    return Robot::getState();
}

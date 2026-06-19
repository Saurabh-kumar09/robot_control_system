#include "../../include/robot/welding_robot.h"

/**
 * @brief Constructs a WeldingRobot from an existing RobotInfo structure.
 *
 * Initializes the WeldingRobot by delegating to the Robot constructor.
 * All robot properties (id, name, state) are set from the info parameter.
 *
 * @param info A const reference to the RobotInfo containing initial data.
 */
WeldingRobot::WeldingRobot(const RobotInfo &info)
    : Robot(info) {}

/**
 * @brief Constructs a WeldingRobot with individual components.
 *
 * Initializes the WeldingRobot by delegating to the Robot constructor
 * with individual parameters.
 *
 * @param id The unique identifier for the robot.
 * @param name The name of the robot.
 * @param state The initial operational state of the robot.
 */
WeldingRobot::WeldingRobot(int id, std::string name, RobotState state)
    : Robot(id, std::move(name), state) {}

/**
 * @brief Retrieves the unique identifier of the welding robot.
 *
 * @return The robot's ID as an integer.
 */
int WeldingRobot::getId() const {
    return Robot::getId();
}

/**
 * @brief Retrieves the name of the welding robot.
 *
 * @return A const reference to the robot's name string.
 */
const std::string &WeldingRobot::getName() const {
    return Robot::getName();
}

/**
 * @brief Retrieves the current operational state of the welding robot.
 *
 * @return The current RobotState enumeration value.
 */
RobotState WeldingRobot::getState() const {
    return Robot::getState();
}

#include "../../include/robot/robot.h"

/**
 * @brief Constructs a Robot from an existing RobotInfo structure.
 *
 * Initializes the Robot by copying the provided RobotInfo data.
 * All robot properties (id, name, state) are set from the info parameter.
 *
 * @param info A const reference to the RobotInfo containing initial data.
 */
Robot::Robot(const RobotInfo &info)
    : info_(info) {}

/**
 * @brief Constructs a Robot with individual components.
 *
 * Initializes the Robot by aggregating individual parameters into a RobotInfo
 * structure. The name string is moved to optimize performance.
 *
 * @param id The unique identifier for the robot.
 * @param name The name of the robot (will be moved).
 * @param state The initial operational state of the robot.
 */
Robot::Robot(int id, std::string name, RobotState state)
    : info_{id, std::move(name), state} {}

int Robot::getId() const {
    return info_.id;
}

const std::string &Robot::getName() const {
    return info_.name;
}

RobotState Robot::getState() const {
    return info_.state;
}

void Robot::setState(RobotState state) {
    info_.state = state;
}

const RobotInfo &Robot::getInfo() const {
    return info_;
}

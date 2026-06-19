#pragma once

#include "robot.h"

/**
 * @class WeldingRobot
 * @brief Specialized robot implementation for welding operations.
 *
 * WeldingRobot is a derived class from Robot that represents a robot
 * specialized for welding tasks. It inherits all base robot functionality
 * and uses the same RobotInfo composition pattern.
 *
 * @see Robot
 * @see RobotBase
 */
class WeldingRobot : public Robot {
public:
    /**
     * @brief Constructs a WeldingRobot from an existing RobotInfo structure.
     * @param info A const reference to the RobotInfo containing initial data.
     */
    explicit WeldingRobot(const RobotInfo &info);

    /**
     * @brief Constructs a WeldingRobot with individual components.
     * @param id The unique identifier for the robot.
     * @param name The name of the robot.
     * @param state The initial operational state of the robot.
     */
    WeldingRobot(int id, std::string name, RobotState state);

    /**
     * @brief Virtual destructor with default implementation.
     */
    ~WeldingRobot() override = default;

    /**
     * @brief Retrieves the unique identifier of the welding robot.
     * @return The robot's ID as an integer.
     */
    int getId() const override;

    /**
     * @brief Retrieves the name of the welding robot.
     * @return A const reference to the robot's name string.
     */
    const std::string &getName() const override;

    /**
     * @brief Retrieves the current operational state of the welding robot.
     * @return The current RobotState enumeration value.
     */
    RobotState getState() const override;
};

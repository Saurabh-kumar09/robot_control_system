#include "robot.h"

/**
 * @class AssemblyRobot
 * @brief Specialized robot implementation for assembly operations.
 *
 * AssemblyRobot is a derived class from Robot that represents a robot
 * specialized for assembly tasks. It inherits all base robot functionality
 * and uses the same RobotInfo composition pattern.
 *
 * @see Robot
 * @see RobotBase
 */
class AssemblyRobot : public Robot {
public:
    /**
     * @brief Constructs an AssemblyRobot from an existing RobotInfo structure.
     * @param info A const reference to the RobotInfo containing initial data.
     */
    explicit AssemblyRobot(const RobotInfo &info);

    /**
     * @brief Constructs an AssemblyRobot with individual components.
     * @param id The unique identifier for the robot.
     * @param name The name of the robot. 
     * @param state The initial operational state of the robot.
     */
    AssemblyRobot(int id, std::string name, RobotState state);

    /**
     * @brief Virtual destructor with default implementation.
     */
    ~AssemblyRobot() override = default;

    /**
     * @brief Retrieves the unique identifier of the assembly robot.
     * @return The robot's ID as an integer.
     */
    int getId() const override;

    /**
     * @brief Retrieves the name of the assembly robot.
     * @return A const reference to the robot's name string.
     */
    const std::string &getName() const override;

    /**
     * @brief Retrieves the current operational state of the assembly robot.
     * @return The current RobotState enumeration value.
     */
    RobotState getState() const override;
};

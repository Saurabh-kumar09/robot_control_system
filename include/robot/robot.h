#include <string>
#include "../common/data.h"

/**
 * @class RobotBase
 * @brief Abstract base class defining the interface for robot implementations.
 *
 * RobotBase provides a pure virtual interface that all concrete robot classes
 * must implement. It defines methods for retrieving and managing robot properties
 * such as ID, name, and operational state.
 */
class RobotBase {
public:
    /**
     * @brief Default constructor for RobotBase.
     */
    RobotBase() = default;

    /**
     * @brief Virtual destructor ensures proper cleanup of derived classes.
     */
    virtual ~RobotBase() = default;

    /**
     * @brief Retrieves the unique identifier of the robot.
     * @return The robot's ID as an integer.
     */
    virtual int getId() const = 0;

    /**
     * @brief Retrieves the name of the robot.
     * @return A const reference to the robot's name string.
     */
    virtual const std::string &getName() const = 0;

    /**
     * @brief Retrieves the current operational state of the robot.
     * @return The current RobotState enumeration value.
     */
    virtual RobotState getState() const = 0;

    /**
     * @brief Sets the operational state of the robot.
     * @param state The new RobotState to set.
     */
    virtual void setState(RobotState state) = 0;
};

/**
 * @class Robot
 * @brief Concrete implementation of RobotBase using composition pattern.
 *
 * Robot is a concrete class that implements the RobotBase interface.
 * It uses composition to manage robot data through a RobotInfo structure,
 * providing storage and retrieval of robot properties.
 *
 * @see RobotBase
 * @see RobotInfo
 */
class Robot : public RobotBase {
public:
    /**
     * @brief Constructs a Robot from an existing RobotInfo structure.
     * @param info A const reference to the RobotInfo containing initial data.
     */
    explicit Robot(const RobotInfo &info);

    /**
     * @brief Constructs a Robot with individual components.
     * @param id The unique identifier for the robot.
     * @param name The name of the robot.
     * @param state The initial operational state of the robot.
     */
    Robot(int id, std::string name, RobotState state);

    /**
     * @brief Virtual destructor with default implementation.
     */
    ~Robot() override = default;

    /**
     * @brief Retrieves the unique identifier of the robot.
     * @return The robot's ID as an integer.
     */
    int getId() const override;

    /**
     * @brief Retrieves the name of the robot.
     * @return A const reference to the robot's name string.
     */
    const std::string &getName() const override;

    /**
     * @brief Retrieves the current operational state of the robot.
     * @return The current RobotState enumeration value.
     */
    RobotState getState() const override;

    /**
     * @brief Sets the operational state of the robot.
     * @param state The new RobotState to set.
     */
    void setState(RobotState state) override;

private:
    /**
     * @brief Internal storage for robot information using composition.
     */
    RobotInfo info_;
};

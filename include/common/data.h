#include <string>

enum class RobotState {
    idle,
    active,
    charging,
    offline,
    maintenance,
    error,
};
struct RobotInfo{
    int id;
    std::string name;
    RobotState state;
};
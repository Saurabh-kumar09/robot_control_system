#pragma once

#include <string>
#include <utility>

enum class RobotState {
    Idle = 0,
    Active,
    Charging,
    Offline,
    Maintenance,
    Error,
};

struct RobotInfo final {
    int Id;
    std::string Name;
    RobotState State;

    RobotInfo()
        : Id(0), Name(), State(RobotState::Idle)
    {
    }

    RobotInfo(int RobotId, std::string RobotName, RobotState RobotStatus)
        : Id(RobotId), Name(std::move(RobotName)), State(RobotStatus)
    {
    }
};

inline auto to_robot_state(int StateValue) -> RobotState
{
    switch (StateValue) {
        case 0:
            return RobotState::Idle;
        case 1:
            return RobotState::Active;
        case 2:
            return RobotState::Charging;
        case 3:
            return RobotState::Offline;
        case 4:
            return RobotState::Maintenance;
        default:
            return RobotState::Error;
    }
}

inline auto to_state_value(RobotState State) -> int
{
    return static_cast<int>(State);
}

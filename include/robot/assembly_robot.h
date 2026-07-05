#pragma once

#include <string>
#include <utility>

#include "robot.h"

class AssemblyRobot final : public Robot {
public:
    explicit AssemblyRobot(const RobotInfo& Info)
        : Robot(Info)
    {
    }

    AssemblyRobot(int Id, std::string Name, RobotState State)
        : Robot(Id, std::move(Name), State)
    {
    }

    ~AssemblyRobot() override = default;
};

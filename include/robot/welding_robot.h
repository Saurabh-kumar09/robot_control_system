#pragma once

#include <string>
#include <utility>

#include "robot.h"

class WeldingRobot final : public Robot {
public:
    explicit WeldingRobot(const RobotInfo& Info)
        : Robot(Info)
    {
    }

    WeldingRobot(int Id, std::string Name, RobotState State)
        : Robot(Id, std::move(Name), State)
    {
    }

    ~WeldingRobot() override = default;
};

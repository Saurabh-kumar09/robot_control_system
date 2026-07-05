#pragma once

#include <memory>
#include <unordered_map>
#include <vector>

#include "../robot/robot.h"

class RobotManager final {
public:
    auto register_robot(std::unique_ptr<RobotBase> Robot) -> void;

    auto remove_robot(int Id) -> bool;

    auto get_robot(int Id) -> RobotBase*;

    auto get_robot(int Id) const -> const RobotBase*;

    auto list_robots() const -> std::vector<RobotInfo>;

    inline auto empty() const -> bool
    {
        return Robots_.empty();
    }

private:
    std::unordered_map<int, std::unique_ptr<RobotBase>> Robots_;
};

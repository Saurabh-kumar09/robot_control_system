#pragma once

#include <string>
#include <utility>

#include "../common/data.h"

class RobotBase {
public:
    RobotBase() = default;
    RobotBase(const RobotBase&) = default;
    RobotBase(RobotBase&&) = default;
    auto operator=(const RobotBase&) -> RobotBase& = default;
    auto operator=(RobotBase&&) -> RobotBase& = default;
    virtual ~RobotBase() = default;

    virtual auto get_id() const -> int = 0;
    virtual auto get_name() const -> const std::string& = 0;
    virtual auto get_state() const -> RobotState = 0;
    virtual auto set_state(RobotState State) -> void = 0;
    virtual auto get_info() const -> const RobotInfo& = 0;
};

class Robot : public RobotBase {
public:
    explicit Robot(const RobotInfo& Info)
        : Info_(Info)
    {
    }

    Robot(int Id, std::string Name, RobotState State)
        : Info_(Id, std::move(Name), State)
    {
    }

    ~Robot() override = default;

    inline auto get_id() const -> int override
    {
        return Info_.Id;
    }

    inline auto get_name() const -> const std::string& override
    {
        return Info_.Name;
    }

    inline auto get_state() const -> RobotState override
    {
        return Info_.State;
    }

    inline auto set_state(RobotState State) -> void override
    {
        Info_.State = State;
    }

    inline auto get_info() const -> const RobotInfo& override
    {
        return Info_;
    }

private:
    RobotInfo Info_;
};

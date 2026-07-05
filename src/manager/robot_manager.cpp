#include "../../include/manager/robot_manager.h"

auto RobotManager::register_robot(std::unique_ptr<RobotBase> Robot) -> void
{
    if (!Robot) {
        return;
    }

    const auto Id = Robot->get_id();

    Robots_[Id] = std::move(Robot);
}

auto RobotManager::remove_robot(int Id) -> bool
{
    return Robots_.erase(Id) > 0;
}

auto RobotManager::get_robot(int Id) -> RobotBase*
{
    auto Iterator = Robots_.find(Id);

    if (Iterator == Robots_.end()) {
        return nullptr;
    }

    return Iterator->second.get();
}

auto RobotManager::get_robot(int Id) const -> const RobotBase*
{
    auto Iterator = Robots_.find(Id);

    if (Iterator == Robots_.end()) {
        return nullptr;
    }

    return Iterator->second.get();
}

auto RobotManager::list_robots() const -> std::vector<RobotInfo>
{
    std::vector<RobotInfo> Robots;

    Robots.reserve(Robots_.size());

    for (const auto& Entry : Robots_) {
        if (Entry.second) {
            Robots.push_back(Entry.second->get_info());
        }
    }

    return Robots;
}

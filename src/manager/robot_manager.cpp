#include "../../include/manager/robot_manager.h"


void RobotManager::registerRobot(std::unique_ptr<Robot> robot)
{
    if(!robot)
    {
        return;
    }

    int id = robot->getId();

    robots_[id] = std::move(robot);
}


bool RobotManager::removeRobot(int id)
{
    return robots_.erase(id) > 0;
}


Robot* RobotManager::getRobot(int id)
{
    auto it = robots_.find(id);

    if(it == robots_.end())
    {
        return nullptr;
    }

    return it->second.get();
}


std::vector<RobotInfo> RobotManager::listRobots() const
{
    std::vector<RobotInfo> robots;

    robots.reserve(this->robots_.size());


    for(const auto& [id, robot] : robots_)
    {
        if(robot)
        {
            robots.push_back(robot->getInfo());
        }
    }


    return robots;
}
#include <memory>
#include <unordered_map>
#include <vector>

#include "../robot/robot.h"

class RobotManager
{
public:

    void registerRobot(std::unique_ptr<Robot> robot);

    bool removeRobot(int id);

    Robot* getRobot(int id);

    std::vector<RobotInfo> listRobots() const;


private:

    std::unordered_map<int, std::unique_ptr<Robot>> robots_;
};
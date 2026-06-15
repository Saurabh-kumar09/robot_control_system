#include <string>
#include "../../include/common/data.h"

class RobotBase {
public:
    virtual ~RobotBase() = default;
    virtual int getId() = 0;
    virtual std::string getName() = 0;
    virtual RobotState getState() = 0;
};

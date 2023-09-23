#include"head.h"
course intToCourse(int intValue) {
    if (intValue >= 0 && intValue < static_cast<int>(course::TotalCourses)) {
        return static_cast<course>(intValue);
    }
    else {
        throw std::invalid_argument("无效的枚举值");
    }
}
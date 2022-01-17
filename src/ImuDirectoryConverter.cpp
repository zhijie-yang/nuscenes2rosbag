#include "nuscenes2bag/ImuDirectoryConverter.hpp"
#include "nuscenes2bag/utils.hpp"
#include <thread>

namespace nuscenes2bag {

boost::optional<sensor_msgs::Imu>
readImuFile(const ImuData& imuData) noexcept
{
  try {
    sensor_msgs::Imu msg;
    msg.header = std_msgs::Header();
    msg.angular_velocity.x = imuData.rotation_rate[0];
    msg.angular_velocity.y = imuData.rotation_rate[1];
    msg.angular_velocity.z = imuData.rotation_rate[2];
    msg.linear_acceleration.x = imuData.linear_accel[0];
    msg.linear_acceleration.y = imuData.linear_accel[1];
    msg.linear_acceleration.z = imuData.linear_accel[2];
    msg.orientation.w = imuData.q[0];
    msg.orientation.x = imuData.q[1];
    msg.orientation.y = imuData.q[2];
    msg.orientation.z = imuData.q[3];

    return boost::optional<sensor_msgs::Imu>(msg);

  } catch (const std::exception& e) {
    PRINT_EXCEPTION(e);
  }

  return boost::none;
}

}
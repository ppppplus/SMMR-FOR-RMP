// Generated by gencpp from file segway_msgs/ros_set_chassis_enable_cmd.msg
// DO NOT EDIT!


#ifndef SEGWAY_MSGS_MESSAGE_ROS_SET_CHASSIS_ENABLE_CMD_H
#define SEGWAY_MSGS_MESSAGE_ROS_SET_CHASSIS_ENABLE_CMD_H

#include <ros/service_traits.h>


#include <segway_msgs/ros_set_chassis_enable_cmdRequest.h>
#include <segway_msgs/ros_set_chassis_enable_cmdResponse.h>


namespace segway_msgs
{

struct ros_set_chassis_enable_cmd
{

typedef ros_set_chassis_enable_cmdRequest Request;
typedef ros_set_chassis_enable_cmdResponse Response;
Request request;
Response response;

typedef Request RequestType;
typedef Response ResponseType;

}; // struct ros_set_chassis_enable_cmd
} // namespace segway_msgs


namespace ros
{
namespace service_traits
{


template<>
struct MD5Sum< ::segway_msgs::ros_set_chassis_enable_cmd > {
  static const char* value()
  {
    return "24512eca4ee1771effd3f75b5e537916";
  }

  static const char* value(const ::segway_msgs::ros_set_chassis_enable_cmd&) { return value(); }
};

template<>
struct DataType< ::segway_msgs::ros_set_chassis_enable_cmd > {
  static const char* value()
  {
    return "segway_msgs/ros_set_chassis_enable_cmd";
  }

  static const char* value(const ::segway_msgs::ros_set_chassis_enable_cmd&) { return value(); }
};


// service_traits::MD5Sum< ::segway_msgs::ros_set_chassis_enable_cmdRequest> should match
// service_traits::MD5Sum< ::segway_msgs::ros_set_chassis_enable_cmd >
template<>
struct MD5Sum< ::segway_msgs::ros_set_chassis_enable_cmdRequest>
{
  static const char* value()
  {
    return MD5Sum< ::segway_msgs::ros_set_chassis_enable_cmd >::value();
  }
  static const char* value(const ::segway_msgs::ros_set_chassis_enable_cmdRequest&)
  {
    return value();
  }
};

// service_traits::DataType< ::segway_msgs::ros_set_chassis_enable_cmdRequest> should match
// service_traits::DataType< ::segway_msgs::ros_set_chassis_enable_cmd >
template<>
struct DataType< ::segway_msgs::ros_set_chassis_enable_cmdRequest>
{
  static const char* value()
  {
    return DataType< ::segway_msgs::ros_set_chassis_enable_cmd >::value();
  }
  static const char* value(const ::segway_msgs::ros_set_chassis_enable_cmdRequest&)
  {
    return value();
  }
};

// service_traits::MD5Sum< ::segway_msgs::ros_set_chassis_enable_cmdResponse> should match
// service_traits::MD5Sum< ::segway_msgs::ros_set_chassis_enable_cmd >
template<>
struct MD5Sum< ::segway_msgs::ros_set_chassis_enable_cmdResponse>
{
  static const char* value()
  {
    return MD5Sum< ::segway_msgs::ros_set_chassis_enable_cmd >::value();
  }
  static const char* value(const ::segway_msgs::ros_set_chassis_enable_cmdResponse&)
  {
    return value();
  }
};

// service_traits::DataType< ::segway_msgs::ros_set_chassis_enable_cmdResponse> should match
// service_traits::DataType< ::segway_msgs::ros_set_chassis_enable_cmd >
template<>
struct DataType< ::segway_msgs::ros_set_chassis_enable_cmdResponse>
{
  static const char* value()
  {
    return DataType< ::segway_msgs::ros_set_chassis_enable_cmd >::value();
  }
  static const char* value(const ::segway_msgs::ros_set_chassis_enable_cmdResponse&)
  {
    return value();
  }
};

} // namespace service_traits
} // namespace ros

#endif // SEGWAY_MSGS_MESSAGE_ROS_SET_CHASSIS_ENABLE_CMD_H

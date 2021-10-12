// Generated by gencpp from file map_msgs/SetMapProjectionsRequest.msg
// DO NOT EDIT!


#ifndef MAP_MSGS_MESSAGE_SETMAPPROJECTIONSREQUEST_H
#define MAP_MSGS_MESSAGE_SETMAPPROJECTIONSREQUEST_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace map_msgs
{
template <class ContainerAllocator>
struct SetMapProjectionsRequest_
{
  typedef SetMapProjectionsRequest_<ContainerAllocator> Type;

  SetMapProjectionsRequest_()
    {
    }
  SetMapProjectionsRequest_(const ContainerAllocator& _alloc)
    {
  (void)_alloc;
    }







  typedef boost::shared_ptr< ::map_msgs::SetMapProjectionsRequest_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::map_msgs::SetMapProjectionsRequest_<ContainerAllocator> const> ConstPtr;

}; // struct SetMapProjectionsRequest_

typedef ::map_msgs::SetMapProjectionsRequest_<std::allocator<void> > SetMapProjectionsRequest;

typedef boost::shared_ptr< ::map_msgs::SetMapProjectionsRequest > SetMapProjectionsRequestPtr;
typedef boost::shared_ptr< ::map_msgs::SetMapProjectionsRequest const> SetMapProjectionsRequestConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::map_msgs::SetMapProjectionsRequest_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::map_msgs::SetMapProjectionsRequest_<ContainerAllocator> >::stream(s, "", v);
return s;
}


} // namespace map_msgs

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsFixedSize< ::map_msgs::SetMapProjectionsRequest_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::map_msgs::SetMapProjectionsRequest_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::map_msgs::SetMapProjectionsRequest_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::map_msgs::SetMapProjectionsRequest_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::map_msgs::SetMapProjectionsRequest_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::map_msgs::SetMapProjectionsRequest_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::map_msgs::SetMapProjectionsRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "d41d8cd98f00b204e9800998ecf8427e";
  }

  static const char* value(const ::map_msgs::SetMapProjectionsRequest_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xd41d8cd98f00b204ULL;
  static const uint64_t static_value2 = 0xe9800998ecf8427eULL;
};

template<class ContainerAllocator>
struct DataType< ::map_msgs::SetMapProjectionsRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "map_msgs/SetMapProjectionsRequest";
  }

  static const char* value(const ::map_msgs::SetMapProjectionsRequest_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::map_msgs::SetMapProjectionsRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "\n"
;
  }

  static const char* value(const ::map_msgs::SetMapProjectionsRequest_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::map_msgs::SetMapProjectionsRequest_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream&, T)
    {}

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct SetMapProjectionsRequest_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::map_msgs::SetMapProjectionsRequest_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream&, const std::string&, const ::map_msgs::SetMapProjectionsRequest_<ContainerAllocator>&)
  {}
};

} // namespace message_operations
} // namespace ros

#endif // MAP_MSGS_MESSAGE_SETMAPPROJECTIONSREQUEST_H

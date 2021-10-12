// Generated by gencpp from file icp_registration/LaserdataResponse.msg
// DO NOT EDIT!


#ifndef ICP_REGISTRATION_MESSAGE_LASERDATARESPONSE_H
#define ICP_REGISTRATION_MESSAGE_LASERDATARESPONSE_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>

#include <geometry_msgs/Transform.h>

namespace icp_registration
{
template <class ContainerAllocator>
struct LaserdataResponse_
{
  typedef LaserdataResponse_<ContainerAllocator> Type;

  LaserdataResponse_()
    : transformation()  {
    }
  LaserdataResponse_(const ContainerAllocator& _alloc)
    : transformation(_alloc)  {
  (void)_alloc;
    }



   typedef  ::geometry_msgs::Transform_<ContainerAllocator>  _transformation_type;
  _transformation_type transformation;





  typedef boost::shared_ptr< ::icp_registration::LaserdataResponse_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::icp_registration::LaserdataResponse_<ContainerAllocator> const> ConstPtr;

}; // struct LaserdataResponse_

typedef ::icp_registration::LaserdataResponse_<std::allocator<void> > LaserdataResponse;

typedef boost::shared_ptr< ::icp_registration::LaserdataResponse > LaserdataResponsePtr;
typedef boost::shared_ptr< ::icp_registration::LaserdataResponse const> LaserdataResponseConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::icp_registration::LaserdataResponse_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::icp_registration::LaserdataResponse_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::icp_registration::LaserdataResponse_<ContainerAllocator1> & lhs, const ::icp_registration::LaserdataResponse_<ContainerAllocator2> & rhs)
{
  return lhs.transformation == rhs.transformation;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::icp_registration::LaserdataResponse_<ContainerAllocator1> & lhs, const ::icp_registration::LaserdataResponse_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace icp_registration

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsFixedSize< ::icp_registration::LaserdataResponse_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::icp_registration::LaserdataResponse_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::icp_registration::LaserdataResponse_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::icp_registration::LaserdataResponse_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::icp_registration::LaserdataResponse_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::icp_registration::LaserdataResponse_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::icp_registration::LaserdataResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "864384f3f3f33b2d787419fc29980bdd";
  }

  static const char* value(const ::icp_registration::LaserdataResponse_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x864384f3f3f33b2dULL;
  static const uint64_t static_value2 = 0x787419fc29980bddULL;
};

template<class ContainerAllocator>
struct DataType< ::icp_registration::LaserdataResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "icp_registration/LaserdataResponse";
  }

  static const char* value(const ::icp_registration::LaserdataResponse_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::icp_registration::LaserdataResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "geometry_msgs/Transform transformation\n"
"\n"
"================================================================================\n"
"MSG: geometry_msgs/Transform\n"
"# This represents the transform between two coordinate frames in free space.\n"
"\n"
"Vector3 translation\n"
"Quaternion rotation\n"
"\n"
"================================================================================\n"
"MSG: geometry_msgs/Vector3\n"
"# This represents a vector in free space. \n"
"# It is only meant to represent a direction. Therefore, it does not\n"
"# make sense to apply a translation to it (e.g., when applying a \n"
"# generic rigid transformation to a Vector3, tf2 will only apply the\n"
"# rotation). If you want your data to be translatable too, use the\n"
"# geometry_msgs/Point message instead.\n"
"\n"
"float64 x\n"
"float64 y\n"
"float64 z\n"
"================================================================================\n"
"MSG: geometry_msgs/Quaternion\n"
"# This represents an orientation in free space in quaternion form.\n"
"\n"
"float64 x\n"
"float64 y\n"
"float64 z\n"
"float64 w\n"
;
  }

  static const char* value(const ::icp_registration::LaserdataResponse_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::icp_registration::LaserdataResponse_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.transformation);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct LaserdataResponse_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::icp_registration::LaserdataResponse_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::icp_registration::LaserdataResponse_<ContainerAllocator>& v)
  {
    s << indent << "transformation: ";
    s << std::endl;
    Printer< ::geometry_msgs::Transform_<ContainerAllocator> >::stream(s, indent + "  ", v.transformation);
  }
};

} // namespace message_operations
} // namespace ros

#endif // ICP_REGISTRATION_MESSAGE_LASERDATARESPONSE_H

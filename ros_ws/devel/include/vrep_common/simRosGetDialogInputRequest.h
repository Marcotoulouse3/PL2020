// Generated by gencpp from file vrep_common/simRosGetDialogInputRequest.msg
// DO NOT EDIT!


#ifndef VREP_COMMON_MESSAGE_SIMROSGETDIALOGINPUTREQUEST_H
#define VREP_COMMON_MESSAGE_SIMROSGETDIALOGINPUTREQUEST_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace vrep_common
{
template <class ContainerAllocator>
struct simRosGetDialogInputRequest_
{
  typedef simRosGetDialogInputRequest_<ContainerAllocator> Type;

  simRosGetDialogInputRequest_()
    : dialogHandle(0)  {
    }
  simRosGetDialogInputRequest_(const ContainerAllocator& _alloc)
    : dialogHandle(0)  {
  (void)_alloc;
    }



   typedef int32_t _dialogHandle_type;
  _dialogHandle_type dialogHandle;




  typedef boost::shared_ptr< ::vrep_common::simRosGetDialogInputRequest_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::vrep_common::simRosGetDialogInputRequest_<ContainerAllocator> const> ConstPtr;

}; // struct simRosGetDialogInputRequest_

typedef ::vrep_common::simRosGetDialogInputRequest_<std::allocator<void> > simRosGetDialogInputRequest;

typedef boost::shared_ptr< ::vrep_common::simRosGetDialogInputRequest > simRosGetDialogInputRequestPtr;
typedef boost::shared_ptr< ::vrep_common::simRosGetDialogInputRequest const> simRosGetDialogInputRequestConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::vrep_common::simRosGetDialogInputRequest_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::vrep_common::simRosGetDialogInputRequest_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace vrep_common

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': True, 'IsMessage': True, 'HasHeader': False}
// {'sensor_msgs': ['/opt/ros/indigo/share/sensor_msgs/cmake/../msg'], 'std_msgs': ['/opt/ros/indigo/share/std_msgs/cmake/../msg'], 'geometry_msgs': ['/opt/ros/indigo/share/geometry_msgs/cmake/../msg'], 'vrep_common': ['/home/projn7cellule/PL_2018/ros_ws/src/vrep_common/msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::vrep_common::simRosGetDialogInputRequest_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::vrep_common::simRosGetDialogInputRequest_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::vrep_common::simRosGetDialogInputRequest_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::vrep_common::simRosGetDialogInputRequest_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::vrep_common::simRosGetDialogInputRequest_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::vrep_common::simRosGetDialogInputRequest_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::vrep_common::simRosGetDialogInputRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "290f4bd47ce8d0f7c78c1d510052331a";
  }

  static const char* value(const ::vrep_common::simRosGetDialogInputRequest_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x290f4bd47ce8d0f7ULL;
  static const uint64_t static_value2 = 0xc78c1d510052331aULL;
};

template<class ContainerAllocator>
struct DataType< ::vrep_common::simRosGetDialogInputRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "vrep_common/simRosGetDialogInputRequest";
  }

  static const char* value(const ::vrep_common::simRosGetDialogInputRequest_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::vrep_common::simRosGetDialogInputRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "\n\
\n\
\n\
\n\
int32 dialogHandle\n\
";
  }

  static const char* value(const ::vrep_common::simRosGetDialogInputRequest_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::vrep_common::simRosGetDialogInputRequest_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.dialogHandle);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct simRosGetDialogInputRequest_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::vrep_common::simRosGetDialogInputRequest_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::vrep_common::simRosGetDialogInputRequest_<ContainerAllocator>& v)
  {
    s << indent << "dialogHandle: ";
    Printer<int32_t>::stream(s, indent + "  ", v.dialogHandle);
  }
};

} // namespace message_operations
} // namespace ros

#endif // VREP_COMMON_MESSAGE_SIMROSGETDIALOGINPUTREQUEST_H

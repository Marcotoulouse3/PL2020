// Generated by gencpp from file vrep_common/simRosLoadScene.msg
// DO NOT EDIT!


#ifndef VREP_COMMON_MESSAGE_SIMROSLOADSCENE_H
#define VREP_COMMON_MESSAGE_SIMROSLOADSCENE_H

#include <ros/service_traits.h>


#include <vrep_common/simRosLoadSceneRequest.h>
#include <vrep_common/simRosLoadSceneResponse.h>


namespace vrep_common
{

struct simRosLoadScene
{

typedef simRosLoadSceneRequest Request;
typedef simRosLoadSceneResponse Response;
Request request;
Response response;

typedef Request RequestType;
typedef Response ResponseType;

}; // struct simRosLoadScene
} // namespace vrep_common


namespace ros
{
namespace service_traits
{


template<>
struct MD5Sum< ::vrep_common::simRosLoadScene > {
  static const char* value()
  {
    return "4ce16c0ffb6dc4c97455e3e44d2010aa";
  }

  static const char* value(const ::vrep_common::simRosLoadScene&) { return value(); }
};

template<>
struct DataType< ::vrep_common::simRosLoadScene > {
  static const char* value()
  {
    return "vrep_common/simRosLoadScene";
  }

  static const char* value(const ::vrep_common::simRosLoadScene&) { return value(); }
};


// service_traits::MD5Sum< ::vrep_common::simRosLoadSceneRequest> should match 
// service_traits::MD5Sum< ::vrep_common::simRosLoadScene > 
template<>
struct MD5Sum< ::vrep_common::simRosLoadSceneRequest>
{
  static const char* value()
  {
    return MD5Sum< ::vrep_common::simRosLoadScene >::value();
  }
  static const char* value(const ::vrep_common::simRosLoadSceneRequest&)
  {
    return value();
  }
};

// service_traits::DataType< ::vrep_common::simRosLoadSceneRequest> should match 
// service_traits::DataType< ::vrep_common::simRosLoadScene > 
template<>
struct DataType< ::vrep_common::simRosLoadSceneRequest>
{
  static const char* value()
  {
    return DataType< ::vrep_common::simRosLoadScene >::value();
  }
  static const char* value(const ::vrep_common::simRosLoadSceneRequest&)
  {
    return value();
  }
};

// service_traits::MD5Sum< ::vrep_common::simRosLoadSceneResponse> should match 
// service_traits::MD5Sum< ::vrep_common::simRosLoadScene > 
template<>
struct MD5Sum< ::vrep_common::simRosLoadSceneResponse>
{
  static const char* value()
  {
    return MD5Sum< ::vrep_common::simRosLoadScene >::value();
  }
  static const char* value(const ::vrep_common::simRosLoadSceneResponse&)
  {
    return value();
  }
};

// service_traits::DataType< ::vrep_common::simRosLoadSceneResponse> should match 
// service_traits::DataType< ::vrep_common::simRosLoadScene > 
template<>
struct DataType< ::vrep_common::simRosLoadSceneResponse>
{
  static const char* value()
  {
    return DataType< ::vrep_common::simRosLoadScene >::value();
  }
  static const char* value(const ::vrep_common::simRosLoadSceneResponse&)
  {
    return value();
  }
};

} // namespace service_traits
} // namespace ros

#endif // VREP_COMMON_MESSAGE_SIMROSLOADSCENE_H

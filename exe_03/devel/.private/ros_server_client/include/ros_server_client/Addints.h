// Generated by gencpp from file ros_server_client/Addints.msg
// DO NOT EDIT!


#ifndef ROS_SERVER_CLIENT_MESSAGE_ADDINTS_H
#define ROS_SERVER_CLIENT_MESSAGE_ADDINTS_H

#include <ros/service_traits.h>


#include <ros_server_client/AddintsRequest.h>
#include <ros_server_client/AddintsResponse.h>


namespace ros_server_client
{

struct Addints
{

typedef AddintsRequest Request;
typedef AddintsResponse Response;
Request request;
Response response;

typedef Request RequestType;
typedef Response ResponseType;

}; // struct Addints
} // namespace ros_server_client


namespace ros
{
namespace service_traits
{


template<>
struct MD5Sum< ::ros_server_client::Addints > {
  static const char* value()
  {
    return "4781436a0c2affec8025955a6041e481";
  }

  static const char* value(const ::ros_server_client::Addints&) { return value(); }
};

template<>
struct DataType< ::ros_server_client::Addints > {
  static const char* value()
  {
    return "ros_server_client/Addints";
  }

  static const char* value(const ::ros_server_client::Addints&) { return value(); }
};


// service_traits::MD5Sum< ::ros_server_client::AddintsRequest> should match
// service_traits::MD5Sum< ::ros_server_client::Addints >
template<>
struct MD5Sum< ::ros_server_client::AddintsRequest>
{
  static const char* value()
  {
    return MD5Sum< ::ros_server_client::Addints >::value();
  }
  static const char* value(const ::ros_server_client::AddintsRequest&)
  {
    return value();
  }
};

// service_traits::DataType< ::ros_server_client::AddintsRequest> should match
// service_traits::DataType< ::ros_server_client::Addints >
template<>
struct DataType< ::ros_server_client::AddintsRequest>
{
  static const char* value()
  {
    return DataType< ::ros_server_client::Addints >::value();
  }
  static const char* value(const ::ros_server_client::AddintsRequest&)
  {
    return value();
  }
};

// service_traits::MD5Sum< ::ros_server_client::AddintsResponse> should match
// service_traits::MD5Sum< ::ros_server_client::Addints >
template<>
struct MD5Sum< ::ros_server_client::AddintsResponse>
{
  static const char* value()
  {
    return MD5Sum< ::ros_server_client::Addints >::value();
  }
  static const char* value(const ::ros_server_client::AddintsResponse&)
  {
    return value();
  }
};

// service_traits::DataType< ::ros_server_client::AddintsResponse> should match
// service_traits::DataType< ::ros_server_client::Addints >
template<>
struct DataType< ::ros_server_client::AddintsResponse>
{
  static const char* value()
  {
    return DataType< ::ros_server_client::Addints >::value();
  }
  static const char* value(const ::ros_server_client::AddintsResponse&)
  {
    return value();
  }
};

} // namespace service_traits
} // namespace ros

#endif // ROS_SERVER_CLIENT_MESSAGE_ADDINTS_H

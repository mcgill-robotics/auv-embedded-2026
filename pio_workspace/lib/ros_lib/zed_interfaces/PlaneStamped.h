#ifndef _ROS_zed_interfaces_PlaneStamped_h
#define _ROS_zed_interfaces_PlaneStamped_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "shape_msgs/Mesh.h"
#include "shape_msgs/Plane.h"
#include "geometry_msgs/Point32.h"
#include "geometry_msgs/Transform.h"
#include "geometry_msgs/Polygon.h"

namespace zed_interfaces
{

  class PlaneStamped : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef shape_msgs::Mesh _mesh_type;
      _mesh_type mesh;
      typedef shape_msgs::Plane _coefficients_type;
      _coefficients_type coefficients;
      typedef geometry_msgs::Point32 _normal_type;
      _normal_type normal;
      typedef geometry_msgs::Point32 _center_type;
      _center_type center;
      typedef geometry_msgs::Transform _pose_type;
      _pose_type pose;
      float extents[2];
      typedef geometry_msgs::Polygon _bounds_type;
      _bounds_type bounds;

    PlaneStamped():
      header(),
      mesh(),
      coefficients(),
      normal(),
      center(),
      pose(),
      extents(),
      bounds()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      offset += this->mesh.serialize(outbuffer + offset);
      offset += this->coefficients.serialize(outbuffer + offset);
      offset += this->normal.serialize(outbuffer + offset);
      offset += this->center.serialize(outbuffer + offset);
      offset += this->pose.serialize(outbuffer + offset);
      for( uint32_t i = 0; i < 2; i++){
      union {
        float real;
        uint32_t base;
      } u_extentsi;
      u_extentsi.real = this->extents[i];
      *(outbuffer + offset + 0) = (u_extentsi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_extentsi.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_extentsi.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_extentsi.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->extents[i]);
      }
      offset += this->bounds.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      offset += this->mesh.deserialize(inbuffer + offset);
      offset += this->coefficients.deserialize(inbuffer + offset);
      offset += this->normal.deserialize(inbuffer + offset);
      offset += this->center.deserialize(inbuffer + offset);
      offset += this->pose.deserialize(inbuffer + offset);
      for( uint32_t i = 0; i < 2; i++){
      union {
        float real;
        uint32_t base;
      } u_extentsi;
      u_extentsi.base = 0;
      u_extentsi.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_extentsi.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_extentsi.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_extentsi.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->extents[i] = u_extentsi.real;
      offset += sizeof(this->extents[i]);
      }
      offset += this->bounds.deserialize(inbuffer + offset);
     return offset;
    }

    virtual const char * getType() override { return "zed_interfaces/PlaneStamped"; };
    virtual const char * getMD5() override { return "1ae4cda68097919aea83add5dc8f86c1"; };

  };

}
#endif

#ifndef _ROS_rtabmap_msgs_CameraModel_h
#define _ROS_rtabmap_msgs_CameraModel_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "sensor_msgs/CameraInfo.h"
#include "geometry_msgs/Transform.h"

namespace rtabmap_msgs
{

  class CameraModel : public ros::Msg
  {
    public:
      typedef sensor_msgs::CameraInfo _camera_info_type;
      _camera_info_type camera_info;
      typedef geometry_msgs::Transform _local_transform_type;
      _local_transform_type local_transform;

    CameraModel():
      camera_info(),
      local_transform()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->camera_info.serialize(outbuffer + offset);
      offset += this->local_transform.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->camera_info.deserialize(inbuffer + offset);
      offset += this->local_transform.deserialize(inbuffer + offset);
     return offset;
    }

    virtual const char * getType() override { return "rtabmap_msgs/CameraModel"; };
    virtual const char * getMD5() override { return "f9352913302b569cfb34fd659fea4d7b"; };

  };

}
#endif

#ifndef _ROS_zed_interfaces_Skeleton3D_h
#define _ROS_zed_interfaces_Skeleton3D_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "zed_interfaces/Keypoint3D.h"

namespace zed_interfaces
{

  class Skeleton3D : public ros::Msg
  {
    public:
      zed_interfaces::Keypoint3D keypoints[18];

    Skeleton3D():
      keypoints()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      for( uint32_t i = 0; i < 18; i++){
      offset += this->keypoints[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      for( uint32_t i = 0; i < 18; i++){
      offset += this->keypoints[i].deserialize(inbuffer + offset);
      }
     return offset;
    }

    virtual const char * getType() override { return "zed_interfaces/Skeleton3D"; };
    virtual const char * getMD5() override { return "b704d948cb88b776b9f51ee392e13c62"; };

  };

}
#endif

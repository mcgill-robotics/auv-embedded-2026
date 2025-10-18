#ifndef _ROS_zed_interfaces_BoundingBox3D_h
#define _ROS_zed_interfaces_BoundingBox3D_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "zed_interfaces/Keypoint3D.h"

namespace zed_interfaces
{

  class BoundingBox3D : public ros::Msg
  {
    public:
      zed_interfaces::Keypoint3D corners[8];

    BoundingBox3D():
      corners()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      for( uint32_t i = 0; i < 8; i++){
      offset += this->corners[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      for( uint32_t i = 0; i < 8; i++){
      offset += this->corners[i].deserialize(inbuffer + offset);
      }
     return offset;
    }

    virtual const char * getType() override { return "zed_interfaces/BoundingBox3D"; };
    virtual const char * getMD5() override { return "3750b81144ba1b26f88ce23eeb4efd34"; };

  };

}
#endif

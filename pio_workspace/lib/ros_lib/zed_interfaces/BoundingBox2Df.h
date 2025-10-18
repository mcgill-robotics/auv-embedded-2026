#ifndef _ROS_zed_interfaces_BoundingBox2Df_h
#define _ROS_zed_interfaces_BoundingBox2Df_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "zed_interfaces/Keypoint2Df.h"

namespace zed_interfaces
{

  class BoundingBox2Df : public ros::Msg
  {
    public:
      zed_interfaces::Keypoint2Df corners[4];

    BoundingBox2Df():
      corners()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      for( uint32_t i = 0; i < 4; i++){
      offset += this->corners[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      for( uint32_t i = 0; i < 4; i++){
      offset += this->corners[i].deserialize(inbuffer + offset);
      }
     return offset;
    }

    virtual const char * getType() override { return "zed_interfaces/BoundingBox2Df"; };
    virtual const char * getMD5() override { return "8ce1e9ea2b267e0dce506c975b1391b0"; };

  };

}
#endif

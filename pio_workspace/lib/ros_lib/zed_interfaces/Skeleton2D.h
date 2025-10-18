#ifndef _ROS_zed_interfaces_Skeleton2D_h
#define _ROS_zed_interfaces_Skeleton2D_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "zed_interfaces/Keypoint2Df.h"

namespace zed_interfaces
{

  class Skeleton2D : public ros::Msg
  {
    public:
      zed_interfaces::Keypoint2Df keypoints[18];

    Skeleton2D():
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

    virtual const char * getType() override { return "zed_interfaces/Skeleton2D"; };
    virtual const char * getMD5() override { return "1754703e1a6ce338ad28b9ee81fb712a"; };

  };

}
#endif

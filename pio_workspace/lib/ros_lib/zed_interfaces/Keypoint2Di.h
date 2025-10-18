#ifndef _ROS_zed_interfaces_Keypoint2Di_h
#define _ROS_zed_interfaces_Keypoint2Di_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace zed_interfaces
{

  class Keypoint2Di : public ros::Msg
  {
    public:
      uint32_t kp[2];

    Keypoint2Di():
      kp()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      for( uint32_t i = 0; i < 2; i++){
      *(outbuffer + offset + 0) = (this->kp[i] >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->kp[i] >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->kp[i] >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->kp[i] >> (8 * 3)) & 0xFF;
      offset += sizeof(this->kp[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      for( uint32_t i = 0; i < 2; i++){
      this->kp[i] =  ((uint32_t) (*(inbuffer + offset)));
      this->kp[i] |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->kp[i] |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->kp[i] |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->kp[i]);
      }
     return offset;
    }

    virtual const char * getType() override { return "zed_interfaces/Keypoint2Di"; };
    virtual const char * getMD5() override { return "5d23739e59e90009d64f8e07a5e96e2b"; };

  };

}
#endif

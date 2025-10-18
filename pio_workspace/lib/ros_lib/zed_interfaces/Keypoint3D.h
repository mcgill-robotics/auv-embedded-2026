#ifndef _ROS_zed_interfaces_Keypoint3D_h
#define _ROS_zed_interfaces_Keypoint3D_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace zed_interfaces
{

  class Keypoint3D : public ros::Msg
  {
    public:
      float kp[3];

    Keypoint3D():
      kp()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      for( uint32_t i = 0; i < 3; i++){
      union {
        float real;
        uint32_t base;
      } u_kpi;
      u_kpi.real = this->kp[i];
      *(outbuffer + offset + 0) = (u_kpi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_kpi.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_kpi.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_kpi.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->kp[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      for( uint32_t i = 0; i < 3; i++){
      union {
        float real;
        uint32_t base;
      } u_kpi;
      u_kpi.base = 0;
      u_kpi.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_kpi.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_kpi.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_kpi.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->kp[i] = u_kpi.real;
      offset += sizeof(this->kp[i]);
      }
     return offset;
    }

    virtual const char * getType() override { return "zed_interfaces/Keypoint3D"; };
    virtual const char * getMD5() override { return "f8f017135a763e4b81273453c9d8ef62"; };

  };

}
#endif

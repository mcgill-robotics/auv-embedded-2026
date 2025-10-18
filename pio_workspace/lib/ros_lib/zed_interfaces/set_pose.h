#ifndef _ROS_SERVICE_set_pose_h
#define _ROS_SERVICE_set_pose_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace zed_interfaces
{

static const char SET_POSE[] = "zed_interfaces/set_pose";

  class set_poseRequest : public ros::Msg
  {
    public:
      typedef float _x_type;
      _x_type x;
      typedef float _y_type;
      _y_type y;
      typedef float _z_type;
      _z_type z;
      typedef float _R_type;
      _R_type R;
      typedef float _P_type;
      _P_type P;
      typedef float _Y_type;
      _Y_type Y;

    set_poseRequest():
      x(0),
      y(0),
      z(0),
      R(0),
      P(0),
      Y(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      union {
        float real;
        uint32_t base;
      } u_x;
      u_x.real = this->x;
      *(outbuffer + offset + 0) = (u_x.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_x.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_x.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_x.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->x);
      union {
        float real;
        uint32_t base;
      } u_y;
      u_y.real = this->y;
      *(outbuffer + offset + 0) = (u_y.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_y.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_y.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_y.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->y);
      union {
        float real;
        uint32_t base;
      } u_z;
      u_z.real = this->z;
      *(outbuffer + offset + 0) = (u_z.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_z.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_z.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_z.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->z);
      union {
        float real;
        uint32_t base;
      } u_R;
      u_R.real = this->R;
      *(outbuffer + offset + 0) = (u_R.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_R.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_R.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_R.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->R);
      union {
        float real;
        uint32_t base;
      } u_P;
      u_P.real = this->P;
      *(outbuffer + offset + 0) = (u_P.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_P.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_P.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_P.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->P);
      union {
        float real;
        uint32_t base;
      } u_Y;
      u_Y.real = this->Y;
      *(outbuffer + offset + 0) = (u_Y.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_Y.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_Y.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_Y.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->Y);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      union {
        float real;
        uint32_t base;
      } u_x;
      u_x.base = 0;
      u_x.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_x.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_x.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_x.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->x = u_x.real;
      offset += sizeof(this->x);
      union {
        float real;
        uint32_t base;
      } u_y;
      u_y.base = 0;
      u_y.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_y.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_y.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_y.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->y = u_y.real;
      offset += sizeof(this->y);
      union {
        float real;
        uint32_t base;
      } u_z;
      u_z.base = 0;
      u_z.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_z.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_z.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_z.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->z = u_z.real;
      offset += sizeof(this->z);
      union {
        float real;
        uint32_t base;
      } u_R;
      u_R.base = 0;
      u_R.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_R.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_R.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_R.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->R = u_R.real;
      offset += sizeof(this->R);
      union {
        float real;
        uint32_t base;
      } u_P;
      u_P.base = 0;
      u_P.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_P.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_P.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_P.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->P = u_P.real;
      offset += sizeof(this->P);
      union {
        float real;
        uint32_t base;
      } u_Y;
      u_Y.base = 0;
      u_Y.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_Y.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_Y.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_Y.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->Y = u_Y.real;
      offset += sizeof(this->Y);
     return offset;
    }

    virtual const char * getType() override { return SET_POSE; };
    virtual const char * getMD5() override { return "2d76cb67dcd5839567c5ce0b111a67e4"; };

  };

  class set_poseResponse : public ros::Msg
  {
    public:
      typedef bool _done_type;
      _done_type done;

    set_poseResponse():
      done(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_done;
      u_done.real = this->done;
      *(outbuffer + offset + 0) = (u_done.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->done);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_done;
      u_done.base = 0;
      u_done.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->done = u_done.real;
      offset += sizeof(this->done);
     return offset;
    }

    virtual const char * getType() override { return SET_POSE; };
    virtual const char * getMD5() override { return "89bb254424e4cffedbf494e7b0ddbfea"; };

  };

  class set_pose {
    public:
    typedef set_poseRequest Request;
    typedef set_poseResponse Response;
  };

}
#endif

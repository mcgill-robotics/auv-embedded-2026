#ifndef _ROS_SERVICE_reset_tracking_h
#define _ROS_SERVICE_reset_tracking_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace zed_interfaces
{

static const char RESET_TRACKING[] = "zed_interfaces/reset_tracking";

  class reset_trackingRequest : public ros::Msg
  {
    public:

    reset_trackingRequest()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
     return offset;
    }

    virtual const char * getType() override { return RESET_TRACKING; };
    virtual const char * getMD5() override { return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class reset_trackingResponse : public ros::Msg
  {
    public:
      typedef bool _reset_done_type;
      _reset_done_type reset_done;

    reset_trackingResponse():
      reset_done(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_reset_done;
      u_reset_done.real = this->reset_done;
      *(outbuffer + offset + 0) = (u_reset_done.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->reset_done);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_reset_done;
      u_reset_done.base = 0;
      u_reset_done.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->reset_done = u_reset_done.real;
      offset += sizeof(this->reset_done);
     return offset;
    }

    virtual const char * getType() override { return RESET_TRACKING; };
    virtual const char * getMD5() override { return "e1e87fc9e9e6c154eca93b9fa292cc05"; };

  };

  class reset_tracking {
    public:
    typedef reset_trackingRequest Request;
    typedef reset_trackingResponse Response;
  };

}
#endif

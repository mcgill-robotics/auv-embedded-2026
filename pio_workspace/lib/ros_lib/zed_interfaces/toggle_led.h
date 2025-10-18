#ifndef _ROS_SERVICE_toggle_led_h
#define _ROS_SERVICE_toggle_led_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace zed_interfaces
{

static const char TOGGLE_LED[] = "zed_interfaces/toggle_led";

  class toggle_ledRequest : public ros::Msg
  {
    public:

    toggle_ledRequest()
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

    virtual const char * getType() override { return TOGGLE_LED; };
    virtual const char * getMD5() override { return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class toggle_ledResponse : public ros::Msg
  {
    public:
      typedef bool _new_led_status_type;
      _new_led_status_type new_led_status;

    toggle_ledResponse():
      new_led_status(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_new_led_status;
      u_new_led_status.real = this->new_led_status;
      *(outbuffer + offset + 0) = (u_new_led_status.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->new_led_status);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_new_led_status;
      u_new_led_status.base = 0;
      u_new_led_status.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->new_led_status = u_new_led_status.real;
      offset += sizeof(this->new_led_status);
     return offset;
    }

    virtual const char * getType() override { return TOGGLE_LED; };
    virtual const char * getMD5() override { return "866beb482157f32341c9f0eac54a1e38"; };

  };

  class toggle_led {
    public:
    typedef toggle_ledRequest Request;
    typedef toggle_ledResponse Response;
  };

}
#endif

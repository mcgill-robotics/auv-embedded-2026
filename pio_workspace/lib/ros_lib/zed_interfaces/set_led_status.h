#ifndef _ROS_SERVICE_set_led_status_h
#define _ROS_SERVICE_set_led_status_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace zed_interfaces
{

static const char SET_LED_STATUS[] = "zed_interfaces/set_led_status";

  class set_led_statusRequest : public ros::Msg
  {
    public:
      typedef bool _led_enabled_type;
      _led_enabled_type led_enabled;

    set_led_statusRequest():
      led_enabled(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_led_enabled;
      u_led_enabled.real = this->led_enabled;
      *(outbuffer + offset + 0) = (u_led_enabled.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->led_enabled);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_led_enabled;
      u_led_enabled.base = 0;
      u_led_enabled.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->led_enabled = u_led_enabled.real;
      offset += sizeof(this->led_enabled);
     return offset;
    }

    virtual const char * getType() override { return SET_LED_STATUS; };
    virtual const char * getMD5() override { return "f2e0f7cf20d5f300d5382e9eab56e737"; };

  };

  class set_led_statusResponse : public ros::Msg
  {
    public:
      typedef bool _done_type;
      _done_type done;

    set_led_statusResponse():
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

    virtual const char * getType() override { return SET_LED_STATUS; };
    virtual const char * getMD5() override { return "89bb254424e4cffedbf494e7b0ddbfea"; };

  };

  class set_led_status {
    public:
    typedef set_led_statusRequest Request;
    typedef set_led_statusResponse Response;
  };

}
#endif

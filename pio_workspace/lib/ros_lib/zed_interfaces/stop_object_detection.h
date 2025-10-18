#ifndef _ROS_SERVICE_stop_object_detection_h
#define _ROS_SERVICE_stop_object_detection_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace zed_interfaces
{

static const char STOP_OBJECT_DETECTION[] = "zed_interfaces/stop_object_detection";

  class stop_object_detectionRequest : public ros::Msg
  {
    public:

    stop_object_detectionRequest()
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

    virtual const char * getType() override { return STOP_OBJECT_DETECTION; };
    virtual const char * getMD5() override { return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class stop_object_detectionResponse : public ros::Msg
  {
    public:
      typedef bool _done_type;
      _done_type done;

    stop_object_detectionResponse():
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

    virtual const char * getType() override { return STOP_OBJECT_DETECTION; };
    virtual const char * getMD5() override { return "89bb254424e4cffedbf494e7b0ddbfea"; };

  };

  class stop_object_detection {
    public:
    typedef stop_object_detectionRequest Request;
    typedef stop_object_detectionResponse Response;
  };

}
#endif

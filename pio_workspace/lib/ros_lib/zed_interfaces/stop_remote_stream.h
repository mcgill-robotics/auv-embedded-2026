#ifndef _ROS_SERVICE_stop_remote_stream_h
#define _ROS_SERVICE_stop_remote_stream_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace zed_interfaces
{

static const char STOP_REMOTE_STREAM[] = "zed_interfaces/stop_remote_stream";

  class stop_remote_streamRequest : public ros::Msg
  {
    public:

    stop_remote_streamRequest()
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

    virtual const char * getType() override { return STOP_REMOTE_STREAM; };
    virtual const char * getMD5() override { return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class stop_remote_streamResponse : public ros::Msg
  {
    public:
      typedef bool _done_type;
      _done_type done;

    stop_remote_streamResponse():
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

    virtual const char * getType() override { return STOP_REMOTE_STREAM; };
    virtual const char * getMD5() override { return "89bb254424e4cffedbf494e7b0ddbfea"; };

  };

  class stop_remote_stream {
    public:
    typedef stop_remote_streamRequest Request;
    typedef stop_remote_streamResponse Response;
  };

}
#endif

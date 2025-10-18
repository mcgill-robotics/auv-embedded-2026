#ifndef _ROS_SERVICE_stop_3d_mapping_h
#define _ROS_SERVICE_stop_3d_mapping_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace zed_interfaces
{

static const char STOP_3D_MAPPING[] = "zed_interfaces/stop_3d_mapping";

  class stop_3d_mappingRequest : public ros::Msg
  {
    public:

    stop_3d_mappingRequest()
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

    virtual const char * getType() override { return STOP_3D_MAPPING; };
    virtual const char * getMD5() override { return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class stop_3d_mappingResponse : public ros::Msg
  {
    public:
      typedef bool _done_type;
      _done_type done;

    stop_3d_mappingResponse():
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

    virtual const char * getType() override { return STOP_3D_MAPPING; };
    virtual const char * getMD5() override { return "89bb254424e4cffedbf494e7b0ddbfea"; };

  };

  class stop_3d_mapping {
    public:
    typedef stop_3d_mappingRequest Request;
    typedef stop_3d_mappingResponse Response;
  };

}
#endif

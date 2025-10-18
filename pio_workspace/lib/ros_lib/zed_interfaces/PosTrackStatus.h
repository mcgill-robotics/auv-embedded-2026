#ifndef _ROS_zed_interfaces_PosTrackStatus_h
#define _ROS_zed_interfaces_PosTrackStatus_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace zed_interfaces
{

  class PosTrackStatus : public ros::Msg
  {
    public:
      typedef uint8_t _status_type;
      _status_type status;
      enum { SEARCHING = 0 };
      enum { OK =  1 };
      enum { OFF =  2 };
      enum { FPS_TOO_LOW =  3 };
      enum { SEARCHING_FLOOR_PLANE =  3 };

    PosTrackStatus():
      status(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->status >> (8 * 0)) & 0xFF;
      offset += sizeof(this->status);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      this->status =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->status);
     return offset;
    }

    virtual const char * getType() override { return "zed_interfaces/PosTrackStatus"; };
    virtual const char * getMD5() override { return "16c87ef5951f2667d385cacb152a0d50"; };

  };

}
#endif

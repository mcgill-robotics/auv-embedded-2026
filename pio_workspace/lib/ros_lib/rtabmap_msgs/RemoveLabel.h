#ifndef _ROS_SERVICE_RemoveLabel_h
#define _ROS_SERVICE_RemoveLabel_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace rtabmap_msgs
{

static const char REMOVELABEL[] = "rtabmap_msgs/RemoveLabel";

  class RemoveLabelRequest : public ros::Msg
  {
    public:
      typedef const char* _label_type;
      _label_type label;

    RemoveLabelRequest():
      label("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      uint32_t length_label = strlen(this->label);
      varToArr(outbuffer + offset, length_label);
      offset += 4;
      memcpy(outbuffer + offset, this->label, length_label);
      offset += length_label;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      uint32_t length_label;
      arrToVar(length_label, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_label; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_label-1]=0;
      this->label = (char *)(inbuffer + offset-1);
      offset += length_label;
     return offset;
    }

    virtual const char * getType() override { return REMOVELABEL; };
    virtual const char * getMD5() override { return "ea23f97416b04c6151d2b576c0665ac1"; };

  };

  class RemoveLabelResponse : public ros::Msg
  {
    public:

    RemoveLabelResponse()
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

    virtual const char * getType() override { return REMOVELABEL; };
    virtual const char * getMD5() override { return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class RemoveLabel {
    public:
    typedef RemoveLabelRequest Request;
    typedef RemoveLabelResponse Response;
  };

}
#endif

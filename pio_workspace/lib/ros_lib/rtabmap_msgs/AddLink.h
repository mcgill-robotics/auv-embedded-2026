#ifndef _ROS_SERVICE_AddLink_h
#define _ROS_SERVICE_AddLink_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "rtabmap_msgs/Link.h"

namespace rtabmap_msgs
{

static const char ADDLINK[] = "rtabmap_msgs/AddLink";

  class AddLinkRequest : public ros::Msg
  {
    public:
      typedef rtabmap_msgs::Link _link_type;
      _link_type link;

    AddLinkRequest():
      link()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->link.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->link.deserialize(inbuffer + offset);
     return offset;
    }

    virtual const char * getType() override { return ADDLINK; };
    virtual const char * getMD5() override { return "050728e3c25a15bf78d487d6aafab152"; };

  };

  class AddLinkResponse : public ros::Msg
  {
    public:

    AddLinkResponse()
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

    virtual const char * getType() override { return ADDLINK; };
    virtual const char * getMD5() override { return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class AddLink {
    public:
    typedef AddLinkRequest Request;
    typedef AddLinkResponse Response;
  };

}
#endif

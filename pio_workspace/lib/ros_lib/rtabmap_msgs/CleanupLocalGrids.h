#ifndef _ROS_SERVICE_CleanupLocalGrids_h
#define _ROS_SERVICE_CleanupLocalGrids_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace rtabmap_msgs
{

static const char CLEANUPLOCALGRIDS[] = "rtabmap_msgs/CleanupLocalGrids";

  class CleanupLocalGridsRequest : public ros::Msg
  {
    public:
      typedef int32_t _radius_type;
      _radius_type radius;
      typedef bool _filter_scans_type;
      _filter_scans_type filter_scans;

    CleanupLocalGridsRequest():
      radius(0),
      filter_scans(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      union {
        int32_t real;
        uint32_t base;
      } u_radius;
      u_radius.real = this->radius;
      *(outbuffer + offset + 0) = (u_radius.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_radius.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_radius.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_radius.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->radius);
      union {
        bool real;
        uint8_t base;
      } u_filter_scans;
      u_filter_scans.real = this->filter_scans;
      *(outbuffer + offset + 0) = (u_filter_scans.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->filter_scans);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      union {
        int32_t real;
        uint32_t base;
      } u_radius;
      u_radius.base = 0;
      u_radius.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_radius.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_radius.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_radius.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->radius = u_radius.real;
      offset += sizeof(this->radius);
      union {
        bool real;
        uint8_t base;
      } u_filter_scans;
      u_filter_scans.base = 0;
      u_filter_scans.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->filter_scans = u_filter_scans.real;
      offset += sizeof(this->filter_scans);
     return offset;
    }

    virtual const char * getType() override { return CLEANUPLOCALGRIDS; };
    virtual const char * getMD5() override { return "f7e9883a6b75c0ecc1bb1c33f3332f61"; };

  };

  class CleanupLocalGridsResponse : public ros::Msg
  {
    public:
      typedef int32_t _modified_type;
      _modified_type modified;

    CleanupLocalGridsResponse():
      modified(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      union {
        int32_t real;
        uint32_t base;
      } u_modified;
      u_modified.real = this->modified;
      *(outbuffer + offset + 0) = (u_modified.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_modified.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_modified.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_modified.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->modified);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      union {
        int32_t real;
        uint32_t base;
      } u_modified;
      u_modified.base = 0;
      u_modified.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_modified.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_modified.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_modified.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->modified = u_modified.real;
      offset += sizeof(this->modified);
     return offset;
    }

    virtual const char * getType() override { return CLEANUPLOCALGRIDS; };
    virtual const char * getMD5() override { return "0079be4fbca49cb5090f065d768dbb2c"; };

  };

  class CleanupLocalGrids {
    public:
    typedef CleanupLocalGridsRequest Request;
    typedef CleanupLocalGridsResponse Response;
  };

}
#endif

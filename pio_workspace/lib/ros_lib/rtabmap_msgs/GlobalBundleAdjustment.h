#ifndef _ROS_SERVICE_GlobalBundleAdjustment_h
#define _ROS_SERVICE_GlobalBundleAdjustment_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace rtabmap_msgs
{

static const char GLOBALBUNDLEADJUSTMENT[] = "rtabmap_msgs/GlobalBundleAdjustment";

  class GlobalBundleAdjustmentRequest : public ros::Msg
  {
    public:
      typedef int32_t _type_type;
      _type_type type;
      typedef int32_t _iterations_type;
      _iterations_type iterations;
      typedef float _pixel_variance_type;
      _pixel_variance_type pixel_variance;
      typedef bool _voc_matches_type;
      _voc_matches_type voc_matches;

    GlobalBundleAdjustmentRequest():
      type(0),
      iterations(0),
      pixel_variance(0),
      voc_matches(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      union {
        int32_t real;
        uint32_t base;
      } u_type;
      u_type.real = this->type;
      *(outbuffer + offset + 0) = (u_type.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_type.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_type.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_type.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->type);
      union {
        int32_t real;
        uint32_t base;
      } u_iterations;
      u_iterations.real = this->iterations;
      *(outbuffer + offset + 0) = (u_iterations.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_iterations.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_iterations.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_iterations.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->iterations);
      union {
        float real;
        uint32_t base;
      } u_pixel_variance;
      u_pixel_variance.real = this->pixel_variance;
      *(outbuffer + offset + 0) = (u_pixel_variance.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_pixel_variance.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_pixel_variance.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_pixel_variance.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->pixel_variance);
      union {
        bool real;
        uint8_t base;
      } u_voc_matches;
      u_voc_matches.real = this->voc_matches;
      *(outbuffer + offset + 0) = (u_voc_matches.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->voc_matches);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      union {
        int32_t real;
        uint32_t base;
      } u_type;
      u_type.base = 0;
      u_type.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_type.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_type.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_type.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->type = u_type.real;
      offset += sizeof(this->type);
      union {
        int32_t real;
        uint32_t base;
      } u_iterations;
      u_iterations.base = 0;
      u_iterations.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_iterations.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_iterations.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_iterations.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->iterations = u_iterations.real;
      offset += sizeof(this->iterations);
      union {
        float real;
        uint32_t base;
      } u_pixel_variance;
      u_pixel_variance.base = 0;
      u_pixel_variance.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_pixel_variance.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_pixel_variance.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_pixel_variance.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->pixel_variance = u_pixel_variance.real;
      offset += sizeof(this->pixel_variance);
      union {
        bool real;
        uint8_t base;
      } u_voc_matches;
      u_voc_matches.base = 0;
      u_voc_matches.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->voc_matches = u_voc_matches.real;
      offset += sizeof(this->voc_matches);
     return offset;
    }

    virtual const char * getType() override { return GLOBALBUNDLEADJUSTMENT; };
    virtual const char * getMD5() override { return "2e1ed640ba9f481fdaa2226734d70674"; };

  };

  class GlobalBundleAdjustmentResponse : public ros::Msg
  {
    public:

    GlobalBundleAdjustmentResponse()
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

    virtual const char * getType() override { return GLOBALBUNDLEADJUSTMENT; };
    virtual const char * getMD5() override { return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class GlobalBundleAdjustment {
    public:
    typedef GlobalBundleAdjustmentRequest Request;
    typedef GlobalBundleAdjustmentResponse Response;
  };

}
#endif

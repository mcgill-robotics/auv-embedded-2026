#ifndef _ROS_SERVICE_start_3d_mapping_h
#define _ROS_SERVICE_start_3d_mapping_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace zed_interfaces
{

static const char START_3D_MAPPING[] = "zed_interfaces/start_3d_mapping";

  class start_3d_mappingRequest : public ros::Msg
  {
    public:
      typedef float _resolution_type;
      _resolution_type resolution;
      typedef float _max_mapping_range_type;
      _max_mapping_range_type max_mapping_range;
      typedef float _fused_pointcloud_freq_type;
      _fused_pointcloud_freq_type fused_pointcloud_freq;

    start_3d_mappingRequest():
      resolution(0),
      max_mapping_range(0),
      fused_pointcloud_freq(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      union {
        float real;
        uint32_t base;
      } u_resolution;
      u_resolution.real = this->resolution;
      *(outbuffer + offset + 0) = (u_resolution.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_resolution.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_resolution.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_resolution.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->resolution);
      union {
        float real;
        uint32_t base;
      } u_max_mapping_range;
      u_max_mapping_range.real = this->max_mapping_range;
      *(outbuffer + offset + 0) = (u_max_mapping_range.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_max_mapping_range.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_max_mapping_range.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_max_mapping_range.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->max_mapping_range);
      union {
        float real;
        uint32_t base;
      } u_fused_pointcloud_freq;
      u_fused_pointcloud_freq.real = this->fused_pointcloud_freq;
      *(outbuffer + offset + 0) = (u_fused_pointcloud_freq.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_fused_pointcloud_freq.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_fused_pointcloud_freq.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_fused_pointcloud_freq.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->fused_pointcloud_freq);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      union {
        float real;
        uint32_t base;
      } u_resolution;
      u_resolution.base = 0;
      u_resolution.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_resolution.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_resolution.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_resolution.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->resolution = u_resolution.real;
      offset += sizeof(this->resolution);
      union {
        float real;
        uint32_t base;
      } u_max_mapping_range;
      u_max_mapping_range.base = 0;
      u_max_mapping_range.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_max_mapping_range.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_max_mapping_range.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_max_mapping_range.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->max_mapping_range = u_max_mapping_range.real;
      offset += sizeof(this->max_mapping_range);
      union {
        float real;
        uint32_t base;
      } u_fused_pointcloud_freq;
      u_fused_pointcloud_freq.base = 0;
      u_fused_pointcloud_freq.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_fused_pointcloud_freq.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_fused_pointcloud_freq.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_fused_pointcloud_freq.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->fused_pointcloud_freq = u_fused_pointcloud_freq.real;
      offset += sizeof(this->fused_pointcloud_freq);
     return offset;
    }

    virtual const char * getType() override { return START_3D_MAPPING; };
    virtual const char * getMD5() override { return "187ac9d444c9f537f1d5a7db64b8e12a"; };

  };

  class start_3d_mappingResponse : public ros::Msg
  {
    public:
      typedef bool _done_type;
      _done_type done;

    start_3d_mappingResponse():
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

    virtual const char * getType() override { return START_3D_MAPPING; };
    virtual const char * getMD5() override { return "89bb254424e4cffedbf494e7b0ddbfea"; };

  };

  class start_3d_mapping {
    public:
    typedef start_3d_mappingRequest Request;
    typedef start_3d_mappingResponse Response;
  };

}
#endif

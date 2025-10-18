#ifndef _ROS_SERVICE_GetMap2_h
#define _ROS_SERVICE_GetMap2_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "rtabmap_msgs/MapData.h"

namespace rtabmap_msgs
{

static const char GETMAP2[] = "rtabmap_msgs/GetMap2";

  class GetMap2Request : public ros::Msg
  {
    public:
      typedef bool _global_type;
      _global_type global;
      typedef bool _optimized_type;
      _optimized_type optimized;
      typedef bool _with_images_type;
      _with_images_type with_images;
      typedef bool _with_scans_type;
      _with_scans_type with_scans;
      typedef bool _with_user_data_type;
      _with_user_data_type with_user_data;
      typedef bool _with_grids_type;
      _with_grids_type with_grids;
      typedef bool _with_words_type;
      _with_words_type with_words;
      typedef bool _with_global_descriptors_type;
      _with_global_descriptors_type with_global_descriptors;

    GetMap2Request():
      global(0),
      optimized(0),
      with_images(0),
      with_scans(0),
      with_user_data(0),
      with_grids(0),
      with_words(0),
      with_global_descriptors(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_global;
      u_global.real = this->global;
      *(outbuffer + offset + 0) = (u_global.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->global);
      union {
        bool real;
        uint8_t base;
      } u_optimized;
      u_optimized.real = this->optimized;
      *(outbuffer + offset + 0) = (u_optimized.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->optimized);
      union {
        bool real;
        uint8_t base;
      } u_with_images;
      u_with_images.real = this->with_images;
      *(outbuffer + offset + 0) = (u_with_images.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->with_images);
      union {
        bool real;
        uint8_t base;
      } u_with_scans;
      u_with_scans.real = this->with_scans;
      *(outbuffer + offset + 0) = (u_with_scans.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->with_scans);
      union {
        bool real;
        uint8_t base;
      } u_with_user_data;
      u_with_user_data.real = this->with_user_data;
      *(outbuffer + offset + 0) = (u_with_user_data.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->with_user_data);
      union {
        bool real;
        uint8_t base;
      } u_with_grids;
      u_with_grids.real = this->with_grids;
      *(outbuffer + offset + 0) = (u_with_grids.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->with_grids);
      union {
        bool real;
        uint8_t base;
      } u_with_words;
      u_with_words.real = this->with_words;
      *(outbuffer + offset + 0) = (u_with_words.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->with_words);
      union {
        bool real;
        uint8_t base;
      } u_with_global_descriptors;
      u_with_global_descriptors.real = this->with_global_descriptors;
      *(outbuffer + offset + 0) = (u_with_global_descriptors.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->with_global_descriptors);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_global;
      u_global.base = 0;
      u_global.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->global = u_global.real;
      offset += sizeof(this->global);
      union {
        bool real;
        uint8_t base;
      } u_optimized;
      u_optimized.base = 0;
      u_optimized.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->optimized = u_optimized.real;
      offset += sizeof(this->optimized);
      union {
        bool real;
        uint8_t base;
      } u_with_images;
      u_with_images.base = 0;
      u_with_images.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->with_images = u_with_images.real;
      offset += sizeof(this->with_images);
      union {
        bool real;
        uint8_t base;
      } u_with_scans;
      u_with_scans.base = 0;
      u_with_scans.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->with_scans = u_with_scans.real;
      offset += sizeof(this->with_scans);
      union {
        bool real;
        uint8_t base;
      } u_with_user_data;
      u_with_user_data.base = 0;
      u_with_user_data.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->with_user_data = u_with_user_data.real;
      offset += sizeof(this->with_user_data);
      union {
        bool real;
        uint8_t base;
      } u_with_grids;
      u_with_grids.base = 0;
      u_with_grids.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->with_grids = u_with_grids.real;
      offset += sizeof(this->with_grids);
      union {
        bool real;
        uint8_t base;
      } u_with_words;
      u_with_words.base = 0;
      u_with_words.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->with_words = u_with_words.real;
      offset += sizeof(this->with_words);
      union {
        bool real;
        uint8_t base;
      } u_with_global_descriptors;
      u_with_global_descriptors.base = 0;
      u_with_global_descriptors.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->with_global_descriptors = u_with_global_descriptors.real;
      offset += sizeof(this->with_global_descriptors);
     return offset;
    }

    virtual const char * getType() override { return GETMAP2; };
    virtual const char * getMD5() override { return "6c99a44d248df7f406229ae2372dab2e"; };

  };

  class GetMap2Response : public ros::Msg
  {
    public:
      typedef rtabmap_msgs::MapData _data_type;
      _data_type data;

    GetMap2Response():
      data()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->data.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->data.deserialize(inbuffer + offset);
     return offset;
    }

    virtual const char * getType() override { return GETMAP2; };
    virtual const char * getMD5() override { return "76e7e98705d080822083ef0a96245bb9"; };

  };

  class GetMap2 {
    public:
    typedef GetMap2Request Request;
    typedef GetMap2Response Response;
  };

}
#endif

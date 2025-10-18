#ifndef _ROS_SERVICE_save_area_memory_h
#define _ROS_SERVICE_save_area_memory_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace zed_interfaces
{

static const char SAVE_AREA_MEMORY[] = "zed_interfaces/save_area_memory";

  class save_area_memoryRequest : public ros::Msg
  {
    public:
      typedef const char* _area_memory_filename_type;
      _area_memory_filename_type area_memory_filename;

    save_area_memoryRequest():
      area_memory_filename("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      uint32_t length_area_memory_filename = strlen(this->area_memory_filename);
      varToArr(outbuffer + offset, length_area_memory_filename);
      offset += 4;
      memcpy(outbuffer + offset, this->area_memory_filename, length_area_memory_filename);
      offset += length_area_memory_filename;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      uint32_t length_area_memory_filename;
      arrToVar(length_area_memory_filename, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_area_memory_filename; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_area_memory_filename-1]=0;
      this->area_memory_filename = (char *)(inbuffer + offset-1);
      offset += length_area_memory_filename;
     return offset;
    }

    virtual const char * getType() override { return SAVE_AREA_MEMORY; };
    virtual const char * getMD5() override { return "ab0f15ea60791be9468710556673c3a9"; };

  };

  class save_area_memoryResponse : public ros::Msg
  {
    public:
      typedef bool _result_type;
      _result_type result;
      typedef const char* _info_type;
      _info_type info;

    save_area_memoryResponse():
      result(0),
      info("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_result;
      u_result.real = this->result;
      *(outbuffer + offset + 0) = (u_result.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->result);
      uint32_t length_info = strlen(this->info);
      varToArr(outbuffer + offset, length_info);
      offset += 4;
      memcpy(outbuffer + offset, this->info, length_info);
      offset += length_info;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_result;
      u_result.base = 0;
      u_result.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->result = u_result.real;
      offset += sizeof(this->result);
      uint32_t length_info;
      arrToVar(length_info, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_info; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_info-1]=0;
      this->info = (char *)(inbuffer + offset-1);
      offset += length_info;
     return offset;
    }

    virtual const char * getType() override { return SAVE_AREA_MEMORY; };
    virtual const char * getMD5() override { return "929b8c0d7b68510a3f501a60258c746e"; };

  };

  class save_area_memory {
    public:
    typedef save_area_memoryRequest Request;
    typedef save_area_memoryResponse Response;
  };

}
#endif

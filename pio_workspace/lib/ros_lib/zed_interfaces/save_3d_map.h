#ifndef _ROS_SERVICE_save_3d_map_h
#define _ROS_SERVICE_save_3d_map_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace zed_interfaces
{

static const char SAVE_3D_MAP[] = "zed_interfaces/save_3d_map";

  class save_3d_mapRequest : public ros::Msg
  {
    public:
      typedef const char* _map_filename_type;
      _map_filename_type map_filename;
      typedef uint8_t _file_format_type;
      _file_format_type file_format;

    save_3d_mapRequest():
      map_filename(""),
      file_format(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      uint32_t length_map_filename = strlen(this->map_filename);
      varToArr(outbuffer + offset, length_map_filename);
      offset += 4;
      memcpy(outbuffer + offset, this->map_filename, length_map_filename);
      offset += length_map_filename;
      *(outbuffer + offset + 0) = (this->file_format >> (8 * 0)) & 0xFF;
      offset += sizeof(this->file_format);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      uint32_t length_map_filename;
      arrToVar(length_map_filename, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_map_filename; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_map_filename-1]=0;
      this->map_filename = (char *)(inbuffer + offset-1);
      offset += length_map_filename;
      this->file_format =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->file_format);
     return offset;
    }

    virtual const char * getType() override { return SAVE_3D_MAP; };
    virtual const char * getMD5() override { return "56677e0c5e358a82a455f7d0d9b27a0e"; };

  };

  class save_3d_mapResponse : public ros::Msg
  {
    public:
      typedef bool _result_type;
      _result_type result;
      typedef const char* _info_type;
      _info_type info;

    save_3d_mapResponse():
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

    virtual const char * getType() override { return SAVE_3D_MAP; };
    virtual const char * getMD5() override { return "929b8c0d7b68510a3f501a60258c746e"; };

  };

  class save_3d_map {
    public:
    typedef save_3d_mapRequest Request;
    typedef save_3d_mapResponse Response;
  };

}
#endif

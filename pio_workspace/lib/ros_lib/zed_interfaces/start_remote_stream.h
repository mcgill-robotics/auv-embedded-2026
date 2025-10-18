#ifndef _ROS_SERVICE_start_remote_stream_h
#define _ROS_SERVICE_start_remote_stream_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace zed_interfaces
{

static const char START_REMOTE_STREAM[] = "zed_interfaces/start_remote_stream";

  class start_remote_streamRequest : public ros::Msg
  {
    public:
      enum { codec = 0 };
      enum { port = 30000 };
      enum { bitrate = 2000 };
      enum { gop_size = -1 };
      enum { adaptative_bitrate = False };

    start_remote_streamRequest()
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

    virtual const char * getType() override { return START_REMOTE_STREAM; };
    virtual const char * getMD5() override { return "a6f55a6077162992b395e1b483a03367"; };

  };

  class start_remote_streamResponse : public ros::Msg
  {
    public:
      typedef bool _result_type;
      _result_type result;
      typedef const char* _info_type;
      _info_type info;

    start_remote_streamResponse():
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

    virtual const char * getType() override { return START_REMOTE_STREAM; };
    virtual const char * getMD5() override { return "929b8c0d7b68510a3f501a60258c746e"; };

  };

  class start_remote_stream {
    public:
    typedef start_remote_streamRequest Request;
    typedef start_remote_streamResponse Response;
  };

}
#endif

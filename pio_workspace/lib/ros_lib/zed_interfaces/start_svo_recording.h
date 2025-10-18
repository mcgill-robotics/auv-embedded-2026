#ifndef _ROS_SERVICE_start_svo_recording_h
#define _ROS_SERVICE_start_svo_recording_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace zed_interfaces
{

static const char START_SVO_RECORDING[] = "zed_interfaces/start_svo_recording";

  class start_svo_recordingRequest : public ros::Msg
  {
    public:
      typedef const char* _svo_filename_type;
      _svo_filename_type svo_filename;

    start_svo_recordingRequest():
      svo_filename("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      uint32_t length_svo_filename = strlen(this->svo_filename);
      varToArr(outbuffer + offset, length_svo_filename);
      offset += 4;
      memcpy(outbuffer + offset, this->svo_filename, length_svo_filename);
      offset += length_svo_filename;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      uint32_t length_svo_filename;
      arrToVar(length_svo_filename, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_svo_filename; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_svo_filename-1]=0;
      this->svo_filename = (char *)(inbuffer + offset-1);
      offset += length_svo_filename;
     return offset;
    }

    virtual const char * getType() override { return START_SVO_RECORDING; };
    virtual const char * getMD5() override { return "d53367c1321809b5cdba020b6f0085ff"; };

  };

  class start_svo_recordingResponse : public ros::Msg
  {
    public:
      typedef bool _result_type;
      _result_type result;
      typedef const char* _info_type;
      _info_type info;

    start_svo_recordingResponse():
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

    virtual const char * getType() override { return START_SVO_RECORDING; };
    virtual const char * getMD5() override { return "929b8c0d7b68510a3f501a60258c746e"; };

  };

  class start_svo_recording {
    public:
    typedef start_svo_recordingRequest Request;
    typedef start_svo_recordingResponse Response;
  };

}
#endif

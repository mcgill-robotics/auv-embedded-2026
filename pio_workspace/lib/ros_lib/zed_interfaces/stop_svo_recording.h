#ifndef _ROS_SERVICE_stop_svo_recording_h
#define _ROS_SERVICE_stop_svo_recording_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace zed_interfaces
{

static const char STOP_SVO_RECORDING[] = "zed_interfaces/stop_svo_recording";

  class stop_svo_recordingRequest : public ros::Msg
  {
    public:

    stop_svo_recordingRequest()
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

    virtual const char * getType() override { return STOP_SVO_RECORDING; };
    virtual const char * getMD5() override { return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class stop_svo_recordingResponse : public ros::Msg
  {
    public:
      typedef bool _done_type;
      _done_type done;
      typedef const char* _info_type;
      _info_type info;

    stop_svo_recordingResponse():
      done(0),
      info("")
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
      } u_done;
      u_done.base = 0;
      u_done.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->done = u_done.real;
      offset += sizeof(this->done);
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

    virtual const char * getType() override { return STOP_SVO_RECORDING; };
    virtual const char * getMD5() override { return "784b6c45ec0bd93cee43c7cd15145736"; };

  };

  class stop_svo_recording {
    public:
    typedef stop_svo_recordingRequest Request;
    typedef stop_svo_recordingResponse Response;
  };

}
#endif

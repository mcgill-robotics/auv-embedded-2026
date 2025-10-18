#ifndef _ROS_SERVICE_LoadDatabase_h
#define _ROS_SERVICE_LoadDatabase_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace rtabmap_msgs
{

static const char LOADDATABASE[] = "rtabmap_msgs/LoadDatabase";

  class LoadDatabaseRequest : public ros::Msg
  {
    public:
      typedef const char* _database_path_type;
      _database_path_type database_path;
      typedef bool _clear_type;
      _clear_type clear;

    LoadDatabaseRequest():
      database_path(""),
      clear(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      uint32_t length_database_path = strlen(this->database_path);
      varToArr(outbuffer + offset, length_database_path);
      offset += 4;
      memcpy(outbuffer + offset, this->database_path, length_database_path);
      offset += length_database_path;
      union {
        bool real;
        uint8_t base;
      } u_clear;
      u_clear.real = this->clear;
      *(outbuffer + offset + 0) = (u_clear.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->clear);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      uint32_t length_database_path;
      arrToVar(length_database_path, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_database_path; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_database_path-1]=0;
      this->database_path = (char *)(inbuffer + offset-1);
      offset += length_database_path;
      union {
        bool real;
        uint8_t base;
      } u_clear;
      u_clear.base = 0;
      u_clear.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->clear = u_clear.real;
      offset += sizeof(this->clear);
     return offset;
    }

    virtual const char * getType() override { return LOADDATABASE; };
    virtual const char * getMD5() override { return "686abf12c0ee22118c7e5fcc29bcdabe"; };

  };

  class LoadDatabaseResponse : public ros::Msg
  {
    public:

    LoadDatabaseResponse()
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

    virtual const char * getType() override { return LOADDATABASE; };
    virtual const char * getMD5() override { return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class LoadDatabase {
    public:
    typedef LoadDatabaseRequest Request;
    typedef LoadDatabaseResponse Response;
  };

}
#endif

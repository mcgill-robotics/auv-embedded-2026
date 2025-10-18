#ifndef _ROS_rtabmap_msgs_GlobalDescriptor_h
#define _ROS_rtabmap_msgs_GlobalDescriptor_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace rtabmap_msgs
{

  class GlobalDescriptor : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef int32_t _type_type;
      _type_type type;
      uint32_t info_length;
      typedef uint8_t _info_type;
      _info_type st_info;
      _info_type * info;
      uint32_t data_length;
      typedef uint8_t _data_type;
      _data_type st_data;
      _data_type * data;

    GlobalDescriptor():
      header(),
      type(0),
      info_length(0), st_info(), info(nullptr),
      data_length(0), st_data(), data(nullptr)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
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
      *(outbuffer + offset + 0) = (this->info_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->info_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->info_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->info_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->info_length);
      for( uint32_t i = 0; i < info_length; i++){
      *(outbuffer + offset + 0) = (this->info[i] >> (8 * 0)) & 0xFF;
      offset += sizeof(this->info[i]);
      }
      *(outbuffer + offset + 0) = (this->data_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->data_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->data_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->data_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->data_length);
      for( uint32_t i = 0; i < data_length; i++){
      *(outbuffer + offset + 0) = (this->data[i] >> (8 * 0)) & 0xFF;
      offset += sizeof(this->data[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
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
      uint32_t info_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      info_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      info_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      info_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->info_length);
      if(info_lengthT > info_length)
        this->info = (uint8_t*)realloc(this->info, info_lengthT * sizeof(uint8_t));
      info_length = info_lengthT;
      for( uint32_t i = 0; i < info_length; i++){
      this->st_info =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->st_info);
        memcpy( &(this->info[i]), &(this->st_info), sizeof(uint8_t));
      }
      uint32_t data_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      data_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      data_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      data_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->data_length);
      if(data_lengthT > data_length)
        this->data = (uint8_t*)realloc(this->data, data_lengthT * sizeof(uint8_t));
      data_length = data_lengthT;
      for( uint32_t i = 0; i < data_length; i++){
      this->st_data =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->st_data);
        memcpy( &(this->data[i]), &(this->st_data), sizeof(uint8_t));
      }
     return offset;
    }

    virtual const char * getType() override { return "rtabmap_msgs/GlobalDescriptor"; };
    virtual const char * getMD5() override { return "cea16e5cbeb4de779e68853766f4772e"; };

  };

}
#endif

#ifndef _ROS_SERVICE_GetNodeData_h
#define _ROS_SERVICE_GetNodeData_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "rtabmap_msgs/Node.h"

namespace rtabmap_msgs
{

static const char GETNODEDATA[] = "rtabmap_msgs/GetNodeData";

  class GetNodeDataRequest : public ros::Msg
  {
    public:
      uint32_t ids_length;
      typedef int32_t _ids_type;
      _ids_type st_ids;
      _ids_type * ids;
      typedef bool _images_type;
      _images_type images;
      typedef bool _scan_type;
      _scan_type scan;
      typedef bool _grid_type;
      _grid_type grid;
      typedef bool _user_data_type;
      _user_data_type user_data;

    GetNodeDataRequest():
      ids_length(0), st_ids(), ids(nullptr),
      images(0),
      scan(0),
      grid(0),
      user_data(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->ids_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->ids_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->ids_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->ids_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->ids_length);
      for( uint32_t i = 0; i < ids_length; i++){
      union {
        int32_t real;
        uint32_t base;
      } u_idsi;
      u_idsi.real = this->ids[i];
      *(outbuffer + offset + 0) = (u_idsi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_idsi.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_idsi.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_idsi.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->ids[i]);
      }
      union {
        bool real;
        uint8_t base;
      } u_images;
      u_images.real = this->images;
      *(outbuffer + offset + 0) = (u_images.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->images);
      union {
        bool real;
        uint8_t base;
      } u_scan;
      u_scan.real = this->scan;
      *(outbuffer + offset + 0) = (u_scan.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->scan);
      union {
        bool real;
        uint8_t base;
      } u_grid;
      u_grid.real = this->grid;
      *(outbuffer + offset + 0) = (u_grid.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->grid);
      union {
        bool real;
        uint8_t base;
      } u_user_data;
      u_user_data.real = this->user_data;
      *(outbuffer + offset + 0) = (u_user_data.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->user_data);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      uint32_t ids_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      ids_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      ids_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      ids_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->ids_length);
      if(ids_lengthT > ids_length)
        this->ids = (int32_t*)realloc(this->ids, ids_lengthT * sizeof(int32_t));
      ids_length = ids_lengthT;
      for( uint32_t i = 0; i < ids_length; i++){
      union {
        int32_t real;
        uint32_t base;
      } u_st_ids;
      u_st_ids.base = 0;
      u_st_ids.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_ids.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_st_ids.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_st_ids.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->st_ids = u_st_ids.real;
      offset += sizeof(this->st_ids);
        memcpy( &(this->ids[i]), &(this->st_ids), sizeof(int32_t));
      }
      union {
        bool real;
        uint8_t base;
      } u_images;
      u_images.base = 0;
      u_images.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->images = u_images.real;
      offset += sizeof(this->images);
      union {
        bool real;
        uint8_t base;
      } u_scan;
      u_scan.base = 0;
      u_scan.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->scan = u_scan.real;
      offset += sizeof(this->scan);
      union {
        bool real;
        uint8_t base;
      } u_grid;
      u_grid.base = 0;
      u_grid.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->grid = u_grid.real;
      offset += sizeof(this->grid);
      union {
        bool real;
        uint8_t base;
      } u_user_data;
      u_user_data.base = 0;
      u_user_data.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->user_data = u_user_data.real;
      offset += sizeof(this->user_data);
     return offset;
    }

    virtual const char * getType() override { return GETNODEDATA; };
    virtual const char * getMD5() override { return "0e8d18cf9b3249ab98f2d25e6071cc75"; };

  };

  class GetNodeDataResponse : public ros::Msg
  {
    public:
      uint32_t data_length;
      typedef rtabmap_msgs::Node _data_type;
      _data_type st_data;
      _data_type * data;

    GetNodeDataResponse():
      data_length(0), st_data(), data(nullptr)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->data_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->data_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->data_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->data_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->data_length);
      for( uint32_t i = 0; i < data_length; i++){
      offset += this->data[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      uint32_t data_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      data_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      data_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      data_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->data_length);
      if(data_lengthT > data_length)
        this->data = (rtabmap_msgs::Node*)realloc(this->data, data_lengthT * sizeof(rtabmap_msgs::Node));
      data_length = data_lengthT;
      for( uint32_t i = 0; i < data_length; i++){
      offset += this->st_data.deserialize(inbuffer + offset);
        memcpy( &(this->data[i]), &(this->st_data), sizeof(rtabmap_msgs::Node));
      }
     return offset;
    }

    virtual const char * getType() override { return GETNODEDATA; };
    virtual const char * getMD5() override { return "0eacd7dc712bd74cb0beddb338a1f77f"; };

  };

  class GetNodeData {
    public:
    typedef GetNodeDataRequest Request;
    typedef GetNodeDataResponse Response;
  };

}
#endif

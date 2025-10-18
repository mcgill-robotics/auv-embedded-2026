#ifndef _ROS_rtabmap_msgs_RGBDImage_h
#define _ROS_rtabmap_msgs_RGBDImage_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "sensor_msgs/CameraInfo.h"
#include "sensor_msgs/Image.h"
#include "sensor_msgs/CompressedImage.h"
#include "rtabmap_msgs/KeyPoint.h"
#include "rtabmap_msgs/Point3f.h"
#include "rtabmap_msgs/GlobalDescriptor.h"

namespace rtabmap_msgs
{

  class RGBDImage : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef sensor_msgs::CameraInfo _rgb_camera_info_type;
      _rgb_camera_info_type rgb_camera_info;
      typedef sensor_msgs::CameraInfo _depth_camera_info_type;
      _depth_camera_info_type depth_camera_info;
      typedef sensor_msgs::Image _rgb_type;
      _rgb_type rgb;
      typedef sensor_msgs::Image _depth_type;
      _depth_type depth;
      typedef sensor_msgs::CompressedImage _rgb_compressed_type;
      _rgb_compressed_type rgb_compressed;
      typedef sensor_msgs::CompressedImage _depth_compressed_type;
      _depth_compressed_type depth_compressed;
      uint32_t key_points_length;
      typedef rtabmap_msgs::KeyPoint _key_points_type;
      _key_points_type st_key_points;
      _key_points_type * key_points;
      uint32_t points_length;
      typedef rtabmap_msgs::Point3f _points_type;
      _points_type st_points;
      _points_type * points;
      uint32_t descriptors_length;
      typedef uint8_t _descriptors_type;
      _descriptors_type st_descriptors;
      _descriptors_type * descriptors;
      typedef rtabmap_msgs::GlobalDescriptor _global_descriptor_type;
      _global_descriptor_type global_descriptor;

    RGBDImage():
      header(),
      rgb_camera_info(),
      depth_camera_info(),
      rgb(),
      depth(),
      rgb_compressed(),
      depth_compressed(),
      key_points_length(0), st_key_points(), key_points(nullptr),
      points_length(0), st_points(), points(nullptr),
      descriptors_length(0), st_descriptors(), descriptors(nullptr),
      global_descriptor()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      offset += this->rgb_camera_info.serialize(outbuffer + offset);
      offset += this->depth_camera_info.serialize(outbuffer + offset);
      offset += this->rgb.serialize(outbuffer + offset);
      offset += this->depth.serialize(outbuffer + offset);
      offset += this->rgb_compressed.serialize(outbuffer + offset);
      offset += this->depth_compressed.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->key_points_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->key_points_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->key_points_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->key_points_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->key_points_length);
      for( uint32_t i = 0; i < key_points_length; i++){
      offset += this->key_points[i].serialize(outbuffer + offset);
      }
      *(outbuffer + offset + 0) = (this->points_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->points_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->points_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->points_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->points_length);
      for( uint32_t i = 0; i < points_length; i++){
      offset += this->points[i].serialize(outbuffer + offset);
      }
      *(outbuffer + offset + 0) = (this->descriptors_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->descriptors_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->descriptors_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->descriptors_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->descriptors_length);
      for( uint32_t i = 0; i < descriptors_length; i++){
      *(outbuffer + offset + 0) = (this->descriptors[i] >> (8 * 0)) & 0xFF;
      offset += sizeof(this->descriptors[i]);
      }
      offset += this->global_descriptor.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      offset += this->rgb_camera_info.deserialize(inbuffer + offset);
      offset += this->depth_camera_info.deserialize(inbuffer + offset);
      offset += this->rgb.deserialize(inbuffer + offset);
      offset += this->depth.deserialize(inbuffer + offset);
      offset += this->rgb_compressed.deserialize(inbuffer + offset);
      offset += this->depth_compressed.deserialize(inbuffer + offset);
      uint32_t key_points_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      key_points_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      key_points_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      key_points_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->key_points_length);
      if(key_points_lengthT > key_points_length)
        this->key_points = (rtabmap_msgs::KeyPoint*)realloc(this->key_points, key_points_lengthT * sizeof(rtabmap_msgs::KeyPoint));
      key_points_length = key_points_lengthT;
      for( uint32_t i = 0; i < key_points_length; i++){
      offset += this->st_key_points.deserialize(inbuffer + offset);
        memcpy( &(this->key_points[i]), &(this->st_key_points), sizeof(rtabmap_msgs::KeyPoint));
      }
      uint32_t points_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      points_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      points_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      points_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->points_length);
      if(points_lengthT > points_length)
        this->points = (rtabmap_msgs::Point3f*)realloc(this->points, points_lengthT * sizeof(rtabmap_msgs::Point3f));
      points_length = points_lengthT;
      for( uint32_t i = 0; i < points_length; i++){
      offset += this->st_points.deserialize(inbuffer + offset);
        memcpy( &(this->points[i]), &(this->st_points), sizeof(rtabmap_msgs::Point3f));
      }
      uint32_t descriptors_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      descriptors_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      descriptors_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      descriptors_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->descriptors_length);
      if(descriptors_lengthT > descriptors_length)
        this->descriptors = (uint8_t*)realloc(this->descriptors, descriptors_lengthT * sizeof(uint8_t));
      descriptors_length = descriptors_lengthT;
      for( uint32_t i = 0; i < descriptors_length; i++){
      this->st_descriptors =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->st_descriptors);
        memcpy( &(this->descriptors[i]), &(this->st_descriptors), sizeof(uint8_t));
      }
      offset += this->global_descriptor.deserialize(inbuffer + offset);
     return offset;
    }

    virtual const char * getType() override { return "rtabmap_msgs/RGBDImage"; };
    virtual const char * getMD5() override { return "affef6cc8804ffba98ce6ed6f1ca8942"; };

  };

}
#endif

#ifndef _ROS_find_object_2d_DetectionInfo_h
#define _ROS_find_object_2d_DetectionInfo_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "std_msgs/Int32.h"
#include "std_msgs/String.h"
#include "std_msgs/Float32MultiArray.h"

namespace find_object_2d
{

  class DetectionInfo : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      uint32_t ids_length;
      typedef std_msgs::Int32 _ids_type;
      _ids_type st_ids;
      _ids_type * ids;
      uint32_t widths_length;
      typedef std_msgs::Int32 _widths_type;
      _widths_type st_widths;
      _widths_type * widths;
      uint32_t heights_length;
      typedef std_msgs::Int32 _heights_type;
      _heights_type st_heights;
      _heights_type * heights;
      uint32_t file_paths_length;
      typedef std_msgs::String _file_paths_type;
      _file_paths_type st_file_paths;
      _file_paths_type * file_paths;
      uint32_t inliers_length;
      typedef std_msgs::Int32 _inliers_type;
      _inliers_type st_inliers;
      _inliers_type * inliers;
      uint32_t outliers_length;
      typedef std_msgs::Int32 _outliers_type;
      _outliers_type st_outliers;
      _outliers_type * outliers;
      uint32_t homographies_length;
      typedef std_msgs::Float32MultiArray _homographies_type;
      _homographies_type st_homographies;
      _homographies_type * homographies;

    DetectionInfo():
      header(),
      ids_length(0), st_ids(), ids(nullptr),
      widths_length(0), st_widths(), widths(nullptr),
      heights_length(0), st_heights(), heights(nullptr),
      file_paths_length(0), st_file_paths(), file_paths(nullptr),
      inliers_length(0), st_inliers(), inliers(nullptr),
      outliers_length(0), st_outliers(), outliers(nullptr),
      homographies_length(0), st_homographies(), homographies(nullptr)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->ids_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->ids_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->ids_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->ids_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->ids_length);
      for( uint32_t i = 0; i < ids_length; i++){
      offset += this->ids[i].serialize(outbuffer + offset);
      }
      *(outbuffer + offset + 0) = (this->widths_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->widths_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->widths_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->widths_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->widths_length);
      for( uint32_t i = 0; i < widths_length; i++){
      offset += this->widths[i].serialize(outbuffer + offset);
      }
      *(outbuffer + offset + 0) = (this->heights_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->heights_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->heights_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->heights_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->heights_length);
      for( uint32_t i = 0; i < heights_length; i++){
      offset += this->heights[i].serialize(outbuffer + offset);
      }
      *(outbuffer + offset + 0) = (this->file_paths_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->file_paths_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->file_paths_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->file_paths_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->file_paths_length);
      for( uint32_t i = 0; i < file_paths_length; i++){
      offset += this->file_paths[i].serialize(outbuffer + offset);
      }
      *(outbuffer + offset + 0) = (this->inliers_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->inliers_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->inliers_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->inliers_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->inliers_length);
      for( uint32_t i = 0; i < inliers_length; i++){
      offset += this->inliers[i].serialize(outbuffer + offset);
      }
      *(outbuffer + offset + 0) = (this->outliers_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->outliers_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->outliers_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->outliers_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->outliers_length);
      for( uint32_t i = 0; i < outliers_length; i++){
      offset += this->outliers[i].serialize(outbuffer + offset);
      }
      *(outbuffer + offset + 0) = (this->homographies_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->homographies_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->homographies_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->homographies_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->homographies_length);
      for( uint32_t i = 0; i < homographies_length; i++){
      offset += this->homographies[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      uint32_t ids_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      ids_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      ids_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      ids_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->ids_length);
      if(ids_lengthT > ids_length)
        this->ids = (std_msgs::Int32*)realloc(this->ids, ids_lengthT * sizeof(std_msgs::Int32));
      ids_length = ids_lengthT;
      for( uint32_t i = 0; i < ids_length; i++){
      offset += this->st_ids.deserialize(inbuffer + offset);
        memcpy( &(this->ids[i]), &(this->st_ids), sizeof(std_msgs::Int32));
      }
      uint32_t widths_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      widths_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      widths_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      widths_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->widths_length);
      if(widths_lengthT > widths_length)
        this->widths = (std_msgs::Int32*)realloc(this->widths, widths_lengthT * sizeof(std_msgs::Int32));
      widths_length = widths_lengthT;
      for( uint32_t i = 0; i < widths_length; i++){
      offset += this->st_widths.deserialize(inbuffer + offset);
        memcpy( &(this->widths[i]), &(this->st_widths), sizeof(std_msgs::Int32));
      }
      uint32_t heights_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      heights_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      heights_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      heights_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->heights_length);
      if(heights_lengthT > heights_length)
        this->heights = (std_msgs::Int32*)realloc(this->heights, heights_lengthT * sizeof(std_msgs::Int32));
      heights_length = heights_lengthT;
      for( uint32_t i = 0; i < heights_length; i++){
      offset += this->st_heights.deserialize(inbuffer + offset);
        memcpy( &(this->heights[i]), &(this->st_heights), sizeof(std_msgs::Int32));
      }
      uint32_t file_paths_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      file_paths_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      file_paths_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      file_paths_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->file_paths_length);
      if(file_paths_lengthT > file_paths_length)
        this->file_paths = (std_msgs::String*)realloc(this->file_paths, file_paths_lengthT * sizeof(std_msgs::String));
      file_paths_length = file_paths_lengthT;
      for( uint32_t i = 0; i < file_paths_length; i++){
      offset += this->st_file_paths.deserialize(inbuffer + offset);
        memcpy( &(this->file_paths[i]), &(this->st_file_paths), sizeof(std_msgs::String));
      }
      uint32_t inliers_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      inliers_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      inliers_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      inliers_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->inliers_length);
      if(inliers_lengthT > inliers_length)
        this->inliers = (std_msgs::Int32*)realloc(this->inliers, inliers_lengthT * sizeof(std_msgs::Int32));
      inliers_length = inliers_lengthT;
      for( uint32_t i = 0; i < inliers_length; i++){
      offset += this->st_inliers.deserialize(inbuffer + offset);
        memcpy( &(this->inliers[i]), &(this->st_inliers), sizeof(std_msgs::Int32));
      }
      uint32_t outliers_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      outliers_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      outliers_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      outliers_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->outliers_length);
      if(outliers_lengthT > outliers_length)
        this->outliers = (std_msgs::Int32*)realloc(this->outliers, outliers_lengthT * sizeof(std_msgs::Int32));
      outliers_length = outliers_lengthT;
      for( uint32_t i = 0; i < outliers_length; i++){
      offset += this->st_outliers.deserialize(inbuffer + offset);
        memcpy( &(this->outliers[i]), &(this->st_outliers), sizeof(std_msgs::Int32));
      }
      uint32_t homographies_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      homographies_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      homographies_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      homographies_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->homographies_length);
      if(homographies_lengthT > homographies_length)
        this->homographies = (std_msgs::Float32MultiArray*)realloc(this->homographies, homographies_lengthT * sizeof(std_msgs::Float32MultiArray));
      homographies_length = homographies_lengthT;
      for( uint32_t i = 0; i < homographies_length; i++){
      offset += this->st_homographies.deserialize(inbuffer + offset);
        memcpy( &(this->homographies[i]), &(this->st_homographies), sizeof(std_msgs::Float32MultiArray));
      }
     return offset;
    }

    virtual const char * getType() override { return "find_object_2d/DetectionInfo"; };
    virtual const char * getMD5() override { return "b640b611f324585835ba0cb953c35aa3"; };

  };

}
#endif

#ifndef _ROS_rtabmap_msgs_LandmarkDetections_h
#define _ROS_rtabmap_msgs_LandmarkDetections_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "rtabmap_msgs/LandmarkDetection.h"

namespace rtabmap_msgs
{

  class LandmarkDetections : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      uint32_t landmarks_length;
      typedef rtabmap_msgs::LandmarkDetection _landmarks_type;
      _landmarks_type st_landmarks;
      _landmarks_type * landmarks;

    LandmarkDetections():
      header(),
      landmarks_length(0), st_landmarks(), landmarks(nullptr)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->landmarks_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->landmarks_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->landmarks_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->landmarks_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->landmarks_length);
      for( uint32_t i = 0; i < landmarks_length; i++){
      offset += this->landmarks[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      uint32_t landmarks_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      landmarks_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      landmarks_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      landmarks_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->landmarks_length);
      if(landmarks_lengthT > landmarks_length)
        this->landmarks = (rtabmap_msgs::LandmarkDetection*)realloc(this->landmarks, landmarks_lengthT * sizeof(rtabmap_msgs::LandmarkDetection));
      landmarks_length = landmarks_lengthT;
      for( uint32_t i = 0; i < landmarks_length; i++){
      offset += this->st_landmarks.deserialize(inbuffer + offset);
        memcpy( &(this->landmarks[i]), &(this->st_landmarks), sizeof(rtabmap_msgs::LandmarkDetection));
      }
     return offset;
    }

    virtual const char * getType() override { return "rtabmap_msgs/LandmarkDetections"; };
    virtual const char * getMD5() override { return "6dd251c7971c681b62f6a4fbf33ff4ab"; };

  };

}
#endif

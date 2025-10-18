#ifndef _ROS_SERVICE_DetectMoreLoopClosures_h
#define _ROS_SERVICE_DetectMoreLoopClosures_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace rtabmap_msgs
{

static const char DETECTMORELOOPCLOSURES[] = "rtabmap_msgs/DetectMoreLoopClosures";

  class DetectMoreLoopClosuresRequest : public ros::Msg
  {
    public:
      typedef float _cluster_radius_max_type;
      _cluster_radius_max_type cluster_radius_max;
      typedef float _cluster_radius_min_type;
      _cluster_radius_min_type cluster_radius_min;
      typedef float _cluster_angle_type;
      _cluster_angle_type cluster_angle;
      typedef int32_t _iterations_type;
      _iterations_type iterations;
      typedef bool _intra_only_type;
      _intra_only_type intra_only;
      typedef bool _inter_only_type;
      _inter_only_type inter_only;

    DetectMoreLoopClosuresRequest():
      cluster_radius_max(0),
      cluster_radius_min(0),
      cluster_angle(0),
      iterations(0),
      intra_only(0),
      inter_only(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      union {
        float real;
        uint32_t base;
      } u_cluster_radius_max;
      u_cluster_radius_max.real = this->cluster_radius_max;
      *(outbuffer + offset + 0) = (u_cluster_radius_max.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_cluster_radius_max.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_cluster_radius_max.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_cluster_radius_max.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->cluster_radius_max);
      union {
        float real;
        uint32_t base;
      } u_cluster_radius_min;
      u_cluster_radius_min.real = this->cluster_radius_min;
      *(outbuffer + offset + 0) = (u_cluster_radius_min.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_cluster_radius_min.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_cluster_radius_min.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_cluster_radius_min.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->cluster_radius_min);
      union {
        float real;
        uint32_t base;
      } u_cluster_angle;
      u_cluster_angle.real = this->cluster_angle;
      *(outbuffer + offset + 0) = (u_cluster_angle.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_cluster_angle.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_cluster_angle.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_cluster_angle.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->cluster_angle);
      union {
        int32_t real;
        uint32_t base;
      } u_iterations;
      u_iterations.real = this->iterations;
      *(outbuffer + offset + 0) = (u_iterations.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_iterations.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_iterations.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_iterations.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->iterations);
      union {
        bool real;
        uint8_t base;
      } u_intra_only;
      u_intra_only.real = this->intra_only;
      *(outbuffer + offset + 0) = (u_intra_only.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->intra_only);
      union {
        bool real;
        uint8_t base;
      } u_inter_only;
      u_inter_only.real = this->inter_only;
      *(outbuffer + offset + 0) = (u_inter_only.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->inter_only);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      union {
        float real;
        uint32_t base;
      } u_cluster_radius_max;
      u_cluster_radius_max.base = 0;
      u_cluster_radius_max.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_cluster_radius_max.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_cluster_radius_max.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_cluster_radius_max.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->cluster_radius_max = u_cluster_radius_max.real;
      offset += sizeof(this->cluster_radius_max);
      union {
        float real;
        uint32_t base;
      } u_cluster_radius_min;
      u_cluster_radius_min.base = 0;
      u_cluster_radius_min.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_cluster_radius_min.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_cluster_radius_min.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_cluster_radius_min.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->cluster_radius_min = u_cluster_radius_min.real;
      offset += sizeof(this->cluster_radius_min);
      union {
        float real;
        uint32_t base;
      } u_cluster_angle;
      u_cluster_angle.base = 0;
      u_cluster_angle.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_cluster_angle.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_cluster_angle.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_cluster_angle.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->cluster_angle = u_cluster_angle.real;
      offset += sizeof(this->cluster_angle);
      union {
        int32_t real;
        uint32_t base;
      } u_iterations;
      u_iterations.base = 0;
      u_iterations.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_iterations.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_iterations.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_iterations.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->iterations = u_iterations.real;
      offset += sizeof(this->iterations);
      union {
        bool real;
        uint8_t base;
      } u_intra_only;
      u_intra_only.base = 0;
      u_intra_only.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->intra_only = u_intra_only.real;
      offset += sizeof(this->intra_only);
      union {
        bool real;
        uint8_t base;
      } u_inter_only;
      u_inter_only.base = 0;
      u_inter_only.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->inter_only = u_inter_only.real;
      offset += sizeof(this->inter_only);
     return offset;
    }

    virtual const char * getType() override { return DETECTMORELOOPCLOSURES; };
    virtual const char * getMD5() override { return "df5cfe58cb7487b0d93ed1614efab4a3"; };

  };

  class DetectMoreLoopClosuresResponse : public ros::Msg
  {
    public:
      typedef int32_t _detected_type;
      _detected_type detected;

    DetectMoreLoopClosuresResponse():
      detected(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      union {
        int32_t real;
        uint32_t base;
      } u_detected;
      u_detected.real = this->detected;
      *(outbuffer + offset + 0) = (u_detected.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_detected.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_detected.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_detected.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->detected);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      union {
        int32_t real;
        uint32_t base;
      } u_detected;
      u_detected.base = 0;
      u_detected.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_detected.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_detected.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_detected.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->detected = u_detected.real;
      offset += sizeof(this->detected);
     return offset;
    }

    virtual const char * getType() override { return DETECTMORELOOPCLOSURES; };
    virtual const char * getMD5() override { return "b915f91311c8f5d6b235ceb818d53f80"; };

  };

  class DetectMoreLoopClosures {
    public:
    typedef DetectMoreLoopClosuresRequest Request;
    typedef DetectMoreLoopClosuresResponse Response;
  };

}
#endif

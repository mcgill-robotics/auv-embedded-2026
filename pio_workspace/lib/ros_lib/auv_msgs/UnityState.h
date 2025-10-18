#ifndef _ROS_auv_msgs_UnityState_h
#define _ROS_auv_msgs_UnityState_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "geometry_msgs/Vector3.h"
#include "geometry_msgs/Quaternion.h"

namespace auv_msgs
{

  class UnityState : public ros::Msg
  {
    public:
      typedef geometry_msgs::Vector3 _position_type;
      _position_type position;
      typedef geometry_msgs::Quaternion _orientation_type;
      _orientation_type orientation;
      typedef geometry_msgs::Vector3 _velocity_type;
      _velocity_type velocity;
      typedef geometry_msgs::Vector3 _angular_velocity_type;
      _angular_velocity_type angular_velocity;
      typedef geometry_msgs::Vector3 _linear_acceleration_type;
      _linear_acceleration_type linear_acceleration;
      uint32_t frequencies_length;
      typedef int32_t _frequencies_type;
      _frequencies_type st_frequencies;
      _frequencies_type * frequencies;
      uint32_t hydrophone_one_freqs_length;
      typedef uint32_t _hydrophone_one_freqs_type;
      _hydrophone_one_freqs_type st_hydrophone_one_freqs;
      _hydrophone_one_freqs_type * hydrophone_one_freqs;
      uint32_t hydrophone_two_freqs_length;
      typedef uint32_t _hydrophone_two_freqs_type;
      _hydrophone_two_freqs_type st_hydrophone_two_freqs;
      _hydrophone_two_freqs_type * hydrophone_two_freqs;
      uint32_t hydrophone_three_freqs_length;
      typedef uint32_t _hydrophone_three_freqs_type;
      _hydrophone_three_freqs_type st_hydrophone_three_freqs;
      _hydrophone_three_freqs_type * hydrophone_three_freqs;
      uint32_t hydrophone_four_freqs_length;
      typedef uint32_t _hydrophone_four_freqs_type;
      _hydrophone_four_freqs_type st_hydrophone_four_freqs;
      _hydrophone_four_freqs_type * hydrophone_four_freqs;
      typedef int32_t _isDVLActive_type;
      _isDVLActive_type isDVLActive;
      typedef int32_t _isDepthSensorActive_type;
      _isDepthSensorActive_type isDepthSensorActive;
      typedef int32_t _isIMUActive_type;
      _isIMUActive_type isIMUActive;
      typedef int32_t _isHydrophonesActive_type;
      _isHydrophonesActive_type isHydrophonesActive;

    UnityState():
      position(),
      orientation(),
      velocity(),
      angular_velocity(),
      linear_acceleration(),
      frequencies_length(0), st_frequencies(), frequencies(nullptr),
      hydrophone_one_freqs_length(0), st_hydrophone_one_freqs(), hydrophone_one_freqs(nullptr),
      hydrophone_two_freqs_length(0), st_hydrophone_two_freqs(), hydrophone_two_freqs(nullptr),
      hydrophone_three_freqs_length(0), st_hydrophone_three_freqs(), hydrophone_three_freqs(nullptr),
      hydrophone_four_freqs_length(0), st_hydrophone_four_freqs(), hydrophone_four_freqs(nullptr),
      isDVLActive(0),
      isDepthSensorActive(0),
      isIMUActive(0),
      isHydrophonesActive(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->position.serialize(outbuffer + offset);
      offset += this->orientation.serialize(outbuffer + offset);
      offset += this->velocity.serialize(outbuffer + offset);
      offset += this->angular_velocity.serialize(outbuffer + offset);
      offset += this->linear_acceleration.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->frequencies_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->frequencies_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->frequencies_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->frequencies_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->frequencies_length);
      for( uint32_t i = 0; i < frequencies_length; i++){
      union {
        int32_t real;
        uint32_t base;
      } u_frequenciesi;
      u_frequenciesi.real = this->frequencies[i];
      *(outbuffer + offset + 0) = (u_frequenciesi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_frequenciesi.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_frequenciesi.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_frequenciesi.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->frequencies[i]);
      }
      *(outbuffer + offset + 0) = (this->hydrophone_one_freqs_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->hydrophone_one_freqs_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->hydrophone_one_freqs_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->hydrophone_one_freqs_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->hydrophone_one_freqs_length);
      for( uint32_t i = 0; i < hydrophone_one_freqs_length; i++){
      *(outbuffer + offset + 0) = (this->hydrophone_one_freqs[i] >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->hydrophone_one_freqs[i] >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->hydrophone_one_freqs[i] >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->hydrophone_one_freqs[i] >> (8 * 3)) & 0xFF;
      offset += sizeof(this->hydrophone_one_freqs[i]);
      }
      *(outbuffer + offset + 0) = (this->hydrophone_two_freqs_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->hydrophone_two_freqs_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->hydrophone_two_freqs_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->hydrophone_two_freqs_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->hydrophone_two_freqs_length);
      for( uint32_t i = 0; i < hydrophone_two_freqs_length; i++){
      *(outbuffer + offset + 0) = (this->hydrophone_two_freqs[i] >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->hydrophone_two_freqs[i] >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->hydrophone_two_freqs[i] >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->hydrophone_two_freqs[i] >> (8 * 3)) & 0xFF;
      offset += sizeof(this->hydrophone_two_freqs[i]);
      }
      *(outbuffer + offset + 0) = (this->hydrophone_three_freqs_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->hydrophone_three_freqs_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->hydrophone_three_freqs_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->hydrophone_three_freqs_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->hydrophone_three_freqs_length);
      for( uint32_t i = 0; i < hydrophone_three_freqs_length; i++){
      *(outbuffer + offset + 0) = (this->hydrophone_three_freqs[i] >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->hydrophone_three_freqs[i] >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->hydrophone_three_freqs[i] >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->hydrophone_three_freqs[i] >> (8 * 3)) & 0xFF;
      offset += sizeof(this->hydrophone_three_freqs[i]);
      }
      *(outbuffer + offset + 0) = (this->hydrophone_four_freqs_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->hydrophone_four_freqs_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->hydrophone_four_freqs_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->hydrophone_four_freqs_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->hydrophone_four_freqs_length);
      for( uint32_t i = 0; i < hydrophone_four_freqs_length; i++){
      *(outbuffer + offset + 0) = (this->hydrophone_four_freqs[i] >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->hydrophone_four_freqs[i] >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->hydrophone_four_freqs[i] >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->hydrophone_four_freqs[i] >> (8 * 3)) & 0xFF;
      offset += sizeof(this->hydrophone_four_freqs[i]);
      }
      union {
        int32_t real;
        uint32_t base;
      } u_isDVLActive;
      u_isDVLActive.real = this->isDVLActive;
      *(outbuffer + offset + 0) = (u_isDVLActive.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_isDVLActive.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_isDVLActive.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_isDVLActive.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->isDVLActive);
      union {
        int32_t real;
        uint32_t base;
      } u_isDepthSensorActive;
      u_isDepthSensorActive.real = this->isDepthSensorActive;
      *(outbuffer + offset + 0) = (u_isDepthSensorActive.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_isDepthSensorActive.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_isDepthSensorActive.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_isDepthSensorActive.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->isDepthSensorActive);
      union {
        int32_t real;
        uint32_t base;
      } u_isIMUActive;
      u_isIMUActive.real = this->isIMUActive;
      *(outbuffer + offset + 0) = (u_isIMUActive.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_isIMUActive.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_isIMUActive.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_isIMUActive.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->isIMUActive);
      union {
        int32_t real;
        uint32_t base;
      } u_isHydrophonesActive;
      u_isHydrophonesActive.real = this->isHydrophonesActive;
      *(outbuffer + offset + 0) = (u_isHydrophonesActive.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_isHydrophonesActive.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_isHydrophonesActive.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_isHydrophonesActive.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->isHydrophonesActive);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->position.deserialize(inbuffer + offset);
      offset += this->orientation.deserialize(inbuffer + offset);
      offset += this->velocity.deserialize(inbuffer + offset);
      offset += this->angular_velocity.deserialize(inbuffer + offset);
      offset += this->linear_acceleration.deserialize(inbuffer + offset);
      uint32_t frequencies_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      frequencies_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      frequencies_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      frequencies_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->frequencies_length);
      if(frequencies_lengthT > frequencies_length)
        this->frequencies = (int32_t*)realloc(this->frequencies, frequencies_lengthT * sizeof(int32_t));
      frequencies_length = frequencies_lengthT;
      for( uint32_t i = 0; i < frequencies_length; i++){
      union {
        int32_t real;
        uint32_t base;
      } u_st_frequencies;
      u_st_frequencies.base = 0;
      u_st_frequencies.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_frequencies.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_st_frequencies.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_st_frequencies.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->st_frequencies = u_st_frequencies.real;
      offset += sizeof(this->st_frequencies);
        memcpy( &(this->frequencies[i]), &(this->st_frequencies), sizeof(int32_t));
      }
      uint32_t hydrophone_one_freqs_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      hydrophone_one_freqs_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      hydrophone_one_freqs_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      hydrophone_one_freqs_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->hydrophone_one_freqs_length);
      if(hydrophone_one_freqs_lengthT > hydrophone_one_freqs_length)
        this->hydrophone_one_freqs = (uint32_t*)realloc(this->hydrophone_one_freqs, hydrophone_one_freqs_lengthT * sizeof(uint32_t));
      hydrophone_one_freqs_length = hydrophone_one_freqs_lengthT;
      for( uint32_t i = 0; i < hydrophone_one_freqs_length; i++){
      this->st_hydrophone_one_freqs =  ((uint32_t) (*(inbuffer + offset)));
      this->st_hydrophone_one_freqs |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->st_hydrophone_one_freqs |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->st_hydrophone_one_freqs |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->st_hydrophone_one_freqs);
        memcpy( &(this->hydrophone_one_freqs[i]), &(this->st_hydrophone_one_freqs), sizeof(uint32_t));
      }
      uint32_t hydrophone_two_freqs_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      hydrophone_two_freqs_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      hydrophone_two_freqs_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      hydrophone_two_freqs_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->hydrophone_two_freqs_length);
      if(hydrophone_two_freqs_lengthT > hydrophone_two_freqs_length)
        this->hydrophone_two_freqs = (uint32_t*)realloc(this->hydrophone_two_freqs, hydrophone_two_freqs_lengthT * sizeof(uint32_t));
      hydrophone_two_freqs_length = hydrophone_two_freqs_lengthT;
      for( uint32_t i = 0; i < hydrophone_two_freqs_length; i++){
      this->st_hydrophone_two_freqs =  ((uint32_t) (*(inbuffer + offset)));
      this->st_hydrophone_two_freqs |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->st_hydrophone_two_freqs |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->st_hydrophone_two_freqs |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->st_hydrophone_two_freqs);
        memcpy( &(this->hydrophone_two_freqs[i]), &(this->st_hydrophone_two_freqs), sizeof(uint32_t));
      }
      uint32_t hydrophone_three_freqs_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      hydrophone_three_freqs_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      hydrophone_three_freqs_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      hydrophone_three_freqs_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->hydrophone_three_freqs_length);
      if(hydrophone_three_freqs_lengthT > hydrophone_three_freqs_length)
        this->hydrophone_three_freqs = (uint32_t*)realloc(this->hydrophone_three_freqs, hydrophone_three_freqs_lengthT * sizeof(uint32_t));
      hydrophone_three_freqs_length = hydrophone_three_freqs_lengthT;
      for( uint32_t i = 0; i < hydrophone_three_freqs_length; i++){
      this->st_hydrophone_three_freqs =  ((uint32_t) (*(inbuffer + offset)));
      this->st_hydrophone_three_freqs |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->st_hydrophone_three_freqs |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->st_hydrophone_three_freqs |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->st_hydrophone_three_freqs);
        memcpy( &(this->hydrophone_three_freqs[i]), &(this->st_hydrophone_three_freqs), sizeof(uint32_t));
      }
      uint32_t hydrophone_four_freqs_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      hydrophone_four_freqs_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      hydrophone_four_freqs_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      hydrophone_four_freqs_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->hydrophone_four_freqs_length);
      if(hydrophone_four_freqs_lengthT > hydrophone_four_freqs_length)
        this->hydrophone_four_freqs = (uint32_t*)realloc(this->hydrophone_four_freqs, hydrophone_four_freqs_lengthT * sizeof(uint32_t));
      hydrophone_four_freqs_length = hydrophone_four_freqs_lengthT;
      for( uint32_t i = 0; i < hydrophone_four_freqs_length; i++){
      this->st_hydrophone_four_freqs =  ((uint32_t) (*(inbuffer + offset)));
      this->st_hydrophone_four_freqs |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->st_hydrophone_four_freqs |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->st_hydrophone_four_freqs |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->st_hydrophone_four_freqs);
        memcpy( &(this->hydrophone_four_freqs[i]), &(this->st_hydrophone_four_freqs), sizeof(uint32_t));
      }
      union {
        int32_t real;
        uint32_t base;
      } u_isDVLActive;
      u_isDVLActive.base = 0;
      u_isDVLActive.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_isDVLActive.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_isDVLActive.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_isDVLActive.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->isDVLActive = u_isDVLActive.real;
      offset += sizeof(this->isDVLActive);
      union {
        int32_t real;
        uint32_t base;
      } u_isDepthSensorActive;
      u_isDepthSensorActive.base = 0;
      u_isDepthSensorActive.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_isDepthSensorActive.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_isDepthSensorActive.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_isDepthSensorActive.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->isDepthSensorActive = u_isDepthSensorActive.real;
      offset += sizeof(this->isDepthSensorActive);
      union {
        int32_t real;
        uint32_t base;
      } u_isIMUActive;
      u_isIMUActive.base = 0;
      u_isIMUActive.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_isIMUActive.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_isIMUActive.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_isIMUActive.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->isIMUActive = u_isIMUActive.real;
      offset += sizeof(this->isIMUActive);
      union {
        int32_t real;
        uint32_t base;
      } u_isHydrophonesActive;
      u_isHydrophonesActive.base = 0;
      u_isHydrophonesActive.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_isHydrophonesActive.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_isHydrophonesActive.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_isHydrophonesActive.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->isHydrophonesActive = u_isHydrophonesActive.real;
      offset += sizeof(this->isHydrophonesActive);
     return offset;
    }

    virtual const char * getType() override { return "auv_msgs/UnityState"; };
    virtual const char * getMD5() override { return "deac3cf7620639c22bbe228fb39d2aa6"; };

  };

}
#endif

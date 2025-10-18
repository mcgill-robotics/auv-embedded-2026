#ifndef _ROS_zed_interfaces_Object_h
#define _ROS_zed_interfaces_Object_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "zed_interfaces/BoundingBox2Di.h"
#include "zed_interfaces/BoundingBox3D.h"
#include "zed_interfaces/BoundingBox2Df.h"
#include "zed_interfaces/Skeleton2D.h"
#include "zed_interfaces/Skeleton3D.h"

namespace zed_interfaces
{

  class Object : public ros::Msg
  {
    public:
      typedef const char* _label_type;
      _label_type label;
      typedef int16_t _label_id_type;
      _label_id_type label_id;
      typedef int16_t _instance_id_type;
      _instance_id_type instance_id;
      typedef const char* _sublabel_type;
      _sublabel_type sublabel;
      typedef float _confidence_type;
      _confidence_type confidence;
      float position[3];
      float position_covariance[6];
      float velocity[3];
      typedef bool _tracking_available_type;
      _tracking_available_type tracking_available;
      typedef int8_t _tracking_state_type;
      _tracking_state_type tracking_state;
      typedef int8_t _action_state_type;
      _action_state_type action_state;
      typedef zed_interfaces::BoundingBox2Di _bounding_box_2d_type;
      _bounding_box_2d_type bounding_box_2d;
      typedef zed_interfaces::BoundingBox3D _bounding_box_3d_type;
      _bounding_box_3d_type bounding_box_3d;
      float dimensions_3d[3];
      typedef bool _skeleton_available_type;
      _skeleton_available_type skeleton_available;
      typedef zed_interfaces::BoundingBox2Df _head_bounding_box_2d_type;
      _head_bounding_box_2d_type head_bounding_box_2d;
      typedef zed_interfaces::BoundingBox3D _head_bounding_box_3d_type;
      _head_bounding_box_3d_type head_bounding_box_3d;
      float head_position[3];
      typedef zed_interfaces::Skeleton2D _skeleton_2d_type;
      _skeleton_2d_type skeleton_2d;
      typedef zed_interfaces::Skeleton3D _skeleton_3d_type;
      _skeleton_3d_type skeleton_3d;

    Object():
      label(""),
      label_id(0),
      instance_id(0),
      sublabel(""),
      confidence(0),
      position(),
      position_covariance(),
      velocity(),
      tracking_available(0),
      tracking_state(0),
      action_state(0),
      bounding_box_2d(),
      bounding_box_3d(),
      dimensions_3d(),
      skeleton_available(0),
      head_bounding_box_2d(),
      head_bounding_box_3d(),
      head_position(),
      skeleton_2d(),
      skeleton_3d()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      uint32_t length_label = strlen(this->label);
      varToArr(outbuffer + offset, length_label);
      offset += 4;
      memcpy(outbuffer + offset, this->label, length_label);
      offset += length_label;
      union {
        int16_t real;
        uint16_t base;
      } u_label_id;
      u_label_id.real = this->label_id;
      *(outbuffer + offset + 0) = (u_label_id.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_label_id.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->label_id);
      union {
        int16_t real;
        uint16_t base;
      } u_instance_id;
      u_instance_id.real = this->instance_id;
      *(outbuffer + offset + 0) = (u_instance_id.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_instance_id.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->instance_id);
      uint32_t length_sublabel = strlen(this->sublabel);
      varToArr(outbuffer + offset, length_sublabel);
      offset += 4;
      memcpy(outbuffer + offset, this->sublabel, length_sublabel);
      offset += length_sublabel;
      union {
        float real;
        uint32_t base;
      } u_confidence;
      u_confidence.real = this->confidence;
      *(outbuffer + offset + 0) = (u_confidence.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_confidence.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_confidence.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_confidence.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->confidence);
      for( uint32_t i = 0; i < 3; i++){
      union {
        float real;
        uint32_t base;
      } u_positioni;
      u_positioni.real = this->position[i];
      *(outbuffer + offset + 0) = (u_positioni.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_positioni.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_positioni.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_positioni.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->position[i]);
      }
      for( uint32_t i = 0; i < 6; i++){
      union {
        float real;
        uint32_t base;
      } u_position_covariancei;
      u_position_covariancei.real = this->position_covariance[i];
      *(outbuffer + offset + 0) = (u_position_covariancei.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_position_covariancei.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_position_covariancei.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_position_covariancei.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->position_covariance[i]);
      }
      for( uint32_t i = 0; i < 3; i++){
      union {
        float real;
        uint32_t base;
      } u_velocityi;
      u_velocityi.real = this->velocity[i];
      *(outbuffer + offset + 0) = (u_velocityi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_velocityi.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_velocityi.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_velocityi.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->velocity[i]);
      }
      union {
        bool real;
        uint8_t base;
      } u_tracking_available;
      u_tracking_available.real = this->tracking_available;
      *(outbuffer + offset + 0) = (u_tracking_available.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->tracking_available);
      union {
        int8_t real;
        uint8_t base;
      } u_tracking_state;
      u_tracking_state.real = this->tracking_state;
      *(outbuffer + offset + 0) = (u_tracking_state.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->tracking_state);
      union {
        int8_t real;
        uint8_t base;
      } u_action_state;
      u_action_state.real = this->action_state;
      *(outbuffer + offset + 0) = (u_action_state.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->action_state);
      offset += this->bounding_box_2d.serialize(outbuffer + offset);
      offset += this->bounding_box_3d.serialize(outbuffer + offset);
      for( uint32_t i = 0; i < 3; i++){
      union {
        float real;
        uint32_t base;
      } u_dimensions_3di;
      u_dimensions_3di.real = this->dimensions_3d[i];
      *(outbuffer + offset + 0) = (u_dimensions_3di.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_dimensions_3di.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_dimensions_3di.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_dimensions_3di.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->dimensions_3d[i]);
      }
      union {
        bool real;
        uint8_t base;
      } u_skeleton_available;
      u_skeleton_available.real = this->skeleton_available;
      *(outbuffer + offset + 0) = (u_skeleton_available.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->skeleton_available);
      offset += this->head_bounding_box_2d.serialize(outbuffer + offset);
      offset += this->head_bounding_box_3d.serialize(outbuffer + offset);
      for( uint32_t i = 0; i < 3; i++){
      union {
        float real;
        uint32_t base;
      } u_head_positioni;
      u_head_positioni.real = this->head_position[i];
      *(outbuffer + offset + 0) = (u_head_positioni.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_head_positioni.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_head_positioni.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_head_positioni.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->head_position[i]);
      }
      offset += this->skeleton_2d.serialize(outbuffer + offset);
      offset += this->skeleton_3d.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      uint32_t length_label;
      arrToVar(length_label, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_label; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_label-1]=0;
      this->label = (char *)(inbuffer + offset-1);
      offset += length_label;
      union {
        int16_t real;
        uint16_t base;
      } u_label_id;
      u_label_id.base = 0;
      u_label_id.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_label_id.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->label_id = u_label_id.real;
      offset += sizeof(this->label_id);
      union {
        int16_t real;
        uint16_t base;
      } u_instance_id;
      u_instance_id.base = 0;
      u_instance_id.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_instance_id.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->instance_id = u_instance_id.real;
      offset += sizeof(this->instance_id);
      uint32_t length_sublabel;
      arrToVar(length_sublabel, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_sublabel; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_sublabel-1]=0;
      this->sublabel = (char *)(inbuffer + offset-1);
      offset += length_sublabel;
      union {
        float real;
        uint32_t base;
      } u_confidence;
      u_confidence.base = 0;
      u_confidence.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_confidence.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_confidence.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_confidence.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->confidence = u_confidence.real;
      offset += sizeof(this->confidence);
      for( uint32_t i = 0; i < 3; i++){
      union {
        float real;
        uint32_t base;
      } u_positioni;
      u_positioni.base = 0;
      u_positioni.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_positioni.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_positioni.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_positioni.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->position[i] = u_positioni.real;
      offset += sizeof(this->position[i]);
      }
      for( uint32_t i = 0; i < 6; i++){
      union {
        float real;
        uint32_t base;
      } u_position_covariancei;
      u_position_covariancei.base = 0;
      u_position_covariancei.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_position_covariancei.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_position_covariancei.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_position_covariancei.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->position_covariance[i] = u_position_covariancei.real;
      offset += sizeof(this->position_covariance[i]);
      }
      for( uint32_t i = 0; i < 3; i++){
      union {
        float real;
        uint32_t base;
      } u_velocityi;
      u_velocityi.base = 0;
      u_velocityi.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_velocityi.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_velocityi.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_velocityi.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->velocity[i] = u_velocityi.real;
      offset += sizeof(this->velocity[i]);
      }
      union {
        bool real;
        uint8_t base;
      } u_tracking_available;
      u_tracking_available.base = 0;
      u_tracking_available.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->tracking_available = u_tracking_available.real;
      offset += sizeof(this->tracking_available);
      union {
        int8_t real;
        uint8_t base;
      } u_tracking_state;
      u_tracking_state.base = 0;
      u_tracking_state.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->tracking_state = u_tracking_state.real;
      offset += sizeof(this->tracking_state);
      union {
        int8_t real;
        uint8_t base;
      } u_action_state;
      u_action_state.base = 0;
      u_action_state.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->action_state = u_action_state.real;
      offset += sizeof(this->action_state);
      offset += this->bounding_box_2d.deserialize(inbuffer + offset);
      offset += this->bounding_box_3d.deserialize(inbuffer + offset);
      for( uint32_t i = 0; i < 3; i++){
      union {
        float real;
        uint32_t base;
      } u_dimensions_3di;
      u_dimensions_3di.base = 0;
      u_dimensions_3di.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_dimensions_3di.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_dimensions_3di.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_dimensions_3di.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->dimensions_3d[i] = u_dimensions_3di.real;
      offset += sizeof(this->dimensions_3d[i]);
      }
      union {
        bool real;
        uint8_t base;
      } u_skeleton_available;
      u_skeleton_available.base = 0;
      u_skeleton_available.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->skeleton_available = u_skeleton_available.real;
      offset += sizeof(this->skeleton_available);
      offset += this->head_bounding_box_2d.deserialize(inbuffer + offset);
      offset += this->head_bounding_box_3d.deserialize(inbuffer + offset);
      for( uint32_t i = 0; i < 3; i++){
      union {
        float real;
        uint32_t base;
      } u_head_positioni;
      u_head_positioni.base = 0;
      u_head_positioni.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_head_positioni.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_head_positioni.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_head_positioni.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->head_position[i] = u_head_positioni.real;
      offset += sizeof(this->head_position[i]);
      }
      offset += this->skeleton_2d.deserialize(inbuffer + offset);
      offset += this->skeleton_3d.deserialize(inbuffer + offset);
     return offset;
    }

    virtual const char * getType() override { return "zed_interfaces/Object"; };
    virtual const char * getMD5() override { return "850ee8ff1282c46cfce0a7d14dd04611"; };

  };

}
#endif

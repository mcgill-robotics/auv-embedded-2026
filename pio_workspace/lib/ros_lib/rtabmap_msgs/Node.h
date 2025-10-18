#ifndef _ROS_rtabmap_msgs_Node_h
#define _ROS_rtabmap_msgs_Node_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "geometry_msgs/Pose.h"
#include "rtabmap_msgs/KeyPoint.h"
#include "rtabmap_msgs/Point3f.h"
#include "rtabmap_msgs/SensorData.h"

namespace rtabmap_msgs
{

  class Node : public ros::Msg
  {
    public:
      typedef int32_t _id_type;
      _id_type id;
      typedef int32_t _map_id_type;
      _map_id_type map_id;
      typedef int32_t _weight_type;
      _weight_type weight;
      typedef float _stamp_type;
      _stamp_type stamp;
      typedef const char* _label_type;
      _label_type label;
      typedef geometry_msgs::Pose _pose_type;
      _pose_type pose;
      uint32_t word_id_keys_length;
      typedef int32_t _word_id_keys_type;
      _word_id_keys_type st_word_id_keys;
      _word_id_keys_type * word_id_keys;
      uint32_t word_id_values_length;
      typedef int32_t _word_id_values_type;
      _word_id_values_type st_word_id_values;
      _word_id_values_type * word_id_values;
      uint32_t word_kpts_length;
      typedef rtabmap_msgs::KeyPoint _word_kpts_type;
      _word_kpts_type st_word_kpts;
      _word_kpts_type * word_kpts;
      uint32_t word_pts_length;
      typedef rtabmap_msgs::Point3f _word_pts_type;
      _word_pts_type st_word_pts;
      _word_pts_type * word_pts;
      uint32_t word_descriptors_length;
      typedef uint8_t _word_descriptors_type;
      _word_descriptors_type st_word_descriptors;
      _word_descriptors_type * word_descriptors;
      typedef rtabmap_msgs::SensorData _data_type;
      _data_type data;

    Node():
      id(0),
      map_id(0),
      weight(0),
      stamp(0),
      label(""),
      pose(),
      word_id_keys_length(0), st_word_id_keys(), word_id_keys(nullptr),
      word_id_values_length(0), st_word_id_values(), word_id_values(nullptr),
      word_kpts_length(0), st_word_kpts(), word_kpts(nullptr),
      word_pts_length(0), st_word_pts(), word_pts(nullptr),
      word_descriptors_length(0), st_word_descriptors(), word_descriptors(nullptr),
      data()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      union {
        int32_t real;
        uint32_t base;
      } u_id;
      u_id.real = this->id;
      *(outbuffer + offset + 0) = (u_id.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_id.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_id.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_id.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->id);
      union {
        int32_t real;
        uint32_t base;
      } u_map_id;
      u_map_id.real = this->map_id;
      *(outbuffer + offset + 0) = (u_map_id.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_map_id.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_map_id.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_map_id.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->map_id);
      union {
        int32_t real;
        uint32_t base;
      } u_weight;
      u_weight.real = this->weight;
      *(outbuffer + offset + 0) = (u_weight.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_weight.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_weight.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_weight.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->weight);
      offset += serializeAvrFloat64(outbuffer + offset, this->stamp);
      uint32_t length_label = strlen(this->label);
      varToArr(outbuffer + offset, length_label);
      offset += 4;
      memcpy(outbuffer + offset, this->label, length_label);
      offset += length_label;
      offset += this->pose.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->word_id_keys_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->word_id_keys_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->word_id_keys_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->word_id_keys_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->word_id_keys_length);
      for( uint32_t i = 0; i < word_id_keys_length; i++){
      union {
        int32_t real;
        uint32_t base;
      } u_word_id_keysi;
      u_word_id_keysi.real = this->word_id_keys[i];
      *(outbuffer + offset + 0) = (u_word_id_keysi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_word_id_keysi.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_word_id_keysi.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_word_id_keysi.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->word_id_keys[i]);
      }
      *(outbuffer + offset + 0) = (this->word_id_values_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->word_id_values_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->word_id_values_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->word_id_values_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->word_id_values_length);
      for( uint32_t i = 0; i < word_id_values_length; i++){
      union {
        int32_t real;
        uint32_t base;
      } u_word_id_valuesi;
      u_word_id_valuesi.real = this->word_id_values[i];
      *(outbuffer + offset + 0) = (u_word_id_valuesi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_word_id_valuesi.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_word_id_valuesi.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_word_id_valuesi.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->word_id_values[i]);
      }
      *(outbuffer + offset + 0) = (this->word_kpts_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->word_kpts_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->word_kpts_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->word_kpts_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->word_kpts_length);
      for( uint32_t i = 0; i < word_kpts_length; i++){
      offset += this->word_kpts[i].serialize(outbuffer + offset);
      }
      *(outbuffer + offset + 0) = (this->word_pts_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->word_pts_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->word_pts_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->word_pts_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->word_pts_length);
      for( uint32_t i = 0; i < word_pts_length; i++){
      offset += this->word_pts[i].serialize(outbuffer + offset);
      }
      *(outbuffer + offset + 0) = (this->word_descriptors_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->word_descriptors_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->word_descriptors_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->word_descriptors_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->word_descriptors_length);
      for( uint32_t i = 0; i < word_descriptors_length; i++){
      *(outbuffer + offset + 0) = (this->word_descriptors[i] >> (8 * 0)) & 0xFF;
      offset += sizeof(this->word_descriptors[i]);
      }
      offset += this->data.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      union {
        int32_t real;
        uint32_t base;
      } u_id;
      u_id.base = 0;
      u_id.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_id.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_id.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_id.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->id = u_id.real;
      offset += sizeof(this->id);
      union {
        int32_t real;
        uint32_t base;
      } u_map_id;
      u_map_id.base = 0;
      u_map_id.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_map_id.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_map_id.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_map_id.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->map_id = u_map_id.real;
      offset += sizeof(this->map_id);
      union {
        int32_t real;
        uint32_t base;
      } u_weight;
      u_weight.base = 0;
      u_weight.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_weight.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_weight.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_weight.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->weight = u_weight.real;
      offset += sizeof(this->weight);
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->stamp));
      uint32_t length_label;
      arrToVar(length_label, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_label; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_label-1]=0;
      this->label = (char *)(inbuffer + offset-1);
      offset += length_label;
      offset += this->pose.deserialize(inbuffer + offset);
      uint32_t word_id_keys_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      word_id_keys_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      word_id_keys_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      word_id_keys_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->word_id_keys_length);
      if(word_id_keys_lengthT > word_id_keys_length)
        this->word_id_keys = (int32_t*)realloc(this->word_id_keys, word_id_keys_lengthT * sizeof(int32_t));
      word_id_keys_length = word_id_keys_lengthT;
      for( uint32_t i = 0; i < word_id_keys_length; i++){
      union {
        int32_t real;
        uint32_t base;
      } u_st_word_id_keys;
      u_st_word_id_keys.base = 0;
      u_st_word_id_keys.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_word_id_keys.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_st_word_id_keys.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_st_word_id_keys.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->st_word_id_keys = u_st_word_id_keys.real;
      offset += sizeof(this->st_word_id_keys);
        memcpy( &(this->word_id_keys[i]), &(this->st_word_id_keys), sizeof(int32_t));
      }
      uint32_t word_id_values_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      word_id_values_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      word_id_values_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      word_id_values_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->word_id_values_length);
      if(word_id_values_lengthT > word_id_values_length)
        this->word_id_values = (int32_t*)realloc(this->word_id_values, word_id_values_lengthT * sizeof(int32_t));
      word_id_values_length = word_id_values_lengthT;
      for( uint32_t i = 0; i < word_id_values_length; i++){
      union {
        int32_t real;
        uint32_t base;
      } u_st_word_id_values;
      u_st_word_id_values.base = 0;
      u_st_word_id_values.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_word_id_values.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_st_word_id_values.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_st_word_id_values.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->st_word_id_values = u_st_word_id_values.real;
      offset += sizeof(this->st_word_id_values);
        memcpy( &(this->word_id_values[i]), &(this->st_word_id_values), sizeof(int32_t));
      }
      uint32_t word_kpts_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      word_kpts_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      word_kpts_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      word_kpts_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->word_kpts_length);
      if(word_kpts_lengthT > word_kpts_length)
        this->word_kpts = (rtabmap_msgs::KeyPoint*)realloc(this->word_kpts, word_kpts_lengthT * sizeof(rtabmap_msgs::KeyPoint));
      word_kpts_length = word_kpts_lengthT;
      for( uint32_t i = 0; i < word_kpts_length; i++){
      offset += this->st_word_kpts.deserialize(inbuffer + offset);
        memcpy( &(this->word_kpts[i]), &(this->st_word_kpts), sizeof(rtabmap_msgs::KeyPoint));
      }
      uint32_t word_pts_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      word_pts_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      word_pts_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      word_pts_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->word_pts_length);
      if(word_pts_lengthT > word_pts_length)
        this->word_pts = (rtabmap_msgs::Point3f*)realloc(this->word_pts, word_pts_lengthT * sizeof(rtabmap_msgs::Point3f));
      word_pts_length = word_pts_lengthT;
      for( uint32_t i = 0; i < word_pts_length; i++){
      offset += this->st_word_pts.deserialize(inbuffer + offset);
        memcpy( &(this->word_pts[i]), &(this->st_word_pts), sizeof(rtabmap_msgs::Point3f));
      }
      uint32_t word_descriptors_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      word_descriptors_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      word_descriptors_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      word_descriptors_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->word_descriptors_length);
      if(word_descriptors_lengthT > word_descriptors_length)
        this->word_descriptors = (uint8_t*)realloc(this->word_descriptors, word_descriptors_lengthT * sizeof(uint8_t));
      word_descriptors_length = word_descriptors_lengthT;
      for( uint32_t i = 0; i < word_descriptors_length; i++){
      this->st_word_descriptors =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->st_word_descriptors);
        memcpy( &(this->word_descriptors[i]), &(this->st_word_descriptors), sizeof(uint8_t));
      }
      offset += this->data.deserialize(inbuffer + offset);
     return offset;
    }

    virtual const char * getType() override { return "rtabmap_msgs/Node"; };
    virtual const char * getMD5() override { return "1e8d995f879dedebdf00969128c2dfa0"; };

  };

}
#endif

#ifndef _ROS_SERVICE_GetNodesInRadius_h
#define _ROS_SERVICE_GetNodesInRadius_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "geometry_msgs/Pose.h"

namespace rtabmap_msgs
{

static const char GETNODESINRADIUS[] = "rtabmap_msgs/GetNodesInRadius";

  class GetNodesInRadiusRequest : public ros::Msg
  {
    public:
      typedef int32_t _node_id_type;
      _node_id_type node_id;
      typedef float _x_type;
      _x_type x;
      typedef float _y_type;
      _y_type y;
      typedef float _z_type;
      _z_type z;
      typedef float _radius_type;
      _radius_type radius;
      typedef int32_t _k_type;
      _k_type k;

    GetNodesInRadiusRequest():
      node_id(0),
      x(0),
      y(0),
      z(0),
      radius(0),
      k(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      union {
        int32_t real;
        uint32_t base;
      } u_node_id;
      u_node_id.real = this->node_id;
      *(outbuffer + offset + 0) = (u_node_id.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_node_id.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_node_id.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_node_id.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->node_id);
      union {
        float real;
        uint32_t base;
      } u_x;
      u_x.real = this->x;
      *(outbuffer + offset + 0) = (u_x.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_x.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_x.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_x.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->x);
      union {
        float real;
        uint32_t base;
      } u_y;
      u_y.real = this->y;
      *(outbuffer + offset + 0) = (u_y.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_y.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_y.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_y.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->y);
      union {
        float real;
        uint32_t base;
      } u_z;
      u_z.real = this->z;
      *(outbuffer + offset + 0) = (u_z.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_z.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_z.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_z.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->z);
      union {
        float real;
        uint32_t base;
      } u_radius;
      u_radius.real = this->radius;
      *(outbuffer + offset + 0) = (u_radius.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_radius.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_radius.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_radius.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->radius);
      union {
        int32_t real;
        uint32_t base;
      } u_k;
      u_k.real = this->k;
      *(outbuffer + offset + 0) = (u_k.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_k.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_k.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_k.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->k);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      union {
        int32_t real;
        uint32_t base;
      } u_node_id;
      u_node_id.base = 0;
      u_node_id.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_node_id.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_node_id.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_node_id.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->node_id = u_node_id.real;
      offset += sizeof(this->node_id);
      union {
        float real;
        uint32_t base;
      } u_x;
      u_x.base = 0;
      u_x.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_x.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_x.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_x.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->x = u_x.real;
      offset += sizeof(this->x);
      union {
        float real;
        uint32_t base;
      } u_y;
      u_y.base = 0;
      u_y.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_y.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_y.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_y.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->y = u_y.real;
      offset += sizeof(this->y);
      union {
        float real;
        uint32_t base;
      } u_z;
      u_z.base = 0;
      u_z.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_z.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_z.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_z.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->z = u_z.real;
      offset += sizeof(this->z);
      union {
        float real;
        uint32_t base;
      } u_radius;
      u_radius.base = 0;
      u_radius.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_radius.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_radius.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_radius.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->radius = u_radius.real;
      offset += sizeof(this->radius);
      union {
        int32_t real;
        uint32_t base;
      } u_k;
      u_k.base = 0;
      u_k.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_k.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_k.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_k.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->k = u_k.real;
      offset += sizeof(this->k);
     return offset;
    }

    virtual const char * getType() override { return GETNODESINRADIUS; };
    virtual const char * getMD5() override { return "5e28a28a199cb5232f355c12c5a65418"; };

  };

  class GetNodesInRadiusResponse : public ros::Msg
  {
    public:
      uint32_t ids_length;
      typedef int32_t _ids_type;
      _ids_type st_ids;
      _ids_type * ids;
      uint32_t poses_length;
      typedef geometry_msgs::Pose _poses_type;
      _poses_type st_poses;
      _poses_type * poses;
      uint32_t distsSqr_length;
      typedef float _distsSqr_type;
      _distsSqr_type st_distsSqr;
      _distsSqr_type * distsSqr;

    GetNodesInRadiusResponse():
      ids_length(0), st_ids(), ids(nullptr),
      poses_length(0), st_poses(), poses(nullptr),
      distsSqr_length(0), st_distsSqr(), distsSqr(nullptr)
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
      *(outbuffer + offset + 0) = (this->poses_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->poses_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->poses_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->poses_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->poses_length);
      for( uint32_t i = 0; i < poses_length; i++){
      offset += this->poses[i].serialize(outbuffer + offset);
      }
      *(outbuffer + offset + 0) = (this->distsSqr_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->distsSqr_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->distsSqr_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->distsSqr_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->distsSqr_length);
      for( uint32_t i = 0; i < distsSqr_length; i++){
      union {
        float real;
        uint32_t base;
      } u_distsSqri;
      u_distsSqri.real = this->distsSqr[i];
      *(outbuffer + offset + 0) = (u_distsSqri.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_distsSqri.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_distsSqri.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_distsSqri.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->distsSqr[i]);
      }
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
      uint32_t poses_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      poses_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      poses_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      poses_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->poses_length);
      if(poses_lengthT > poses_length)
        this->poses = (geometry_msgs::Pose*)realloc(this->poses, poses_lengthT * sizeof(geometry_msgs::Pose));
      poses_length = poses_lengthT;
      for( uint32_t i = 0; i < poses_length; i++){
      offset += this->st_poses.deserialize(inbuffer + offset);
        memcpy( &(this->poses[i]), &(this->st_poses), sizeof(geometry_msgs::Pose));
      }
      uint32_t distsSqr_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      distsSqr_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      distsSqr_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      distsSqr_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->distsSqr_length);
      if(distsSqr_lengthT > distsSqr_length)
        this->distsSqr = (float*)realloc(this->distsSqr, distsSqr_lengthT * sizeof(float));
      distsSqr_length = distsSqr_lengthT;
      for( uint32_t i = 0; i < distsSqr_length; i++){
      union {
        float real;
        uint32_t base;
      } u_st_distsSqr;
      u_st_distsSqr.base = 0;
      u_st_distsSqr.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_distsSqr.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_st_distsSqr.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_st_distsSqr.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->st_distsSqr = u_st_distsSqr.real;
      offset += sizeof(this->st_distsSqr);
        memcpy( &(this->distsSqr[i]), &(this->st_distsSqr), sizeof(float));
      }
     return offset;
    }

    virtual const char * getType() override { return GETNODESINRADIUS; };
    virtual const char * getMD5() override { return "1b8b2d45b8ca77eac8d3c9b89916ddbf"; };

  };

  class GetNodesInRadius {
    public:
    typedef GetNodesInRadiusRequest Request;
    typedef GetNodesInRadiusResponse Response;
  };

}
#endif

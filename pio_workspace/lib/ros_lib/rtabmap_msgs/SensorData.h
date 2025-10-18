#ifndef _ROS_rtabmap_msgs_SensorData_h
#define _ROS_rtabmap_msgs_SensorData_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "sensor_msgs/Image.h"
#include "sensor_msgs/CameraInfo.h"
#include "geometry_msgs/Transform.h"
#include "sensor_msgs/PointCloud2.h"
#include "rtabmap_msgs/Point3f.h"
#include "rtabmap_msgs/KeyPoint.h"
#include "rtabmap_msgs/GlobalDescriptor.h"
#include "rtabmap_msgs/EnvSensor.h"
#include "sensor_msgs/Imu.h"
#include "rtabmap_msgs/LandmarkDetection.h"
#include "geometry_msgs/Pose.h"
#include "rtabmap_msgs/GPS.h"

namespace rtabmap_msgs
{

  class SensorData : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef sensor_msgs::Image _left_type;
      _left_type left;
      typedef sensor_msgs::Image _right_type;
      _right_type right;
      uint32_t left_compressed_length;
      typedef uint8_t _left_compressed_type;
      _left_compressed_type st_left_compressed;
      _left_compressed_type * left_compressed;
      uint32_t right_compressed_length;
      typedef uint8_t _right_compressed_type;
      _right_compressed_type st_right_compressed;
      _right_compressed_type * right_compressed;
      uint32_t left_camera_info_length;
      typedef sensor_msgs::CameraInfo _left_camera_info_type;
      _left_camera_info_type st_left_camera_info;
      _left_camera_info_type * left_camera_info;
      uint32_t right_camera_info_length;
      typedef sensor_msgs::CameraInfo _right_camera_info_type;
      _right_camera_info_type st_right_camera_info;
      _right_camera_info_type * right_camera_info;
      uint32_t local_transform_length;
      typedef geometry_msgs::Transform _local_transform_type;
      _local_transform_type st_local_transform;
      _local_transform_type * local_transform;
      typedef sensor_msgs::PointCloud2 _laser_scan_type;
      _laser_scan_type laser_scan;
      uint32_t laser_scan_compressed_length;
      typedef uint8_t _laser_scan_compressed_type;
      _laser_scan_compressed_type st_laser_scan_compressed;
      _laser_scan_compressed_type * laser_scan_compressed;
      typedef int32_t _laser_scan_max_pts_type;
      _laser_scan_max_pts_type laser_scan_max_pts;
      typedef float _laser_scan_max_range_type;
      _laser_scan_max_range_type laser_scan_max_range;
      typedef int32_t _laser_scan_format_type;
      _laser_scan_format_type laser_scan_format;
      typedef geometry_msgs::Transform _laser_scan_local_transform_type;
      _laser_scan_local_transform_type laser_scan_local_transform;
      uint32_t user_data_length;
      typedef uint8_t _user_data_type;
      _user_data_type st_user_data;
      _user_data_type * user_data;
      uint32_t grid_ground_length;
      typedef uint8_t _grid_ground_type;
      _grid_ground_type st_grid_ground;
      _grid_ground_type * grid_ground;
      uint32_t grid_obstacles_length;
      typedef uint8_t _grid_obstacles_type;
      _grid_obstacles_type st_grid_obstacles;
      _grid_obstacles_type * grid_obstacles;
      uint32_t grid_empty_cells_length;
      typedef uint8_t _grid_empty_cells_type;
      _grid_empty_cells_type st_grid_empty_cells;
      _grid_empty_cells_type * grid_empty_cells;
      typedef float _grid_cell_size_type;
      _grid_cell_size_type grid_cell_size;
      typedef rtabmap_msgs::Point3f _grid_view_point_type;
      _grid_view_point_type grid_view_point;
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
      uint32_t global_descriptors_length;
      typedef rtabmap_msgs::GlobalDescriptor _global_descriptors_type;
      _global_descriptors_type st_global_descriptors;
      _global_descriptors_type * global_descriptors;
      uint32_t env_sensors_length;
      typedef rtabmap_msgs::EnvSensor _env_sensors_type;
      _env_sensors_type st_env_sensors;
      _env_sensors_type * env_sensors;
      typedef sensor_msgs::Imu _imu_type;
      _imu_type imu;
      typedef geometry_msgs::Transform _imu_local_transform_type;
      _imu_local_transform_type imu_local_transform;
      uint32_t landmarks_length;
      typedef rtabmap_msgs::LandmarkDetection _landmarks_type;
      _landmarks_type st_landmarks;
      _landmarks_type * landmarks;
      typedef geometry_msgs::Pose _ground_truth_pose_type;
      _ground_truth_pose_type ground_truth_pose;
      typedef rtabmap_msgs::GPS _gps_type;
      _gps_type gps;

    SensorData():
      header(),
      left(),
      right(),
      left_compressed_length(0), st_left_compressed(), left_compressed(nullptr),
      right_compressed_length(0), st_right_compressed(), right_compressed(nullptr),
      left_camera_info_length(0), st_left_camera_info(), left_camera_info(nullptr),
      right_camera_info_length(0), st_right_camera_info(), right_camera_info(nullptr),
      local_transform_length(0), st_local_transform(), local_transform(nullptr),
      laser_scan(),
      laser_scan_compressed_length(0), st_laser_scan_compressed(), laser_scan_compressed(nullptr),
      laser_scan_max_pts(0),
      laser_scan_max_range(0),
      laser_scan_format(0),
      laser_scan_local_transform(),
      user_data_length(0), st_user_data(), user_data(nullptr),
      grid_ground_length(0), st_grid_ground(), grid_ground(nullptr),
      grid_obstacles_length(0), st_grid_obstacles(), grid_obstacles(nullptr),
      grid_empty_cells_length(0), st_grid_empty_cells(), grid_empty_cells(nullptr),
      grid_cell_size(0),
      grid_view_point(),
      key_points_length(0), st_key_points(), key_points(nullptr),
      points_length(0), st_points(), points(nullptr),
      descriptors_length(0), st_descriptors(), descriptors(nullptr),
      global_descriptors_length(0), st_global_descriptors(), global_descriptors(nullptr),
      env_sensors_length(0), st_env_sensors(), env_sensors(nullptr),
      imu(),
      imu_local_transform(),
      landmarks_length(0), st_landmarks(), landmarks(nullptr),
      ground_truth_pose(),
      gps()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      offset += this->left.serialize(outbuffer + offset);
      offset += this->right.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->left_compressed_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->left_compressed_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->left_compressed_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->left_compressed_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->left_compressed_length);
      for( uint32_t i = 0; i < left_compressed_length; i++){
      *(outbuffer + offset + 0) = (this->left_compressed[i] >> (8 * 0)) & 0xFF;
      offset += sizeof(this->left_compressed[i]);
      }
      *(outbuffer + offset + 0) = (this->right_compressed_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->right_compressed_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->right_compressed_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->right_compressed_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->right_compressed_length);
      for( uint32_t i = 0; i < right_compressed_length; i++){
      *(outbuffer + offset + 0) = (this->right_compressed[i] >> (8 * 0)) & 0xFF;
      offset += sizeof(this->right_compressed[i]);
      }
      *(outbuffer + offset + 0) = (this->left_camera_info_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->left_camera_info_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->left_camera_info_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->left_camera_info_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->left_camera_info_length);
      for( uint32_t i = 0; i < left_camera_info_length; i++){
      offset += this->left_camera_info[i].serialize(outbuffer + offset);
      }
      *(outbuffer + offset + 0) = (this->right_camera_info_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->right_camera_info_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->right_camera_info_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->right_camera_info_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->right_camera_info_length);
      for( uint32_t i = 0; i < right_camera_info_length; i++){
      offset += this->right_camera_info[i].serialize(outbuffer + offset);
      }
      *(outbuffer + offset + 0) = (this->local_transform_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->local_transform_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->local_transform_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->local_transform_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->local_transform_length);
      for( uint32_t i = 0; i < local_transform_length; i++){
      offset += this->local_transform[i].serialize(outbuffer + offset);
      }
      offset += this->laser_scan.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->laser_scan_compressed_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->laser_scan_compressed_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->laser_scan_compressed_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->laser_scan_compressed_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->laser_scan_compressed_length);
      for( uint32_t i = 0; i < laser_scan_compressed_length; i++){
      *(outbuffer + offset + 0) = (this->laser_scan_compressed[i] >> (8 * 0)) & 0xFF;
      offset += sizeof(this->laser_scan_compressed[i]);
      }
      union {
        int32_t real;
        uint32_t base;
      } u_laser_scan_max_pts;
      u_laser_scan_max_pts.real = this->laser_scan_max_pts;
      *(outbuffer + offset + 0) = (u_laser_scan_max_pts.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_laser_scan_max_pts.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_laser_scan_max_pts.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_laser_scan_max_pts.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->laser_scan_max_pts);
      union {
        float real;
        uint32_t base;
      } u_laser_scan_max_range;
      u_laser_scan_max_range.real = this->laser_scan_max_range;
      *(outbuffer + offset + 0) = (u_laser_scan_max_range.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_laser_scan_max_range.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_laser_scan_max_range.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_laser_scan_max_range.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->laser_scan_max_range);
      union {
        int32_t real;
        uint32_t base;
      } u_laser_scan_format;
      u_laser_scan_format.real = this->laser_scan_format;
      *(outbuffer + offset + 0) = (u_laser_scan_format.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_laser_scan_format.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_laser_scan_format.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_laser_scan_format.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->laser_scan_format);
      offset += this->laser_scan_local_transform.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->user_data_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->user_data_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->user_data_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->user_data_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->user_data_length);
      for( uint32_t i = 0; i < user_data_length; i++){
      *(outbuffer + offset + 0) = (this->user_data[i] >> (8 * 0)) & 0xFF;
      offset += sizeof(this->user_data[i]);
      }
      *(outbuffer + offset + 0) = (this->grid_ground_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->grid_ground_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->grid_ground_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->grid_ground_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->grid_ground_length);
      for( uint32_t i = 0; i < grid_ground_length; i++){
      *(outbuffer + offset + 0) = (this->grid_ground[i] >> (8 * 0)) & 0xFF;
      offset += sizeof(this->grid_ground[i]);
      }
      *(outbuffer + offset + 0) = (this->grid_obstacles_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->grid_obstacles_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->grid_obstacles_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->grid_obstacles_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->grid_obstacles_length);
      for( uint32_t i = 0; i < grid_obstacles_length; i++){
      *(outbuffer + offset + 0) = (this->grid_obstacles[i] >> (8 * 0)) & 0xFF;
      offset += sizeof(this->grid_obstacles[i]);
      }
      *(outbuffer + offset + 0) = (this->grid_empty_cells_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->grid_empty_cells_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->grid_empty_cells_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->grid_empty_cells_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->grid_empty_cells_length);
      for( uint32_t i = 0; i < grid_empty_cells_length; i++){
      *(outbuffer + offset + 0) = (this->grid_empty_cells[i] >> (8 * 0)) & 0xFF;
      offset += sizeof(this->grid_empty_cells[i]);
      }
      union {
        float real;
        uint32_t base;
      } u_grid_cell_size;
      u_grid_cell_size.real = this->grid_cell_size;
      *(outbuffer + offset + 0) = (u_grid_cell_size.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_grid_cell_size.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_grid_cell_size.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_grid_cell_size.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->grid_cell_size);
      offset += this->grid_view_point.serialize(outbuffer + offset);
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
      *(outbuffer + offset + 0) = (this->global_descriptors_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->global_descriptors_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->global_descriptors_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->global_descriptors_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->global_descriptors_length);
      for( uint32_t i = 0; i < global_descriptors_length; i++){
      offset += this->global_descriptors[i].serialize(outbuffer + offset);
      }
      *(outbuffer + offset + 0) = (this->env_sensors_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->env_sensors_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->env_sensors_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->env_sensors_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->env_sensors_length);
      for( uint32_t i = 0; i < env_sensors_length; i++){
      offset += this->env_sensors[i].serialize(outbuffer + offset);
      }
      offset += this->imu.serialize(outbuffer + offset);
      offset += this->imu_local_transform.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->landmarks_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->landmarks_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->landmarks_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->landmarks_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->landmarks_length);
      for( uint32_t i = 0; i < landmarks_length; i++){
      offset += this->landmarks[i].serialize(outbuffer + offset);
      }
      offset += this->ground_truth_pose.serialize(outbuffer + offset);
      offset += this->gps.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      offset += this->left.deserialize(inbuffer + offset);
      offset += this->right.deserialize(inbuffer + offset);
      uint32_t left_compressed_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      left_compressed_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      left_compressed_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      left_compressed_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->left_compressed_length);
      if(left_compressed_lengthT > left_compressed_length)
        this->left_compressed = (uint8_t*)realloc(this->left_compressed, left_compressed_lengthT * sizeof(uint8_t));
      left_compressed_length = left_compressed_lengthT;
      for( uint32_t i = 0; i < left_compressed_length; i++){
      this->st_left_compressed =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->st_left_compressed);
        memcpy( &(this->left_compressed[i]), &(this->st_left_compressed), sizeof(uint8_t));
      }
      uint32_t right_compressed_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      right_compressed_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      right_compressed_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      right_compressed_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->right_compressed_length);
      if(right_compressed_lengthT > right_compressed_length)
        this->right_compressed = (uint8_t*)realloc(this->right_compressed, right_compressed_lengthT * sizeof(uint8_t));
      right_compressed_length = right_compressed_lengthT;
      for( uint32_t i = 0; i < right_compressed_length; i++){
      this->st_right_compressed =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->st_right_compressed);
        memcpy( &(this->right_compressed[i]), &(this->st_right_compressed), sizeof(uint8_t));
      }
      uint32_t left_camera_info_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      left_camera_info_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      left_camera_info_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      left_camera_info_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->left_camera_info_length);
      if(left_camera_info_lengthT > left_camera_info_length)
        this->left_camera_info = (sensor_msgs::CameraInfo*)realloc(this->left_camera_info, left_camera_info_lengthT * sizeof(sensor_msgs::CameraInfo));
      left_camera_info_length = left_camera_info_lengthT;
      for( uint32_t i = 0; i < left_camera_info_length; i++){
      offset += this->st_left_camera_info.deserialize(inbuffer + offset);
        memcpy( &(this->left_camera_info[i]), &(this->st_left_camera_info), sizeof(sensor_msgs::CameraInfo));
      }
      uint32_t right_camera_info_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      right_camera_info_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      right_camera_info_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      right_camera_info_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->right_camera_info_length);
      if(right_camera_info_lengthT > right_camera_info_length)
        this->right_camera_info = (sensor_msgs::CameraInfo*)realloc(this->right_camera_info, right_camera_info_lengthT * sizeof(sensor_msgs::CameraInfo));
      right_camera_info_length = right_camera_info_lengthT;
      for( uint32_t i = 0; i < right_camera_info_length; i++){
      offset += this->st_right_camera_info.deserialize(inbuffer + offset);
        memcpy( &(this->right_camera_info[i]), &(this->st_right_camera_info), sizeof(sensor_msgs::CameraInfo));
      }
      uint32_t local_transform_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      local_transform_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      local_transform_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      local_transform_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->local_transform_length);
      if(local_transform_lengthT > local_transform_length)
        this->local_transform = (geometry_msgs::Transform*)realloc(this->local_transform, local_transform_lengthT * sizeof(geometry_msgs::Transform));
      local_transform_length = local_transform_lengthT;
      for( uint32_t i = 0; i < local_transform_length; i++){
      offset += this->st_local_transform.deserialize(inbuffer + offset);
        memcpy( &(this->local_transform[i]), &(this->st_local_transform), sizeof(geometry_msgs::Transform));
      }
      offset += this->laser_scan.deserialize(inbuffer + offset);
      uint32_t laser_scan_compressed_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      laser_scan_compressed_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      laser_scan_compressed_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      laser_scan_compressed_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->laser_scan_compressed_length);
      if(laser_scan_compressed_lengthT > laser_scan_compressed_length)
        this->laser_scan_compressed = (uint8_t*)realloc(this->laser_scan_compressed, laser_scan_compressed_lengthT * sizeof(uint8_t));
      laser_scan_compressed_length = laser_scan_compressed_lengthT;
      for( uint32_t i = 0; i < laser_scan_compressed_length; i++){
      this->st_laser_scan_compressed =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->st_laser_scan_compressed);
        memcpy( &(this->laser_scan_compressed[i]), &(this->st_laser_scan_compressed), sizeof(uint8_t));
      }
      union {
        int32_t real;
        uint32_t base;
      } u_laser_scan_max_pts;
      u_laser_scan_max_pts.base = 0;
      u_laser_scan_max_pts.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_laser_scan_max_pts.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_laser_scan_max_pts.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_laser_scan_max_pts.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->laser_scan_max_pts = u_laser_scan_max_pts.real;
      offset += sizeof(this->laser_scan_max_pts);
      union {
        float real;
        uint32_t base;
      } u_laser_scan_max_range;
      u_laser_scan_max_range.base = 0;
      u_laser_scan_max_range.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_laser_scan_max_range.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_laser_scan_max_range.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_laser_scan_max_range.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->laser_scan_max_range = u_laser_scan_max_range.real;
      offset += sizeof(this->laser_scan_max_range);
      union {
        int32_t real;
        uint32_t base;
      } u_laser_scan_format;
      u_laser_scan_format.base = 0;
      u_laser_scan_format.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_laser_scan_format.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_laser_scan_format.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_laser_scan_format.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->laser_scan_format = u_laser_scan_format.real;
      offset += sizeof(this->laser_scan_format);
      offset += this->laser_scan_local_transform.deserialize(inbuffer + offset);
      uint32_t user_data_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      user_data_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      user_data_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      user_data_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->user_data_length);
      if(user_data_lengthT > user_data_length)
        this->user_data = (uint8_t*)realloc(this->user_data, user_data_lengthT * sizeof(uint8_t));
      user_data_length = user_data_lengthT;
      for( uint32_t i = 0; i < user_data_length; i++){
      this->st_user_data =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->st_user_data);
        memcpy( &(this->user_data[i]), &(this->st_user_data), sizeof(uint8_t));
      }
      uint32_t grid_ground_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      grid_ground_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      grid_ground_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      grid_ground_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->grid_ground_length);
      if(grid_ground_lengthT > grid_ground_length)
        this->grid_ground = (uint8_t*)realloc(this->grid_ground, grid_ground_lengthT * sizeof(uint8_t));
      grid_ground_length = grid_ground_lengthT;
      for( uint32_t i = 0; i < grid_ground_length; i++){
      this->st_grid_ground =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->st_grid_ground);
        memcpy( &(this->grid_ground[i]), &(this->st_grid_ground), sizeof(uint8_t));
      }
      uint32_t grid_obstacles_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      grid_obstacles_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      grid_obstacles_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      grid_obstacles_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->grid_obstacles_length);
      if(grid_obstacles_lengthT > grid_obstacles_length)
        this->grid_obstacles = (uint8_t*)realloc(this->grid_obstacles, grid_obstacles_lengthT * sizeof(uint8_t));
      grid_obstacles_length = grid_obstacles_lengthT;
      for( uint32_t i = 0; i < grid_obstacles_length; i++){
      this->st_grid_obstacles =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->st_grid_obstacles);
        memcpy( &(this->grid_obstacles[i]), &(this->st_grid_obstacles), sizeof(uint8_t));
      }
      uint32_t grid_empty_cells_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      grid_empty_cells_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      grid_empty_cells_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      grid_empty_cells_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->grid_empty_cells_length);
      if(grid_empty_cells_lengthT > grid_empty_cells_length)
        this->grid_empty_cells = (uint8_t*)realloc(this->grid_empty_cells, grid_empty_cells_lengthT * sizeof(uint8_t));
      grid_empty_cells_length = grid_empty_cells_lengthT;
      for( uint32_t i = 0; i < grid_empty_cells_length; i++){
      this->st_grid_empty_cells =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->st_grid_empty_cells);
        memcpy( &(this->grid_empty_cells[i]), &(this->st_grid_empty_cells), sizeof(uint8_t));
      }
      union {
        float real;
        uint32_t base;
      } u_grid_cell_size;
      u_grid_cell_size.base = 0;
      u_grid_cell_size.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_grid_cell_size.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_grid_cell_size.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_grid_cell_size.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->grid_cell_size = u_grid_cell_size.real;
      offset += sizeof(this->grid_cell_size);
      offset += this->grid_view_point.deserialize(inbuffer + offset);
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
      uint32_t global_descriptors_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      global_descriptors_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      global_descriptors_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      global_descriptors_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->global_descriptors_length);
      if(global_descriptors_lengthT > global_descriptors_length)
        this->global_descriptors = (rtabmap_msgs::GlobalDescriptor*)realloc(this->global_descriptors, global_descriptors_lengthT * sizeof(rtabmap_msgs::GlobalDescriptor));
      global_descriptors_length = global_descriptors_lengthT;
      for( uint32_t i = 0; i < global_descriptors_length; i++){
      offset += this->st_global_descriptors.deserialize(inbuffer + offset);
        memcpy( &(this->global_descriptors[i]), &(this->st_global_descriptors), sizeof(rtabmap_msgs::GlobalDescriptor));
      }
      uint32_t env_sensors_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      env_sensors_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      env_sensors_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      env_sensors_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->env_sensors_length);
      if(env_sensors_lengthT > env_sensors_length)
        this->env_sensors = (rtabmap_msgs::EnvSensor*)realloc(this->env_sensors, env_sensors_lengthT * sizeof(rtabmap_msgs::EnvSensor));
      env_sensors_length = env_sensors_lengthT;
      for( uint32_t i = 0; i < env_sensors_length; i++){
      offset += this->st_env_sensors.deserialize(inbuffer + offset);
        memcpy( &(this->env_sensors[i]), &(this->st_env_sensors), sizeof(rtabmap_msgs::EnvSensor));
      }
      offset += this->imu.deserialize(inbuffer + offset);
      offset += this->imu_local_transform.deserialize(inbuffer + offset);
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
      offset += this->ground_truth_pose.deserialize(inbuffer + offset);
      offset += this->gps.deserialize(inbuffer + offset);
     return offset;
    }

    virtual const char * getType() override { return "rtabmap_msgs/SensorData"; };
    virtual const char * getMD5() override { return "1408cf03fa94547ee9b7bdda6d8918c2"; };

  };

}
#endif

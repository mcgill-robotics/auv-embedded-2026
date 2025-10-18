#ifndef _ROS_zed_interfaces_RGBDSensors_h
#define _ROS_zed_interfaces_RGBDSensors_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "sensor_msgs/CameraInfo.h"
#include "sensor_msgs/Image.h"
#include "sensor_msgs/Imu.h"
#include "sensor_msgs/MagneticField.h"

namespace zed_interfaces
{

  class RGBDSensors : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef sensor_msgs::CameraInfo _rgbCameraInfo_type;
      _rgbCameraInfo_type rgbCameraInfo;
      typedef sensor_msgs::CameraInfo _depthCameraInfo_type;
      _depthCameraInfo_type depthCameraInfo;
      typedef sensor_msgs::Image _rgb_type;
      _rgb_type rgb;
      typedef sensor_msgs::Image _depth_type;
      _depth_type depth;
      typedef sensor_msgs::Imu _imu_type;
      _imu_type imu;
      typedef sensor_msgs::MagneticField _mag_type;
      _mag_type mag;

    RGBDSensors():
      header(),
      rgbCameraInfo(),
      depthCameraInfo(),
      rgb(),
      depth(),
      imu(),
      mag()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      offset += this->rgbCameraInfo.serialize(outbuffer + offset);
      offset += this->depthCameraInfo.serialize(outbuffer + offset);
      offset += this->rgb.serialize(outbuffer + offset);
      offset += this->depth.serialize(outbuffer + offset);
      offset += this->imu.serialize(outbuffer + offset);
      offset += this->mag.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      offset += this->rgbCameraInfo.deserialize(inbuffer + offset);
      offset += this->depthCameraInfo.deserialize(inbuffer + offset);
      offset += this->rgb.deserialize(inbuffer + offset);
      offset += this->depth.deserialize(inbuffer + offset);
      offset += this->imu.deserialize(inbuffer + offset);
      offset += this->mag.deserialize(inbuffer + offset);
     return offset;
    }

    virtual const char * getType() override { return "zed_interfaces/RGBDSensors"; };
    virtual const char * getMD5() override { return "815807ecc415e89b119ed074d28d12dd"; };

  };

}
#endif

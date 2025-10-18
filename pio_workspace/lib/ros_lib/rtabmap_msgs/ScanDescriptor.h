#ifndef _ROS_rtabmap_msgs_ScanDescriptor_h
#define _ROS_rtabmap_msgs_ScanDescriptor_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "sensor_msgs/LaserScan.h"
#include "sensor_msgs/PointCloud2.h"
#include "rtabmap_msgs/GlobalDescriptor.h"

namespace rtabmap_msgs
{

  class ScanDescriptor : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef sensor_msgs::LaserScan _scan_type;
      _scan_type scan;
      typedef sensor_msgs::PointCloud2 _scan_cloud_type;
      _scan_cloud_type scan_cloud;
      typedef rtabmap_msgs::GlobalDescriptor _global_descriptor_type;
      _global_descriptor_type global_descriptor;

    ScanDescriptor():
      header(),
      scan(),
      scan_cloud(),
      global_descriptor()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      offset += this->scan.serialize(outbuffer + offset);
      offset += this->scan_cloud.serialize(outbuffer + offset);
      offset += this->global_descriptor.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      offset += this->scan.deserialize(inbuffer + offset);
      offset += this->scan_cloud.deserialize(inbuffer + offset);
      offset += this->global_descriptor.deserialize(inbuffer + offset);
     return offset;
    }

    virtual const char * getType() override { return "rtabmap_msgs/ScanDescriptor"; };
    virtual const char * getMD5() override { return "e76f45a9fe00fd5492368db8040ccbec"; };

  };

}
#endif

#ifndef _ROS_auv_msgs_ThrusterForces_h
#define _ROS_auv_msgs_ThrusterForces_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace auv_msgs
{

  class ThrusterForces : public ros::Msg
  {
    public:
      typedef float _front_left_type;
      _front_left_type front_left;
      typedef float _back_left_type;
      _back_left_type back_left;
      typedef float _heave_back_left_type;
      _heave_back_left_type heave_back_left;
      typedef float _heave_front_left_type;
      _heave_front_left_type heave_front_left;
      typedef float _front_right_type;
      _front_right_type front_right;
      typedef float _heave_front_right_type;
      _heave_front_right_type heave_front_right;
      typedef float _back_right_type;
      _back_right_type back_right;
      typedef float _heave_back_right_type;
      _heave_back_right_type heave_back_right;

    ThrusterForces():
      front_left(0),
      back_left(0),
      heave_back_left(0),
      heave_front_left(0),
      front_right(0),
      heave_front_right(0),
      back_right(0),
      heave_back_right(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += serializeAvrFloat64(outbuffer + offset, this->front_left);
      offset += serializeAvrFloat64(outbuffer + offset, this->back_left);
      offset += serializeAvrFloat64(outbuffer + offset, this->heave_back_left);
      offset += serializeAvrFloat64(outbuffer + offset, this->heave_front_left);
      offset += serializeAvrFloat64(outbuffer + offset, this->front_right);
      offset += serializeAvrFloat64(outbuffer + offset, this->heave_front_right);
      offset += serializeAvrFloat64(outbuffer + offset, this->back_right);
      offset += serializeAvrFloat64(outbuffer + offset, this->heave_back_right);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->front_left));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->back_left));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->heave_back_left));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->heave_front_left));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->front_right));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->heave_front_right));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->back_right));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->heave_back_right));
     return offset;
    }

    virtual const char * getType() override { return "auv_msgs/ThrusterForces"; };
    virtual const char * getMD5() override { return "87d1913726f1a30a5009c3771816b687"; };

  };

}
#endif

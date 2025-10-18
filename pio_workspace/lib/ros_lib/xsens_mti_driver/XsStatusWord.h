#ifndef _ROS_xsens_mti_driver_XsStatusWord_h
#define _ROS_xsens_mti_driver_XsStatusWord_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace xsens_mti_driver
{

  class XsStatusWord : public ros::Msg
  {
    public:
      typedef bool _selftest_type;
      _selftest_type selftest;
      typedef bool _filter_valid_type;
      _filter_valid_type filter_valid;
      typedef bool _gnss_fix_type;
      _gnss_fix_type gnss_fix;
      typedef uint8_t _no_rotation_update_status_type;
      _no_rotation_update_status_type no_rotation_update_status;
      typedef bool _representative_motion_type;
      _representative_motion_type representative_motion;
      typedef bool _clock_bias_estimation_type;
      _clock_bias_estimation_type clock_bias_estimation;
      typedef bool _clipflag_acc_x_type;
      _clipflag_acc_x_type clipflag_acc_x;
      typedef bool _clipflag_acc_y_type;
      _clipflag_acc_y_type clipflag_acc_y;
      typedef bool _clipflag_acc_z_type;
      _clipflag_acc_z_type clipflag_acc_z;
      typedef bool _clipflag_gyr_x_type;
      _clipflag_gyr_x_type clipflag_gyr_x;
      typedef bool _clipflag_gyr_y_type;
      _clipflag_gyr_y_type clipflag_gyr_y;
      typedef bool _clipflag_gyr_z_type;
      _clipflag_gyr_z_type clipflag_gyr_z;
      typedef bool _clipflag_mag_x_type;
      _clipflag_mag_x_type clipflag_mag_x;
      typedef bool _clipflag_mag_y_type;
      _clipflag_mag_y_type clipflag_mag_y;
      typedef bool _clipflag_mag_z_type;
      _clipflag_mag_z_type clipflag_mag_z;
      typedef bool _clipping_indication_type;
      _clipping_indication_type clipping_indication;
      typedef bool _syncin_marker_type;
      _syncin_marker_type syncin_marker;
      typedef bool _syncout_marker_type;
      _syncout_marker_type syncout_marker;
      typedef uint8_t _filter_mode_type;
      _filter_mode_type filter_mode;
      typedef bool _have_gnss_time_pulse_type;
      _have_gnss_time_pulse_type have_gnss_time_pulse;
      typedef uint8_t _rtk_status_type;
      _rtk_status_type rtk_status;

    XsStatusWord():
      selftest(0),
      filter_valid(0),
      gnss_fix(0),
      no_rotation_update_status(0),
      representative_motion(0),
      clock_bias_estimation(0),
      clipflag_acc_x(0),
      clipflag_acc_y(0),
      clipflag_acc_z(0),
      clipflag_gyr_x(0),
      clipflag_gyr_y(0),
      clipflag_gyr_z(0),
      clipflag_mag_x(0),
      clipflag_mag_y(0),
      clipflag_mag_z(0),
      clipping_indication(0),
      syncin_marker(0),
      syncout_marker(0),
      filter_mode(0),
      have_gnss_time_pulse(0),
      rtk_status(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_selftest;
      u_selftest.real = this->selftest;
      *(outbuffer + offset + 0) = (u_selftest.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->selftest);
      union {
        bool real;
        uint8_t base;
      } u_filter_valid;
      u_filter_valid.real = this->filter_valid;
      *(outbuffer + offset + 0) = (u_filter_valid.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->filter_valid);
      union {
        bool real;
        uint8_t base;
      } u_gnss_fix;
      u_gnss_fix.real = this->gnss_fix;
      *(outbuffer + offset + 0) = (u_gnss_fix.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->gnss_fix);
      *(outbuffer + offset + 0) = (this->no_rotation_update_status >> (8 * 0)) & 0xFF;
      offset += sizeof(this->no_rotation_update_status);
      union {
        bool real;
        uint8_t base;
      } u_representative_motion;
      u_representative_motion.real = this->representative_motion;
      *(outbuffer + offset + 0) = (u_representative_motion.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->representative_motion);
      union {
        bool real;
        uint8_t base;
      } u_clock_bias_estimation;
      u_clock_bias_estimation.real = this->clock_bias_estimation;
      *(outbuffer + offset + 0) = (u_clock_bias_estimation.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->clock_bias_estimation);
      union {
        bool real;
        uint8_t base;
      } u_clipflag_acc_x;
      u_clipflag_acc_x.real = this->clipflag_acc_x;
      *(outbuffer + offset + 0) = (u_clipflag_acc_x.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->clipflag_acc_x);
      union {
        bool real;
        uint8_t base;
      } u_clipflag_acc_y;
      u_clipflag_acc_y.real = this->clipflag_acc_y;
      *(outbuffer + offset + 0) = (u_clipflag_acc_y.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->clipflag_acc_y);
      union {
        bool real;
        uint8_t base;
      } u_clipflag_acc_z;
      u_clipflag_acc_z.real = this->clipflag_acc_z;
      *(outbuffer + offset + 0) = (u_clipflag_acc_z.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->clipflag_acc_z);
      union {
        bool real;
        uint8_t base;
      } u_clipflag_gyr_x;
      u_clipflag_gyr_x.real = this->clipflag_gyr_x;
      *(outbuffer + offset + 0) = (u_clipflag_gyr_x.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->clipflag_gyr_x);
      union {
        bool real;
        uint8_t base;
      } u_clipflag_gyr_y;
      u_clipflag_gyr_y.real = this->clipflag_gyr_y;
      *(outbuffer + offset + 0) = (u_clipflag_gyr_y.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->clipflag_gyr_y);
      union {
        bool real;
        uint8_t base;
      } u_clipflag_gyr_z;
      u_clipflag_gyr_z.real = this->clipflag_gyr_z;
      *(outbuffer + offset + 0) = (u_clipflag_gyr_z.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->clipflag_gyr_z);
      union {
        bool real;
        uint8_t base;
      } u_clipflag_mag_x;
      u_clipflag_mag_x.real = this->clipflag_mag_x;
      *(outbuffer + offset + 0) = (u_clipflag_mag_x.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->clipflag_mag_x);
      union {
        bool real;
        uint8_t base;
      } u_clipflag_mag_y;
      u_clipflag_mag_y.real = this->clipflag_mag_y;
      *(outbuffer + offset + 0) = (u_clipflag_mag_y.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->clipflag_mag_y);
      union {
        bool real;
        uint8_t base;
      } u_clipflag_mag_z;
      u_clipflag_mag_z.real = this->clipflag_mag_z;
      *(outbuffer + offset + 0) = (u_clipflag_mag_z.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->clipflag_mag_z);
      union {
        bool real;
        uint8_t base;
      } u_clipping_indication;
      u_clipping_indication.real = this->clipping_indication;
      *(outbuffer + offset + 0) = (u_clipping_indication.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->clipping_indication);
      union {
        bool real;
        uint8_t base;
      } u_syncin_marker;
      u_syncin_marker.real = this->syncin_marker;
      *(outbuffer + offset + 0) = (u_syncin_marker.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->syncin_marker);
      union {
        bool real;
        uint8_t base;
      } u_syncout_marker;
      u_syncout_marker.real = this->syncout_marker;
      *(outbuffer + offset + 0) = (u_syncout_marker.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->syncout_marker);
      *(outbuffer + offset + 0) = (this->filter_mode >> (8 * 0)) & 0xFF;
      offset += sizeof(this->filter_mode);
      union {
        bool real;
        uint8_t base;
      } u_have_gnss_time_pulse;
      u_have_gnss_time_pulse.real = this->have_gnss_time_pulse;
      *(outbuffer + offset + 0) = (u_have_gnss_time_pulse.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->have_gnss_time_pulse);
      *(outbuffer + offset + 0) = (this->rtk_status >> (8 * 0)) & 0xFF;
      offset += sizeof(this->rtk_status);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_selftest;
      u_selftest.base = 0;
      u_selftest.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->selftest = u_selftest.real;
      offset += sizeof(this->selftest);
      union {
        bool real;
        uint8_t base;
      } u_filter_valid;
      u_filter_valid.base = 0;
      u_filter_valid.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->filter_valid = u_filter_valid.real;
      offset += sizeof(this->filter_valid);
      union {
        bool real;
        uint8_t base;
      } u_gnss_fix;
      u_gnss_fix.base = 0;
      u_gnss_fix.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->gnss_fix = u_gnss_fix.real;
      offset += sizeof(this->gnss_fix);
      this->no_rotation_update_status =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->no_rotation_update_status);
      union {
        bool real;
        uint8_t base;
      } u_representative_motion;
      u_representative_motion.base = 0;
      u_representative_motion.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->representative_motion = u_representative_motion.real;
      offset += sizeof(this->representative_motion);
      union {
        bool real;
        uint8_t base;
      } u_clock_bias_estimation;
      u_clock_bias_estimation.base = 0;
      u_clock_bias_estimation.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->clock_bias_estimation = u_clock_bias_estimation.real;
      offset += sizeof(this->clock_bias_estimation);
      union {
        bool real;
        uint8_t base;
      } u_clipflag_acc_x;
      u_clipflag_acc_x.base = 0;
      u_clipflag_acc_x.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->clipflag_acc_x = u_clipflag_acc_x.real;
      offset += sizeof(this->clipflag_acc_x);
      union {
        bool real;
        uint8_t base;
      } u_clipflag_acc_y;
      u_clipflag_acc_y.base = 0;
      u_clipflag_acc_y.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->clipflag_acc_y = u_clipflag_acc_y.real;
      offset += sizeof(this->clipflag_acc_y);
      union {
        bool real;
        uint8_t base;
      } u_clipflag_acc_z;
      u_clipflag_acc_z.base = 0;
      u_clipflag_acc_z.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->clipflag_acc_z = u_clipflag_acc_z.real;
      offset += sizeof(this->clipflag_acc_z);
      union {
        bool real;
        uint8_t base;
      } u_clipflag_gyr_x;
      u_clipflag_gyr_x.base = 0;
      u_clipflag_gyr_x.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->clipflag_gyr_x = u_clipflag_gyr_x.real;
      offset += sizeof(this->clipflag_gyr_x);
      union {
        bool real;
        uint8_t base;
      } u_clipflag_gyr_y;
      u_clipflag_gyr_y.base = 0;
      u_clipflag_gyr_y.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->clipflag_gyr_y = u_clipflag_gyr_y.real;
      offset += sizeof(this->clipflag_gyr_y);
      union {
        bool real;
        uint8_t base;
      } u_clipflag_gyr_z;
      u_clipflag_gyr_z.base = 0;
      u_clipflag_gyr_z.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->clipflag_gyr_z = u_clipflag_gyr_z.real;
      offset += sizeof(this->clipflag_gyr_z);
      union {
        bool real;
        uint8_t base;
      } u_clipflag_mag_x;
      u_clipflag_mag_x.base = 0;
      u_clipflag_mag_x.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->clipflag_mag_x = u_clipflag_mag_x.real;
      offset += sizeof(this->clipflag_mag_x);
      union {
        bool real;
        uint8_t base;
      } u_clipflag_mag_y;
      u_clipflag_mag_y.base = 0;
      u_clipflag_mag_y.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->clipflag_mag_y = u_clipflag_mag_y.real;
      offset += sizeof(this->clipflag_mag_y);
      union {
        bool real;
        uint8_t base;
      } u_clipflag_mag_z;
      u_clipflag_mag_z.base = 0;
      u_clipflag_mag_z.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->clipflag_mag_z = u_clipflag_mag_z.real;
      offset += sizeof(this->clipflag_mag_z);
      union {
        bool real;
        uint8_t base;
      } u_clipping_indication;
      u_clipping_indication.base = 0;
      u_clipping_indication.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->clipping_indication = u_clipping_indication.real;
      offset += sizeof(this->clipping_indication);
      union {
        bool real;
        uint8_t base;
      } u_syncin_marker;
      u_syncin_marker.base = 0;
      u_syncin_marker.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->syncin_marker = u_syncin_marker.real;
      offset += sizeof(this->syncin_marker);
      union {
        bool real;
        uint8_t base;
      } u_syncout_marker;
      u_syncout_marker.base = 0;
      u_syncout_marker.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->syncout_marker = u_syncout_marker.real;
      offset += sizeof(this->syncout_marker);
      this->filter_mode =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->filter_mode);
      union {
        bool real;
        uint8_t base;
      } u_have_gnss_time_pulse;
      u_have_gnss_time_pulse.base = 0;
      u_have_gnss_time_pulse.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->have_gnss_time_pulse = u_have_gnss_time_pulse.real;
      offset += sizeof(this->have_gnss_time_pulse);
      this->rtk_status =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->rtk_status);
     return offset;
    }

    virtual const char * getType() override { return "xsens_mti_driver/XsStatusWord"; };
    virtual const char * getMD5() override { return "dad684e003fb0f5d7e08711072d64f83"; };

  };

}
#endif

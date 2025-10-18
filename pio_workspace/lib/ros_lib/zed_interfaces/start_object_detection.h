#ifndef _ROS_SERVICE_start_object_detection_h
#define _ROS_SERVICE_start_object_detection_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace zed_interfaces
{

static const char START_OBJECT_DETECTION[] = "zed_interfaces/start_object_detection";

  class start_object_detectionRequest : public ros::Msg
  {
    public:
      typedef int8_t _model_type;
      _model_type model;
      typedef float _confidence_type;
      _confidence_type confidence;
      typedef float _max_range_type;
      _max_range_type max_range;
      typedef bool _tracking_type;
      _tracking_type tracking;
      typedef bool _sk_body_fitting_type;
      _sk_body_fitting_type sk_body_fitting;
      typedef bool _mc_people_type;
      _mc_people_type mc_people;
      typedef bool _mc_vehicles_type;
      _mc_vehicles_type mc_vehicles;
      typedef bool _mc_bag_type;
      _mc_bag_type mc_bag;
      typedef bool _mc_animal_type;
      _mc_animal_type mc_animal;
      typedef bool _mc_electronics_type;
      _mc_electronics_type mc_electronics;
      typedef bool _mc_fruit_vegetable_type;
      _mc_fruit_vegetable_type mc_fruit_vegetable;
      typedef bool _mc_sport_type;
      _mc_sport_type mc_sport;

    start_object_detectionRequest():
      model(0),
      confidence(0),
      max_range(0),
      tracking(0),
      sk_body_fitting(0),
      mc_people(0),
      mc_vehicles(0),
      mc_bag(0),
      mc_animal(0),
      mc_electronics(0),
      mc_fruit_vegetable(0),
      mc_sport(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      union {
        int8_t real;
        uint8_t base;
      } u_model;
      u_model.real = this->model;
      *(outbuffer + offset + 0) = (u_model.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->model);
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
      union {
        float real;
        uint32_t base;
      } u_max_range;
      u_max_range.real = this->max_range;
      *(outbuffer + offset + 0) = (u_max_range.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_max_range.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_max_range.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_max_range.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->max_range);
      union {
        bool real;
        uint8_t base;
      } u_tracking;
      u_tracking.real = this->tracking;
      *(outbuffer + offset + 0) = (u_tracking.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->tracking);
      union {
        bool real;
        uint8_t base;
      } u_sk_body_fitting;
      u_sk_body_fitting.real = this->sk_body_fitting;
      *(outbuffer + offset + 0) = (u_sk_body_fitting.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->sk_body_fitting);
      union {
        bool real;
        uint8_t base;
      } u_mc_people;
      u_mc_people.real = this->mc_people;
      *(outbuffer + offset + 0) = (u_mc_people.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->mc_people);
      union {
        bool real;
        uint8_t base;
      } u_mc_vehicles;
      u_mc_vehicles.real = this->mc_vehicles;
      *(outbuffer + offset + 0) = (u_mc_vehicles.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->mc_vehicles);
      union {
        bool real;
        uint8_t base;
      } u_mc_bag;
      u_mc_bag.real = this->mc_bag;
      *(outbuffer + offset + 0) = (u_mc_bag.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->mc_bag);
      union {
        bool real;
        uint8_t base;
      } u_mc_animal;
      u_mc_animal.real = this->mc_animal;
      *(outbuffer + offset + 0) = (u_mc_animal.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->mc_animal);
      union {
        bool real;
        uint8_t base;
      } u_mc_electronics;
      u_mc_electronics.real = this->mc_electronics;
      *(outbuffer + offset + 0) = (u_mc_electronics.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->mc_electronics);
      union {
        bool real;
        uint8_t base;
      } u_mc_fruit_vegetable;
      u_mc_fruit_vegetable.real = this->mc_fruit_vegetable;
      *(outbuffer + offset + 0) = (u_mc_fruit_vegetable.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->mc_fruit_vegetable);
      union {
        bool real;
        uint8_t base;
      } u_mc_sport;
      u_mc_sport.real = this->mc_sport;
      *(outbuffer + offset + 0) = (u_mc_sport.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->mc_sport);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      union {
        int8_t real;
        uint8_t base;
      } u_model;
      u_model.base = 0;
      u_model.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->model = u_model.real;
      offset += sizeof(this->model);
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
      union {
        float real;
        uint32_t base;
      } u_max_range;
      u_max_range.base = 0;
      u_max_range.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_max_range.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_max_range.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_max_range.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->max_range = u_max_range.real;
      offset += sizeof(this->max_range);
      union {
        bool real;
        uint8_t base;
      } u_tracking;
      u_tracking.base = 0;
      u_tracking.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->tracking = u_tracking.real;
      offset += sizeof(this->tracking);
      union {
        bool real;
        uint8_t base;
      } u_sk_body_fitting;
      u_sk_body_fitting.base = 0;
      u_sk_body_fitting.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->sk_body_fitting = u_sk_body_fitting.real;
      offset += sizeof(this->sk_body_fitting);
      union {
        bool real;
        uint8_t base;
      } u_mc_people;
      u_mc_people.base = 0;
      u_mc_people.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->mc_people = u_mc_people.real;
      offset += sizeof(this->mc_people);
      union {
        bool real;
        uint8_t base;
      } u_mc_vehicles;
      u_mc_vehicles.base = 0;
      u_mc_vehicles.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->mc_vehicles = u_mc_vehicles.real;
      offset += sizeof(this->mc_vehicles);
      union {
        bool real;
        uint8_t base;
      } u_mc_bag;
      u_mc_bag.base = 0;
      u_mc_bag.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->mc_bag = u_mc_bag.real;
      offset += sizeof(this->mc_bag);
      union {
        bool real;
        uint8_t base;
      } u_mc_animal;
      u_mc_animal.base = 0;
      u_mc_animal.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->mc_animal = u_mc_animal.real;
      offset += sizeof(this->mc_animal);
      union {
        bool real;
        uint8_t base;
      } u_mc_electronics;
      u_mc_electronics.base = 0;
      u_mc_electronics.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->mc_electronics = u_mc_electronics.real;
      offset += sizeof(this->mc_electronics);
      union {
        bool real;
        uint8_t base;
      } u_mc_fruit_vegetable;
      u_mc_fruit_vegetable.base = 0;
      u_mc_fruit_vegetable.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->mc_fruit_vegetable = u_mc_fruit_vegetable.real;
      offset += sizeof(this->mc_fruit_vegetable);
      union {
        bool real;
        uint8_t base;
      } u_mc_sport;
      u_mc_sport.base = 0;
      u_mc_sport.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->mc_sport = u_mc_sport.real;
      offset += sizeof(this->mc_sport);
     return offset;
    }

    virtual const char * getType() override { return START_OBJECT_DETECTION; };
    virtual const char * getMD5() override { return "237986910a8e55bd46f1c5ba0541a75b"; };

  };

  class start_object_detectionResponse : public ros::Msg
  {
    public:
      typedef bool _done_type;
      _done_type done;

    start_object_detectionResponse():
      done(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_done;
      u_done.real = this->done;
      *(outbuffer + offset + 0) = (u_done.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->done);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_done;
      u_done.base = 0;
      u_done.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->done = u_done.real;
      offset += sizeof(this->done);
     return offset;
    }

    virtual const char * getType() override { return START_OBJECT_DETECTION; };
    virtual const char * getMD5() override { return "89bb254424e4cffedbf494e7b0ddbfea"; };

  };

  class start_object_detection {
    public:
    typedef start_object_detectionRequest Request;
    typedef start_object_detectionResponse Response;
  };

}
#endif

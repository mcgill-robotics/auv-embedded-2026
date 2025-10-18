#ifndef _ROS_rtabmap_msgs_OdomInfo_h
#define _ROS_rtabmap_msgs_OdomInfo_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "rtabmap_msgs/CameraModels.h"
#include "geometry_msgs/Pose.h"
#include "geometry_msgs/Transform.h"
#include "rtabmap_msgs/KeyPoint.h"
#include "rtabmap_msgs/Point3f.h"
#include "sensor_msgs/PointCloud2.h"
#include "rtabmap_msgs/Point2f.h"

namespace rtabmap_msgs
{

  class OdomInfo : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef bool _lost_type;
      _lost_type lost;
      typedef int32_t _matches_type;
      _matches_type matches;
      typedef int32_t _inliers_type;
      _inliers_type inliers;
      typedef float _icpInliersRatio_type;
      _icpInliersRatio_type icpInliersRatio;
      typedef float _icpRotation_type;
      _icpRotation_type icpRotation;
      typedef float _icpTranslation_type;
      _icpTranslation_type icpTranslation;
      typedef float _icpStructuralComplexity_type;
      _icpStructuralComplexity_type icpStructuralComplexity;
      typedef float _icpStructuralDistribution_type;
      _icpStructuralDistribution_type icpStructuralDistribution;
      typedef int32_t _icpCorrespondences_type;
      _icpCorrespondences_type icpCorrespondences;
      float covariance[36];
      typedef int32_t _features_type;
      _features_type features;
      typedef int32_t _localMapSize_type;
      _localMapSize_type localMapSize;
      typedef int32_t _localScanMapSize_type;
      _localScanMapSize_type localScanMapSize;
      typedef int32_t _localKeyFrames_type;
      _localKeyFrames_type localKeyFrames;
      typedef int32_t _localBundleOutliers_type;
      _localBundleOutliers_type localBundleOutliers;
      typedef int32_t _localBundleConstraints_type;
      _localBundleConstraints_type localBundleConstraints;
      typedef float _localBundleTime_type;
      _localBundleTime_type localBundleTime;
      typedef float _localBundleAvgInlierDistance_type;
      _localBundleAvgInlierDistance_type localBundleAvgInlierDistance;
      typedef int32_t _localBundleMaxKeyFramesForInlier_type;
      _localBundleMaxKeyFramesForInlier_type localBundleMaxKeyFramesForInlier;
      typedef bool _keyFrameAdded_type;
      _keyFrameAdded_type keyFrameAdded;
      typedef float _timeEstimation_type;
      _timeEstimation_type timeEstimation;
      typedef float _timeParticleFiltering_type;
      _timeParticleFiltering_type timeParticleFiltering;
      typedef float _stamp_type;
      _stamp_type stamp;
      typedef float _interval_type;
      _interval_type interval;
      typedef float _distanceTravelled_type;
      _distanceTravelled_type distanceTravelled;
      typedef int32_t _memoryUsage_type;
      _memoryUsage_type memoryUsage;
      typedef float _gravityRollError_type;
      _gravityRollError_type gravityRollError;
      typedef float _gravityPitchError_type;
      _gravityPitchError_type gravityPitchError;
      uint32_t localBundleIds_length;
      typedef int32_t _localBundleIds_type;
      _localBundleIds_type st_localBundleIds;
      _localBundleIds_type * localBundleIds;
      uint32_t localBundleModels_length;
      typedef rtabmap_msgs::CameraModels _localBundleModels_type;
      _localBundleModels_type st_localBundleModels;
      _localBundleModels_type * localBundleModels;
      uint32_t localBundlePoses_length;
      typedef geometry_msgs::Pose _localBundlePoses_type;
      _localBundlePoses_type st_localBundlePoses;
      _localBundlePoses_type * localBundlePoses;
      typedef geometry_msgs::Transform _transform_type;
      _transform_type transform;
      typedef geometry_msgs::Transform _transformFiltered_type;
      _transformFiltered_type transformFiltered;
      typedef geometry_msgs::Transform _transformGroundTruth_type;
      _transformGroundTruth_type transformGroundTruth;
      typedef geometry_msgs::Transform _guess_type;
      _guess_type guess;
      typedef int32_t _type_type;
      _type_type type;
      uint32_t wordsKeys_length;
      typedef int32_t _wordsKeys_type;
      _wordsKeys_type st_wordsKeys;
      _wordsKeys_type * wordsKeys;
      uint32_t wordsValues_length;
      typedef rtabmap_msgs::KeyPoint _wordsValues_type;
      _wordsValues_type st_wordsValues;
      _wordsValues_type * wordsValues;
      uint32_t wordMatches_length;
      typedef int32_t _wordMatches_type;
      _wordMatches_type st_wordMatches;
      _wordMatches_type * wordMatches;
      uint32_t wordInliers_length;
      typedef int32_t _wordInliers_type;
      _wordInliers_type st_wordInliers;
      _wordInliers_type * wordInliers;
      uint32_t localMapKeys_length;
      typedef int32_t _localMapKeys_type;
      _localMapKeys_type st_localMapKeys;
      _localMapKeys_type * localMapKeys;
      uint32_t localMapValues_length;
      typedef rtabmap_msgs::Point3f _localMapValues_type;
      _localMapValues_type st_localMapValues;
      _localMapValues_type * localMapValues;
      typedef sensor_msgs::PointCloud2 _localScanMap_type;
      _localScanMap_type localScanMap;
      uint32_t refCorners_length;
      typedef rtabmap_msgs::Point2f _refCorners_type;
      _refCorners_type st_refCorners;
      _refCorners_type * refCorners;
      uint32_t newCorners_length;
      typedef rtabmap_msgs::Point2f _newCorners_type;
      _newCorners_type st_newCorners;
      _newCorners_type * newCorners;
      uint32_t cornerInliers_length;
      typedef int32_t _cornerInliers_type;
      _cornerInliers_type st_cornerInliers;
      _cornerInliers_type * cornerInliers;

    OdomInfo():
      header(),
      lost(0),
      matches(0),
      inliers(0),
      icpInliersRatio(0),
      icpRotation(0),
      icpTranslation(0),
      icpStructuralComplexity(0),
      icpStructuralDistribution(0),
      icpCorrespondences(0),
      covariance(),
      features(0),
      localMapSize(0),
      localScanMapSize(0),
      localKeyFrames(0),
      localBundleOutliers(0),
      localBundleConstraints(0),
      localBundleTime(0),
      localBundleAvgInlierDistance(0),
      localBundleMaxKeyFramesForInlier(0),
      keyFrameAdded(0),
      timeEstimation(0),
      timeParticleFiltering(0),
      stamp(0),
      interval(0),
      distanceTravelled(0),
      memoryUsage(0),
      gravityRollError(0),
      gravityPitchError(0),
      localBundleIds_length(0), st_localBundleIds(), localBundleIds(nullptr),
      localBundleModels_length(0), st_localBundleModels(), localBundleModels(nullptr),
      localBundlePoses_length(0), st_localBundlePoses(), localBundlePoses(nullptr),
      transform(),
      transformFiltered(),
      transformGroundTruth(),
      guess(),
      type(0),
      wordsKeys_length(0), st_wordsKeys(), wordsKeys(nullptr),
      wordsValues_length(0), st_wordsValues(), wordsValues(nullptr),
      wordMatches_length(0), st_wordMatches(), wordMatches(nullptr),
      wordInliers_length(0), st_wordInliers(), wordInliers(nullptr),
      localMapKeys_length(0), st_localMapKeys(), localMapKeys(nullptr),
      localMapValues_length(0), st_localMapValues(), localMapValues(nullptr),
      localScanMap(),
      refCorners_length(0), st_refCorners(), refCorners(nullptr),
      newCorners_length(0), st_newCorners(), newCorners(nullptr),
      cornerInliers_length(0), st_cornerInliers(), cornerInliers(nullptr)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      union {
        bool real;
        uint8_t base;
      } u_lost;
      u_lost.real = this->lost;
      *(outbuffer + offset + 0) = (u_lost.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->lost);
      union {
        int32_t real;
        uint32_t base;
      } u_matches;
      u_matches.real = this->matches;
      *(outbuffer + offset + 0) = (u_matches.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_matches.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_matches.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_matches.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->matches);
      union {
        int32_t real;
        uint32_t base;
      } u_inliers;
      u_inliers.real = this->inliers;
      *(outbuffer + offset + 0) = (u_inliers.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_inliers.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_inliers.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_inliers.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->inliers);
      union {
        float real;
        uint32_t base;
      } u_icpInliersRatio;
      u_icpInliersRatio.real = this->icpInliersRatio;
      *(outbuffer + offset + 0) = (u_icpInliersRatio.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_icpInliersRatio.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_icpInliersRatio.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_icpInliersRatio.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->icpInliersRatio);
      union {
        float real;
        uint32_t base;
      } u_icpRotation;
      u_icpRotation.real = this->icpRotation;
      *(outbuffer + offset + 0) = (u_icpRotation.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_icpRotation.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_icpRotation.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_icpRotation.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->icpRotation);
      union {
        float real;
        uint32_t base;
      } u_icpTranslation;
      u_icpTranslation.real = this->icpTranslation;
      *(outbuffer + offset + 0) = (u_icpTranslation.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_icpTranslation.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_icpTranslation.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_icpTranslation.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->icpTranslation);
      union {
        float real;
        uint32_t base;
      } u_icpStructuralComplexity;
      u_icpStructuralComplexity.real = this->icpStructuralComplexity;
      *(outbuffer + offset + 0) = (u_icpStructuralComplexity.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_icpStructuralComplexity.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_icpStructuralComplexity.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_icpStructuralComplexity.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->icpStructuralComplexity);
      union {
        float real;
        uint32_t base;
      } u_icpStructuralDistribution;
      u_icpStructuralDistribution.real = this->icpStructuralDistribution;
      *(outbuffer + offset + 0) = (u_icpStructuralDistribution.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_icpStructuralDistribution.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_icpStructuralDistribution.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_icpStructuralDistribution.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->icpStructuralDistribution);
      union {
        int32_t real;
        uint32_t base;
      } u_icpCorrespondences;
      u_icpCorrespondences.real = this->icpCorrespondences;
      *(outbuffer + offset + 0) = (u_icpCorrespondences.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_icpCorrespondences.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_icpCorrespondences.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_icpCorrespondences.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->icpCorrespondences);
      for( uint32_t i = 0; i < 36; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->covariance[i]);
      }
      union {
        int32_t real;
        uint32_t base;
      } u_features;
      u_features.real = this->features;
      *(outbuffer + offset + 0) = (u_features.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_features.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_features.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_features.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->features);
      union {
        int32_t real;
        uint32_t base;
      } u_localMapSize;
      u_localMapSize.real = this->localMapSize;
      *(outbuffer + offset + 0) = (u_localMapSize.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_localMapSize.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_localMapSize.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_localMapSize.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->localMapSize);
      union {
        int32_t real;
        uint32_t base;
      } u_localScanMapSize;
      u_localScanMapSize.real = this->localScanMapSize;
      *(outbuffer + offset + 0) = (u_localScanMapSize.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_localScanMapSize.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_localScanMapSize.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_localScanMapSize.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->localScanMapSize);
      union {
        int32_t real;
        uint32_t base;
      } u_localKeyFrames;
      u_localKeyFrames.real = this->localKeyFrames;
      *(outbuffer + offset + 0) = (u_localKeyFrames.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_localKeyFrames.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_localKeyFrames.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_localKeyFrames.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->localKeyFrames);
      union {
        int32_t real;
        uint32_t base;
      } u_localBundleOutliers;
      u_localBundleOutliers.real = this->localBundleOutliers;
      *(outbuffer + offset + 0) = (u_localBundleOutliers.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_localBundleOutliers.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_localBundleOutliers.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_localBundleOutliers.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->localBundleOutliers);
      union {
        int32_t real;
        uint32_t base;
      } u_localBundleConstraints;
      u_localBundleConstraints.real = this->localBundleConstraints;
      *(outbuffer + offset + 0) = (u_localBundleConstraints.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_localBundleConstraints.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_localBundleConstraints.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_localBundleConstraints.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->localBundleConstraints);
      union {
        float real;
        uint32_t base;
      } u_localBundleTime;
      u_localBundleTime.real = this->localBundleTime;
      *(outbuffer + offset + 0) = (u_localBundleTime.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_localBundleTime.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_localBundleTime.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_localBundleTime.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->localBundleTime);
      union {
        float real;
        uint32_t base;
      } u_localBundleAvgInlierDistance;
      u_localBundleAvgInlierDistance.real = this->localBundleAvgInlierDistance;
      *(outbuffer + offset + 0) = (u_localBundleAvgInlierDistance.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_localBundleAvgInlierDistance.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_localBundleAvgInlierDistance.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_localBundleAvgInlierDistance.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->localBundleAvgInlierDistance);
      union {
        int32_t real;
        uint32_t base;
      } u_localBundleMaxKeyFramesForInlier;
      u_localBundleMaxKeyFramesForInlier.real = this->localBundleMaxKeyFramesForInlier;
      *(outbuffer + offset + 0) = (u_localBundleMaxKeyFramesForInlier.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_localBundleMaxKeyFramesForInlier.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_localBundleMaxKeyFramesForInlier.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_localBundleMaxKeyFramesForInlier.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->localBundleMaxKeyFramesForInlier);
      union {
        bool real;
        uint8_t base;
      } u_keyFrameAdded;
      u_keyFrameAdded.real = this->keyFrameAdded;
      *(outbuffer + offset + 0) = (u_keyFrameAdded.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->keyFrameAdded);
      union {
        float real;
        uint32_t base;
      } u_timeEstimation;
      u_timeEstimation.real = this->timeEstimation;
      *(outbuffer + offset + 0) = (u_timeEstimation.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_timeEstimation.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_timeEstimation.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_timeEstimation.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->timeEstimation);
      union {
        float real;
        uint32_t base;
      } u_timeParticleFiltering;
      u_timeParticleFiltering.real = this->timeParticleFiltering;
      *(outbuffer + offset + 0) = (u_timeParticleFiltering.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_timeParticleFiltering.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_timeParticleFiltering.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_timeParticleFiltering.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->timeParticleFiltering);
      union {
        float real;
        uint32_t base;
      } u_stamp;
      u_stamp.real = this->stamp;
      *(outbuffer + offset + 0) = (u_stamp.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_stamp.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_stamp.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_stamp.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->stamp);
      union {
        float real;
        uint32_t base;
      } u_interval;
      u_interval.real = this->interval;
      *(outbuffer + offset + 0) = (u_interval.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_interval.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_interval.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_interval.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->interval);
      union {
        float real;
        uint32_t base;
      } u_distanceTravelled;
      u_distanceTravelled.real = this->distanceTravelled;
      *(outbuffer + offset + 0) = (u_distanceTravelled.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_distanceTravelled.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_distanceTravelled.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_distanceTravelled.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->distanceTravelled);
      union {
        int32_t real;
        uint32_t base;
      } u_memoryUsage;
      u_memoryUsage.real = this->memoryUsage;
      *(outbuffer + offset + 0) = (u_memoryUsage.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_memoryUsage.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_memoryUsage.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_memoryUsage.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->memoryUsage);
      union {
        float real;
        uint32_t base;
      } u_gravityRollError;
      u_gravityRollError.real = this->gravityRollError;
      *(outbuffer + offset + 0) = (u_gravityRollError.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_gravityRollError.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_gravityRollError.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_gravityRollError.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->gravityRollError);
      union {
        float real;
        uint32_t base;
      } u_gravityPitchError;
      u_gravityPitchError.real = this->gravityPitchError;
      *(outbuffer + offset + 0) = (u_gravityPitchError.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_gravityPitchError.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_gravityPitchError.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_gravityPitchError.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->gravityPitchError);
      *(outbuffer + offset + 0) = (this->localBundleIds_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->localBundleIds_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->localBundleIds_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->localBundleIds_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->localBundleIds_length);
      for( uint32_t i = 0; i < localBundleIds_length; i++){
      union {
        int32_t real;
        uint32_t base;
      } u_localBundleIdsi;
      u_localBundleIdsi.real = this->localBundleIds[i];
      *(outbuffer + offset + 0) = (u_localBundleIdsi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_localBundleIdsi.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_localBundleIdsi.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_localBundleIdsi.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->localBundleIds[i]);
      }
      *(outbuffer + offset + 0) = (this->localBundleModels_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->localBundleModels_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->localBundleModels_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->localBundleModels_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->localBundleModels_length);
      for( uint32_t i = 0; i < localBundleModels_length; i++){
      offset += this->localBundleModels[i].serialize(outbuffer + offset);
      }
      *(outbuffer + offset + 0) = (this->localBundlePoses_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->localBundlePoses_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->localBundlePoses_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->localBundlePoses_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->localBundlePoses_length);
      for( uint32_t i = 0; i < localBundlePoses_length; i++){
      offset += this->localBundlePoses[i].serialize(outbuffer + offset);
      }
      offset += this->transform.serialize(outbuffer + offset);
      offset += this->transformFiltered.serialize(outbuffer + offset);
      offset += this->transformGroundTruth.serialize(outbuffer + offset);
      offset += this->guess.serialize(outbuffer + offset);
      union {
        int32_t real;
        uint32_t base;
      } u_type;
      u_type.real = this->type;
      *(outbuffer + offset + 0) = (u_type.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_type.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_type.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_type.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->type);
      *(outbuffer + offset + 0) = (this->wordsKeys_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->wordsKeys_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->wordsKeys_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->wordsKeys_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->wordsKeys_length);
      for( uint32_t i = 0; i < wordsKeys_length; i++){
      union {
        int32_t real;
        uint32_t base;
      } u_wordsKeysi;
      u_wordsKeysi.real = this->wordsKeys[i];
      *(outbuffer + offset + 0) = (u_wordsKeysi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_wordsKeysi.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_wordsKeysi.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_wordsKeysi.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->wordsKeys[i]);
      }
      *(outbuffer + offset + 0) = (this->wordsValues_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->wordsValues_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->wordsValues_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->wordsValues_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->wordsValues_length);
      for( uint32_t i = 0; i < wordsValues_length; i++){
      offset += this->wordsValues[i].serialize(outbuffer + offset);
      }
      *(outbuffer + offset + 0) = (this->wordMatches_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->wordMatches_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->wordMatches_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->wordMatches_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->wordMatches_length);
      for( uint32_t i = 0; i < wordMatches_length; i++){
      union {
        int32_t real;
        uint32_t base;
      } u_wordMatchesi;
      u_wordMatchesi.real = this->wordMatches[i];
      *(outbuffer + offset + 0) = (u_wordMatchesi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_wordMatchesi.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_wordMatchesi.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_wordMatchesi.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->wordMatches[i]);
      }
      *(outbuffer + offset + 0) = (this->wordInliers_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->wordInliers_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->wordInliers_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->wordInliers_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->wordInliers_length);
      for( uint32_t i = 0; i < wordInliers_length; i++){
      union {
        int32_t real;
        uint32_t base;
      } u_wordInliersi;
      u_wordInliersi.real = this->wordInliers[i];
      *(outbuffer + offset + 0) = (u_wordInliersi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_wordInliersi.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_wordInliersi.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_wordInliersi.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->wordInliers[i]);
      }
      *(outbuffer + offset + 0) = (this->localMapKeys_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->localMapKeys_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->localMapKeys_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->localMapKeys_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->localMapKeys_length);
      for( uint32_t i = 0; i < localMapKeys_length; i++){
      union {
        int32_t real;
        uint32_t base;
      } u_localMapKeysi;
      u_localMapKeysi.real = this->localMapKeys[i];
      *(outbuffer + offset + 0) = (u_localMapKeysi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_localMapKeysi.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_localMapKeysi.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_localMapKeysi.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->localMapKeys[i]);
      }
      *(outbuffer + offset + 0) = (this->localMapValues_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->localMapValues_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->localMapValues_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->localMapValues_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->localMapValues_length);
      for( uint32_t i = 0; i < localMapValues_length; i++){
      offset += this->localMapValues[i].serialize(outbuffer + offset);
      }
      offset += this->localScanMap.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->refCorners_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->refCorners_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->refCorners_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->refCorners_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->refCorners_length);
      for( uint32_t i = 0; i < refCorners_length; i++){
      offset += this->refCorners[i].serialize(outbuffer + offset);
      }
      *(outbuffer + offset + 0) = (this->newCorners_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->newCorners_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->newCorners_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->newCorners_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->newCorners_length);
      for( uint32_t i = 0; i < newCorners_length; i++){
      offset += this->newCorners[i].serialize(outbuffer + offset);
      }
      *(outbuffer + offset + 0) = (this->cornerInliers_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->cornerInliers_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->cornerInliers_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->cornerInliers_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->cornerInliers_length);
      for( uint32_t i = 0; i < cornerInliers_length; i++){
      union {
        int32_t real;
        uint32_t base;
      } u_cornerInliersi;
      u_cornerInliersi.real = this->cornerInliers[i];
      *(outbuffer + offset + 0) = (u_cornerInliersi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_cornerInliersi.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_cornerInliersi.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_cornerInliersi.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->cornerInliers[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      union {
        bool real;
        uint8_t base;
      } u_lost;
      u_lost.base = 0;
      u_lost.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->lost = u_lost.real;
      offset += sizeof(this->lost);
      union {
        int32_t real;
        uint32_t base;
      } u_matches;
      u_matches.base = 0;
      u_matches.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_matches.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_matches.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_matches.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->matches = u_matches.real;
      offset += sizeof(this->matches);
      union {
        int32_t real;
        uint32_t base;
      } u_inliers;
      u_inliers.base = 0;
      u_inliers.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_inliers.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_inliers.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_inliers.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->inliers = u_inliers.real;
      offset += sizeof(this->inliers);
      union {
        float real;
        uint32_t base;
      } u_icpInliersRatio;
      u_icpInliersRatio.base = 0;
      u_icpInliersRatio.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_icpInliersRatio.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_icpInliersRatio.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_icpInliersRatio.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->icpInliersRatio = u_icpInliersRatio.real;
      offset += sizeof(this->icpInliersRatio);
      union {
        float real;
        uint32_t base;
      } u_icpRotation;
      u_icpRotation.base = 0;
      u_icpRotation.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_icpRotation.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_icpRotation.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_icpRotation.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->icpRotation = u_icpRotation.real;
      offset += sizeof(this->icpRotation);
      union {
        float real;
        uint32_t base;
      } u_icpTranslation;
      u_icpTranslation.base = 0;
      u_icpTranslation.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_icpTranslation.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_icpTranslation.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_icpTranslation.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->icpTranslation = u_icpTranslation.real;
      offset += sizeof(this->icpTranslation);
      union {
        float real;
        uint32_t base;
      } u_icpStructuralComplexity;
      u_icpStructuralComplexity.base = 0;
      u_icpStructuralComplexity.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_icpStructuralComplexity.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_icpStructuralComplexity.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_icpStructuralComplexity.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->icpStructuralComplexity = u_icpStructuralComplexity.real;
      offset += sizeof(this->icpStructuralComplexity);
      union {
        float real;
        uint32_t base;
      } u_icpStructuralDistribution;
      u_icpStructuralDistribution.base = 0;
      u_icpStructuralDistribution.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_icpStructuralDistribution.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_icpStructuralDistribution.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_icpStructuralDistribution.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->icpStructuralDistribution = u_icpStructuralDistribution.real;
      offset += sizeof(this->icpStructuralDistribution);
      union {
        int32_t real;
        uint32_t base;
      } u_icpCorrespondences;
      u_icpCorrespondences.base = 0;
      u_icpCorrespondences.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_icpCorrespondences.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_icpCorrespondences.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_icpCorrespondences.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->icpCorrespondences = u_icpCorrespondences.real;
      offset += sizeof(this->icpCorrespondences);
      for( uint32_t i = 0; i < 36; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->covariance[i]));
      }
      union {
        int32_t real;
        uint32_t base;
      } u_features;
      u_features.base = 0;
      u_features.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_features.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_features.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_features.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->features = u_features.real;
      offset += sizeof(this->features);
      union {
        int32_t real;
        uint32_t base;
      } u_localMapSize;
      u_localMapSize.base = 0;
      u_localMapSize.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_localMapSize.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_localMapSize.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_localMapSize.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->localMapSize = u_localMapSize.real;
      offset += sizeof(this->localMapSize);
      union {
        int32_t real;
        uint32_t base;
      } u_localScanMapSize;
      u_localScanMapSize.base = 0;
      u_localScanMapSize.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_localScanMapSize.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_localScanMapSize.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_localScanMapSize.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->localScanMapSize = u_localScanMapSize.real;
      offset += sizeof(this->localScanMapSize);
      union {
        int32_t real;
        uint32_t base;
      } u_localKeyFrames;
      u_localKeyFrames.base = 0;
      u_localKeyFrames.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_localKeyFrames.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_localKeyFrames.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_localKeyFrames.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->localKeyFrames = u_localKeyFrames.real;
      offset += sizeof(this->localKeyFrames);
      union {
        int32_t real;
        uint32_t base;
      } u_localBundleOutliers;
      u_localBundleOutliers.base = 0;
      u_localBundleOutliers.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_localBundleOutliers.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_localBundleOutliers.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_localBundleOutliers.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->localBundleOutliers = u_localBundleOutliers.real;
      offset += sizeof(this->localBundleOutliers);
      union {
        int32_t real;
        uint32_t base;
      } u_localBundleConstraints;
      u_localBundleConstraints.base = 0;
      u_localBundleConstraints.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_localBundleConstraints.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_localBundleConstraints.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_localBundleConstraints.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->localBundleConstraints = u_localBundleConstraints.real;
      offset += sizeof(this->localBundleConstraints);
      union {
        float real;
        uint32_t base;
      } u_localBundleTime;
      u_localBundleTime.base = 0;
      u_localBundleTime.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_localBundleTime.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_localBundleTime.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_localBundleTime.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->localBundleTime = u_localBundleTime.real;
      offset += sizeof(this->localBundleTime);
      union {
        float real;
        uint32_t base;
      } u_localBundleAvgInlierDistance;
      u_localBundleAvgInlierDistance.base = 0;
      u_localBundleAvgInlierDistance.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_localBundleAvgInlierDistance.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_localBundleAvgInlierDistance.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_localBundleAvgInlierDistance.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->localBundleAvgInlierDistance = u_localBundleAvgInlierDistance.real;
      offset += sizeof(this->localBundleAvgInlierDistance);
      union {
        int32_t real;
        uint32_t base;
      } u_localBundleMaxKeyFramesForInlier;
      u_localBundleMaxKeyFramesForInlier.base = 0;
      u_localBundleMaxKeyFramesForInlier.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_localBundleMaxKeyFramesForInlier.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_localBundleMaxKeyFramesForInlier.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_localBundleMaxKeyFramesForInlier.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->localBundleMaxKeyFramesForInlier = u_localBundleMaxKeyFramesForInlier.real;
      offset += sizeof(this->localBundleMaxKeyFramesForInlier);
      union {
        bool real;
        uint8_t base;
      } u_keyFrameAdded;
      u_keyFrameAdded.base = 0;
      u_keyFrameAdded.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->keyFrameAdded = u_keyFrameAdded.real;
      offset += sizeof(this->keyFrameAdded);
      union {
        float real;
        uint32_t base;
      } u_timeEstimation;
      u_timeEstimation.base = 0;
      u_timeEstimation.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_timeEstimation.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_timeEstimation.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_timeEstimation.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->timeEstimation = u_timeEstimation.real;
      offset += sizeof(this->timeEstimation);
      union {
        float real;
        uint32_t base;
      } u_timeParticleFiltering;
      u_timeParticleFiltering.base = 0;
      u_timeParticleFiltering.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_timeParticleFiltering.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_timeParticleFiltering.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_timeParticleFiltering.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->timeParticleFiltering = u_timeParticleFiltering.real;
      offset += sizeof(this->timeParticleFiltering);
      union {
        float real;
        uint32_t base;
      } u_stamp;
      u_stamp.base = 0;
      u_stamp.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_stamp.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_stamp.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_stamp.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->stamp = u_stamp.real;
      offset += sizeof(this->stamp);
      union {
        float real;
        uint32_t base;
      } u_interval;
      u_interval.base = 0;
      u_interval.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_interval.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_interval.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_interval.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->interval = u_interval.real;
      offset += sizeof(this->interval);
      union {
        float real;
        uint32_t base;
      } u_distanceTravelled;
      u_distanceTravelled.base = 0;
      u_distanceTravelled.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_distanceTravelled.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_distanceTravelled.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_distanceTravelled.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->distanceTravelled = u_distanceTravelled.real;
      offset += sizeof(this->distanceTravelled);
      union {
        int32_t real;
        uint32_t base;
      } u_memoryUsage;
      u_memoryUsage.base = 0;
      u_memoryUsage.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_memoryUsage.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_memoryUsage.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_memoryUsage.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->memoryUsage = u_memoryUsage.real;
      offset += sizeof(this->memoryUsage);
      union {
        float real;
        uint32_t base;
      } u_gravityRollError;
      u_gravityRollError.base = 0;
      u_gravityRollError.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_gravityRollError.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_gravityRollError.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_gravityRollError.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->gravityRollError = u_gravityRollError.real;
      offset += sizeof(this->gravityRollError);
      union {
        float real;
        uint32_t base;
      } u_gravityPitchError;
      u_gravityPitchError.base = 0;
      u_gravityPitchError.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_gravityPitchError.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_gravityPitchError.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_gravityPitchError.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->gravityPitchError = u_gravityPitchError.real;
      offset += sizeof(this->gravityPitchError);
      uint32_t localBundleIds_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      localBundleIds_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      localBundleIds_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      localBundleIds_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->localBundleIds_length);
      if(localBundleIds_lengthT > localBundleIds_length)
        this->localBundleIds = (int32_t*)realloc(this->localBundleIds, localBundleIds_lengthT * sizeof(int32_t));
      localBundleIds_length = localBundleIds_lengthT;
      for( uint32_t i = 0; i < localBundleIds_length; i++){
      union {
        int32_t real;
        uint32_t base;
      } u_st_localBundleIds;
      u_st_localBundleIds.base = 0;
      u_st_localBundleIds.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_localBundleIds.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_st_localBundleIds.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_st_localBundleIds.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->st_localBundleIds = u_st_localBundleIds.real;
      offset += sizeof(this->st_localBundleIds);
        memcpy( &(this->localBundleIds[i]), &(this->st_localBundleIds), sizeof(int32_t));
      }
      uint32_t localBundleModels_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      localBundleModels_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      localBundleModels_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      localBundleModels_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->localBundleModels_length);
      if(localBundleModels_lengthT > localBundleModels_length)
        this->localBundleModels = (rtabmap_msgs::CameraModels*)realloc(this->localBundleModels, localBundleModels_lengthT * sizeof(rtabmap_msgs::CameraModels));
      localBundleModels_length = localBundleModels_lengthT;
      for( uint32_t i = 0; i < localBundleModels_length; i++){
      offset += this->st_localBundleModels.deserialize(inbuffer + offset);
        memcpy( &(this->localBundleModels[i]), &(this->st_localBundleModels), sizeof(rtabmap_msgs::CameraModels));
      }
      uint32_t localBundlePoses_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      localBundlePoses_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      localBundlePoses_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      localBundlePoses_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->localBundlePoses_length);
      if(localBundlePoses_lengthT > localBundlePoses_length)
        this->localBundlePoses = (geometry_msgs::Pose*)realloc(this->localBundlePoses, localBundlePoses_lengthT * sizeof(geometry_msgs::Pose));
      localBundlePoses_length = localBundlePoses_lengthT;
      for( uint32_t i = 0; i < localBundlePoses_length; i++){
      offset += this->st_localBundlePoses.deserialize(inbuffer + offset);
        memcpy( &(this->localBundlePoses[i]), &(this->st_localBundlePoses), sizeof(geometry_msgs::Pose));
      }
      offset += this->transform.deserialize(inbuffer + offset);
      offset += this->transformFiltered.deserialize(inbuffer + offset);
      offset += this->transformGroundTruth.deserialize(inbuffer + offset);
      offset += this->guess.deserialize(inbuffer + offset);
      union {
        int32_t real;
        uint32_t base;
      } u_type;
      u_type.base = 0;
      u_type.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_type.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_type.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_type.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->type = u_type.real;
      offset += sizeof(this->type);
      uint32_t wordsKeys_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      wordsKeys_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      wordsKeys_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      wordsKeys_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->wordsKeys_length);
      if(wordsKeys_lengthT > wordsKeys_length)
        this->wordsKeys = (int32_t*)realloc(this->wordsKeys, wordsKeys_lengthT * sizeof(int32_t));
      wordsKeys_length = wordsKeys_lengthT;
      for( uint32_t i = 0; i < wordsKeys_length; i++){
      union {
        int32_t real;
        uint32_t base;
      } u_st_wordsKeys;
      u_st_wordsKeys.base = 0;
      u_st_wordsKeys.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_wordsKeys.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_st_wordsKeys.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_st_wordsKeys.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->st_wordsKeys = u_st_wordsKeys.real;
      offset += sizeof(this->st_wordsKeys);
        memcpy( &(this->wordsKeys[i]), &(this->st_wordsKeys), sizeof(int32_t));
      }
      uint32_t wordsValues_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      wordsValues_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      wordsValues_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      wordsValues_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->wordsValues_length);
      if(wordsValues_lengthT > wordsValues_length)
        this->wordsValues = (rtabmap_msgs::KeyPoint*)realloc(this->wordsValues, wordsValues_lengthT * sizeof(rtabmap_msgs::KeyPoint));
      wordsValues_length = wordsValues_lengthT;
      for( uint32_t i = 0; i < wordsValues_length; i++){
      offset += this->st_wordsValues.deserialize(inbuffer + offset);
        memcpy( &(this->wordsValues[i]), &(this->st_wordsValues), sizeof(rtabmap_msgs::KeyPoint));
      }
      uint32_t wordMatches_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      wordMatches_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      wordMatches_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      wordMatches_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->wordMatches_length);
      if(wordMatches_lengthT > wordMatches_length)
        this->wordMatches = (int32_t*)realloc(this->wordMatches, wordMatches_lengthT * sizeof(int32_t));
      wordMatches_length = wordMatches_lengthT;
      for( uint32_t i = 0; i < wordMatches_length; i++){
      union {
        int32_t real;
        uint32_t base;
      } u_st_wordMatches;
      u_st_wordMatches.base = 0;
      u_st_wordMatches.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_wordMatches.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_st_wordMatches.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_st_wordMatches.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->st_wordMatches = u_st_wordMatches.real;
      offset += sizeof(this->st_wordMatches);
        memcpy( &(this->wordMatches[i]), &(this->st_wordMatches), sizeof(int32_t));
      }
      uint32_t wordInliers_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      wordInliers_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      wordInliers_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      wordInliers_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->wordInliers_length);
      if(wordInliers_lengthT > wordInliers_length)
        this->wordInliers = (int32_t*)realloc(this->wordInliers, wordInliers_lengthT * sizeof(int32_t));
      wordInliers_length = wordInliers_lengthT;
      for( uint32_t i = 0; i < wordInliers_length; i++){
      union {
        int32_t real;
        uint32_t base;
      } u_st_wordInliers;
      u_st_wordInliers.base = 0;
      u_st_wordInliers.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_wordInliers.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_st_wordInliers.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_st_wordInliers.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->st_wordInliers = u_st_wordInliers.real;
      offset += sizeof(this->st_wordInliers);
        memcpy( &(this->wordInliers[i]), &(this->st_wordInliers), sizeof(int32_t));
      }
      uint32_t localMapKeys_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      localMapKeys_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      localMapKeys_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      localMapKeys_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->localMapKeys_length);
      if(localMapKeys_lengthT > localMapKeys_length)
        this->localMapKeys = (int32_t*)realloc(this->localMapKeys, localMapKeys_lengthT * sizeof(int32_t));
      localMapKeys_length = localMapKeys_lengthT;
      for( uint32_t i = 0; i < localMapKeys_length; i++){
      union {
        int32_t real;
        uint32_t base;
      } u_st_localMapKeys;
      u_st_localMapKeys.base = 0;
      u_st_localMapKeys.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_localMapKeys.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_st_localMapKeys.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_st_localMapKeys.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->st_localMapKeys = u_st_localMapKeys.real;
      offset += sizeof(this->st_localMapKeys);
        memcpy( &(this->localMapKeys[i]), &(this->st_localMapKeys), sizeof(int32_t));
      }
      uint32_t localMapValues_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      localMapValues_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      localMapValues_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      localMapValues_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->localMapValues_length);
      if(localMapValues_lengthT > localMapValues_length)
        this->localMapValues = (rtabmap_msgs::Point3f*)realloc(this->localMapValues, localMapValues_lengthT * sizeof(rtabmap_msgs::Point3f));
      localMapValues_length = localMapValues_lengthT;
      for( uint32_t i = 0; i < localMapValues_length; i++){
      offset += this->st_localMapValues.deserialize(inbuffer + offset);
        memcpy( &(this->localMapValues[i]), &(this->st_localMapValues), sizeof(rtabmap_msgs::Point3f));
      }
      offset += this->localScanMap.deserialize(inbuffer + offset);
      uint32_t refCorners_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      refCorners_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      refCorners_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      refCorners_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->refCorners_length);
      if(refCorners_lengthT > refCorners_length)
        this->refCorners = (rtabmap_msgs::Point2f*)realloc(this->refCorners, refCorners_lengthT * sizeof(rtabmap_msgs::Point2f));
      refCorners_length = refCorners_lengthT;
      for( uint32_t i = 0; i < refCorners_length; i++){
      offset += this->st_refCorners.deserialize(inbuffer + offset);
        memcpy( &(this->refCorners[i]), &(this->st_refCorners), sizeof(rtabmap_msgs::Point2f));
      }
      uint32_t newCorners_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      newCorners_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      newCorners_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      newCorners_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->newCorners_length);
      if(newCorners_lengthT > newCorners_length)
        this->newCorners = (rtabmap_msgs::Point2f*)realloc(this->newCorners, newCorners_lengthT * sizeof(rtabmap_msgs::Point2f));
      newCorners_length = newCorners_lengthT;
      for( uint32_t i = 0; i < newCorners_length; i++){
      offset += this->st_newCorners.deserialize(inbuffer + offset);
        memcpy( &(this->newCorners[i]), &(this->st_newCorners), sizeof(rtabmap_msgs::Point2f));
      }
      uint32_t cornerInliers_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      cornerInliers_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      cornerInliers_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      cornerInliers_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->cornerInliers_length);
      if(cornerInliers_lengthT > cornerInliers_length)
        this->cornerInliers = (int32_t*)realloc(this->cornerInliers, cornerInliers_lengthT * sizeof(int32_t));
      cornerInliers_length = cornerInliers_lengthT;
      for( uint32_t i = 0; i < cornerInliers_length; i++){
      union {
        int32_t real;
        uint32_t base;
      } u_st_cornerInliers;
      u_st_cornerInliers.base = 0;
      u_st_cornerInliers.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_cornerInliers.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_st_cornerInliers.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_st_cornerInliers.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->st_cornerInliers = u_st_cornerInliers.real;
      offset += sizeof(this->st_cornerInliers);
        memcpy( &(this->cornerInliers[i]), &(this->st_cornerInliers), sizeof(int32_t));
      }
     return offset;
    }

    virtual const char * getType() override { return "rtabmap_msgs/OdomInfo"; };
    virtual const char * getMD5() override { return "9a9c97dc6c27f8a4f2a53d9cd23d41d7"; };

  };

}
#endif

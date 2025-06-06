// This file was generated by generate-classes.
// DO NOT EDIT THIS FILE!
#pragma once

#include <CesiumGltf/AnimationChannel.h>
#include <CesiumGltf/AnimationSampler.h>
#include <CesiumGltf/Library.h>
#include <CesiumGltf/NamedObject.h>

#include <vector>

namespace CesiumGltf {
/**
 * @brief A keyframe animation.
 */
struct CESIUMGLTF_API Animation final : public CesiumGltf::NamedObject {
  /**
   * @brief The original name of this type.
   */
  static constexpr const char* TypeName = "Animation";

  /**
   * @brief An array of animation channels. An animation channel combines an
   * animation sampler with a target property being animated. Different channels
   * of the same animation **MUST NOT** have the same targets.
   */
  std::vector<CesiumGltf::AnimationChannel> channels;

  /**
   * @brief An array of animation samplers. An animation sampler combines
   * timestamps with a sequence of output values and defines an interpolation
   * algorithm.
   */
  std::vector<CesiumGltf::AnimationSampler> samplers;

  /**
   * @brief Calculates the size in bytes of this object, including the contents
   * of all collections, pointers, and strings. This will NOT include the size
   * of any extensions attached to the object. Calling this method may be slow
   * as it requires traversing the object's entire structure.
   */
  int64_t getSizeBytes() const {
    int64_t accum = 0;
    accum += int64_t(sizeof(Animation));
    accum += CesiumGltf::NamedObject::getSizeBytes() -
             int64_t(sizeof(CesiumGltf::NamedObject));
    accum += int64_t(
        sizeof(CesiumGltf::AnimationChannel) * this->channels.capacity());
    for (const CesiumGltf::AnimationChannel& value : this->channels) {
      accum +=
          value.getSizeBytes() - int64_t(sizeof(CesiumGltf::AnimationChannel));
    }
    accum += int64_t(
        sizeof(CesiumGltf::AnimationSampler) * this->samplers.capacity());
    for (const CesiumGltf::AnimationSampler& value : this->samplers) {
      accum +=
          value.getSizeBytes() - int64_t(sizeof(CesiumGltf::AnimationSampler));
    }
    return accum;
  }
};
} // namespace CesiumGltf

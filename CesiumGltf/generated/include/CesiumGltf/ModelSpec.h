// This file was generated by generate-classes.
// DO NOT EDIT THIS FILE!
#pragma once

#include <CesiumGltf/Accessor.h>
#include <CesiumGltf/Animation.h>
#include <CesiumGltf/Asset.h>
#include <CesiumGltf/Buffer.h>
#include <CesiumGltf/BufferView.h>
#include <CesiumGltf/Camera.h>
#include <CesiumGltf/Image.h>
#include <CesiumGltf/Library.h>
#include <CesiumGltf/Material.h>
#include <CesiumGltf/Mesh.h>
#include <CesiumGltf/Node.h>
#include <CesiumGltf/Sampler.h>
#include <CesiumGltf/Scene.h>
#include <CesiumGltf/Skin.h>
#include <CesiumGltf/Texture.h>
#include <CesiumUtility/ExtensibleObject.h>

#include <cstdint>
#include <string>
#include <vector>

namespace CesiumGltf {
/**
 * @brief The root object for a glTF asset.
 */
struct CESIUMGLTF_API ModelSpec : public CesiumUtility::ExtensibleObject {
  /**
   * @brief The original name of this type.
   */
  static constexpr const char* TypeName = "Model";

  /**
   * @brief Names of glTF extensions used in this asset.
   */
  std::vector<std::string> extensionsUsed;

  /**
   * @brief Names of glTF extensions required to properly load this asset.
   */
  std::vector<std::string> extensionsRequired;

  /**
   * @brief An array of accessors.
   *
   * An accessor is a typed view into a bufferView.
   */
  std::vector<CesiumGltf::Accessor> accessors;

  /**
   * @brief An array of keyframe animations.
   */
  std::vector<CesiumGltf::Animation> animations;

  /**
   * @brief Metadata about the glTF asset.
   */
  CesiumGltf::Asset asset;

  /**
   * @brief An array of buffers.
   *
   * A buffer points to binary geometry, animation, or skins.
   */
  std::vector<CesiumGltf::Buffer> buffers;

  /**
   * @brief An array of bufferViews.
   *
   * A bufferView is a view into a buffer generally representing a subset of the
   * buffer.
   */
  std::vector<CesiumGltf::BufferView> bufferViews;

  /**
   * @brief An array of cameras.
   *
   * A camera defines a projection matrix.
   */
  std::vector<CesiumGltf::Camera> cameras;

  /**
   * @brief An array of images.
   *
   * An image defines data used to create a texture.
   */
  std::vector<CesiumGltf::Image> images;

  /**
   * @brief An array of materials.
   *
   * A material defines the appearance of a primitive.
   */
  std::vector<CesiumGltf::Material> materials;

  /**
   * @brief An array of meshes.
   *
   * A mesh is a set of primitives to be rendered.
   */
  std::vector<CesiumGltf::Mesh> meshes;

  /**
   * @brief An array of nodes.
   */
  std::vector<CesiumGltf::Node> nodes;

  /**
   * @brief An array of samplers.
   *
   * A sampler contains properties for texture filtering and wrapping modes.
   */
  std::vector<CesiumGltf::Sampler> samplers;

  /**
   * @brief The index of the default scene.
   *
   * This property **MUST NOT** be defined, when `scenes` is undefined.
   */
  int32_t scene = -1;

  /**
   * @brief An array of scenes.
   */
  std::vector<CesiumGltf::Scene> scenes;

  /**
   * @brief An array of skins.
   *
   * A skin is defined by joints and matrices.
   */
  std::vector<CesiumGltf::Skin> skins;

  /**
   * @brief An array of textures.
   */
  std::vector<CesiumGltf::Texture> textures;

  /**
   * @brief Calculates the size in bytes of this object, including the contents
   * of all collections, pointers, and strings. This will NOT include the size
   * of any extensions attached to the object. Calling this method may be slow
   * as it requires traversing the object's entire structure.
   */
  int64_t getSizeBytes() const {
    int64_t accum = 0;
    accum += int64_t(sizeof(ModelSpec));
    accum += CesiumUtility::ExtensibleObject::getSizeBytes() -
             int64_t(sizeof(CesiumUtility::ExtensibleObject));
    accum += int64_t(sizeof(std::string) * this->extensionsUsed.capacity());
    accum += int64_t(sizeof(std::string) * this->extensionsRequired.capacity());
    accum += int64_t(sizeof(CesiumGltf::Accessor) * this->accessors.capacity());
    for (const CesiumGltf::Accessor& value : this->accessors) {
      accum += value.getSizeBytes() - int64_t(sizeof(CesiumGltf::Accessor));
    }
    accum +=
        int64_t(sizeof(CesiumGltf::Animation) * this->animations.capacity());
    for (const CesiumGltf::Animation& value : this->animations) {
      accum += value.getSizeBytes() - int64_t(sizeof(CesiumGltf::Animation));
    }
    accum += this->asset.getSizeBytes() - int64_t(sizeof(CesiumGltf::Asset));
    accum += int64_t(sizeof(CesiumGltf::Buffer) * this->buffers.capacity());
    for (const CesiumGltf::Buffer& value : this->buffers) {
      accum += value.getSizeBytes() - int64_t(sizeof(CesiumGltf::Buffer));
    }
    accum +=
        int64_t(sizeof(CesiumGltf::BufferView) * this->bufferViews.capacity());
    for (const CesiumGltf::BufferView& value : this->bufferViews) {
      accum += value.getSizeBytes() - int64_t(sizeof(CesiumGltf::BufferView));
    }
    accum += int64_t(sizeof(CesiumGltf::Camera) * this->cameras.capacity());
    for (const CesiumGltf::Camera& value : this->cameras) {
      accum += value.getSizeBytes() - int64_t(sizeof(CesiumGltf::Camera));
    }
    accum += int64_t(sizeof(CesiumGltf::Image) * this->images.capacity());
    for (const CesiumGltf::Image& value : this->images) {
      accum += value.getSizeBytes() - int64_t(sizeof(CesiumGltf::Image));
    }
    accum += int64_t(sizeof(CesiumGltf::Material) * this->materials.capacity());
    for (const CesiumGltf::Material& value : this->materials) {
      accum += value.getSizeBytes() - int64_t(sizeof(CesiumGltf::Material));
    }
    accum += int64_t(sizeof(CesiumGltf::Mesh) * this->meshes.capacity());
    for (const CesiumGltf::Mesh& value : this->meshes) {
      accum += value.getSizeBytes() - int64_t(sizeof(CesiumGltf::Mesh));
    }
    accum += int64_t(sizeof(CesiumGltf::Node) * this->nodes.capacity());
    for (const CesiumGltf::Node& value : this->nodes) {
      accum += value.getSizeBytes() - int64_t(sizeof(CesiumGltf::Node));
    }
    accum += int64_t(sizeof(CesiumGltf::Sampler) * this->samplers.capacity());
    for (const CesiumGltf::Sampler& value : this->samplers) {
      accum += value.getSizeBytes() - int64_t(sizeof(CesiumGltf::Sampler));
    }
    accum += int64_t(sizeof(CesiumGltf::Scene) * this->scenes.capacity());
    for (const CesiumGltf::Scene& value : this->scenes) {
      accum += value.getSizeBytes() - int64_t(sizeof(CesiumGltf::Scene));
    }
    accum += int64_t(sizeof(CesiumGltf::Skin) * this->skins.capacity());
    for (const CesiumGltf::Skin& value : this->skins) {
      accum += value.getSizeBytes() - int64_t(sizeof(CesiumGltf::Skin));
    }
    accum += int64_t(sizeof(CesiumGltf::Texture) * this->textures.capacity());
    for (const CesiumGltf::Texture& value : this->textures) {
      accum += value.getSizeBytes() - int64_t(sizeof(CesiumGltf::Texture));
    }
    return accum;
  }

protected:
  /**
   * @brief This class is not meant to be instantiated directly. Use {@link Model} instead.
   */
  ModelSpec() = default;
  friend struct Model;
};
} // namespace CesiumGltf

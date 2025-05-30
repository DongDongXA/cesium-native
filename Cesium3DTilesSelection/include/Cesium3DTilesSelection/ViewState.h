#pragma once

#include <Cesium3DTilesSelection/BoundingVolume.h>
#include <Cesium3DTilesSelection/Library.h>
#include <CesiumGeometry/CullingVolume.h>
#include <CesiumGeometry/Plane.h>
#include <CesiumGeospatial/Cartographic.h>
#include <CesiumGeospatial/Ellipsoid.h>

#include <glm/mat3x3.hpp>
#include <glm/mat4x4.hpp>
#include <glm/vec2.hpp>
#include <glm/vec3.hpp>

#include <optional>
#include <vector>

namespace Cesium3DTilesSelection {

/**
 * @brief The state of the view that is used during the traversal of a tileset.
 *
 * An instance of a view state can be created with the {@link create} function.
 */
class CESIUM3DTILESSELECTION_API ViewState final {

public:
  /**
   * @brief Creates a new instance of a view state with a symmetric perspective
   * projection.
   * @deprecated Use {@link ViewState::ViewState} instead.
   */
  [[deprecated("Use ViewState::ViewState instead.")]] static ViewState create(
      const glm::dvec3& position,
      const glm::dvec3& direction,
      const glm::dvec3& up,
      const glm::dvec2& viewportSize,
      double horizontalFieldOfView,
      double verticalFieldOfView,
      const CesiumGeospatial::Ellipsoid& ellipsoid CESIUM_DEFAULT_ELLIPSOID);

  /**
   * @brief Creates a new instance.
   *
   * @param position The position of the eye point of the camera.
   * @param direction The view direction vector of the camera.
   * @param up The up vector of the camera.
   * @param viewportSize The size of the viewport, in pixels.
   * @param horizontalFieldOfView The horizontal field-of-view (opening)
   * angle of the camera, in radians.
   * @param verticalFieldOfView The vertical field-of-view (opening)
   * angle of the camera, in radians.
   * @param ellipsoid The ellipsoid that will be used to compute the
   * {@link ViewState#getPositionCartographic cartographic position}
   * from the cartesian position.
   * Default value: {@link CesiumGeospatial::Ellipsoid::WGS84}.
   */
  ViewState(
      const glm::dvec3& position,
      const glm::dvec3& direction,
      const glm::dvec3& up,
      const glm::dvec2& viewportSize,
      double horizontalFieldOfView,
      double verticalFieldOfView,
      const CesiumGeospatial::Ellipsoid& ellipsoid CESIUM_DEFAULT_ELLIPSOID);

  /**
   * @brief Creates a new instance of a view state with a general projection,
   * including skewed perspective and orthographic projections.
   *
   * @param viewMatrix The view's view matrix i.e., the inverse of its pose
   * @param projectionMatrix see e.g.
   * {@link CesiumGeometry::Transforms::createPerspectiveMatrix}
   * @param viewportSize The size of the viewport, in pixels.
   * @param ellipsoid The ellipsoid that will be used to compute the
   * {@link ViewState#getPositionCartographic cartographic position}
   * from the cartesian position.
   * Default value: {@link CesiumGeospatial::Ellipsoid::WGS84}.
   */
  ViewState(
      const glm::dmat4& viewMatrix,
      const glm::dmat4& projectionMatrix,
      const glm::dvec2& viewportSize,
      const CesiumGeospatial::Ellipsoid& ellipsoid CESIUM_DEFAULT_ELLIPSOID);

  /**
   * @brief Creates a new instance of a view state with an orthographic
   * projection.
   *
   * @param position The position of the eye point of the camera.
   * @param direction The view direction vector of the camera.
   * @param up The up vector of the camera.
   * @param viewportSize The size of the viewport, in pixels.
   * @param left left distance of near plane edge from center
   * @param right right distance of near plane edge
   * @param bottom bottom distance of near plane edge
   * @param top top distance of near plane edge
   * @param ellipsoid The ellipsoid that will be used to compute the
   * {@link ViewState#getPositionCartographic cartographic position}
   * from the cartesian position.
   * Default value: {@link CesiumGeospatial::Ellipsoid::WGS84}.
   */
  ViewState(
      const glm::dvec3& position,
      const glm::dvec3& direction,
      const glm::dvec3& up,
      const glm::dvec2& viewportSize,
      double left,
      double right,
      double bottom,
      double top,
      const CesiumGeospatial::Ellipsoid& ellipsoid CESIUM_DEFAULT_ELLIPSOID);

  /**
   * @brief Gets the position of the camera in Earth-centered, Earth-fixed
   * coordinates.
   */
  const glm::dvec3& getPosition() const noexcept { return this->_position; }

  /**
   * @brief Gets the look direction of the camera in Earth-centered, Earth-fixed
   * coordinates.
   */
  const glm::dvec3& getDirection() const noexcept { return this->_direction; }

  /**
   * @brief Gets the up direction of the camera in Earth-centered, Earth-fixed
   * coordinates.
   */
  glm::dvec3 getUp() const noexcept {
    return {
        this->_viewMatrix[0][1],
        this->_viewMatrix[1][1],
        this->_viewMatrix[2][1]};
  }

  /**
   * @brief Gets the position of the camera as a longitude / latitude / height.
   *
   * The result may be `std::nullopt` if the Cartesian position is
   * very near the center of the Ellipsoid.
   */
  const std::optional<CesiumGeospatial::Cartographic>&
  getPositionCartographic() const noexcept {
    return this->_positionCartographic;
  }

  /**
   * @brief Gets the size of the viewport in pixels.
   */
  const glm::dvec2& getViewportSize() const noexcept {
    return this->_viewportSize;
  }

  /**
   * @brief Gets the horizontal field-of-view angle in radians. This is only
   * valid for a symmetric perspective projection.
   */
  double getHorizontalFieldOfView() const noexcept;

  /**
   * @brief Gets the vertical field-of-view angle in radians. This is only
   * valid for a symmetric perspective projection.
   */
  double getVerticalFieldOfView() const noexcept;

  /**
   * @brief Gets the view matrix for the ViewState.
   */
  const glm::dmat4& getViewMatrix() const noexcept { return this->_viewMatrix; }

  /**
   * @brief Gets the projection matrix for the ViewState.
   */
  const glm::dmat4& getProjectionMatrix() const noexcept {
    return this->_projectionMatrix;
  }

  /**
   * @brief Returns whether the given {@link BoundingVolume} is visible for this
   * camera
   *
   * Returns whether the given bounding volume is visible for this camera,
   * meaning that the given volume is at least partially contained in
   * the frustum of this camera.
   *
   * @return Whether the bounding volume is visible
   */
  bool
  isBoundingVolumeVisible(const BoundingVolume& boundingVolume) const noexcept;

  /**
   * @brief Computes the squared distance to the given {@link BoundingVolume}.
   *
   * Computes the squared euclidean distance from the position of this camera
   * to the closest point of the given bounding volume.
   *
   * @param boundingVolume The bounding volume
   * @returns The squared distance
   */
  double computeDistanceSquaredToBoundingVolume(
      const BoundingVolume& boundingVolume) const noexcept;

  /**
   * @brief Computes the screen space error from a given geometric error
   *
   * Computes the screen space error (SSE) that results from the given
   * geometric error, when it is viewed with this camera from the given
   * distance.
   *
   * The given distance will be clamped to a small positive value if
   * it is negative or too close to zero.
   *
   * @param geometricError The geometric error
   * @param distance The viewing distance
   * @return The screen space error
   */
  double computeScreenSpaceError(double geometricError, double distance)
      const noexcept;

private:
  const glm::dvec3 _position;
  const glm::dvec3 _direction;
  const glm::dvec2 _viewportSize;
  const CesiumGeospatial::Ellipsoid _ellipsoid;

  const std::optional<CesiumGeospatial::Cartographic> _positionCartographic;

  const CesiumGeometry::CullingVolume _cullingVolume;
  const glm::dmat4 _viewMatrix;
  const glm::dmat4 _projectionMatrix;
};

} // namespace Cesium3DTilesSelection

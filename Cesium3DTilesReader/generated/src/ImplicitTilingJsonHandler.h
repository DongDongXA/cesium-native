// This file was generated by generate-classes.
// DO NOT EDIT THIS FILE!
#pragma once

#include "SubtreesJsonHandler.h"

#include <Cesium3DTiles/ImplicitTiling.h>
#include <CesiumJsonReader/ExtensibleObjectJsonHandler.h>
#include <CesiumJsonReader/IntegerJsonHandler.h>
#include <CesiumJsonReader/StringJsonHandler.h>

namespace CesiumJsonReader {
class JsonReaderOptions;
} // namespace CesiumJsonReader

namespace Cesium3DTilesReader {
class ImplicitTilingJsonHandler
    : public CesiumJsonReader::ExtensibleObjectJsonHandler {
public:
  using ValueType = Cesium3DTiles::ImplicitTiling;

  explicit ImplicitTilingJsonHandler(
      const CesiumJsonReader::JsonReaderOptions& options) noexcept;
  void
  reset(IJsonHandler* pParentHandler, Cesium3DTiles::ImplicitTiling* pObject);

  IJsonHandler* readObjectKey(const std::string_view& str) override;

protected:
  IJsonHandler* readObjectKeyImplicitTiling(
      const std::string& objectType,
      const std::string_view& str,
      Cesium3DTiles::ImplicitTiling& o);

private:
  Cesium3DTiles::ImplicitTiling* _pObject = nullptr;
  CesiumJsonReader::StringJsonHandler _subdivisionScheme;
  CesiumJsonReader::IntegerJsonHandler<int64_t> _subtreeLevels;
  CesiumJsonReader::IntegerJsonHandler<int64_t> _availableLevels;
  SubtreesJsonHandler _subtrees;
};
} // namespace Cesium3DTilesReader

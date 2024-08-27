/*
 * Copyright 2020-2024 Toyota Connected North America
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#include "deserialize.h"

namespace plugin_filament_view {

::filament::math::float3 Deserialize::Format3(
    const flutter::EncodableMap& map) {
  double x, y, z;
  x = y = z = 0.0f;

  for (auto& it : map) {
    if (it.second.IsNull())
      continue;

    auto key = std::get<std::string>(it.first);
    if (key == "x" && std::holds_alternative<double>(it.second)) {
      x = std::get<double>(it.second);
    } else if (key == "y" && std::holds_alternative<double>(it.second)) {
      y = std::get<double>(it.second);
    } else if (key == "z" && std::holds_alternative<double>(it.second)) {
      z = std::get<double>(it.second);
    }
  }
  return {static_cast<float>(x), static_cast<float>(y), static_cast<float>(z)};
}

::filament::math::quatf Deserialize::Format4(const flutter::EncodableMap& map) {
  double x, y, z, w;
  x = y = z = 0.0f;
  w = 1.0f;

  for (auto& it : map) {
    if (it.second.IsNull())
      continue;

    auto key = std::get<std::string>(it.first);
    if (key == "x" && std::holds_alternative<double>(it.second)) {
      x = std::get<double>(it.second);
    } else if (key == "y" && std::holds_alternative<double>(it.second)) {
      y = std::get<double>(it.second);
    } else if (key == "z" && std::holds_alternative<double>(it.second)) {
      z = std::get<double>(it.second);
    } else if (key == "w" && std::holds_alternative<double>(it.second)) {
      w = std::get<double>(it.second);
    }
  }
  return {static_cast<float>(x), static_cast<float>(y), static_cast<float>(z), static_cast<float>(w)};
}

}  // namespace plugin_filament_view

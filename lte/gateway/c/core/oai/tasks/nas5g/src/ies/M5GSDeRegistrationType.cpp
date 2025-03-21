/*
Copyright 2020 The Magma Authors.
This source code is licensed under the BSD-style license found in the
LICENSE file in the root directory of this source tree.
Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
*/

#include <iostream>
#include <sstream>
#include <cstdint>
#include "lte/gateway/c/core/oai/tasks/nas5g/include/ies/M5GSDeRegistrationType.hpp"
#include "lte/gateway/c/core/oai/tasks/nas5g/include/M5GCommonDefs.h"

namespace magma5g {
M5GSDeRegistrationTypeMsg::M5GSDeRegistrationTypeMsg() {};
M5GSDeRegistrationTypeMsg::~M5GSDeRegistrationTypeMsg() {};

int M5GSDeRegistrationTypeMsg::DecodeM5GSDeRegistrationTypeMsg(
    M5GSDeRegistrationTypeMsg* de_reg_type, uint8_t iei, uint8_t* buffer,
    uint32_t len) {
  uint8_t decoded = 0;

  de_reg_type->switchoff = (*(buffer + decoded) >> 3) & 0x01;
  de_reg_type->re_reg_required = (*(buffer + decoded) >> 2) & 0x01;
  de_reg_type->access_type = *(buffer + decoded) & 0x03;
  return (decoded);
};

int M5GSDeRegistrationTypeMsg::EncodeM5GSDeRegistrationTypeMsg(
    M5GSDeRegistrationTypeMsg* de_reg_type, uint8_t iei, uint8_t* buffer,
    uint32_t len) {
  uint8_t encoded = 0;

  *(buffer + encoded) = 0x00 | ((de_reg_type->switchoff << 3) & 0x08) |
                        ((de_reg_type->re_reg_required << 2) & 0x04) |
                        (de_reg_type->access_type & 0x03);
  encoded++;
  return (encoded);
};
}  // namespace magma5g

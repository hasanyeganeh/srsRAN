/**
 *
 * \section COPYRIGHT
 *
 * Copyright 2013-2021 Software Radio Systems Limited
 *
 * By using this file, you agree to the terms and conditions set
 * forth in the LICENSE file which can be found at the top level of
 * the distribution.
 *
 */

#ifndef SRSENB_COMMON_ENB_H
#define SRSENB_COMMON_ENB_H

/*******************************************************************************
                              INCLUDES
*******************************************************************************/

#include "srsran/common/lte_common.h"
#include <stdint.h>

namespace srsenb {

#define SRSENB_RRC_MAX_N_PLMN_IDENTITIES 6

#define SRSENB_N_SRB 3
#define SRSENB_N_DRB 8
#define SRSENB_N_RADIO_BEARERS 11
#define SRSENB_MAX_UES 64

using srsran::lte_drb;
using srsran::lte_srb;
using srsran::srb_to_lcid;
inline const char* get_rb_name(uint32_t lcid)
{
  return (srsran::is_lte_srb(lcid)) ? srsran::get_srb_name(srsran::lte_lcid_to_srb(lcid))
                                    : srsran::get_drb_name(static_cast<srsran::lte_drb>(lcid - srsran::MAX_LTE_SRB_ID));
}
constexpr uint32_t drb_to_lcid(lte_drb drb_id)
{
  return srb_to_lcid(lte_srb::srb2) + static_cast<uint32_t>(drb_id);
}

// Cat 3 UE - Max number of DL-SCH transport block bits received within a TTI
// 3GPP 36.306 Table 4.1.1
#define SRSENB_MAX_BUFFER_SIZE_BITS 102048
#define SRSENB_MAX_BUFFER_SIZE_BYTES 12756
#define SRSENB_BUFFER_HEADER_OFFSET 1024

} // namespace srsenb

#endif // SRSENB_COMMON_ENB_H

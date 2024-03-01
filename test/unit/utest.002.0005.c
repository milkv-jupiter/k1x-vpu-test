/*
 * The confidential and proprietary information contained in this file may
 * only be used by a person authorised under and to the extent permitted
 * by a subsisting licensing agreement from Arm Technology (China) Co., Ltd.
 *
 *            (C) COPYRIGHT 2021-2021 Arm Technology (China) Co., Ltd.
 *                ALL RIGHTS RESERVED
 *
 * This entire notice must be reproduced on all copies of this file
 * and copies of this file may only be made by a person if such person is
 * permitted to do so under the terms of a subsisting license agreement
 * from Arm Technology (China) Co., Ltd.
 *
 * SPDX-License-Identifier: GPL-2.0-only
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301,
 * USA.
 *
 */

/*
#CODE-EXTRACT: driver/ngCore/mvx_if.c::find_hw_dev
#CODE-EXTRACT: driver/ngCore/mvx_if.c::mvx_hw_instance_devices

#DESCRIPTION: It shall be possible to find "null"
*/

#include <stdlib.h>

#ifndef bool
typedef int bool;
#endif

/**********************************************************
 * Facades
 **********************************************************/
struct device;
struct mutex {
  struct device *placeholder;
};

/**********************************************************
 * Include artefact under test
 **********************************************************/
#include "extracted-code"

int main(int argc, char **argv) {
  int n, i;
  int reply = -1;
  struct device *test_ptr;

  struct mvx_hw_instance_devices *instances = NULL;
  instances = calloc(1, sizeof(struct mvx_hw_instance_devices));

  if (instances) {
    /* Create a fake device-ptr, different from NULL. */
    test_ptr = (struct device *)&test_ptr;

    /* Install the fake pointer everywhere, but the first */
    n = sizeof(instances->instances) / sizeof(instances->instances[0]);
    for (i = 1; i < (n - 1); ++i) {
      instances->instances[i] = test_ptr;
    }

    /* We expect to find the null at position 0
     */
    if (0 == find_hw_dev(instances, NULL)) {
      reply = 0;
    }
    free(instances);
  }
  return reply;
}
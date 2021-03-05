#
# Copyright (c) 2020 Nordic Semiconductor ASA
#
# SPDX-License-Identifier: LicenseRef-Nordic-5-Clause
#

cmake_minimum_required(VERSION 3.13.1)

set(OT_NCP_VENDOR_HOOK_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR})

if(RCP_MINIMAL)
        set(CONF_FILE prj-rcp_minimal.conf)
else()
        list(INSERT OVERLAY_CONFIG 0 ../common/overlay-ot-defaults.conf)
endif()


find_package(Zephyr REQUIRED HINTS $ENV{ZEPHYR_BASE})

project(openthread_coprocessor)

# NORDIC SDK APP START
target_sources(app PRIVATE src/main.c src/nrf_802154_radio_wrapper.c)
# NORDIC SDK APP END

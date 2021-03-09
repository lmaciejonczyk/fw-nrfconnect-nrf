/*
 * Copyright (c) 2020-2021 Nordic Semiconductor ASA
 *
 * SPDX-License-Identifier: LicenseRef-Nordic-5-Clause
 */
#include <zephyr.h>
#include <logging/log.h>
#include <usb/usb_device.h>

LOG_MODULE_REGISTER(coprocessor_sample, CONFIG_OT_COPROCESSOR_LOG_LEVEL);

#define WELCOME_TEXT                                                           \
	"\n\r"                                                                 \
	"\n\r"                                                                 \
	"=========================================================\n\r"        \
	"OpenThread Coprocessor application is now running on NCS.\n\r"        \
	"=========================================================\n\r"

void main(void)
{
	int ret;

	LOG_INF(WELCOME_TEXT);

	if (IS_ENABLED(CONFIG_USB_DEVICE_STACK)) {
		ret = usb_enable(NULL);
		if (ret != 0) {
			LOG_ERR("Failed to enable USB");
			return;
		}
	}
}

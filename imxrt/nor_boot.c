/*
 * Copyright 2017 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */


#include "nor_boot.h"

extern void _vStackTop(void);
extern void ResetHandler(void);

#ifdef ARDUINO_QUARTO

__attribute__ ((used, section(".isr_vector")))
void (* const g_pfnVectors[])(void) = {
    &_vStackTop,                       // The initial stack pointer
    ResetHandler,                      // The reset handler (boot startup)
    NMI_Handler,                       // The NMI handler
    HardFault_Handler,                 // The hard fault handler
	(void*) APPLICATION_BOOT_HEADER,           // Header to know we have legit application code
	(void*) APPLICATION_BOOT_HEADER_AND_VERSION,
};

__attribute__((section(".boot_hdr.dcd_data")))
const uint8_t dcd_data[] = {
	/* HEADER */
	/* Tag */
	0xD2,
	/* Image Length */
	0x04, 0x30,
	/* Version */
	0x41,

	/* COMMANDS */

	/* group: 'Imported Commands' */
	/* #1.1-117, command header bytes for merged 'Write - value' command */
	0xCC, 0x03, 0xAC, 0x04,
	/* #1.1, command: write_value, address: CCM_CCGR0, value: 0xFFFFFFFF, size: 4 */
	0x40, 0x0F, 0xC0, 0x68, 0xFF, 0xFF, 0xFF, 0xFF,
	/* #1.2, command: write_value, address: CCM_CCGR1, value: 0xFFFFFFFF, size: 4 */
	0x40, 0x0F, 0xC0, 0x6C, 0xFF, 0xFF, 0xFF, 0xFF,
	/* #1.3, command: write_value, address: CCM_CCGR2, value: 0xFFFFFFFF, size: 4 */
	0x40, 0x0F, 0xC0, 0x70, 0xFF, 0xFF, 0xFF, 0xFF,
	/* #1.4, command: write_value, address: CCM_CCGR3, value: 0xFFFFFFFF, size: 4 */
	0x40, 0x0F, 0xC0, 0x74, 0xFF, 0xFF, 0xFF, 0xFF,
	/* #1.5, command: write_value, address: CCM_CCGR4, value: 0xFFFFFFFF, size: 4 */
	0x40, 0x0F, 0xC0, 0x78, 0xFF, 0xFF, 0xFF, 0xFF,
	/* #1.6, command: write_value, address: CCM_CCGR5, value: 0xFFFFFFFF, size: 4 */
	0x40, 0x0F, 0xC0, 0x7C, 0xFF, 0xFF, 0xFF, 0xFF,
	/* #1.7, command: write_value, address: CCM_CCGR6, value: 0xFFFFFFFF, size: 4 */
	0x40, 0x0F, 0xC0, 0x80, 0xFF, 0xFF, 0xFF, 0xFF,
	/* #1.8, command: write_value, address: CCM_ANALOG_PLL_SYS, value: 0x2001, size: 4 */
	0x40, 0x0D, 0x80, 0x30, 0x00, 0x00, 0x20, 0x01,
	/* #1.9, command: write_value, address: CCM_ANALOG_PFD_528, value: 0x1D0000, size: 4 */
	0x40, 0x0D, 0x81, 0x00, 0x00, 0x1D, 0x00, 0x00,
	/* #1.10, command: write_value, address: CCM_CBCDR, value: 0x10D40, size: 4 */
	0x40, 0x0F, 0xC0, 0x14, 0x00, 0x01, 0x0D, 0x40,
	/* #1.11, command: write_value, address: IOMUXC_SW_MUX_CTL_PAD_GPIO_EMC_00, value: 0x00, size: 4 */
	0x40, 0x1F, 0x80, 0x14, 0x00, 0x00, 0x00, 0x00,
	/* #1.12, command: write_value, address: IOMUXC_SW_MUX_CTL_PAD_GPIO_EMC_01, value: 0x00, size: 4 */
	0x40, 0x1F, 0x80, 0x18, 0x00, 0x00, 0x00, 0x00,
	/* #1.13, command: write_value, address: IOMUXC_SW_MUX_CTL_PAD_GPIO_EMC_02, value: 0x00, size: 4 */
	0x40, 0x1F, 0x80, 0x1C, 0x00, 0x00, 0x00, 0x00,
	/* #1.14, command: write_value, address: IOMUXC_SW_MUX_CTL_PAD_GPIO_EMC_03, value: 0x00, size: 4 */
	0x40, 0x1F, 0x80, 0x20, 0x00, 0x00, 0x00, 0x00,
	/* #1.15, command: write_value, address: IOMUXC_SW_MUX_CTL_PAD_GPIO_EMC_04, value: 0x00, size: 4 */
	0x40, 0x1F, 0x80, 0x24, 0x00, 0x00, 0x00, 0x00,
	/* #1.16, command: write_value, address: IOMUXC_SW_MUX_CTL_PAD_GPIO_EMC_05, value: 0x00, size: 4 */
	0x40, 0x1F, 0x80, 0x28, 0x00, 0x00, 0x00, 0x00,
	/* #1.17, command: write_value, address: IOMUXC_SW_MUX_CTL_PAD_GPIO_EMC_06, value: 0x00, size: 4 */
	0x40, 0x1F, 0x80, 0x2C, 0x00, 0x00, 0x00, 0x00,
	/* #1.18, command: write_value, address: IOMUXC_SW_MUX_CTL_PAD_GPIO_EMC_07, value: 0x00, size: 4 */
	0x40, 0x1F, 0x80, 0x30, 0x00, 0x00, 0x00, 0x00,
	/* #1.19, command: write_value, address: IOMUXC_SW_MUX_CTL_PAD_GPIO_EMC_08, value: 0x00, size: 4 */
	0x40, 0x1F, 0x80, 0x34, 0x00, 0x00, 0x00, 0x00,
	/* #1.20, command: write_value, address: IOMUXC_SW_MUX_CTL_PAD_GPIO_EMC_09, value: 0x00, size: 4 */
	0x40, 0x1F, 0x80, 0x38, 0x00, 0x00, 0x00, 0x00,
	/* #1.21, command: write_value, address: IOMUXC_SW_MUX_CTL_PAD_GPIO_EMC_10, value: 0x00, size: 4 */
	0x40, 0x1F, 0x80, 0x3C, 0x00, 0x00, 0x00, 0x00,
	/* #1.22, command: write_value, address: IOMUXC_SW_MUX_CTL_PAD_GPIO_EMC_11, value: 0x00, size: 4 */
	0x40, 0x1F, 0x80, 0x40, 0x00, 0x00, 0x00, 0x00,
	/* #1.23, command: write_value, address: IOMUXC_SW_MUX_CTL_PAD_GPIO_EMC_12, value: 0x00, size: 4 */
	0x40, 0x1F, 0x80, 0x44, 0x00, 0x00, 0x00, 0x00,
	/* #1.24, command: write_value, address: IOMUXC_SW_MUX_CTL_PAD_GPIO_EMC_13, value: 0x00, size: 4 */
	0x40, 0x1F, 0x80, 0x48, 0x00, 0x00, 0x00, 0x00,
	/* #1.25, command: write_value, address: IOMUXC_SW_MUX_CTL_PAD_GPIO_EMC_14, value: 0x00, size: 4 */
	0x40, 0x1F, 0x80, 0x4C, 0x00, 0x00, 0x00, 0x00,
	/* #1.26, command: write_value, address: IOMUXC_SW_MUX_CTL_PAD_GPIO_EMC_15, value: 0x00, size: 4 */
	0x40, 0x1F, 0x80, 0x50, 0x00, 0x00, 0x00, 0x00,
	/* #1.27, command: write_value, address: IOMUXC_SW_MUX_CTL_PAD_GPIO_EMC_16, value: 0x00, size: 4 */
	0x40, 0x1F, 0x80, 0x54, 0x00, 0x00, 0x00, 0x00,
	/* #1.28, command: write_value, address: IOMUXC_SW_MUX_CTL_PAD_GPIO_EMC_17, value: 0x00, size: 4 */
	0x40, 0x1F, 0x80, 0x58, 0x00, 0x00, 0x00, 0x00,
	/* #1.29, command: write_value, address: IOMUXC_SW_MUX_CTL_PAD_GPIO_EMC_18, value: 0x00, size: 4 */
	0x40, 0x1F, 0x80, 0x5C, 0x00, 0x00, 0x00, 0x00,
	/* #1.30, command: write_value, address: IOMUXC_SW_MUX_CTL_PAD_GPIO_EMC_19, value: 0x00, size: 4 */
	0x40, 0x1F, 0x80, 0x60, 0x00, 0x00, 0x00, 0x00,
	/* #1.31, command: write_value, address: IOMUXC_SW_MUX_CTL_PAD_GPIO_EMC_20, value: 0x00, size: 4 */
	0x40, 0x1F, 0x80, 0x64, 0x00, 0x00, 0x00, 0x00,
	/* #1.32, command: write_value, address: IOMUXC_SW_MUX_CTL_PAD_GPIO_EMC_21, value: 0x00, size: 4 */
	0x40, 0x1F, 0x80, 0x68, 0x00, 0x00, 0x00, 0x00,
	/* #1.33, command: write_value, address: IOMUXC_SW_MUX_CTL_PAD_GPIO_EMC_22, value: 0x00, size: 4 */
	0x40, 0x1F, 0x80, 0x6C, 0x00, 0x00, 0x00, 0x00,
	/* #1.34, command: write_value, address: IOMUXC_SW_MUX_CTL_PAD_GPIO_EMC_23, value: 0x00, size: 4 */
	0x40, 0x1F, 0x80, 0x70, 0x00, 0x00, 0x00, 0x00,
	/* #1.35, command: write_value, address: IOMUXC_SW_MUX_CTL_PAD_GPIO_EMC_24, value: 0x00, size: 4 */
	0x40, 0x1F, 0x80, 0x74, 0x00, 0x00, 0x00, 0x00,
	/* #1.36, command: write_value, address: IOMUXC_SW_MUX_CTL_PAD_GPIO_EMC_25, value: 0x00, size: 4 */
	0x40, 0x1F, 0x80, 0x78, 0x00, 0x00, 0x00, 0x00,
	/* #1.37, command: write_value, address: IOMUXC_SW_MUX_CTL_PAD_GPIO_EMC_26, value: 0x00, size: 4 */
	0x40, 0x1F, 0x80, 0x7C, 0x00, 0x00, 0x00, 0x00,
	/* #1.38, command: write_value, address: IOMUXC_SW_MUX_CTL_PAD_GPIO_EMC_27, value: 0x00, size: 4 */
	0x40, 0x1F, 0x80, 0x80, 0x00, 0x00, 0x00, 0x00,
	/* #1.39, command: write_value, address: IOMUXC_SW_MUX_CTL_PAD_GPIO_EMC_28, value: 0x00, size: 4 */
	0x40, 0x1F, 0x80, 0x84, 0x00, 0x00, 0x00, 0x00,
	/* #1.40, command: write_value, address: IOMUXC_SW_MUX_CTL_PAD_GPIO_EMC_29, value: 0x00, size: 4 */
	0x40, 0x1F, 0x80, 0x88, 0x00, 0x00, 0x00, 0x00,
	/* #1.41, command: write_value, address: IOMUXC_SW_MUX_CTL_PAD_GPIO_EMC_30, value: 0x00, size: 4 */
	0x40, 0x1F, 0x80, 0x8C, 0x00, 0x00, 0x00, 0x00,
	/* #1.42, command: write_value, address: IOMUXC_SW_MUX_CTL_PAD_GPIO_EMC_31, value: 0x00, size: 4 */
	0x40, 0x1F, 0x80, 0x90, 0x00, 0x00, 0x00, 0x00,
	/* #1.43, command: write_value, address: IOMUXC_SW_MUX_CTL_PAD_GPIO_EMC_32, value: 0x00, size: 4 */
	0x40, 0x1F, 0x80, 0x94, 0x00, 0x00, 0x00, 0x00,
	/* #1.44, command: write_value, address: IOMUXC_SW_MUX_CTL_PAD_GPIO_EMC_33, value: 0x00, size: 4 */
	0x40, 0x1F, 0x80, 0x98, 0x00, 0x00, 0x00, 0x00,
	/* #1.45, command: write_value, address: IOMUXC_SW_MUX_CTL_PAD_GPIO_EMC_34, value: 0x00, size: 4 */
	0x40, 0x1F, 0x80, 0x9C, 0x00, 0x00, 0x00, 0x00,
	/* #1.46, command: write_value, address: IOMUXC_SW_MUX_CTL_PAD_GPIO_EMC_35, value: 0x00, size: 4 */
	0x40, 0x1F, 0x80, 0xA0, 0x00, 0x00, 0x00, 0x00,
	/* #1.47, command: write_value, address: IOMUXC_SW_MUX_CTL_PAD_GPIO_EMC_36, value: 0x00, size: 4 */
	0x40, 0x1F, 0x80, 0xA4, 0x00, 0x00, 0x00, 0x00,
	/* #1.48, command: write_value, address: IOMUXC_SW_MUX_CTL_PAD_GPIO_EMC_37, value: 0x00, size: 4 */
	0x40, 0x1F, 0x80, 0xA8, 0x00, 0x00, 0x00, 0x00,
	/* #1.49, command: write_value, address: IOMUXC_SW_MUX_CTL_PAD_GPIO_EMC_38, value: 0x00, size: 4 */
	0x40, 0x1F, 0x80, 0xAC, 0x00, 0x00, 0x00, 0x00,
	/* #1.50, command: write_value, address: IOMUXC_SW_MUX_CTL_PAD_GPIO_EMC_39, value: 0x10, size: 4 */
	0x40, 0x1F, 0x80, 0xB0, 0x00, 0x00, 0x00, 0x10,
	/* #1.51, command: write_value, address: IOMUXC_SW_MUX_CTL_PAD_GPIO_EMC_40, value: 0x00, size: 4 */
	0x40, 0x1F, 0x80, 0xB4, 0x00, 0x00, 0x00, 0x00,
	/* #1.52, command: write_value, address: IOMUXC_SW_MUX_CTL_PAD_GPIO_EMC_41, value: 0x00, size: 4 */
	0x40, 0x1F, 0x80, 0xB8, 0x00, 0x00, 0x00, 0x00,
	/* #1.53, command: write_value, address: IOMUXC_SW_PAD_CTL_PAD_GPIO_EMC_00, value: 0x110F9, size: 4 */
	0x40, 0x1F, 0x82, 0x04, 0x00, 0x01, 0x10, 0xF9,
	/* #1.54, command: write_value, address: IOMUXC_SW_PAD_CTL_PAD_GPIO_EMC_01, value: 0x110F9, size: 4 */
	0x40, 0x1F, 0x82, 0x08, 0x00, 0x01, 0x10, 0xF9,
	/* #1.55, command: write_value, address: IOMUXC_SW_PAD_CTL_PAD_GPIO_EMC_02, value: 0x110F9, size: 4 */
	0x40, 0x1F, 0x82, 0x0C, 0x00, 0x01, 0x10, 0xF9,
	/* #1.56, command: write_value, address: IOMUXC_SW_PAD_CTL_PAD_GPIO_EMC_03, value: 0x110F9, size: 4 */
	0x40, 0x1F, 0x82, 0x10, 0x00, 0x01, 0x10, 0xF9,
	/* #1.57, command: write_value, address: IOMUXC_SW_PAD_CTL_PAD_GPIO_EMC_04, value: 0x110F9, size: 4 */
	0x40, 0x1F, 0x82, 0x14, 0x00, 0x01, 0x10, 0xF9,
	/* #1.58, command: write_value, address: IOMUXC_SW_PAD_CTL_PAD_GPIO_EMC_05, value: 0x110F9, size: 4 */
	0x40, 0x1F, 0x82, 0x18, 0x00, 0x01, 0x10, 0xF9,
	/* #1.59, command: write_value, address: IOMUXC_SW_PAD_CTL_PAD_GPIO_EMC_06, value: 0x110F9, size: 4 */
	0x40, 0x1F, 0x82, 0x1C, 0x00, 0x01, 0x10, 0xF9,
	/* #1.60, command: write_value, address: IOMUXC_SW_PAD_CTL_PAD_GPIO_EMC_07, value: 0x110F9, size: 4 */
	0x40, 0x1F, 0x82, 0x20, 0x00, 0x01, 0x10, 0xF9,
	/* #1.61, command: write_value, address: IOMUXC_SW_PAD_CTL_PAD_GPIO_EMC_08, value: 0x110F9, size: 4 */
	0x40, 0x1F, 0x82, 0x24, 0x00, 0x01, 0x10, 0xF9,
	/* #1.62, command: write_value, address: IOMUXC_SW_PAD_CTL_PAD_GPIO_EMC_09, value: 0x110F9, size: 4 */
	0x40, 0x1F, 0x82, 0x28, 0x00, 0x01, 0x10, 0xF9,
	/* #1.63, command: write_value, address: IOMUXC_SW_PAD_CTL_PAD_GPIO_EMC_10, value: 0x110F9, size: 4 */
	0x40, 0x1F, 0x82, 0x2C, 0x00, 0x01, 0x10, 0xF9,
	/* #1.64, command: write_value, address: IOMUXC_SW_PAD_CTL_PAD_GPIO_EMC_11, value: 0x110F9, size: 4 */
	0x40, 0x1F, 0x82, 0x30, 0x00, 0x01, 0x10, 0xF9,
	/* #1.65, command: write_value, address: IOMUXC_SW_PAD_CTL_PAD_GPIO_EMC_12, value: 0x110F9, size: 4 */
	0x40, 0x1F, 0x82, 0x34, 0x00, 0x01, 0x10, 0xF9,
	/* #1.66, command: write_value, address: IOMUXC_SW_PAD_CTL_PAD_GPIO_EMC_13, value: 0x110F9, size: 4 */
	0x40, 0x1F, 0x82, 0x38, 0x00, 0x01, 0x10, 0xF9,
	/* #1.67, command: write_value, address: IOMUXC_SW_PAD_CTL_PAD_GPIO_EMC_14, value: 0x110F9, size: 4 */
	0x40, 0x1F, 0x82, 0x3C, 0x00, 0x01, 0x10, 0xF9,
	/* #1.68, command: write_value, address: IOMUXC_SW_PAD_CTL_PAD_GPIO_EMC_15, value: 0x110F9, size: 4 */
	0x40, 0x1F, 0x82, 0x40, 0x00, 0x01, 0x10, 0xF9,
	/* #1.69, command: write_value, address: IOMUXC_SW_PAD_CTL_PAD_GPIO_EMC_16, value: 0x110F9, size: 4 */
	0x40, 0x1F, 0x82, 0x44, 0x00, 0x01, 0x10, 0xF9,
	/* #1.70, command: write_value, address: IOMUXC_SW_PAD_CTL_PAD_GPIO_EMC_17, value: 0x110F9, size: 4 */
	0x40, 0x1F, 0x82, 0x48, 0x00, 0x01, 0x10, 0xF9,
	/* #1.71, command: write_value, address: IOMUXC_SW_PAD_CTL_PAD_GPIO_EMC_18, value: 0x110F9, size: 4 */
	0x40, 0x1F, 0x82, 0x4C, 0x00, 0x01, 0x10, 0xF9,
	/* #1.72, command: write_value, address: IOMUXC_SW_PAD_CTL_PAD_GPIO_EMC_19, value: 0x110F9, size: 4 */
	0x40, 0x1F, 0x82, 0x50, 0x00, 0x01, 0x10, 0xF9,
	/* #1.73, command: write_value, address: IOMUXC_SW_PAD_CTL_PAD_GPIO_EMC_20, value: 0x110F9, size: 4 */
	0x40, 0x1F, 0x82, 0x54, 0x00, 0x01, 0x10, 0xF9,
	/* #1.74, command: write_value, address: IOMUXC_SW_PAD_CTL_PAD_GPIO_EMC_21, value: 0x110F9, size: 4 */
	0x40, 0x1F, 0x82, 0x58, 0x00, 0x01, 0x10, 0xF9,
	/* #1.75, command: write_value, address: IOMUXC_SW_PAD_CTL_PAD_GPIO_EMC_22, value: 0x110F9, size: 4 */
	0x40, 0x1F, 0x82, 0x5C, 0x00, 0x01, 0x10, 0xF9,
	/* #1.76, command: write_value, address: IOMUXC_SW_PAD_CTL_PAD_GPIO_EMC_23, value: 0x110F9, size: 4 */
	0x40, 0x1F, 0x82, 0x60, 0x00, 0x01, 0x10, 0xF9,
	/* #1.77, command: write_value, address: IOMUXC_SW_PAD_CTL_PAD_GPIO_EMC_24, value: 0x110F9, size: 4 */
	0x40, 0x1F, 0x82, 0x64, 0x00, 0x01, 0x10, 0xF9,
	/* #1.78, command: write_value, address: IOMUXC_SW_PAD_CTL_PAD_GPIO_EMC_25, value: 0x110F9, size: 4 */
	0x40, 0x1F, 0x82, 0x68, 0x00, 0x01, 0x10, 0xF9,
	/* #1.79, command: write_value, address: IOMUXC_SW_PAD_CTL_PAD_GPIO_EMC_26, value: 0x110F9, size: 4 */
	0x40, 0x1F, 0x82, 0x6C, 0x00, 0x01, 0x10, 0xF9,
	/* #1.80, command: write_value, address: IOMUXC_SW_PAD_CTL_PAD_GPIO_EMC_27, value: 0x110F9, size: 4 */
	0x40, 0x1F, 0x82, 0x70, 0x00, 0x01, 0x10, 0xF9,
	/* #1.81, command: write_value, address: IOMUXC_SW_PAD_CTL_PAD_GPIO_EMC_28, value: 0x110F9, size: 4 */
	0x40, 0x1F, 0x82, 0x74, 0x00, 0x01, 0x10, 0xF9,
	/* #1.82, command: write_value, address: IOMUXC_SW_PAD_CTL_PAD_GPIO_EMC_29, value: 0x110F9, size: 4 */
	0x40, 0x1F, 0x82, 0x78, 0x00, 0x01, 0x10, 0xF9,
	/* #1.83, command: write_value, address: IOMUXC_SW_PAD_CTL_PAD_GPIO_EMC_30, value: 0x110F9, size: 4 */
	0x40, 0x1F, 0x82, 0x7C, 0x00, 0x01, 0x10, 0xF9,
	/* #1.84, command: write_value, address: IOMUXC_SW_PAD_CTL_PAD_GPIO_EMC_31, value: 0x110F9, size: 4 */
	0x40, 0x1F, 0x82, 0x80, 0x00, 0x01, 0x10, 0xF9,
	/* #1.85, command: write_value, address: IOMUXC_SW_PAD_CTL_PAD_GPIO_EMC_32, value: 0x110F9, size: 4 */
	0x40, 0x1F, 0x82, 0x84, 0x00, 0x01, 0x10, 0xF9,
	/* #1.86, command: write_value, address: IOMUXC_SW_PAD_CTL_PAD_GPIO_EMC_33, value: 0x110F9, size: 4 */
	0x40, 0x1F, 0x82, 0x88, 0x00, 0x01, 0x10, 0xF9,
	/* #1.87, command: write_value, address: IOMUXC_SW_PAD_CTL_PAD_GPIO_EMC_34, value: 0x110F9, size: 4 */
	0x40, 0x1F, 0x82, 0x8C, 0x00, 0x01, 0x10, 0xF9,
	/* #1.88, command: write_value, address: IOMUXC_SW_PAD_CTL_PAD_GPIO_EMC_35, value: 0x110F9, size: 4 */
	0x40, 0x1F, 0x82, 0x90, 0x00, 0x01, 0x10, 0xF9,
	/* #1.89, command: write_value, address: IOMUXC_SW_PAD_CTL_PAD_GPIO_EMC_36, value: 0x110F9, size: 4 */
	0x40, 0x1F, 0x82, 0x94, 0x00, 0x01, 0x10, 0xF9,
	/* #1.90, command: write_value, address: IOMUXC_SW_PAD_CTL_PAD_GPIO_EMC_37, value: 0x110F9, size: 4 */
	0x40, 0x1F, 0x82, 0x98, 0x00, 0x01, 0x10, 0xF9,
	/* #1.91, command: write_value, address: IOMUXC_SW_PAD_CTL_PAD_GPIO_EMC_38, value: 0x110F9, size: 4 */
	0x40, 0x1F, 0x82, 0x9C, 0x00, 0x01, 0x10, 0xF9,
	/* #1.92, command: write_value, address: IOMUXC_SW_PAD_CTL_PAD_GPIO_EMC_39, value: 0x110F9, size: 4 */
	0x40, 0x1F, 0x82, 0xA0, 0x00, 0x01, 0x10, 0xF9,
	/* #1.93, command: write_value, address: IOMUXC_SW_PAD_CTL_PAD_GPIO_EMC_40, value: 0x110F9, size: 4 */
	0x40, 0x1F, 0x82, 0xA4, 0x00, 0x01, 0x10, 0xF9,
	/* #1.94, command: write_value, address: IOMUXC_SW_PAD_CTL_PAD_GPIO_EMC_41, value: 0x110F9, size: 4 */
	0x40, 0x1F, 0x82, 0xA8, 0x00, 0x01, 0x10, 0xF9,
	/* #1.95, command: write_value, address: SEMC_MCR, value: 0x10000004, size: 4 */
	0x40, 0x2F, 0x00, 0x00, 0x10, 0x00, 0x00, 0x04,
	/* #1.96, command: write_value, address: SEMC_BMCR0, value: 0x30524, size: 4 */
	0x40, 0x2F, 0x00, 0x08, 0x00, 0x03, 0x05, 0x24,
	/* #1.97, command: write_value, address: SEMC_BMCR1, value: 0x6030524, size: 4 */
	0x40, 0x2F, 0x00, 0x0C, 0x06, 0x03, 0x05, 0x24,
	/* #1.98, command: write_value, address: SEMC_BR0, value: 0x8000001B, size: 4 */
	0x40, 0x2F, 0x00, 0x10, 0x80, 0x00, 0x00, 0x1B,
	/* #1.99, command: write_value, address: SEMC_BR1, value: 0x8200001B, size: 4 */
	0x40, 0x2F, 0x00, 0x14, 0x82, 0x00, 0x00, 0x1B,
	/* #1.100, command: write_value, address: SEMC_BR2, value: 0x8400001B, size: 4 */
	0x40, 0x2F, 0x00, 0x18, 0x84, 0x00, 0x00, 0x1B,
	/* #1.101, command: write_value, address: SEMC_BR3, value: 0x8600001B, size: 4 */
	0x40, 0x2F, 0x00, 0x1C, 0x86, 0x00, 0x00, 0x1B,
	/* #1.102, command: write_value, address: SEMC_BR4, value: 0x90000021, size: 4 */
	0x40, 0x2F, 0x00, 0x20, 0x90, 0x00, 0x00, 0x21,
	/* #1.103, command: write_value, address: SEMC_BR5, value: 0xA0000019, size: 4 */
	0x40, 0x2F, 0x00, 0x24, 0xA0, 0x00, 0x00, 0x19,
	/* #1.104, command: write_value, address: SEMC_BR6, value: 0xA8000017, size: 4 */
	0x40, 0x2F, 0x00, 0x28, 0xA8, 0x00, 0x00, 0x17,
	/* #1.105, command: write_value, address: SEMC_BR7, value: 0xA900001B, size: 4 */
	0x40, 0x2F, 0x00, 0x2C, 0xA9, 0x00, 0x00, 0x1B,
	/* #1.106, command: write_value, address: SEMC_BR8, value: 0x21, size: 4 */
	0x40, 0x2F, 0x00, 0x30, 0x00, 0x00, 0x00, 0x21,
	/* #1.107, command: write_value, address: SEMC_IOCR, value: 0x79A8, size: 4 */
	0x40, 0x2F, 0x00, 0x04, 0x00, 0x00, 0x79, 0xA8,
	/* #1.108, command: write_value, address: SEMC_SDRAMCR0, value: 0xF31, size: 4 */
	0x40, 0x2F, 0x00, 0x40, 0x00, 0x00, 0x0F, 0x31,
	/* #1.109, command: write_value, address: SEMC_SDRAMCR1, value: 0x652922, size: 4 */
	0x40, 0x2F, 0x00, 0x44, 0x00, 0x65, 0x29, 0x22,
	/* #1.110, command: write_value, address: SEMC_SDRAMCR2, value: 0x10920, size: 4 */
	0x40, 0x2F, 0x00, 0x48, 0x00, 0x01, 0x09, 0x20,
	/* #1.111, command: write_value, address: SEMC_SDRAMCR3, value: 0x50210A08, size: 4 */
	0x40, 0x2F, 0x00, 0x4C, 0x50, 0x21, 0x0A, 0x08,
	/* #1.112, command: write_value, address: SEMC_DBICR0, value: 0x21, size: 4 */
	0x40, 0x2F, 0x00, 0x80, 0x00, 0x00, 0x00, 0x21,
	/* #1.113, command: write_value, address: SEMC_DBICR1, value: 0x888888, size: 4 */
	0x40, 0x2F, 0x00, 0x84, 0x00, 0x88, 0x88, 0x88,
	/* #1.114, command: write_value, address: SEMC_IPCR1, value: 0x02, size: 4 */
	0x40, 0x2F, 0x00, 0x94, 0x00, 0x00, 0x00, 0x02,
	/* #1.115, command: write_value, address: SEMC_IPCR2, value: 0x00, size: 4 */
	0x40, 0x2F, 0x00, 0x98, 0x00, 0x00, 0x00, 0x00,
	/* #1.116, command: write_value, address: SEMC_IPCR0, value: 0x80000000, size: 4 */
	0x40, 0x2F, 0x00, 0x90, 0x80, 0x00, 0x00, 0x00,
	/* #1.117, command: write_value, address: SEMC_IPCMD, value: 0xA55A000F, size: 4 */
	0x40, 0x2F, 0x00, 0x9C, 0xA5, 0x5A, 0x00, 0x0F,
	/* #2, command: check_any_bit_set, address: SEMC_INTR, value: 0x01, size: 4 */
	0xCF, 0x00, 0x0C, 0x1C, 0x40, 0x2F, 0x00, 0x3C, 0x00, 0x00, 0x00, 0x01,
	/* #3.1-2, command header bytes for merged 'Write - value' command */
	0xCC, 0x00, 0x14, 0x04,
	/* #3.1, command: write_value, address: SEMC_IPCR0, value: 0x80000000, size: 4 */
	0x40, 0x2F, 0x00, 0x90, 0x80, 0x00, 0x00, 0x00,
	/* #3.2, command: write_value, address: SEMC_IPCMD, value: 0xA55A000C, size: 4 */
	0x40, 0x2F, 0x00, 0x9C, 0xA5, 0x5A, 0x00, 0x0C,
	/* #4, command: check_any_bit_set, address: SEMC_INTR, value: 0x01, size: 4 */
	0xCF, 0x00, 0x0C, 0x1C, 0x40, 0x2F, 0x00, 0x3C, 0x00, 0x00, 0x00, 0x01,
	/* #5.1-2, command header bytes for merged 'Write - value' command */
	0xCC, 0x00, 0x14, 0x04,
	/* #5.1, command: write_value, address: SEMC_IPCR0, value: 0x80000000, size: 4 */
	0x40, 0x2F, 0x00, 0x90, 0x80, 0x00, 0x00, 0x00,
	/* #5.2, command: write_value, address: SEMC_IPCMD, value: 0xA55A000C, size: 4 */
	0x40, 0x2F, 0x00, 0x9C, 0xA5, 0x5A, 0x00, 0x0C,
	/* #6, command: check_any_bit_set, address: SEMC_INTR, value: 0x01, size: 4 */
	0xCF, 0x00, 0x0C, 0x1C, 0x40, 0x2F, 0x00, 0x3C, 0x00, 0x00, 0x00, 0x01,
	/* #7.1-3, command header bytes for merged 'Write - value' command */
	0xCC, 0x00, 0x1C, 0x04,
	/* #7.1, command: write_value, address: SEMC_IPTXDAT, value: 0x33, size: 4 */
	0x40, 0x2F, 0x00, 0xA0, 0x00, 0x00, 0x00, 0x33,
	/* #7.2, command: write_value, address: SEMC_IPCR0, value: 0x80000000, size: 4 */
	0x40, 0x2F, 0x00, 0x90, 0x80, 0x00, 0x00, 0x00,
	/* #7.3, command: write_value, address: SEMC_IPCMD, value: 0xA55A000A, size: 4 */
	0x40, 0x2F, 0x00, 0x9C, 0xA5, 0x5A, 0x00, 0x0A,
	/* #8, command: check_any_bit_set, address: SEMC_INTR, value: 0x01, size: 4 */
	0xCF, 0x00, 0x0C, 0x1C, 0x40, 0x2F, 0x00, 0x3C, 0x00, 0x00, 0x00, 0x01,
	/* #9, command: write_value, address: SEMC_SDRAMCR3, value: 0x50210A09, size: 4 */
	0xCC, 0x00, 0x0C, 0x04, 0x40, 0x2F, 0x00, 0x4C, 0x50, 0x21, 0x0A, 0x09};



__attribute__((section(".boot_hdr.boot_data")))
const BOOT_DATA_T boot_data = {
  FLASH_BASE,                 /* boot start location */
  BOARD_FLASH_SIZE,                 /* size */
  PLUGIN_FLAG,                /* Plugin flag*/
  0xFFFFFFFF  				  /* empty - extra data word */
};


__attribute__((section(".boot_hdr.ivt")))
const ivt image_vector_table = {
  IVT_HEADER,                         /* IVT Header */
  IMAGE_ENTRY_ADDRESS,                /* Image Entry Function */
  IVT_RSVD,                           /* Reserved = 0 */
  (uint32_t)dcd_data,              /* Address where DCD information is stored */
  (uint32_t)BOOT_DATA_ADDRESS,        /* Address where BOOT Data Structure is stored */
  (uint32_t)&image_vector_table,      /* Pointer to IVT Self (absolute address */
  (uint32_t)CSF_ADDRESS,              /* Address where CSF file is stored */
  IVT_RSVD                            /* Reserved = 0 */
};



__attribute__((section(".boot_hdr.conf")))
const flexspi_nor_config_t qspiflash_config = {
	.memConfig = {
		.tag              = FLEXSPI_CFG_BLK_TAG,
		.version          = FLEXSPI_CFG_BLK_VERSION,
		.readSampleClkSrc = kFlexSPIReadSampleClk_LoopbackFromDqsPad,
		.csHoldTime       = 3u,
		.csSetupTime      = 3u,
		// Enable DDR mode, Wordaddassable, Safe configuration, Differential clock
		.sflashPadType = kSerialFlash_4Pads,
		.serialClkFreq = kFlexSpiSerialClk_100MHz,
		.sflashA1Size  = 8u * 1024u * 1024u,
		.lookupTable = 	{
			// Read LUTs
			FLEXSPI_LUT_SEQ(CMD_SDR, FLEXSPI_1PAD, 0xEB, RADDR_SDR, FLEXSPI_4PAD, 0x18),
			FLEXSPI_LUT_SEQ(DUMMY_SDR, FLEXSPI_4PAD, 0x06, READ_SDR, FLEXSPI_4PAD, 0x04),
		},
	},

	.pageSize           = 256u,
	.sectorSize         = 4u * 1024u,
	.blockSize          = 256u * 1024u,
	.isUniformBlockSize = false,
    };


__attribute__ ((weak, section(".startup"))) void NMI_Handler(void) {
	SRC_GPR5 = 0xBADC0000;
	while(1) {}

}

__attribute__ ((weak, section(".startup"))) void HardFault_Handler(void) {
    SRC_GPR5 = 0xBADD0000;
	while(1) {}
}


//const uint32_t* keep_trick[] = {(uint32_t*)&qspiflash_config, (uint32_t*)&boot_data,(uint32_t*)&image_vector_table,(uint32_t*)&g_pfnVectors};
const uint32_t* keep_trick[] = {(uint32_t*) &g_pfnVectors};

#endif //ARDUINO_QUARTO

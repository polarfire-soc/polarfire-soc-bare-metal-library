/*******************************************************************************
 * Copyright 2020 Microchip Corporation.
 *
 * SPDX-License-Identifier: MIT
 *
 * This file contains system specific definitions for the PolarFire SoC MSS
 * Ethernet MAC device driver.
 * 
 * Note: This file is maintained in the driver source repository in the same
 *       folder as the driver source to keep them consistent but in the example
 *       repositories the working copy resides in the current boards
 *       platform_config/drivers/mss_mac folder and a reference copy is found in
 *       the platform/platform_config_reference/drivers/mss_mac folder.
 *
 */

#ifndef MICROSEMI__FIRMWARE__POLARFIRE_SOC_MSS_ETHERNET_MAC_DRIVER__1_7_103_CONFIGURATION_HEADER
#define MICROSEMI__FIRMWARE__POLARFIRE_SOC_MSS_ETHERNET_MAC_DRIVER__1_7_103_CONFIGURATION_HEADER

#define CORE_VENDOR "Microsemi"
#define CORE_LIBRARY "Firmware"
#define CORE_NAME "PolarFire_SoC_MSS_Ethernet_MAC_Driver"
#define CORE_VERSION "1.7.103"

/*
 * Define this macro to add support for high speed transmission for network
 * saturation testing. Not recommended for normal builds of the code as it may
 * cause some unexpected behaviour for normal operations.
 *
 * #define MSS_MAC_SPEED_TEST
 *
 * If using debug mode build, you might set the NDEBUG macro in the project
 * settings to reduce interrupt overhead when using this option.
 */

/* #define MSS_MAC_SPEED_TEST */

/*
 * Defines for OS and network stack specific support
 * Un-comment as necessary or define in project properties etc.
 */

/* #define USING_FREERTOS */
/* #define USING_LWIP */

/* Allowed PHY interface types: */

#define NULL_PHY                        (0x0001U) /* No PHY in connection, for example GEM0 and GEM1 connected via fabric */
#define GMII                            (0x0002U) /* Currently only on Aloe board */
#define TBI                             (0x0004U) /* G5 SoC Emulation Platform designs with TBI */
#define GMII_SGMII                      (0x0008U) /* G5 SoC Emulation Platform designs with SGMII to GMII conversion */
#define BASEX1000                       (0x0010U) /* Not currently available */
#define RGMII                           (0x0020U) /* Not currently available */
#define RMII                            (0x0040U) /* Not currently available */
#define SGMII                           (0x0080U) /* Not currently available */

/* Allowed PHY models: */

#define MSS_MAC_DEV_PHY_NULL            (0x0001U)
#define MSS_MAC_DEV_PHY_VSC8575         (0x0002U) /* Uses full VTSS API */
#define MSS_MAC_DEV_PHY_VSC8541         (0x0004U)
#define MSS_MAC_DEV_PHY_DP83867         (0x0008U)
#define MSS_MAC_DEV_PHY_VSC8575_LITE    (0x0010U) /* Uses Lite VTSS API */
#define MSS_MAC_DEV_PHY_VSC8662         (0x0020U)


/*
 * Defines for the different hardware configurations on the G5 SoC Emulation
 * Platform etc.
 *
 * Used to allow software configure GPIO etc, to support the appropriate
 * hardware configuration. Not strictly part of the driver but we manage them
 * here to keep things tidy.
 */

#define MSS_MAC_DESIGN_ALOE                     (0)  /* ALOE board from Sifive                                                             */
#define MSS_MAC_DESIGN_EMUL_GMII                (1)  /* G5 SoC Emulation Platform VSC8575 designs with GMII to SGMII bridge on GEM0        */
#define MSS_MAC_DESIGN_EMUL_TBI                 (2)  /* G5 SoC Emulation Platform VSC8575 designs with TBI to SGMII bridge on GEM0         */
#define MSS_MAC_DESIGN_EMUL_DUAL_INTERNAL       (3)  /* G5 SoC Emulation Platform Dual GEM design with loopback in fabric                  */
#define MSS_MAC_DESIGN_EMUL_TI_GMII             (4)  /* G5 SoC Emulation Platform DP83867 design with GMII to SGMII bridge                 */
#define MSS_MAC_DESIGN_EMUL_DUAL_EX_TI          (5)  /* G5 SoC Emulation Platform Dual GEM design with external TI PHY on GEM1 (GMII)      */
#define MSS_MAC_DESIGN_EMUL_DUAL_EX_VTS         (6)  /* G5 SoC Emulation Platform Dual GEM design with external Vitess PHY on GEM0 (GMII)  */
#define MSS_MAC_DESIGN_EMUL_GMII_GEM1           (7)  /* G5 SoC Emulation Platform VSC8575 designs with GMII to SGMII bridge on GEM 1       */
#define MSS_MAC_DESIGN_EMUL_DUAL_EXTERNAL       (8)  /* G5 SoC Emulation Platform Dual GEM design with GEM0 -> VSC, GEM1 -> TI (both GMII) */
#define MSS_MAC_DESIGN_EMUL_TBI_GEM1            (9)  /* G5 SoC Emulation Platform VSC8575 designs with TBI to SGMII bridge GEM1            */
#define MSS_MAC_DESIGN_EMUL_TBI_TI              (10) /* G5 SoC Emulation Platform DP83867 designs with TBI to SGMII bridge GEM0            */
#define MSS_MAC_DESIGN_EMUL_TBI_GEM1_TI         (11) /* G5 SoC Emulation Platform DP83867 designs with TBI to SGMII bridge GEM1            */
#define MSS_MAC_DESIGN_EMUL_GMII_LOCAL          (12) /* G5 SoC Emulation Platform VSC8575 design with GMII to SGMII bridge with local ints */
#define MSS_MAC_DESIGN_RENODE                   (13) /* Renode */
#define MSS_MAC_DESIGN_SVG_SGMII_GEM0           (14) /* Silicon validation board GEM0 */
#define MSS_MAC_DESIGN_SVG_SGMII_GEM1           (15) /* Silicon validation board GEM1 */
#define MSS_MAC_DESIGN_SVG_DUAL_GEM             (16) /* Silicon validation board both GEMS */
#define MSS_MAC_DESIGN_SVG_GMII_GEM0            (17) /* Silicon validation board GEM0 */
#define MSS_MAC_DESIGN_SVG_GMII_GEM1            (18) /* Silicon validation board GEM1 */
#define MSS_MAC_DESIGN_ICICLE_SGMII_GEM0        (19) /* Icicle board GEM0 */
#define MSS_MAC_DESIGN_ICICLE_SGMII_GEM1        (20) /* Icicle board GEM1 */
#define MSS_MAC_DESIGN_ICICLE_SGMII_GEMS        (21) /* Icicle board GEM0 and GEM1 */
#define MSS_MAC_DESIGN_ICICLE_STD_GEM0          (22) /* Icicle board GEM0 Standard Reference Design */
#define MSS_MAC_DESIGN_ICICLE_STD_GEM1          (23) /* Icicle board GEM1 Standard Reference Design */
#define MSS_MAC_DESIGN_ICICLE_STD_GEMS          (24) /* Icicle board GEM0 and GEM1 Standard Reference Design */
#define MSS_MAC_DESIGN_SVG_GMII_GEM0_SGMII_GEM1 (25) /* Silicon validation  board GEM0 (GMII) and GEM1 (SGMII) */
#define MSS_MAC_DESIGN_ICICLE_STD_GEM0_LOCAL    (26) /* Icicle board GEM0 Standard Reference Design - local interrupts on U54 2 */

#if defined(TARGET_ALOE)
#define MSS_MAC_PHY_INTERFACE GMII /* Only one option allowed here... */
#define MSS_MAC_RX_RING_SIZE (4U)
#define MSS_MAC_TX_RING_SIZE (2U)
#define MSS_MAC_PHYS (MSS_MAC_DEV_PHY_NULL | MSS_MAC_DEV_PHY_VSC8541)
#define MSS_MAC_HW_PLATFORM MSS_MAC_DESIGN_ALOE
#endif

/*
 * Define one of these macros if using the VSC8662 PHY recovered clock through
 * the NWC at 25MHZ or 125MHZ. You will need to configure the SGMII PLL Mux as
 * well.
 *
 * #define MSS_MAC_VSC8662_NWC_25
 * #define MSS_MAC_VSC8662_NWC_125
 *
 */

#if defined(TARGET_G5_SOC)
#define MSS_MAC_PHYS (MSS_MAC_DEV_PHY_NULL | MSS_MAC_DEV_PHY_VSC8575_LITE | MSS_MAC_DEV_PHY_DP83867 | MSS_MAC_DEV_PHY_VSC8662 | MSS_MAC_DEV_PHY_VSC8541)

#define MSS_MAC_HW_PLATFORM MSS_MAC_DESIGN_ICICLE_STD_GEM0_LOCAL
//#define MSS_MAC_HW_PLATFORM MSS_MAC_DESIGN_SVG_SGMII_GEM1
//#define MSS_MAC_HW_PLATFORM MSS_MAC_DESIGN_EMUL_DUAL_EX_VTS
/*
 *  Minimum size is 16 as the buffering implemented by our implementation of
 *  the GEM DMA requires that we make sure there are valid packet descriptors in
 *  all the buffer slots so we need to allocate 16.
 */
#define MSS_MAC_RX_RING_SIZE (16U)

/*
 *  The buffering implemented by our implementation of the GEM DMA requires that
 *  we make sure there are valid packet descriptors in all the buffer slots so
 *  we need to allocate at6 least 16.
 */
#if defined(MSS_MAC_SPEED_TEST)
#define MSS_MAC_TX_RING_SIZE (4001U)
#else
#define MSS_MAC_TX_RING_SIZE (16U)
#endif
#endif

#define MSS_MAC_USE_PHY_VSC8575      (0U != (MSS_MAC_PHYS & MSS_MAC_DEV_PHY_VSC8575))
#define MSS_MAC_USE_PHY_VSC8575_LITE (0U != (MSS_MAC_PHYS & MSS_MAC_DEV_PHY_VSC8575_LITE))
#define MSS_MAC_USE_PHY_VSC8541      (0U != (MSS_MAC_PHYS & MSS_MAC_DEV_PHY_VSC8541))
#define MSS_MAC_USE_PHY_DP83867      (0U != (MSS_MAC_PHYS & MSS_MAC_DEV_PHY_DP83867))
#define MSS_MAC_USE_PHY_NULL         (0U != (MSS_MAC_PHYS & MSS_MAC_DEV_PHY_NULL))
#define MSS_MAC_USE_PHY_VSC8662      (0U != (MSS_MAC_PHYS & MSS_MAC_DEV_PHY_VSC8662))

#if !defined(MSS_MAC_SPEED_TEST)
#define MSS_MAC_TIME_STAMPED_MODE      (0) /* Enable time stamp support */
#define MSS_MAC_64_BIT_ADDRESS_MODE    (0) /* Enable 64 bit addressing */
#endif

/*
 * Defines for different memory areas. Set the macro MSS_MAC_USE_DDR to one of
 * these values to select the area of memory and buffer sizes to use when
 * testing for non LIM based areas of memory.
 */

#define MSS_MAC_MEM_DDR    (0)
#define MSS_MAC_MEM_FIC0   (1)
#define MSS_MAC_MEM_FIC1   (2)
#define MSS_MAC_MEM_CRYPTO (3)

/*
 * Number of additional queues for PMAC.
 *
 * Note. We explicitly set the number of queues in the MAC structure as we have
 * to indicate the Interrupt Number so this is slightly artificial...
 */
#if defined(TARGET_ALOE)
#define MSS_MAC_QUEUE_COUNT (1)
#else
#if defined(MSS_MAC_SPEED_TEST)
#define MSS_MAC_QUEUE_COUNT (1)
#else
#define MSS_MAC_QUEUE_COUNT (4)
#endif
#endif


/*
 * Number of Type 1 and 2 screeners
 */

#define MSS_MAC_TYPE_1_SCREENERS  (4U)
#define MSS_MAC_TYPE_2_SCREENERS  (4U)
#define MSS_MAC_TYPE_2_ETHERTYPES (4U)
#define MSS_MAC_TYPE_2_COMPARERS  (4U)

/* These are hard coded and not user selectable */
#define MSS_MAC_EMAC_TYPE_2_SCREENERS  (2U)
#define MSS_MAC_EMAC_TYPE_2_COMPARERS  (6U)

/*
 * Define one or both of these macros to enable support for hardware based
 * Hard Reset or Soft Reset of the PHY. This will result in inclusion of the
 * MSS GPIO  driver in the project.
 */

/*
 * If this is defined, the hard reset of the PHY is controllable via GPIO.
 *
 * #define MSS_MAC_PHY_HW_RESET
 *
 */

/*
 * If this is defined, the soft reset of the PHY is controllable via GPIO.
 *
 * #define MSS_MAC_PHY_HW_SRESET
 *
 */

#endif /* MICROSEMI__FIRMWARE__POLARFIRE_SOC_MSS_ETHERNET_MAC_DRIVER__1_5_101_CONFIGURATION_HEADER */


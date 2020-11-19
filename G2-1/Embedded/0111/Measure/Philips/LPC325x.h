/******************************************************************************
 *   LPC325x.h:  Header file for Philips LPC325x Family Microprocessors
 *   The header file is the super set of all hardware definition of the 
 *   peripherals for the LPC325x family microprocessor.
 *
 *   Copyright(C) 2008, Philips Semiconductor
 *   All rights reserved.

 *   History
 *   2008.01.10  ver 1.00    Prelimnary version, first Release
 *
******************************************************************************/

#ifndef __LPC325x_H
#define __LPC325x_H


/* System Control */
#define SYSCTRL_BASE_ADDR	0x40004000
#define BOOT_MAP		(*(volatile unsigned long *)(SYSCTRL_BASE_ADDR + 0x14))

/* Clock and Power Control */
#define CLK_PM_BASE_ADDR	0x40004000
#define USB_DIV			(*(volatile unsigned long *)(CLK_PM_BASE_ADDR + 0x1C))
#define PWR_CTRL		(*(volatile unsigned long *)(CLK_PM_BASE_ADDR + 0x44))
#define OSC_CTRL		(*(volatile unsigned long *)(CLK_PM_BASE_ADDR + 0x4C))
#define SYSCLK_CTRL		(*(volatile unsigned long *)(CLK_PM_BASE_ADDR + 0x50))
#define PLL397_CTRL		(*(volatile unsigned long *)(CLK_PM_BASE_ADDR + 0x48))	
#define HCLKPLL_CTRL	(*(volatile unsigned long *)(CLK_PM_BASE_ADDR + 0x58))
#define HCLKDIV_CTRL	(*(volatile unsigned long *)(CLK_PM_BASE_ADDR + 0x40))
#define TEST_CLK		(*(volatile unsigned long *)(CLK_PM_BASE_ADDR + 0xA4))
#define AUTOCLK_CTRL	(*(volatile unsigned long *)(CLK_PM_BASE_ADDR + 0xEC))

#define START_ER_INT	(*(volatile unsigned long *)(CLK_PM_BASE_ADDR + 0x20))
#define START_ER_PIN	(*(volatile unsigned long *)(CLK_PM_BASE_ADDR + 0x30))
#define START_RSR_INT	(*(volatile unsigned long *)(CLK_PM_BASE_ADDR + 0x24))
#define START_RSR_PIN	(*(volatile unsigned long *)(CLK_PM_BASE_ADDR + 0x34))
#define START_SR_INT	(*(volatile unsigned long *)(CLK_PM_BASE_ADDR + 0x28))
#define START_SR_PIN	(*(volatile unsigned long *)(CLK_PM_BASE_ADDR + 0x38))
#define START_APR_INT	(*(volatile unsigned long *)(CLK_PM_BASE_ADDR + 0x2C))
#define START_APR_PIN	(*(volatile unsigned long *)(CLK_PM_BASE_ADDR + 0x3C))

#define USBCLK_CTRL		(*(volatile unsigned long *)(CLK_PM_BASE_ADDR + 0x64))
#define I2SCLK_CTRL		(*(volatile unsigned long *)(CLK_PM_BASE_ADDR + 0x7C))
#define MS_CTRL			(*(volatile unsigned long *)(CLK_PM_BASE_ADDR + 0x80))
#define MACCLK_CTRL		(*(volatile unsigned long *)(CLK_PM_BASE_ADDR + 0x90))
#define I2CCLK_CTRL		(*(volatile unsigned long *)(CLK_PM_BASE_ADDR + 0xAC))
#define KEYCLK_CTRL		(*(volatile unsigned long *)(CLK_PM_BASE_ADDR + 0xB0))
#define ADCLK_CTRL		(*(volatile unsigned long *)(CLK_PM_BASE_ADDR + 0xB4))
#define ADCLK_CTRL1		(*(volatile unsigned long *)(CLK_PM_BASE_ADDR + 0x60))
#define PWMCLK_CTRL		(*(volatile unsigned long *)(CLK_PM_BASE_ADDR + 0xB8))
#define TIMCLK_CTRL		(*(volatile unsigned long *)(CLK_PM_BASE_ADDR + 0xBC))
#define SPI_CTRL		(*(volatile unsigned long *)(CLK_PM_BASE_ADDR + 0xC4))
#define FLASHCLK_CTRL	(*(volatile unsigned long *)(CLK_PM_BASE_ADDR + 0xC8))
#define UARTCLK_CTRL	(*(volatile unsigned long *)(CLK_PM_BASE_ADDR + 0xE4))
#define DMACLK_CTRL		(*(volatile unsigned long *)(CLK_PM_BASE_ADDR + 0xE8))

/* SDRAM Control register */
#define SDRAM_CLK_BASE_ADDR	0x40004000
#define SDRAMCLK_CTRL	(*(volatile unsigned long *)(SDRAM_CLK_BASE_ADDR + 0x68))

#define SDRAM_BASE_ADDR		0x31080000
#define MPMCControl		(*(volatile unsigned long *)(SDRAM_BASE_ADDR + 0x00))
#define MPMCStatus		(*(volatile unsigned long *)(SDRAM_BASE_ADDR + 0x04))
#define MPMCConfig		(*(volatile unsigned long *)(SDRAM_BASE_ADDR + 0x08))
#define MPMCDynamicControl		(*(volatile unsigned long *)(SDRAM_BASE_ADDR + 0x20))
#define MPMCDynamicRefresh		(*(volatile unsigned long *)(SDRAM_BASE_ADDR + 0x24))
#define MPMCDynamicReadConfig	(*(volatile unsigned long *)(SDRAM_BASE_ADDR + 0x28))
#define MPMCDynamicRP	(*(volatile unsigned long *)(SDRAM_BASE_ADDR + 0x30))
#define MPMCDynamicRAS	(*(volatile unsigned long *)(SDRAM_BASE_ADDR + 0x34))
#define MPMCDynamicSREX	(*(volatile unsigned long *)(SDRAM_BASE_ADDR + 0x38))
#define MPMCDynamicWR	(*(volatile unsigned long *)(SDRAM_BASE_ADDR + 0x44))
#define MPMCDynamicRC	(*(volatile unsigned long *)(SDRAM_BASE_ADDR + 0x48))
#define MPMCDynamicRFC	(*(volatile unsigned long *)(SDRAM_BASE_ADDR + 0x4C))
#define MPMCDynamicXSR	(*(volatile unsigned long *)(SDRAM_BASE_ADDR + 0x50))
#define MPMCDynamicRRD	(*(volatile unsigned long *)(SDRAM_BASE_ADDR + 0x54))
#define MPMCDynamicMRD	(*(volatile unsigned long *)(SDRAM_BASE_ADDR + 0x58))
#define MPMCDynamicCDLR	(*(volatile unsigned long *)(SDRAM_BASE_ADDR + 0x5C))

#define MPMCDynamicConfig0	(*(volatile unsigned long *)(SDRAM_BASE_ADDR + 0x100))
#define MPMCDynamicRasCas0	(*(volatile unsigned long *)(SDRAM_BASE_ADDR + 0x104))

#define MPMCAHBControl0	(*(volatile unsigned long *)(SDRAM_BASE_ADDR + 0x400))
#define MPMCAHBStatus0	(*(volatile unsigned long *)(SDRAM_BASE_ADDR + 0x404))
#define MPMCAHBTimeout0	(*(volatile unsigned long *)(SDRAM_BASE_ADDR + 0x408))

#define MPMCAHBControl2	(*(volatile unsigned long *)(SDRAM_BASE_ADDR + 0x440))
#define MPMCAHBStatus2	(*(volatile unsigned long *)(SDRAM_BASE_ADDR + 0x444))
#define MPMCAHBTimeout2	(*(volatile unsigned long *)(SDRAM_BASE_ADDR + 0x448))

#define MPMCAHBControl3	(*(volatile unsigned long *)(SDRAM_BASE_ADDR + 0x460))
#define MPMCAHBStatus3	(*(volatile unsigned long *)(SDRAM_BASE_ADDR + 0x464))
#define MPMCAHBTimeout3	(*(volatile unsigned long *)(SDRAM_BASE_ADDR + 0x468))

#define MPMCAHBControl4	(*(volatile unsigned long *)(SDRAM_BASE_ADDR + 0x480))
#define MPMCAHBStatus4	(*(volatile unsigned long *)(SDRAM_BASE_ADDR + 0x484))
#define MPMCAHBTimeout4	(*(volatile unsigned long *)(SDRAM_BASE_ADDR + 0x488))

#define DDR_BASE_ADDR	0x40004000
#define DDR_LAP_NOM		(*(volatile unsigned long *)(DDR_BASE_ADDR + 0x6C))
#define DDR_LAP_COUNT	(*(volatile unsigned long *)(DDR_BASE_ADDR + 0x70))
#define DDR_CAL_DELAY	(*(volatile unsigned long *)(DDR_BASE_ADDR + 0x74))
#define RINGOSC_CTRL	(*(volatile unsigned long *)(DDR_BASE_ADDR + 0x88))

/* Serial ID */
#define SERIAL_ID_BASE_ADDR 0x40004130
#define SERIAL_ID0  (*(volatile unsigned long *)(SERIAL_ID_BASE_ADDR + 0x00))
#define SERIAL_ID1  (*(volatile unsigned long *)(SERIAL_ID_BASE_ADDR + 0x04))
#define SERIAL_ID2  (*(volatile unsigned long *)(SERIAL_ID_BASE_ADDR + 0x08))
#define SERIAL_ID3  (*(volatile unsigned long *)(SERIAL_ID_BASE_ADDR + 0x0C))

/* Interrupt Controller */
#define MIC_BASE_ADDR	0x40008000
#define MIC_ER		(*(volatile unsigned long *)(MIC_BASE_ADDR + 0x00))
#define MIC_RSR		(*(volatile unsigned long *)(MIC_BASE_ADDR + 0x04))
#define MIC_SR		(*(volatile unsigned long *)(MIC_BASE_ADDR + 0x08))
#define MIC_APR		(*(volatile unsigned long *)(MIC_BASE_ADDR + 0x0C))	
#define MIC_ATR		(*(volatile unsigned long *)(MIC_BASE_ADDR + 0x10))
#define MIC_ITR		(*(volatile unsigned long *)(MIC_BASE_ADDR + 0x14))

#define SIC1_BASE_ADDR	0x4000C000
#define SIC1_ER		(*(volatile unsigned long *)(SIC1_BASE_ADDR + 0x00))
#define SIC1_RSR		(*(volatile unsigned long *)(SIC1_BASE_ADDR + 0x04))
#define SIC1_SR		(*(volatile unsigned long *)(SIC1_BASE_ADDR + 0x08))
#define SIC1_APR		(*(volatile unsigned long *)(SIC1_BASE_ADDR + 0x0C))
#define SIC1_ATR		(*(volatile unsigned long *)(SIC1_BASE_ADDR + 0x10))
#define SIC1_ITR		(*(volatile unsigned long *)(SIC1_BASE_ADDR + 0x14))

#define SIC2_BASE_ADDR	0x40010000
#define SIC2_ER		(*(volatile unsigned long *)(SIC2_BASE_ADDR + 0x00))
#define SIC2_RSR		(*(volatile unsigned long *)(SIC2_BASE_ADDR + 0x04))
#define SIC2_SR		(*(volatile unsigned long *)(SIC2_BASE_ADDR + 0x08))
#define SIC2_APR		(*(volatile unsigned long *)(SIC2_BASE_ADDR + 0x0C))
#define SIC2_ATR		(*(volatile unsigned long *)(SIC2_BASE_ADDR + 0x10))
#define SIC2_ITR		(*(volatile unsigned long *)(SIC2_BASE_ADDR + 0x14))

#define SWI_BASE_ADDR	0x40004000
#define SW_INT		(*(volatile unsigned long *)(SWI_BASE_ADDR + 0xA8))

/* Multiple level NAND Flash */
#define MLC_BUFF_ADDR	0x200A8000
#define MLC_BUFF		(*(volatile unsigned long *)(MLC_BUFF_ADDR + 0x0000))
#define MLC_DATA		(*(volatile unsigned long *)(MLC_BUFF_ADDR + 0x8000))

#define MLC_BASE_ADDR	0x200B8000
#define MLC_CMD			(*(volatile unsigned long *)(MLC_BASE_ADDR + 0x00))
#define MLC_ADDR		(*(volatile unsigned long *)(MLC_BASE_ADDR + 0x04))
#define MLC_ECC_ENC_REG	(*(volatile unsigned long *)(MLC_BASE_ADDR + 0x08))
#define MLC_ECC_DEC_REG	(*(volatile unsigned long *)(MLC_BASE_ADDR + 0x0C))
#define MLC_ECC_AUTO_ENC_REG	(*(volatile unsigned long *)(MLC_BASE_ADDR + 0x10))
#define MLC_ECC_AUTO_DEC_REG	(*(volatile unsigned long *)(MLC_BASE_ADDR + 0x14))
#define MLC_RPR		(*(volatile unsigned long *)(MLC_BASE_ADDR + 0x18))
#define MLC_WPR		(*(volatile unsigned long *)(MLC_BASE_ADDR + 0x1C))
#define MLC_RUBP	(*(volatile unsigned long *)(MLC_BASE_ADDR + 0x20))
#define MLC_ROBP	(*(volatile unsigned long *)(MLC_BASE_ADDR + 0x24))
#define MLC_SW_WP_ADD_LOW	(*(volatile unsigned long *)(MLC_BASE_ADDR + 0x28))
#define MLC_SW_WP_ADD_HIG	(*(volatile unsigned long *)(MLC_BASE_ADDR + 0x2C))
#define MLC_ICR			(*(volatile unsigned long *)(MLC_BASE_ADDR + 0x30))
#define MLC_TIME_REG	(*(volatile unsigned long *)(MLC_BASE_ADDR + 0x34))
#define MLC_IRQ_MR	(*(volatile unsigned long *)(MLC_BASE_ADDR + 0x38))
#define MLC_IRQ_SR	(*(volatile unsigned long *)(MLC_BASE_ADDR + 0x3C))
#define MLC_LOCK_PR	(*(volatile unsigned long *)(MLC_BASE_ADDR + 0x44))
#define MLC_ISR		(*(volatile unsigned long *)(MLC_BASE_ADDR + 0x48))
#define MLC_CEH		(*(volatile unsigned long *)(MLC_BASE_ADDR + 0x4C))

/* Single level NAND Flash */
#define SLC_BASE_ADDR	0x20020000
#define SLC_DATA	(*(volatile unsigned long *)(SLC_BASE_ADDR + 0x00))
#define SLC_ADDR	(*(volatile unsigned long *)(SLC_BASE_ADDR + 0x04))
#define SLC_CMD		(*(volatile unsigned long *)(SLC_BASE_ADDR + 0x08))
#define SLC_STOP	(*(volatile unsigned long *)(SLC_BASE_ADDR + 0x0C))
#define SLC_CTRL	(*(volatile unsigned long *)(SLC_BASE_ADDR + 0x10))
#define SLC_CFG		(*(volatile unsigned long *)(SLC_BASE_ADDR + 0x14))
#define SLC_STAT	(*(volatile unsigned long *)(SLC_BASE_ADDR + 0x18))
#define SLC_INT_STAT	(*(volatile unsigned long *)(SLC_BASE_ADDR + 0x1C))
#define SLC_IEN		(*(volatile unsigned long *)(SLC_BASE_ADDR + 0x20))
#define SLC_ISR		(*(volatile unsigned long *)(SLC_BASE_ADDR + 0x24))
#define SLC_ICR		(*(volatile unsigned long *)(SLC_BASE_ADDR + 0x28))
#define SLC_TAC		(*(volatile unsigned long *)(SLC_BASE_ADDR + 0x2C))
#define SLC_TC		(*(volatile unsigned long *)(SLC_BASE_ADDR + 0x30))
#define SLC_ECC		(*(volatile unsigned long *)(SLC_BASE_ADDR + 0x34))
#define SLC_DMA_DATA	(*(volatile unsigned long *)(SLC_BASE_ADDR + 0x38))

/* GPIOs */
#define GPIO_BASE_ADDR	0x40028000
#define P0_INP_STATE	(*(volatile unsigned long *)(GPIO_BASE_ADDR + 0x40))
#define P0_OUTP_SET		(*(volatile unsigned long *)(GPIO_BASE_ADDR + 0x44))
#define P0_OUTP_CLR		(*(volatile unsigned long *)(GPIO_BASE_ADDR + 0x48))
#define P0_OUTP_STATE	(*(volatile unsigned long *)(GPIO_BASE_ADDR + 0x4C))
#define P0_DIR_SET		(*(volatile unsigned long *)(GPIO_BASE_ADDR + 0x50))
#define P0_DIR_CLR		(*(volatile unsigned long *)(GPIO_BASE_ADDR + 0x54))
#define P0_DIR_STATE	(*(volatile unsigned long *)(GPIO_BASE_ADDR + 0x58))

#define P1_INP_STATE	(*(volatile unsigned long *)(GPIO_BASE_ADDR + 0x60))
#define P1_OUTP_SET		(*(volatile unsigned long *)(GPIO_BASE_ADDR + 0x64))
#define P1_OUTP_CLR		(*(volatile unsigned long *)(GPIO_BASE_ADDR + 0x68))
#define P1_OUTP_STATE	(*(volatile unsigned long *)(GPIO_BASE_ADDR + 0x6C))
#define P1_DIR_SET		(*(volatile unsigned long *)(GPIO_BASE_ADDR + 0x70))
#define P1_DIR_CLR		(*(volatile unsigned long *)(GPIO_BASE_ADDR + 0x74))
#define P1_DIR_STATE	(*(volatile unsigned long *)(GPIO_BASE_ADDR + 0x78))

#define P2_INP_STATE	(*(volatile unsigned long *)(GPIO_BASE_ADDR + 0x1C))
#define P2_OUTP_SET		(*(volatile unsigned long *)(GPIO_BASE_ADDR + 0x20))
#define P2_OUTP_CLR		(*(volatile unsigned long *)(GPIO_BASE_ADDR + 0x24))

#define P2_DIR_SET		(*(volatile unsigned long *)(GPIO_BASE_ADDR + 0x10))
#define P2_DIR_CLR		(*(volatile unsigned long *)(GPIO_BASE_ADDR + 0x14))
#define P2_DIR_STATE	(*(volatile unsigned long *)(GPIO_BASE_ADDR + 0x18))

#define P3_INP_STATE	(*(volatile unsigned long *)(GPIO_BASE_ADDR + 0x00))
#define P3_OUTP_SET		(*(volatile unsigned long *)(GPIO_BASE_ADDR + 0x04))
#define P3_OUTP_CLR		(*(volatile unsigned long *)(GPIO_BASE_ADDR + 0x08))
#define P3_OUTP_STATE	(*(volatile unsigned long *)(GPIO_BASE_ADDR + 0x0C))

/* peripheral multiplexer */
#define P_MUX_SET		(*(volatile unsigned long *)(GPIO_BASE_ADDR + 0x100))
#define P_MUX_CLR		(*(volatile unsigned long *)(GPIO_BASE_ADDR + 0x104))
#define P_MUX_STATE		(*(volatile unsigned long *)(GPIO_BASE_ADDR + 0x108))

#define P0_MUX_SET		(*(volatile unsigned long *)(GPIO_BASE_ADDR + 0x120))
#define P0_MUX_CLR		(*(volatile unsigned long *)(GPIO_BASE_ADDR + 0x124))
#define P0_MUX_STATE	(*(volatile unsigned long *)(GPIO_BASE_ADDR + 0x128))

#define P1_MUX_SET		(*(volatile unsigned long *)(GPIO_BASE_ADDR + 0x130))
#define P1_MUX_CLR		(*(volatile unsigned long *)(GPIO_BASE_ADDR + 0x134))
#define P1_MUX_STATE	(*(volatile unsigned long *)(GPIO_BASE_ADDR + 0x138))

#define P2_MUX_SET		(*(volatile unsigned long *)(GPIO_BASE_ADDR + 0x28))
#define P2_MUX_CLR		(*(volatile unsigned long *)(GPIO_BASE_ADDR + 0x2C))
#define P2_MUX_STATE	(*(volatile unsigned long *)(GPIO_BASE_ADDR + 0x30))

#define P3_MUX_SET		(*(volatile unsigned long *)(GPIO_BASE_ADDR + 0x110))
#define P3_MUX_CLR		(*(volatile unsigned long *)(GPIO_BASE_ADDR + 0x114))
#define P3_MUX_STATE	(*(volatile unsigned long *)(GPIO_BASE_ADDR + 0x118))

/* USB Device */
#define USB_BASE_ADDR	0x31020200
/* Device Interrupt Registers */
#define DEV_INT_STAT	(*(volatile unsigned long *)(USB_BASE_ADDR + 0x00))
#define DEV_INT_EN		(*(volatile unsigned long *)(USB_BASE_ADDR + 0x04))
#define DEV_INT_CLR		(*(volatile unsigned long *)(USB_BASE_ADDR + 0x08))
#define DEV_INT_SET		(*(volatile unsigned long *)(USB_BASE_ADDR + 0x0C))
#define DEV_INT_PRIO	(*(volatile unsigned long *)(USB_BASE_ADDR + 0x2C))

/* Endpoint Interrupt Registers */
#define EP_INT_STAT	(*(volatile unsigned long *)(USB_BASE_ADDR + 0x30))
#define EP_INT_EN	(*(volatile unsigned long *)(USB_BASE_ADDR + 0x34))
#define EP_INT_CLR	(*(volatile unsigned long *)(USB_BASE_ADDR + 0x38))
#define EP_INT_SET	(*(volatile unsigned long *)(USB_BASE_ADDR + 0x3C))
#define EP_INT_PRIO	(*(volatile unsigned long *)(USB_BASE_ADDR + 0x40))

/* Endpoint Realization Registers */
#define REALIZE_EP		(*(volatile unsigned long *)(USB_BASE_ADDR + 0x44))
#define EP_INDEX		(*(volatile unsigned long *)(USB_BASE_ADDR + 0x48))
#define MAXPACKET_SIZE	(*(volatile unsigned long *)(USB_BASE_ADDR + 0x4C))

/* Command Reagisters */
#define CMD_CODE	(*(volatile unsigned long *)(USB_BASE_ADDR + 0x10))
#define CMD_DATA	(*(volatile unsigned long *)(USB_BASE_ADDR + 0x14))

/* Data Transfer Registers */
#define RX_DATA		(*(volatile unsigned long *)(USB_BASE_ADDR + 0x18))
#define TX_DATA		(*(volatile unsigned long *)(USB_BASE_ADDR + 0x1C))
#define RX_PLENGTH	(*(volatile unsigned long *)(USB_BASE_ADDR + 0x20))
#define TX_PLENGTH	(*(volatile unsigned long *)(USB_BASE_ADDR + 0x24))
#define USB_CTRL	(*(volatile unsigned long *)(USB_BASE_ADDR + 0x28))

/* System Register */
#define DC_REVISION	(*(volatile unsigned long *)(USB_BASE_ADDR + 0x7C))

/* DMA Registers */
#define DMA_REQ_STAT	(*(volatile unsigned long *)(USB_BASE_ADDR + 0x50))
#define DMA_REQ_CLR		(*(volatile unsigned long *)(USB_BASE_ADDR + 0x54))
#define DMA_REQ_SET		(*(volatile unsigned long *)(USB_BASE_ADDR + 0x58))
#define UDCA_HEAD		(*(volatile unsigned long *)(USB_BASE_ADDR + 0x80))
#define EP_DMA_STAT		(*(volatile unsigned long *)(USB_BASE_ADDR + 0x84))
#define EP_DMA_EN		(*(volatile unsigned long *)(USB_BASE_ADDR + 0x88))
#define EP_DMA_DIS		(*(volatile unsigned long *)(USB_BASE_ADDR + 0x8C))
#define DMA_INT_STAT	(*(volatile unsigned long *)(USB_BASE_ADDR + 0x90))
#define DMA_INT_EN		(*(volatile unsigned long *)(USB_BASE_ADDR + 0x94))
#define EOT_INT_STAT	(*(volatile unsigned long *)(USB_BASE_ADDR + 0xA0))
#define EOT_INT_CLR		(*(volatile unsigned long *)(USB_BASE_ADDR + 0xA4))
#define EOT_INT_SET		(*(volatile unsigned long *)(USB_BASE_ADDR + 0xA8))
#define NDD_REQ_INT_STAT	(*(volatile unsigned long *)(USB_BASE_ADDR + 0xAC))
#define NDD_REQ_INT_CLR		(*(volatile unsigned long *)(USB_BASE_ADDR + 0xB0))
#define NDD_REQ_INT_SET		(*(volatile unsigned long *)(USB_BASE_ADDR + 0xB4))
#define SYS_ERR_INT_STAT	(*(volatile unsigned long *)(USB_BASE_ADDR + 0xB8))
#define SYS_ERR_INT_CLR		(*(volatile unsigned long *)(USB_BASE_ADDR + 0xBC))
#define SYS_ERR_INT_SET		(*(volatile unsigned long *)(USB_BASE_ADDR + 0xC0))
#define MODULE_ID			(*(volatile unsigned long *)(USB_BASE_ADDR + 0xFC))


/* USB Host Registers */
#define USBHC_BASE_ADDR		0x31020000
#define HC_REVISION         (*(volatile unsigned long *)(USBHC_BASE_ADDR + 0x00))
#define HC_CONTROL          (*(volatile unsigned long *)(USBHC_BASE_ADDR + 0x04))
#define HC_CMD_STAT         (*(volatile unsigned long *)(USBHC_BASE_ADDR + 0x08))
#define HC_INT_STAT         (*(volatile unsigned long *)(USBHC_BASE_ADDR + 0x0C))
#define HC_INT_EN           (*(volatile unsigned long *)(USBHC_BASE_ADDR + 0x10))
#define HC_INT_DIS          (*(volatile unsigned long *)(USBHC_BASE_ADDR + 0x14))
#define HC_HCCA             (*(volatile unsigned long *)(USBHC_BASE_ADDR + 0x18))
#define HC_PERIOD_CUR_ED    (*(volatile unsigned long *)(USBHC_BASE_ADDR + 0x1C))
#define HC_CTRL_HEAD_ED     (*(volatile unsigned long *)(USBHC_BASE_ADDR + 0x20))
#define HC_CTRL_CUR_ED      (*(volatile unsigned long *)(USBHC_BASE_ADDR + 0x24))
#define HC_BULK_HEAD_ED     (*(volatile unsigned long *)(USBHC_BASE_ADDR + 0x28))
#define HC_BULK_CUR_ED      (*(volatile unsigned long *)(USBHC_BASE_ADDR + 0x2C))
#define HC_DONE_HEAD        (*(volatile unsigned long *)(USBHC_BASE_ADDR + 0x30))
#define HC_FM_INTERVAL      (*(volatile unsigned long *)(USBHC_BASE_ADDR + 0x34))
#define HC_FM_REMAINING     (*(volatile unsigned long *)(USBHC_BASE_ADDR + 0x38))
#define HC_FM_NUMBER        (*(volatile unsigned long *)(USBHC_BASE_ADDR + 0x3C))
#define HC_PERIOD_START     (*(volatile unsigned long *)(USBHC_BASE_ADDR + 0x40))
#define HC_LS_THRHLD        (*(volatile unsigned long *)(USBHC_BASE_ADDR + 0x44))
#define HC_RH_DESCA         (*(volatile unsigned long *)(USBHC_BASE_ADDR + 0x48))
#define HC_RH_DESCB         (*(volatile unsigned long *)(USBHC_BASE_ADDR + 0x4C))
#define HC_RH_STAT          (*(volatile unsigned long *)(USBHC_BASE_ADDR + 0x50))
#define HC_RH_PORT_STAT1    (*(volatile unsigned long *)(USBHC_BASE_ADDR + 0x54))
#define HC_RH_PORT_STAT2    (*(volatile unsigned long *)(USBHC_BASE_ADDR + 0x58))

#if 0
/* USB Host Controller */
#define USBH_BASE_ADDR	0x31020000
#define HcRevision			(*(volatile unsigned long *)(USBH_BASE_ADDR + 0x00))
#define HcControl			(*(volatile unsigned long *)(USBH_BASE_ADDR + 0x04))
#define HcCommandStatus		(*(volatile unsigned long *)(USBH_BASE_ADDR + 0x08))
#define HcInterruptStatus	(*(volatile unsigned long *)(USBH_BASE_ADDR + 0x0C))
#define HcInterruptEnable	(*(volatile unsigned long *)(USBH_BASE_ADDR + 0x10))
#define HcInterruptDisable	(*(volatile unsigned long *)(USBH_BASE_ADDR + 0x14))
#define HcHCCA				(*(volatile unsigned long *)(USBH_BASE_ADDR + 0x18))
#define HcPeriodCurrentED	(*(volatile unsigned long *)(USBH_BASE_ADDR + 0x1C))
#define HcControlHeadED		(*(volatile unsigned long *)(USBH_BASE_ADDR + 0x20))
#define HcControlCurrentED	(*(volatile unsigned long *)(USBH_BASE_ADDR + 0x24))
#define HcBulkHeadED		(*(volatile unsigned long *)(USBH_BASE_ADDR + 0x28))
#define HcBulkCurrentED		(*(volatile unsigned long *)(USBH_BASE_ADDR + 0x2C))
#define HcDoneHead			(*(volatile unsigned long *)(USBH_BASE_ADDR + 0x30))
#define HcFmInterval		(*(volatile unsigned long *)(USBH_BASE_ADDR + 0x34))
#define HcFmRemaining		(*(volatile unsigned long *)(USBH_BASE_ADDR + 0x38))
#define HcFmNumber			(*(volatile unsigned long *)(USBH_BASE_ADDR + 0x3C))
#define HcPeriodicStart		(*(volatile unsigned long *)(USBH_BASE_ADDR + 0x40))
#define HcLSThreshold		(*(volatile unsigned long *)(USBH_BASE_ADDR + 0x44))
#define HcRhDescriptorA		(*(volatile unsigned long *)(USBH_BASE_ADDR + 0x48))
#define HcRhDescriptorB		(*(volatile unsigned long *)(USBH_BASE_ADDR + 0x4C))
#define HcRhStatus			(*(volatile unsigned long *)(USBH_BASE_ADDR + 0x50))
#define HcRhPortStatus1		(*(volatile unsigned long *)(USBH_BASE_ADDR + 0x54))
#define HcRhPortStatus2		(*(volatile unsigned long *)(USBH_BASE_ADDR + 0x58))
#define HcModuleID			(*(volatile unsigned long *)(USBH_BASE_ADDR + 0x5C))
#endif

/* USB OTG Controller */
#define USBOTG_BASE_ADDR	0x31020000
#define OTG_INT_STAT        (*(volatile unsigned long *)(USBOTG_BASE_ADDR + 0x100))
#define OTG_INT_EN          (*(volatile unsigned long *)(USBOTG_BASE_ADDR + 0x104))
#define OTG_INT_SET         (*(volatile unsigned long *)(USBOTG_BASE_ADDR + 0x108))
#define OTG_INT_CLR         (*(volatile unsigned long *)(USBOTG_BASE_ADDR + 0x10C))
#define OTG_STAT_CTRL       (*(volatile unsigned long *)(USBOTG_BASE_ADDR + 0x110))
#define OTG_TIMER           (*(volatile unsigned long *)(USBOTG_BASE_ADDR + 0x114))

#define OTG_I2C_RX          (*(volatile unsigned long *)(USBOTG_BASE_ADDR + 0x300))
#define OTG_I2C_TX          (*(volatile unsigned long *)(USBOTG_BASE_ADDR + 0x300))
#define OTG_I2C_STS         (*(volatile unsigned long *)(USBOTG_BASE_ADDR + 0x304))
#define OTG_I2C_CTL         (*(volatile unsigned long *)(USBOTG_BASE_ADDR + 0x308))
#define OTG_I2C_CLKHI       (*(volatile unsigned long *)(USBOTG_BASE_ADDR + 0x30C))
#define OTG_I2C_CLKLO       (*(volatile unsigned long *)(USBOTG_BASE_ADDR + 0x310))

#define OTG_CLK_CTRL        (*(volatile unsigned long *)(USBOTG_BASE_ADDR + 0xFF4))
#define OTG_CLK_STAT        (*(volatile unsigned long *)(USBOTG_BASE_ADDR + 0xFF8))

/* Below are redundant names as the original driver souce uses the different name 
convention for LPC24xx */
/* USB OTG */
#define OTG_int_status	(*(volatile unsigned long *)(USBOTG_BASE_ADDR + 0x100))
#define OTG_int_enable	(*(volatile unsigned long *)(USBOTG_BASE_ADDR + 0x104))
#define OTG_int_set		(*(volatile unsigned long *)(USBOTG_BASE_ADDR + 0x108))
#define OTG_int_clear	(*(volatile unsigned long *)(USBOTG_BASE_ADDR + 0x10C))
#define OTG_status_ctrl	(*(volatile unsigned long *)(USBOTG_BASE_ADDR + 0x110))
#define OTG_timer		(*(volatile unsigned long *)(USBOTG_BASE_ADDR + 0x114))

/* USB OTG I2C register */
#define I2C_RX			(*(volatile unsigned long *)(USBOTG_BASE_ADDR + 0x300))
#define I2C_TX			(*(volatile unsigned long *)(USBOTG_BASE_ADDR + 0x300))
#define I2C_STS			(*(volatile unsigned long *)(USBOTG_BASE_ADDR + 0x304))
#define I2C_CTRL		(*(volatile unsigned long *)(USBOTG_BASE_ADDR + 0x308))
#define I2C_CLKH		(*(volatile unsigned long *)(USBOTG_BASE_ADDR + 0x30C))
#define I2C_CLKL		(*(volatile unsigned long *)(USBOTG_BASE_ADDR + 0x310))

/* OTG clock control registers */
#define OTG_clock_control	(*(volatile unsigned long *)(USBOTG_BASE_ADDR + 0xFF4))
#define OTG_clock_status	(*(volatile unsigned long *)(USBOTG_BASE_ADDR + 0xFF8))
#define OTG_module_id		(*(volatile unsigned long *)(USBOTG_BASE_ADDR + 0xFFC))

							
/* Universal Asynchronous Receiver Transmitter (Standard UART3,4,5,6) */
#define UART3_BASE_ADDR		0x40080000
#define U3RBR          (*(volatile unsigned long *)(UART3_BASE_ADDR + 0x00))
#define U3THR          (*(volatile unsigned long *)(UART3_BASE_ADDR + 0x00))
#define U3DLL          (*(volatile unsigned long *)(UART3_BASE_ADDR + 0x00))
#define U3DLM          (*(volatile unsigned long *)(UART3_BASE_ADDR + 0x04))
#define U3IER          (*(volatile unsigned long *)(UART3_BASE_ADDR + 0x04))
#define U3IIR          (*(volatile unsigned long *)(UART3_BASE_ADDR + 0x08))
#define U3FCR          (*(volatile unsigned long *)(UART3_BASE_ADDR + 0x08))
#define U3LCR          (*(volatile unsigned long *)(UART3_BASE_ADDR + 0x0C))
#define U3LSR          (*(volatile unsigned long *)(UART3_BASE_ADDR + 0x14))
#define U3RXLEV        (*(volatile unsigned long *)(UART3_BASE_ADDR + 0x1C))

#define UART4_BASE_ADDR		0x40088000
#define U4RBR          (*(volatile unsigned long *)(UART4_BASE_ADDR + 0x00))
#define U4THR          (*(volatile unsigned long *)(UART4_BASE_ADDR + 0x00))
#define U4DLL          (*(volatile unsigned long *)(UART4_BASE_ADDR + 0x00))
#define U4DLM          (*(volatile unsigned long *)(UART4_BASE_ADDR + 0x04))
#define U4IER          (*(volatile unsigned long *)(UART4_BASE_ADDR + 0x04))
#define U4IIR          (*(volatile unsigned long *)(UART4_BASE_ADDR + 0x08))
#define U4FCR          (*(volatile unsigned long *)(UART4_BASE_ADDR + 0x08))
#define U4LCR          (*(volatile unsigned long *)(UART4_BASE_ADDR + 0x0C))
#define U4LSR          (*(volatile unsigned long *)(UART4_BASE_ADDR + 0x14))
#define U4RXLEV        (*(volatile unsigned long *)(UART4_BASE_ADDR + 0x1C))

#define UART5_BASE_ADDR		0x40090000
#define U5RBR          (*(volatile unsigned long *)(UART5_BASE_ADDR + 0x00))
#define U5THR          (*(volatile unsigned long *)(UART5_BASE_ADDR + 0x00))
#define U5DLL          (*(volatile unsigned long *)(UART5_BASE_ADDR + 0x00))
#define U5DLM          (*(volatile unsigned long *)(UART5_BASE_ADDR + 0x04))
#define U5IER          (*(volatile unsigned long *)(UART5_BASE_ADDR + 0x04))
#define U5IIR          (*(volatile unsigned long *)(UART5_BASE_ADDR + 0x08))
#define U5FCR          (*(volatile unsigned long *)(UART5_BASE_ADDR + 0x08))
#define U5LCR          (*(volatile unsigned long *)(UART5_BASE_ADDR + 0x0C))
#define U5LSR          (*(volatile unsigned long *)(UART5_BASE_ADDR + 0x14))
#define U5RXLEV        (*(volatile unsigned long *)(UART5_BASE_ADDR + 0x1C))

#define UART6_BASE_ADDR		0x40098000
#define U6RBR          (*(volatile unsigned long *)(UART6_BASE_ADDR + 0x00))
#define U6THR          (*(volatile unsigned long *)(UART6_BASE_ADDR + 0x00))
#define U6DLL          (*(volatile unsigned long *)(UART6_BASE_ADDR + 0x00))
#define U6DLM          (*(volatile unsigned long *)(UART6_BASE_ADDR + 0x04))
#define U6IER          (*(volatile unsigned long *)(UART6_BASE_ADDR + 0x04))
#define U6IIR          (*(volatile unsigned long *)(UART6_BASE_ADDR + 0x08))
#define U6FCR          (*(volatile unsigned long *)(UART6_BASE_ADDR + 0x08))
#define U6LCR          (*(volatile unsigned long *)(UART6_BASE_ADDR + 0x0C))
#define U6LSR          (*(volatile unsigned long *)(UART6_BASE_ADDR + 0x14))
#define U6RXLEV        (*(volatile unsigned long *)(UART6_BASE_ADDR + 0x1C))

#define UART_CLK_BASE_ADDR	0x40004000
#define U3CLK          (*(volatile unsigned long *)(UART_CLK_BASE_ADDR + 0xD0))
#define U4CLK          (*(volatile unsigned long *)(UART_CLK_BASE_ADDR + 0xD4))
#define U5CLK          (*(volatile unsigned long *)(UART_CLK_BASE_ADDR + 0xD8))
#define U6CLK          (*(volatile unsigned long *)(UART_CLK_BASE_ADDR + 0xDC))
#define IRDACLK        (*(volatile unsigned long *)(UART_CLK_BASE_ADDR + 0xE0))

#define UART_CTRL_BASE_ADDR	0x40054000
#define UART_CTRL      (*(volatile unsigned long *)(UART_CTRL_BASE_ADDR + 0x00))
#define UART_CLKMODE   (*(volatile unsigned long *)(UART_CTRL_BASE_ADDR + 0x04))
#define UART_LOOP      (*(volatile unsigned long *)(UART_CTRL_BASE_ADDR + 0x08))


/* High-speed Universal Asynchronous Receiver Transmitter (UART1,2,7) */
#define HS_UART1_BASE_ADDR		0x40014000
#define HSU1_RX        (*(volatile unsigned long *)(HS_UART1_BASE_ADDR + 0x00))
#define HSU1_TX        (*(volatile unsigned long *)(HS_UART1_BASE_ADDR + 0x00))
#define HSU1_LEVEL     (*(volatile unsigned long *)(HS_UART1_BASE_ADDR + 0x04))
#define HSU1_IIR       (*(volatile unsigned long *)(HS_UART1_BASE_ADDR + 0x08))
#define HSU1_CTRL      (*(volatile unsigned long *)(HS_UART1_BASE_ADDR + 0x0C))
#define HSU1_RATE      (*(volatile unsigned long *)(HS_UART1_BASE_ADDR + 0x10))

#define HS_UART2_BASE_ADDR		0x40018000
#define HSU2_RX        (*(volatile unsigned long *)(HS_UART2_BASE_ADDR + 0x00))
#define HSU2_TX        (*(volatile unsigned long *)(HS_UART2_BASE_ADDR + 0x00))
#define HSU2_LEVEL     (*(volatile unsigned long *)(HS_UART2_BASE_ADDR + 0x04))
#define HSU2_IIR       (*(volatile unsigned long *)(HS_UART2_BASE_ADDR + 0x08))
#define HSU2_CTRL      (*(volatile unsigned long *)(HS_UART2_BASE_ADDR + 0x0C))
#define HSU2_RATE      (*(volatile unsigned long *)(HS_UART2_BASE_ADDR + 0x10))

#define HS_UART7_BASE_ADDR		0x4001C000
#define HSU7_RX        (*(volatile unsigned long *)(HS_UART7_BASE_ADDR + 0x00))
#define HSU7_TX        (*(volatile unsigned long *)(HS_UART7_BASE_ADDR + 0x00))
#define HSU7_LEVEL     (*(volatile unsigned long *)(HS_UART7_BASE_ADDR + 0x04))
#define HSU7_IIR       (*(volatile unsigned long *)(HS_UART7_BASE_ADDR + 0x08))
#define HSU7_CTRL      (*(volatile unsigned long *)(HS_UART7_BASE_ADDR + 0x0C))
#define HSU7_RATE      (*(volatile unsigned long *)(HS_UART7_BASE_ADDR + 0x10))

/* SPI Interface */
#define SPI1_BASE_ADDR	0x20088000
#define SPI1_GLOBAL	(*(volatile unsigned long *)(SPI1_BASE_ADDR + 0x000))
#define SPI1_CON	(*(volatile unsigned long *)(SPI1_BASE_ADDR + 0x004))
#define SPI1_FRM	(*(volatile unsigned long *)(SPI1_BASE_ADDR + 0x008))
#define SPI1_IER	(*(volatile unsigned long *)(SPI1_BASE_ADDR + 0x00C))
#define SPI1_STAT	(*(volatile unsigned long *)(SPI1_BASE_ADDR + 0x010))
#define SPI1_DAT	(*(volatile unsigned long *)(SPI1_BASE_ADDR + 0x014))
#define SPI1_TIM_CTRL	(*(volatile unsigned long *)(SPI1_BASE_ADDR + 0x400))
#define SPI1_TIM_COUNT	(*(volatile unsigned long *)(SPI1_BASE_ADDR + 0x404))
#define SPI1_TIM_STAT	(*(volatile unsigned long *)(SPI1_BASE_ADDR + 0x408))

#define SPI2_BASE_ADDR	0x20090000
#define SPI2_GLOBAL	(*(volatile unsigned long *)(SPI2_BASE_ADDR + 0x000))
#define SPI2_CON	(*(volatile unsigned long *)(SPI2_BASE_ADDR + 0x004))
#define SPI2_FRM	(*(volatile unsigned long *)(SPI2_BASE_ADDR + 0x008))
#define SPI2_IER	(*(volatile unsigned long *)(SPI2_BASE_ADDR + 0x00C))
#define SPI2_STAT	(*(volatile unsigned long *)(SPI2_BASE_ADDR + 0x010))
#define SPI2_DAT	(*(volatile unsigned long *)(SPI2_BASE_ADDR + 0x014))
#define SPI2_TIM_CTRL	(*(volatile unsigned long *)(SPI2_BASE_ADDR + 0x400))
#define SPI2_TIM_COUNT	(*(volatile unsigned long *)(SPI2_BASE_ADDR + 0x404))
#define SPI2_TIM_STAT	(*(volatile unsigned long *)(SPI2_BASE_ADDR + 0x408))


/* SD Card Interface */
#define MCI_BASE_ADDR	0x20098000
#define MCI_POWER      (*(volatile unsigned long *)(MCI_BASE_ADDR + 0x00))
#define MCI_CLOCK      (*(volatile unsigned long *)(MCI_BASE_ADDR + 0x04))
#define MCI_ARGUMENT   (*(volatile unsigned long *)(MCI_BASE_ADDR + 0x08))
#define MCI_COMMAND    (*(volatile unsigned long *)(MCI_BASE_ADDR + 0x0C))
#define MCI_RESP_CMD   (*(volatile unsigned long *)(MCI_BASE_ADDR + 0x10))
#define MCI_RESP0      (*(volatile unsigned long *)(MCI_BASE_ADDR + 0x14))
#define MCI_RESP1      (*(volatile unsigned long *)(MCI_BASE_ADDR + 0x18))
#define MCI_RESP2      (*(volatile unsigned long *)(MCI_BASE_ADDR + 0x1C))
#define MCI_RESP3      (*(volatile unsigned long *)(MCI_BASE_ADDR + 0x20))
#define MCI_DATA_TMR   (*(volatile unsigned long *)(MCI_BASE_ADDR + 0x24))
#define MCI_DATA_LEN   (*(volatile unsigned long *)(MCI_BASE_ADDR + 0x28))
#define MCI_DATA_CTRL  (*(volatile unsigned long *)(MCI_BASE_ADDR + 0x2C))
#define MCI_DATA_CNT   (*(volatile unsigned long *)(MCI_BASE_ADDR + 0x30))
#define MCI_STATUS     (*(volatile unsigned long *)(MCI_BASE_ADDR + 0x34))
#define MCI_CLEAR      (*(volatile unsigned long *)(MCI_BASE_ADDR + 0x38))
#define MCI_MASK0      (*(volatile unsigned long *)(MCI_BASE_ADDR + 0x3C))
#define MCI_MASK1      (*(volatile unsigned long *)(MCI_BASE_ADDR + 0x40))
#define MCI_FIFO_CNT   (*(volatile unsigned long *)(MCI_BASE_ADDR + 0x48))
#define MCI_FIFO       (*(volatile unsigned long *)(MCI_BASE_ADDR + 0x80))

/* I2C Interface 0 */
#define I2C0_BASE_ADDR		0x400A0000
#define I2C0_RX		(*(volatile unsigned long *)(I2C0_BASE_ADDR + 0x00))
#define I2C0_TX		(*(volatile unsigned long *)(I2C0_BASE_ADDR + 0x00))
#define I2C0_STS	(*(volatile unsigned long *)(I2C0_BASE_ADDR + 0x04))
#define I2C0_CTRL	(*(volatile unsigned long *)(I2C0_BASE_ADDR + 0x08))
#define I2C0_CLKH	(*(volatile unsigned long *)(I2C0_BASE_ADDR + 0x0C))
#define I2C0_CLKL	(*(volatile unsigned long *)(I2C0_BASE_ADDR + 0x10))

/* I2C Interface 1 */
#define I2C1_BASE_ADDR		0x400A8000
#define I2C1_RX		(*(volatile unsigned long *)(I2C1_BASE_ADDR + 0x00))
#define I2C1_TX		(*(volatile unsigned long *)(I2C1_BASE_ADDR + 0x00))
#define I2C1_STS	(*(volatile unsigned long *)(I2C1_BASE_ADDR + 0x04))
#define I2C1_CTRL	(*(volatile unsigned long *)(I2C1_BASE_ADDR + 0x08))
#define I2C1_CLKH	(*(volatile unsigned long *)(I2C1_BASE_ADDR + 0x0C))
#define I2C1_CLKL	(*(volatile unsigned long *)(I2C1_BASE_ADDR + 0x10))


/* Keyboard Scan controller interface */
#define KS_BASE_ADDR		0x40050000
#define KS_DEB			(*(volatile unsigned long *)(KS_BASE_ADDR + 0x00))
#define KS_STATE_COND	(*(volatile unsigned long *)(KS_BASE_ADDR + 0x04))
#define KS_IRQ			(*(volatile unsigned long *)(KS_BASE_ADDR + 0x08))
#define KS_SCAN_CTL		(*(volatile unsigned long *)(KS_BASE_ADDR + 0x0C))
#define KS_FAST_TST		(*(volatile unsigned long *)(KS_BASE_ADDR + 0x10))
#define KS_MATRIX_DIM	(*(volatile unsigned long *)(KS_BASE_ADDR + 0x14))
#define KS_DATA0		(*(volatile unsigned long *)(KS_BASE_ADDR + 0x40))
#define KS_DATA1		(*(volatile unsigned long *)(KS_BASE_ADDR + 0x44))
#define KS_DATA2		(*(volatile unsigned long *)(KS_BASE_ADDR + 0x48))
#define KS_DATA3		(*(volatile unsigned long *)(KS_BASE_ADDR + 0x4C))
#define KS_DATA4		(*(volatile unsigned long *)(KS_BASE_ADDR + 0x50))
#define KS_DATA5		(*(volatile unsigned long *)(KS_BASE_ADDR + 0x54))
#define KS_DATA6		(*(volatile unsigned long *)(KS_BASE_ADDR + 0x58))
#define KS_DATA7		(*(volatile unsigned long *)(KS_BASE_ADDR + 0x5C))


/* High-speed Timer  */
#define HSTIM_BASE_ADDR		0x40038000
#define HSTIM_INT		(*(volatile unsigned long *)(HSTIM_BASE_ADDR + 0x00))
#define HSTIM_CTRL		(*(volatile unsigned long *)(HSTIM_BASE_ADDR + 0x04))
#define HSTIM_COUNTER	(*(volatile unsigned long *)(HSTIM_BASE_ADDR + 0x08))
#define HSTIM_PMATCH	(*(volatile unsigned long *)(HSTIM_BASE_ADDR + 0x0C))
#define HSTIM_PCOUNT	(*(volatile unsigned long *)(HSTIM_BASE_ADDR + 0x10))
#define HSTIM_MCTRL		(*(volatile unsigned long *)(HSTIM_BASE_ADDR + 0x14))
#define HSTIM_MATCH0	(*(volatile unsigned long *)(HSTIM_BASE_ADDR + 0x18))
#define HSTIM_MATCH1	(*(volatile unsigned long *)(HSTIM_BASE_ADDR + 0x1C))
#define HSTIM_MATCH2	(*(volatile unsigned long *)(HSTIM_BASE_ADDR + 0x20))
#define HSTIM_CCR		(*(volatile unsigned long *)(HSTIM_BASE_ADDR + 0x28))
#define HSTIM_CR0		(*(volatile unsigned long *)(HSTIM_BASE_ADDR + 0x2C))
#define HSTIM_CR1		(*(volatile unsigned long *)(HSTIM_BASE_ADDR + 0x30))


/* Millisecond Timer */
#define MSTIM_BASE_ADDR		0x40034000
#define MSTIM_INT		(*(volatile unsigned long *)(MSTIM_BASE_ADDR + 0x00))
#define MSTIM_CTRL		(*(volatile unsigned long *)(MSTIM_BASE_ADDR + 0x04))
#define MSTIM_COUNTER	(*(volatile unsigned long *)(MSTIM_BASE_ADDR + 0x08))
#define MSTIM_MCTRL		(*(volatile unsigned long *)(MSTIM_BASE_ADDR + 0x14))
#define MSTIM_MATCH0	(*(volatile unsigned long *)(MSTIM_BASE_ADDR + 0x18))
#define MSTIM_MATCH1	(*(volatile unsigned long *)(MSTIM_BASE_ADDR + 0x1C))

/* Real Time Clock */
#define RTC_BASE_ADDR		0x40024000
#define RTC_UCOUNT	(*(volatile unsigned long *)(RTC_BASE_ADDR + 0x00))
#define RTC_DCOUNT	(*(volatile unsigned long *)(RTC_BASE_ADDR + 0x04))
#define RTC_MATCH0	(*(volatile unsigned long *)(RTC_BASE_ADDR + 0x08))
#define RTC_MATCH1	(*(volatile unsigned long *)(RTC_BASE_ADDR + 0x0C))
#define RTC_CTRL	(*(volatile unsigned long *)(RTC_BASE_ADDR + 0x10))
#define RTC_INTSTAT	(*(volatile unsigned long *)(RTC_BASE_ADDR + 0x14))
#define RTC_KEY		(*(volatile unsigned long *)(RTC_BASE_ADDR + 0x18))
#define RTC_SRAM	(*(volatile unsigned long *)(RTC_BASE_ADDR + 0x80))

/* Watchdog timer */
#define WDTIM_BASE_ADDR		0x4003C000
#define WDTIM_INT		(*(volatile unsigned long *)(WDTIM_BASE_ADDR + 0x00))
#define WDTIM_CTRL		(*(volatile unsigned long *)(WDTIM_BASE_ADDR + 0x04))
#define WDTIM_COUNTER	(*(volatile unsigned long *)(WDTIM_BASE_ADDR + 0x08))
#define WDTIM_MCTRL		(*(volatile unsigned long *)(WDTIM_BASE_ADDR + 0x0C))
#define WDTIM_MATCH0	(*(volatile unsigned long *)(WDTIM_BASE_ADDR + 0x10))
#define WDTIM_EMR		(*(volatile unsigned long *)(WDTIM_BASE_ADDR + 0x14))
#define WDTIM_PULSE		(*(volatile unsigned long *)(WDTIM_BASE_ADDR + 0x18))
#define WDTIM_RES		(*(volatile unsigned long *)(WDTIM_BASE_ADDR + 0x1C))


/* A/D Converter */
#define ADC_BASE_ADDR		0x40048000
#define ADSTAT		(*(volatile unsigned long *)(ADC_BASE_ADDR + 0x00))
#define ADSEL		(*(volatile unsigned long *)(ADC_BASE_ADDR + 0x04))
#define ADCON		(*(volatile unsigned long *)(ADC_BASE_ADDR + 0x08))
#define ADDAT		(*(volatile unsigned long *)(ADC_BASE_ADDR + 0x48))


/* DMA */
#define DMA_BASE_ADDR		0x31000000
#define GPDMA_INT_STAT         (*(volatile unsigned long *)(DMA_BASE_ADDR + 0x000))
#define GPDMA_INT_TCSTAT       (*(volatile unsigned long *)(DMA_BASE_ADDR + 0x004))
#define GPDMA_INT_TCCLR        (*(volatile unsigned long *)(DMA_BASE_ADDR + 0x008))
#define GPDMA_INT_ERR_STAT     (*(volatile unsigned long *)(DMA_BASE_ADDR + 0x00C))
#define GPDMA_INT_ERR_CLR      (*(volatile unsigned long *)(DMA_BASE_ADDR + 0x010))
#define GPDMA_RAW_INT_TCSTAT   (*(volatile unsigned long *)(DMA_BASE_ADDR + 0x014))
#define GPDMA_RAW_INT_ERR_STAT (*(volatile unsigned long *)(DMA_BASE_ADDR + 0x018))
#define GPDMA_ENABLED_CHNS     (*(volatile unsigned long *)(DMA_BASE_ADDR + 0x01C))
#define GPDMA_SOFT_BREQ        (*(volatile unsigned long *)(DMA_BASE_ADDR + 0x020))
#define GPDMA_SOFT_SREQ        (*(volatile unsigned long *)(DMA_BASE_ADDR + 0x024))
#define GPDMA_SOFT_LBREQ       (*(volatile unsigned long *)(DMA_BASE_ADDR + 0x028))
#define GPDMA_SOFT_LSREQ       (*(volatile unsigned long *)(DMA_BASE_ADDR + 0x02C))
#define GPDMA_CONFIG           (*(volatile unsigned long *)(DMA_BASE_ADDR + 0x030))
#define GPDMA_SYNC             (*(volatile unsigned long *)(DMA_BASE_ADDR + 0x034))

/* DMA channel 0 registers */
#define GPDMA_CH0_SRC      (*(volatile unsigned long *)(DMA_BASE_ADDR + 0x100))
#define GPDMA_CH0_DEST     (*(volatile unsigned long *)(DMA_BASE_ADDR + 0x104))
#define GPDMA_CH0_LLI      (*(volatile unsigned long *)(DMA_BASE_ADDR + 0x108))
#define GPDMA_CH0_CTRL     (*(volatile unsigned long *)(DMA_BASE_ADDR + 0x10C))
#define GPDMA_CH0_CFG      (*(volatile unsigned long *)(DMA_BASE_ADDR + 0x110))

/* DMA channel 1 registers */
#define GPDMA_CH1_SRC      (*(volatile unsigned long *)(DMA_BASE_ADDR + 0x120))
#define GPDMA_CH1_DEST     (*(volatile unsigned long *)(DMA_BASE_ADDR + 0x124))
#define GPDMA_CH1_LLI      (*(volatile unsigned long *)(DMA_BASE_ADDR + 0x128))
#define GPDMA_CH1_CTRL     (*(volatile unsigned long *)(DMA_BASE_ADDR + 0x12C))
#define GPDMA_CH1_CFG      (*(volatile unsigned long *)(DMA_BASE_ADDR + 0x130))

/* DMA channel 2 registers */
#define GPDMA_CH2_SRC      (*(volatile unsigned long *)(DMA_BASE_ADDR + 0x140))
#define GPDMA_CH2_DEST     (*(volatile unsigned long *)(DMA_BASE_ADDR + 0x144))
#define GPDMA_CH2_LLI      (*(volatile unsigned long *)(DMA_BASE_ADDR + 0x148))
#define GPDMA_CH2_CTRL     (*(volatile unsigned long *)(DMA_BASE_ADDR + 0x14C))
#define GPDMA_CH2_CFG      (*(volatile unsigned long *)(DMA_BASE_ADDR + 0x150))

/* DMA channel 3 registers */
#define GPDMA_CH3_SRC      (*(volatile unsigned long *)(DMA_BASE_ADDR + 0x160))
#define GPDMA_CH3_DEST     (*(volatile unsigned long *)(DMA_BASE_ADDR + 0x164))
#define GPDMA_CH3_LLI      (*(volatile unsigned long *)(DMA_BASE_ADDR + 0x168))
#define GPDMA_CH3_CTRL     (*(volatile unsigned long *)(DMA_BASE_ADDR + 0x16C))
#define GPDMA_CH3_CFG      (*(volatile unsigned long *)(DMA_BASE_ADDR + 0x170))

/* DMA channel 4 registers */
#define GPDMA_CH4_SRC      (*(volatile unsigned long *)(DMA_BASE_ADDR + 0x180))
#define GPDMA_CH4_DEST     (*(volatile unsigned long *)(DMA_BASE_ADDR + 0x184))
#define GPDMA_CH4_LLI      (*(volatile unsigned long *)(DMA_BASE_ADDR + 0x188))
#define GPDMA_CH4_CTRL     (*(volatile unsigned long *)(DMA_BASE_ADDR + 0x18C))
#define GPDMA_CH4_CFG      (*(volatile unsigned long *)(DMA_BASE_ADDR + 0x190))

/* DMA channel 5 registers */
#define GPDMA_CH5_SRC      (*(volatile unsigned long *)(DMA_BASE_ADDR + 0x1A0))
#define GPDMA_CH5_DEST     (*(volatile unsigned long *)(DMA_BASE_ADDR + 0x1A4))
#define GPDMA_CH5_LLI      (*(volatile unsigned long *)(DMA_BASE_ADDR + 0x1A8))
#define GPDMA_CH5_CTRL     (*(volatile unsigned long *)(DMA_BASE_ADDR + 0x1AC))
#define GPDMA_CH5_CFG      (*(volatile unsigned long *)(DMA_BASE_ADDR + 0x1B0))

/* DMA channel 6 registers */
#define GPDMA_CH6_SRC      (*(volatile unsigned long *)(DMA_BASE_ADDR + 0x1C0))
#define GPDMA_CH6_DEST     (*(volatile unsigned long *)(DMA_BASE_ADDR + 0x1C4))
#define GPDMA_CH6_LLI      (*(volatile unsigned long *)(DMA_BASE_ADDR + 0x1C8))
#define GPDMA_CH6_CTRL     (*(volatile unsigned long *)(DMA_BASE_ADDR + 0x1CC))
#define GPDMA_CH6_CFG      (*(volatile unsigned long *)(DMA_BASE_ADDR + 0x1D0))

/* DMA channel 7 registers */
#define GPDMA_CH7_SRC      (*(volatile unsigned long *)(DMA_BASE_ADDR + 0x1E0))
#define GPDMA_CH7_DEST     (*(volatile unsigned long *)(DMA_BASE_ADDR + 0x1E4))
#define GPDMA_CH7_LLI      (*(volatile unsigned long *)(DMA_BASE_ADDR + 0x1E8))
#define GPDMA_CH7_CTRL     (*(volatile unsigned long *)(DMA_BASE_ADDR + 0x1EC))
#define GPDMA_CH7_CFG      (*(volatile unsigned long *)(DMA_BASE_ADDR + 0x1F0))

/* Ethernet MAC (32 bit data bus) -- all registers are RW unless indicated in parentheses */
#define MAC_BASE_ADDR		0x31060000 /* AHB Peripheral # 0 */
#define MAC_MAC1            (*(volatile unsigned long *)(MAC_BASE_ADDR + 0x000)) /* MAC config reg 1 */
#define MAC_MAC2            (*(volatile unsigned long *)(MAC_BASE_ADDR + 0x004)) /* MAC config reg 2 */
#define MAC_IPGT            (*(volatile unsigned long *)(MAC_BASE_ADDR + 0x008)) /* b2b InterPacketGap reg */
#define MAC_IPGR            (*(volatile unsigned long *)(MAC_BASE_ADDR + 0x00C)) /* non b2b InterPacketGap reg */
#define MAC_CLRT            (*(volatile unsigned long *)(MAC_BASE_ADDR + 0x010)) /* CoLlision window/ReTry reg */
#define MAC_MAXF            (*(volatile unsigned long *)(MAC_BASE_ADDR + 0x014)) /* MAXimum Frame reg */
#define MAC_SUPP            (*(volatile unsigned long *)(MAC_BASE_ADDR + 0x018)) /* PHY SUPPort reg */
#define MAC_TEST            (*(volatile unsigned long *)(MAC_BASE_ADDR + 0x01C)) /* TEST reg */
#define MAC_MCFG            (*(volatile unsigned long *)(MAC_BASE_ADDR + 0x020)) /* MII Mgmt ConFiG reg */
#define MAC_MCMD            (*(volatile unsigned long *)(MAC_BASE_ADDR + 0x024)) /* MII Mgmt CoMmanD reg */
#define MAC_MADR            (*(volatile unsigned long *)(MAC_BASE_ADDR + 0x028)) /* MII Mgmt ADdRess reg */
#define MAC_MWTD            (*(volatile unsigned long *)(MAC_BASE_ADDR + 0x02C)) /* MII Mgmt WriTe Data reg (WO) */
#define MAC_MRDD            (*(volatile unsigned long *)(MAC_BASE_ADDR + 0x030)) /* MII Mgmt ReaD Data reg (RO) */
#define MAC_MIND            (*(volatile unsigned long *)(MAC_BASE_ADDR + 0x034)) /* MII Mgmt INDicators reg (RO) */

#define MAC_SA0             (*(volatile unsigned long *)(MAC_BASE_ADDR + 0x040)) /* Station Address 0 reg */
#define MAC_SA1             (*(volatile unsigned long *)(MAC_BASE_ADDR + 0x044)) /* Station Address 1 reg */
#define MAC_SA2             (*(volatile unsigned long *)(MAC_BASE_ADDR + 0x048)) /* Station Address 2 reg */

#define MAC_COMMAND         (*(volatile unsigned long *)(MAC_BASE_ADDR + 0x100)) /* Command reg */
#define MAC_STATUS          (*(volatile unsigned long *)(MAC_BASE_ADDR + 0x104)) /* Status reg (RO) */
#define MAC_RXDESCRIPTOR    (*(volatile unsigned long *)(MAC_BASE_ADDR + 0x108)) /* Rx descriptor base address reg */
#define MAC_RXSTATUS        (*(volatile unsigned long *)(MAC_BASE_ADDR + 0x10C)) /* Rx status base address reg */
#define MAC_RXDESCRIPTORNUM (*(volatile unsigned long *)(MAC_BASE_ADDR + 0x110)) /* Rx number of descriptors reg */
#define MAC_RXPRODUCEINDEX  (*(volatile unsigned long *)(MAC_BASE_ADDR + 0x114)) /* Rx produce index reg (RO) */
#define MAC_RXCONSUMEINDEX  (*(volatile unsigned long *)(MAC_BASE_ADDR + 0x118)) /* Rx consume index reg */
#define MAC_TXDESCRIPTOR    (*(volatile unsigned long *)(MAC_BASE_ADDR + 0x11C)) /* Tx descriptor base address reg */
#define MAC_TXSTATUS        (*(volatile unsigned long *)(MAC_BASE_ADDR + 0x120)) /* Tx status base address reg */
#define MAC_TXDESCRIPTORNUM (*(volatile unsigned long *)(MAC_BASE_ADDR + 0x124)) /* Tx number of descriptors reg */
#define MAC_TXPRODUCEINDEX  (*(volatile unsigned long *)(MAC_BASE_ADDR + 0x128)) /* Tx produce index reg */
#define MAC_TXCONSUMEINDEX  (*(volatile unsigned long *)(MAC_BASE_ADDR + 0x12C)) /* Tx consume index reg (RO) */

#define MAC_TSV0            (*(volatile unsigned long *)(MAC_BASE_ADDR + 0x158)) /* Tx status vector 0 reg (RO) */
#define MAC_TSV1            (*(volatile unsigned long *)(MAC_BASE_ADDR + 0x15C)) /* Tx status vector 1 reg (RO) */
#define MAC_RSV             (*(volatile unsigned long *)(MAC_BASE_ADDR + 0x160)) /* Rx status vector reg (RO) */

#define MAC_FLOWCONTROLCNT  (*(volatile unsigned long *)(MAC_BASE_ADDR + 0x170)) /* Flow control counter reg */
#define MAC_FLOWCONTROLSTS  (*(volatile unsigned long *)(MAC_BASE_ADDR + 0x174)) /* Flow control status reg */

#define MAC_RXFILTERCTRL    (*(volatile unsigned long *)(MAC_BASE_ADDR + 0x200)) /* Rx filter ctrl reg */
#define MAC_RXFILTERWOLSTS  (*(volatile unsigned long *)(MAC_BASE_ADDR + 0x204)) /* Rx filter WoL status reg (RO) */
#define MAC_RXFILTERWOLCLR  (*(volatile unsigned long *)(MAC_BASE_ADDR + 0x208)) /* Rx filter WoL clear reg (WO) */

#define MAC_HASHFILTERL     (*(volatile unsigned long *)(MAC_BASE_ADDR + 0x210)) /* Hash filter LSBs reg */
#define MAC_HASHFILTERH     (*(volatile unsigned long *)(MAC_BASE_ADDR + 0x214)) /* Hash filter MSBs reg */

#define MAC_INTSTATUS       (*(volatile unsigned long *)(MAC_BASE_ADDR + 0xFE0)) /* Interrupt status reg (RO) */
#define MAC_INTENABLE       (*(volatile unsigned long *)(MAC_BASE_ADDR + 0xFE4)) /* Interrupt enable reg  */
#define MAC_INTCLEAR        (*(volatile unsigned long *)(MAC_BASE_ADDR + 0xFE8)) /* Interrupt clear reg (WO) */
#define MAC_INTSET          (*(volatile unsigned long *)(MAC_BASE_ADDR + 0xFEC)) /* Interrupt set reg (WO) */

#define MAC_POWERDOWN       (*(volatile unsigned long *)(MAC_BASE_ADDR + 0xFF4)) /* Power-down reg */
#define MAC_MODULEID        (*(volatile unsigned long *)(MAC_BASE_ADDR + 0xFFC)) /* Module ID reg (RO) */

/* I2S Interface Controller (I2S) */
#define I2S0_BASE_ADDR		0x20094000
#define I2S0_DAO        (*(volatile unsigned long *)(I2S0_BASE_ADDR + 0x00))
#define I2S0_DAI        (*(volatile unsigned long *)(I2S0_BASE_ADDR + 0x04))
#define I2S0_TX_FIFO    (*(volatile unsigned long *)(I2S0_BASE_ADDR + 0x08))
#define I2S0_RX_FIFO    (*(volatile unsigned long *)(I2S0_BASE_ADDR + 0x0C))
#define I2S0_STATE      (*(volatile unsigned long *)(I2S0_BASE_ADDR + 0x10))
#define I2S0_DMA1       (*(volatile unsigned long *)(I2S0_BASE_ADDR + 0x14))
#define I2S0_DMA2       (*(volatile unsigned long *)(I2S0_BASE_ADDR + 0x18))
#define I2S0_IRQ        (*(volatile unsigned long *)(I2S0_BASE_ADDR + 0x1C))
#define I2S0_TXRATE     (*(volatile unsigned long *)(I2S0_BASE_ADDR + 0x20))
#define I2S0_RXRATE     (*(volatile unsigned long *)(I2S0_BASE_ADDR + 0x24))

#define I2S1_BASE_ADDR		0x2009C000
#define I2S1_DAO        (*(volatile unsigned long *)(I2S1_BASE_ADDR + 0x00))
#define I2S1_DAI        (*(volatile unsigned long *)(I2S1_BASE_ADDR + 0x04))
#define I2S1_TX_FIFO    (*(volatile unsigned long *)(I2S1_BASE_ADDR + 0x08))
#define I2S1_RX_FIFO    (*(volatile unsigned long *)(I2S1_BASE_ADDR + 0x0C))
#define I2S1_STATE      (*(volatile unsigned long *)(I2S1_BASE_ADDR + 0x10))
#define I2S1_DMA1       (*(volatile unsigned long *)(I2S1_BASE_ADDR + 0x14))
#define I2S1_DMA2       (*(volatile unsigned long *)(I2S1_BASE_ADDR + 0x18))
#define I2S1_IRQ        (*(volatile unsigned long *)(I2S1_BASE_ADDR + 0x1C))
#define I2S1_TXRATE     (*(volatile unsigned long *)(I2S1_BASE_ADDR + 0x20))
#define I2S1_RXRATE     (*(volatile unsigned long *)(I2S1_BASE_ADDR + 0x24))

#endif  // __LPC325x_H


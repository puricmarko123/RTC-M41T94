/*
 * @what: Module for RTC M41T94
 * @why: Real time clock support
 * @who: Marko Puric
 * @when: 09.01.2020
 */

#ifndef M41T94_DEFS_H
#define M41T94_DEFS_H

/* M41T94 Clock register map */
#define M41T94_REG_SECONDS			(0x01U)
#define M41T94_REG_MINUTES 			(0x02U)
#define M41T94_REG_HOURS 			(0x03U)
#define M41T94_REG_WDAY				(0x04U)
#define M41T94_REG_DAY				(0x05U)
#define M41T94_REG_MONTH			(0x06U)
#define M41T94_REG_YEAR				(0x07U)

#define M41T94_REG_CONTROL			(0x08U)
#define M41T94_REG_WATCHDOG			(0x09U)
#define M41T94_REG_ALARM_MONTH		(0x0AU)
#define M41T94_REG_ALARM_DATE		(0x0BU)
#define M41T94_REG_ALARM_HOUR		(0x0CU)
#define M41T94_REG_ALARM_MINUTES	(0x0DU)
#define M41T94_REG_ALARM_SECONDS	(0x0EU)

#define M41T94_BIT_HALT				(0x40U)
#define M41T94_BIT_STOP				(0x80U)
#define M41T94_BIT_CB				(0x40U)
#define M41T94_BIT_CEB				(0x80U)

#define SEND_FF						(0xFFU)

#endif /* M41T94_DEFS_H */

/*
 * @what: Driver for RTC M41T94
 * @who: Marko Puric
 * @when: 09.01.2020
 */

#ifndef RTC_M41T94_H
#define RTC_M41T94_H

void M41T94_Init(void);
void M41T94_Read_RTC(void);

uint8_t RTC_Get_Seconds(void);
uint8_t RTC_Get_Minutes(void);
uint8_t RTC_Get_Hours(void);
uint8_t RTC_Get_Weekday(void);
uint8_t RTC_Get_Day(void);
uint8_t RTC_Get_Month(void);
uint8_t RTC_Get_Year(void);

#endif /* RTC_M41T94_H_ */

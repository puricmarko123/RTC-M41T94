/*
 * @what: Module for RTC M41T94
 * @why: Real time clock support
 * @who: Marko Puric
 * @when: 09.01.2020
 */

#ifndef RTC_M41T94_H
#define RTC_M41T94_H

void M41T94_Init(void);
uint8_t M41T94_Read_Register(uint8_t address);
void M41T94_Write_Register(uint8_t address, uint8_t data);
void M41T94_Read_RTC(void);

uint8_t RTC_Get_Seconds(void);
uint8_t RTC_Get_Minutes(void);
uint8_t RTC_Get_Hours(void);
uint8_t RTC_Get_Weekday(void);
uint8_t RTC_Get_Day(void);
uint8_t RTC_Get_Month(void);
uint8_t RTC_Get_Year(void);

uint8_t bin2bcd(uint8_t bin);
uint8_t bcd2bin(uint8_t bcd);


#endif /* RTC_M41T94_H_ */

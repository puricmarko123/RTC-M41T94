/*
 * @what: Module for RTC M41T94
 * @why: Real time clock support
 * @who: Marko Puric
 * @when: 09.01.2020
 */

#include "RTC_M41T94.h"
#include "M41T94_defs.h"

/* Number of days from begin of the year */
/* Leap-year */
static const uint16_t MONTH_DAYS[] = {0U,0U,31U,59U,90U,120U,151U,181U,212U,243U,273U,304U,334U};

/*
 * @what: Initialize RTC M41T94
 * @why: Clear HT bit
 */
void M41T94_Init(void) {

    /* Clear HT bit */
    M41T94_Write_Register(M41T94_REG_ALARM_HOUR, 0x00U);

    return;
}

/*
 * @what: Store time to predefined structure
 * @why: Calculate milliseconds past from current day at 00:00 and days past since 1.1.2000.
 */
void M41T94_Read_RTC(void)
{
	/* Clear HT bit */
	M41T94_Write_Register(M41T94_REG_ALARM_HOUR, 0x00U);

	/* Store time to predefined structure */
	Time.Second = RTC_Get_Seconds();
	Time.Minute = RTC_Get_Minutes();
	Time.Hour = RTC_Get_Hours();
	Time.Day = RTC_Get_Day();
	Time.Month = RTC_Get_Month();
	Time.Year = RTC_Get_Year();

	/* Calculate milliseconds past from 00:00 (current day) */
	RTCmilliSeconds = ((Time.Hour * 3600U) + (Time.Minute * 60U) + Time.Second) * 1000U;

	/* Compute number of days from 2000 till given year */
	RTCdays = (Time.Year * 365U) + ((Time.Year + 3U) / 4U);

	/* Add number of days till given month */
	RTCdays += MONTH_DAYS[Time.Month];
	RTCdays += Time.Day;

	/* For non-leap year or month <= 2, decrement day counter */
	if ((Time.Year & 3U) || (Time.Month <= 2U))
	{
	  RTCdays--;
	}

	return;
}

/*
 * @what: Convert binary to BCD
 * @why: RTC register input in BCD format
 */
uint8_t bin2bcd(uint8_t bin)
{
    uint8_t bcd = 0;

    bin = bin % 100U;
    bcd = bin % 10U;
    bcd = bcd + (bin / 10U) * 0x10U;

    return bcd;
}

/*
 * @what: Convert BCD to binary
 * @why: Convert to decimal value when reading RTC registers
 */
uint8_t bcd2bin(uint8_t bcd)
{
    uint8_t bin = 0;

    bin  = (bcd >> 4U) * 10U;
    bin = bin + (bcd & 0x0FU);

    return bin;
}

/*
 * @what: Read data from RTC register
 * @why:
 */
uint8_t M41T94_Read_Register(uint8_t address)
{
	/* Send register address.  First bit must be LOW, then 7 bit address. SPI_CMD_RTC pulls CS LOW */
	SPI_CMD_RTC(address, SPI_RTC_CS);

	/* Receive value from register and pull CS HIGH */
	uint8_t buffer = SPI_CMD_LAST_RTC(SEND_FF, SPI_RTC_CS);

	return buffer;

}

/*
 * @what: Write data to RTC register
 * @why:
 */
void M41T94_Write_Register(uint8_t address, uint8_t data)
{
	/* Send register address. First bit must be HIGH, then 7 bit address. SPI_CMD_RTC pulls CS LOW */
	SPI_CMD_RTC((0x80 | address), SPI_RTC_CS);

	/* Write data to register and pull CS HIGH */
	SPI_CMD_LAST_RTC(data, SPI_RTC_CS);

	return;
}

/*
 * @what: Obtain seconds from RTC
 * @why:
 */
uint8_t RTC_Get_Seconds(void)
{
	uint8_t buffer =  M41T94_Read_Register(M41T94_REG_SECONDS);

	return bcd2bin(buffer);
}

/*
 * @what: Obtain minutes from RTC
 * @why:
 */
uint8_t RTC_Get_Minutes(void)
{
	uint8_t buffer = M41T94_Read_Register(M41T94_REG_MINUTES);

	return bcd2bin(buffer);
}

/*
 * @what: Obtain hours from RTC
 * @why:
 */
uint8_t RTC_Get_Hours(void)
{
	uint8_t buffer = M41T94_Read_Register(M41T94_REG_HOURS);

	return bcd2bin(buffer);
}

/*
 * @what: Obtain weekday from RTC
 * @why:
 */
uint8_t RTC_Get_Weekday(void)
{
	uint8_t buffer = M41T94_Read_Register(M41T94_REG_WDAY);

	return bcd2bin(buffer);
}

/*
 * @what: Obtain date from RTC
 * @why:
 */
uint8_t RTC_Get_Day(void)
{
	uint8_t buffer = M41T94_Read_Register(M41T94_REG_DAY);

	return bcd2bin(buffer);
}

/*
 * @what: Obtain month from RTC
 * @why:
 */
uint8_t RTC_Get_Month(void)
{
	uint8_t buffer = M41T94_Read_Register(M41T94_REG_MONTH);

	return bcd2bin(buffer);
}

/*
 * @what: Obtain year from RTC
 * @why:
 */
uint8_t RTC_Get_Year(void)
{
	uint8_t buffer = M41T94_Read_Register(M41T94_REG_YEAR);

	return bcd2bin(buffer);
}

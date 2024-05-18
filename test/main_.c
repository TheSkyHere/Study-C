#include "stdio.h"
#include "stdlib.h"
//by sky

typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned char u8;

#define POLY    (0x1070U << 3)


static u8 crc8(u16 data)
{
	int i;

	for (i = 0; i < 8; i++) {
		if (data & 0x8000)
			data = data ^ POLY;
		data = data << 1;
	}
	return (u8)(data >> 8);
}

static u8 i2c_smbus_pec(u8 crc, u8 *p, size_t count)
{
	int i;

	for (i = 0; i < count; i++)
		crc = crc8((crc ^ p[i]) << 8);
	return crc;
}




int main()
{
    u8 pec;
    char buf[12] = {0xc8};
    char buf0[12] = {0xc9};
    char buf1[12] = {0x88};
    char buf2[12] = {0xc3,0xe0};
    pec = i2c_smbus_pec(0, buf, 1);
    pec = i2c_smbus_pec(pec, buf1, 1);
    pec = i2c_smbus_pec(pec, buf0, 1);
    pec = i2c_smbus_pec(pec, buf2, 2);
    printf("test===0x%x\n",pec);

    return 0;
}
class DS1307(object):
    """Driver para el RTC DS1307 en MicroPython."""
    def __init__(self, i2c, addr=0x68):
        self.i2c = i2c
        self.addr = addr
        self.weekday_start = 1

    def dec2bcd(self, value):
        """Convierte decimal a Binary Coded Decimal (BCD)."""
        return (value // 10) << 4 | (value % 10)

    def bcd2dec(self, value):
        """Convierte Binary Coded Decimal (BCD) a decimal."""
        return ((value >> 4) * 10) + (value & 0x0F)

    def datetime(self, datetime=None):
        """Obtiene o configura la fecha y hora."""
        if datetime is None:
            buf = self.i2c.readfrom_mem(self.addr, 0, 7)
            return (
                self.bcd2dec(buf[6]) + 2000, # año
                self.bcd2dec(buf[5]),        # mes
                self.bcd2dec(buf[4]),        # día
                self.bcd2dec(buf[3] - self.weekday_start), # día de la semana
                self.bcd2dec(buf[2]),        # hora
                self.bcd2dec(buf[1]),        # minuto
                self.bcd2dec(buf[0] & 0x7F), # segundo
                0                            # subsegundos
            )
        buf = bytearray(7)
        buf[0] = self.dec2bcd(datetime[6]) & 0x7F # segundo
        buf[1] = self.dec2bcd(datetime[5])        # minuto
        buf[2] = self.dec2bcd(datetime[4])        # hora
        buf[3] = self.dec2bcd(datetime[3] + self.weekday_start) # día de la semana
        buf[4] = self.dec2bcd(datetime[2])        # día
        buf[5] = self.dec2bcd(datetime[1])        # mes
        buf[6] = self.dec2bcd(datetime[0] - 2000) # año
        self.i2c.writeto_mem(self.addr, 0, buf)
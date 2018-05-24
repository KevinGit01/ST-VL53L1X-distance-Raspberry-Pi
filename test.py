#!/usr/bin/python
# -*- coding:utf-8 -*-
import smbus
import time

address = 0x29

bus = smbus.SMBus(1)
while True:
    result = bus.read_word_data(address, 0x010F)
    print result
time.sleep(0.5)

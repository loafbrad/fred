/*
Logical address make no distinction among 3 different address spaces handled by MMU
Main:
000000-1FFFFF System RAM
I/O:
000000-001FFF Slot 1 decode low
002000-003FFF Slot 1 decode high
004000-005FFF Slot 2 decode low
006000-007FFF Slot 2 decode high
008000-009FFF Slot 3 decode low
00A000-00BFFF Slot 3 decode high
00C000-00CFFF Floppy Controller memory
00D000-00DFFF I/O Devices
00E000-00EFFF CPU Devices

During operation only OS has access to special I/O
Only used during startup
Special I/O:
xx0000-xx3FFF Boot and Self test ROM
*/
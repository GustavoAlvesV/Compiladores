.section .data
	 zero: .quad 0
.section . text
	 .extern printf
	 .global _start
_start:
	 MOVL 4.0 , 602(RSP) 
	 PUSHL 602(RSP) 
	 PUSHL $intf
	 CALL printf 
	 MOVL 000(RRX), %RAX 
	 ADDL 3.0 , %RAX 
	 MOVL %RAX, 000(RRX) 
	 MOVL 000(RRX), %RAX 
	 MULTL 4.0 , %RAX 
	 MOVL %RAX, 000(RRX) 
	 MOVL 000(RRX), %RAX 
	 SUBL 1.0 , %RAX 
	 MOVL %RAX, 000(RRX) 
	 MOVL 000(RX) , 600(RSP) 
	 PUSHL 600(RSP) 
	 PUSHL $intf
	 CALL printf 

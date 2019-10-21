.data
	STR1: .string "A"
	STR2: .string "A"
	MSG1: .string "Deu Bom"
	MSG2: .string "Deu Ruim"
.text
	la s0, STR1
	la s1, STR2
	
REPETE: lb t0, 0(s0)
	lb t1, 0(s1)
	bne t0, t1, DEURUIM
	addi s0, s0, 1
	addi s1, s1, 1
	bne t0, zero, REPETE
	
	li a7, 4
	la a0, MSG1
	ecall
	
	jal zero, FIM
	
	
DEURUIM: li a7, 4
	 la a0, MSG2
	 ecall
FIM:
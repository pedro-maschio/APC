.data

.text
	li a7, 5
	ecall
	mv s0, a0 # s0 = a
	
	li a7, 5
	ecall
	mv s1, a0 # s0 = b
	
	li a7, 5
	ecall
	mv s2, a0 # s0 = c
	
	li a7, 5
	ecall
	mv s3, a0 # s0 = x
	
	
	mul s3, s3, s3 # x^2
	mul s3, s3, s0 # x^2*a
	
	mul s1, s1, s3 # b*x
	
	add t0, s3, s1 # x^2*a + b*x
	add t0, t0, s2 #x^2*a + b*x + c
	
	mv a0, t0
	
	li a7, 1
	ecall
	
	
	
	
	
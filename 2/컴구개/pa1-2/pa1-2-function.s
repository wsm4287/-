product:
#-----------------------------------------------------
# Your code "START" here
#-----------------------------------------------------
addi $sp, $sp, -36
sw $ra, 32($sp)
sw $s0, 28($sp)	 #i
sw $s1, 24($sp) 	 #j
sw $s2, 20($sp)	 #k
sw $s3, 16($sp)	 #N
sw $s4, 12($sp)	 #DIM
sw $s5, 8($sp)        #MAX
sw $s6, 4($sp)
sw $s7, 0($sp)
la $s3, N
lw $s3, 0($s3)
la $s4, DIM
lw $s4, 0($s4)

L0:
move $v1, $zero
addi $v1, 1
beq $v1, $s3, exit
move $s0, $zero
move $s1, $zero
move $s2, $zero
move $s5, $zero
addi $s5, $s5, 10


L1 :
la $a0, C
la $a1, B
la $a2, A
move $t0, $s0
move $t1, $s1
move $t2, $s2
sll $t2, $t2, 2
sll $t1, $t1, 2
sll $t0, $t0, 2
add $t7, $a0, $t1
mul $t3, $t0, $s5
add $t7, $t7, $t3
add $s7, $a1, $t1
mul $t3, $t2, $s5
add $s7, $s7, $t3
add $t6, $a2, $t2
mul $t3, $t0, $s5
add $t6, $t6, $t3
lw $t4, 0($t6)
lw $t5, 0($s7)
mul $t5, $t4, $t5
lw $v0, 0($t7)
add $t5, $t5, $v0
sw $t5, 0($t7)
addi $s2, $s2, 1
slt $t0, $s2, $s4
bne $t0, $zero, L1
move $s2, $zero
addi $s1, $s1, 1
slt $t0, $s1, $s4
bne $t0, $zero, L1
move $s1, $zero
addi $s0, $s0, 1
slt $t0, $s0, $s4
bne $t0, $zero, L1
move $s0, $zero
move $s1, $zero
move $s2, $zero
j L2

L2 :
la $a0, C
la $a1, B
move $t0, $s0
move $t1, $s1
sll $t0, $t0, 2
sll $t1, $t1, 2
mul $t0, $t0, $s5
add $a0, $a0, $t0
add $a0, $a0, $t1
add $a1, $a1, $t0
add $a1, $a1, $t1
lw $t2, 0($a0)
sw $t2, 0($a1)
sw $zero, 0($a0)
addi $s1, $s1, 1
slt $t0, $s1, $s4
bne $t0, $zero, L2
move $s1, $zero
addi $s0, $s0, 1
slt $t0, $s0, $s4
bne $t0, $zero, L2
addi $s3, $s3 -1
sw $s3, N
jal product



exit:
lw $s7, 0($sp)
lw $s6, 4($sp)
lw $s5, 8($sp)   
lw $s4, 12($sp)	   
lw $s3, 16($sp)	
lw $s2, 20($sp)	
lw $s1, 24($sp) 	
lw $s0, 28($sp)
lw $ra, 32($sp)
addi $sp, $sp, 36


#-----------------------------------------------------
# Your code "END" here
#-----------------------------------------------------
jr  $ra

printResult:
#-----------------------------------------------------
# Your code "START" here
#-----------------------------------------------------
addi $sp, $sp, -20
sw $ra, 16($sp)
sw $s0, 12($sp)	 #i
sw $s1, 8($sp)	 #j
sw $s2, 4($sp)	 #DIM
sw $s3, 0($sp)
la $s2, DIM
lw $s2, 0($s2)
move $s0, $zero
move $s1, $zero
move $s3, $zero
addi $s3, $s3, 10

L3:
la $a2, B
move $a1, $a2
sll $t0, $s0, 2
sll $t1, $s1, 2
mul $t0, $t0, $s3
add $a1, $a1, $t0
add $a1, $a1, $t1
li $v0, 1
lw $a0, 0($a1)
syscall
li $v0, 4
la $a0, SPACE
syscall
addi $s1, $s1, 1
slt $t2, $s1, $s2
bne $t2, $zero, L3
li $v0, 4
la $a0, ENTER
syscall
move $s1, $zero
addi $s0, $s0, 1
slt $t2, $s0, $s2
bne $t2, $zero, L3
j exit2

exit2:
lw $s3, 0($sp)
lw $s2, 4($sp)
lw $s1, 8($sp)
lw $s0, 12($sp)
lw $ra, 16($sp)
addi $sp, $sp, 20
#-----------------------------------------------------
# Your code "END" here
#-----------------------------------------------------
jr  $ra
swap:
#-----------------------------------------------------
# Your code "START" here
#-----------------------------------------------------
addi $sp, $sp, -12
sw $ra, 8($sp)
sw $s0, 4($sp)		#temp
sw $s1, 0($sp)

lw $s0, 0($a2)
lw $s1, 0($a3)
sw $s1, 0($a2)
sw $s0, 0($a3)


lw $s1, 0($sp)
lw $s0, 4($sp)
lw $ra, 8($sp)
addi $sp, $sp, 12
#-----------------------------------------------------
# Your code "END" here
#-----------------------------------------------------
jr  $ra

partition:
#-----------------------------------------------------
# Your code "START" here
#-----------------------------------------------------
addi $sp, $sp, -36
sw $ra, 32($sp)
sw $s0, 28($sp)			#pivot
sw $s1, 24($sp)			#temp
sw $s2, 20($sp)			#low
sw $s3, 16($sp)			#high
sw $s4, 12($sp)			#list
sw $s5, 8($sp)			#int size
sw $s6, 4($sp)			#list[low]
sw $s7, 0($sp)			#list[hight]

move $s2, $a0
addi $s3, $a1, 1
la $s4, list
sll $s5, $a0, 2
add $s0, $s4, $s5
lw $s0, 0($s0)


L1 :
addi $s2, $s2, 1
slt $t0, $a1, $s2
bne $t0, $zero, L2
move $s6, $s4
sll $t1, $s2, 2
add $s6, $s6, $t1
lw $t6, 0($s6)
slt $t0, $t6, $s0
beq $t0, $zero, L2
j L1

L2 :
addi $s3, $s3, -1
slt $t0, $s3, $a0
bne $t0, $zero, L3
move $s7, $s4
sll $t1, $s3, 2
add $s7, $s7, $t1
lw $t7, 0($s7)
slt $t0, $s0, $t7
beq $t0, $zero, L3
j L2

L3:
slt $t0, $s2, $s3
sll $t1, $s2, 2
sll $t2, $s3, 2
add $a2, $s4, $t1
add $a3, $s4, $t2
bne $t0, $zero, L4
j L5 

L4 :
jal swap

L5 :
slt $t0, $s2, $s3
bne $t0, $zero, L1


sll $t1, $a0, 2
add $a2, $s4, $t1
sll $t1, $s3, 2
add $a3, $s4, $t1 
jal swap

move $v0, $s3


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

Quick_sort:
#-----------------------------------------------------
# Your code "START" here
#-----------------------------------------------------
addi $sp, $sp, -16
sw $ra, 12($sp)
sw $s0, 8($sp)		#left
sw $s1, 4($sp)		#right
sw $s2, 0($sp)		#p

move $s0, $a0
move $s1, $a1
slt $t0, $s0, $s1
beq $t0, $zero, exit 
jal partition

move $s2, $v0
addi $a1, $s2, -1
jal Quick_sort

move $a1, $s1
addi $a0, $2, 1
jal Quick_sort

exit :
lw $s2, 0($sp)
lw $s1, 4($sp)
lw $s0, 8($sp)
lw $ra, 12($sp)
addi $sp, $sp, 16

#-----------------------------------------------------
# Your code "END" here
#-----------------------------------------------------
jr  $ra
GCD:
addi $sp, $sp, -20
sw $ra, 16($sp)			
sw $s0, 12($sp)
sw $s1, 8($sp)				
sw $s2, 4($sp)
sw $s3, 0($sp)		
slt $t0, $a0, $a1
bne $t0, $zero, L1
move $s1,$a1
j L2

L1:
move $s1, $a0
j  L2

L2:
move $s0, $s1
slt $t0, $zero, $s0
bne $t0, $zero L3
j exit

L3:
move $t1, $s0
move $t2, $a0
div $t2, $t1
mfhi $t2
addi $s0, $s0, -1
bne $t2, $zero, L3
addi $s0, $s0, 1
move $t1, $s0
move $t2, $a1
div $t2, $t1
mfhi $t2
addi $s0, $s0, -1
bne $t2, $zero, L3
addi $s0, $s0, 1
move $s2, $s0
move $v0, $s2
lw $s3, 0($sp)
lw $s2, 4($sp)
lw $s1, 8($sp)
lw $s0, 12($sp)
lw $ra, 16($sp)
addi $sp, $sp, 20
j exit



exit :
jr  $ra


LCM:
addi $sp, $sp, -20
sw $ra, 16($sp)			
sw $s0, 12($sp)
sw $s1, 8($sp)				
sw $s2, 4($sp)
sw $s3, 0($sp)		
slt $t0, $a1, $a0
beq $t0, $zero, L4
move $s1,$a0
move $s0, $s1
j L5

L4:
move $s1, $a1
move $s0, $s1
j  L5

L5:
move $t1, $s0
move $t2, $a0
div $t1, $t2
mfhi $t2
add $s0, $s0, $s1
bne $t2, $zero, L5
sub $s0, $s0, $s1
move $t1, $s0
move $t2, $a1
div $t1, $t2
mfhi $t2
add $s0, $s0, $s1
bne $t2, $zero, L5
sub $s0, $s0, $s1
move $s2, $s0
move $v0, $s2
lw $s3, 0($sp)
lw $s2, 4($sp)
lw $s1, 8($sp)
lw $s0, 12($sp)
lw $ra, 16($sp)
addi $sp, $sp, 20
j exit


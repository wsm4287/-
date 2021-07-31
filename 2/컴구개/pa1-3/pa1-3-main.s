##################################################
#SWE3005 Introduction to Computer Architectures (Fall 2019)

#Instructor: Prof. Jinkyu Jeong (jinkyu@skku.edu)

#TA: Minwoo Ahn(minwoo.ahn@csi.skku.edu), Sunghwan Kim(sunghwan.kim@csi.skku.edu)

#Semiconductor Building #400509

#Author: Sunghwan Kim

#Description: Quick sort

#Copyright (c) 2019 SungKyunKwan Univ. CSI(Computer Systems Intelligence)
##################################################
.data
  buffer:	.space 1000
  list:   .space 400
  input:	.asciiz "pa1-3.input"
  ENTER:	.asciiz "\n"
  SPACE:	.asciiz " "

.text
main:
  addi	$sp, $sp, -12
  sw	$ra, 0($sp)

  # open input file
  li	$v0, 13
  la	$a0, input
  la	$a1, 0x000
  la	$a2, 0644
  syscall
  move $s0, $v0
  #############

  # read input file
  li	$v0, 14
  move $a0, $s0
  la	$a1, buffer
  li	$a2, 1000
  syscall
  #############

  add   $s1, $a1, $v0
  addi  $s2, $s1, -1
  li    $s3, 10
  lb    $s4, 0($s2)
  beq   $s3, $s4, LNX
WIN:
  sb    $s3, 0($s1)
  sb    $0, 1($s1)
  j     MER
LNX:
  sb    $0, 0($s1)
MER:

  # close input file
  li	$v0, 16
  move $a0, $s0
  syscall
  #############

INIT:
  #  init  #
  #  0($sp) =  $ra
  #  4($sp) =  &buffer[0]
  la    $t0, buffer     
  sw    $t0, 4($sp)

START:
  #  start  #
  move  $t0, $0                 # i = 0
  move  $t1, $0                 # n = 0
  lw    $s0, 4($sp)             # &buffer[cursor]
  li    $s1, 32                 # $s1 = ' '   (space)
  li    $s2, 10                 # $s2 = '\n'  (newline)
  li    $s3, 10                 # $s3 = digit (10)
  li    $s4, 4                  # $s4 = digit (4)
  la    $s5, list               # $s5 = &list[0]

WHILELOOP:
  lb    $t2, 0($s0)             # buffer[cursor]
  beq   $t2, $s1, ENDWHILE      # buffer[cursor] == ' '?
  beq   $t2, $s2, ENDWHILE      # buffer[cursor] == '\n'?
  addi  $s0, $s0, 1             # cursor++
  mul   $t3, $t1, $s4           # $t3 = n * 4
  add   $t4, $s5, $t3           # $t4 = &list[n]
  lw    $t3, 0($t4)             # $t3 = list[n]
  mul   $t3, $t3, $s3           # list[n] *= 10
  add   $t3, $t3, $t2
  addi  $t3, $t3, -48           # list[n] += buffer[cursor] - '0'
  sw    $t3, 0($t4)             
  j     WHILELOOP
ENDWHILE:
  addi  $t1, $t1, 1             # n++
  lb    $t2, 0($s0)             # buffer[cursor]
  addi  $s0, $s0, 1             # cursor++
  beq   $t2, $s2, ENDLOOP       # buffer[cursor] == '\n'?
  j     WHILELOOP
ENDLOOP:
  # call Quick_sort
  move  $a0, $0                 # arg1: 0
  addi  $a1, $t1, -1            # arg2: n-1
  sw    $t1, 8($sp)             # save n
  jal   Quick_sort

  # print result
  lw    $t1, 8($sp)             # load n
PRINTLOOP:
  slt   $t2, $t0, $t1
  beq   $t2, $0, END            # check i < n
  mul   $t2, $t0, $s4           # $t2 = i * 4
  add   $t3, $s5, $t2           # $t3 = &list[i]
  li	$v0, 1
  lw	$a0, 0($t3)
  syscall                       # printf("%d", list[i])
  li	$v0, 4
  la	$a0, SPACE
  syscall                       # printf(" ")
  addi $t0, $t0, 1              # i++
  j PRINTLOOP
END:
  li	$v0, 4
  la	$a0, ENTER
  syscall                       # printf("\n")
  # return
  lw    $ra, 0($sp)
  addi  $sp, $sp, 12
  jr    $ra
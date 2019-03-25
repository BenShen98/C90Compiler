.globl main
.ent main
main:
.frame $fp,72,$31
addiu $sp, $sp, -72
sw $31, 20($sp)
# Enter scope
# Enter scope
li $t0,2 #imm id _1:16_
lw $t1,60($sp) #load _1:12_ to$t1
li $t2,4 #imm id _1:20_
mult $t0,$t2 #cal offset _1:24
mflo $t3#cal offset _1:24
addu $t0,$t1,$t3 #dst id _1:28_
lw $t0,0($t0) #de ref
li $t3,1 #imm id _1:36_
# assign _1:36_ to _1:32_ in reg $t3
li $t0,12 #imm id _1:40_
# assign _1:40_ to _1:44_ in reg $t0
move $2,$t0
b EXIT_main
# End scope
# End scope
EXIT_main:
lw $31, 20($sp)
addiu $sp, $sp, 72
j $31
.end main


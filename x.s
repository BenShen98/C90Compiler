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
li $t3,1 #imm id _1:32_
sw $t0,44($sp) #write back id 1:28
sw $t2,52($sp) #write back id 1:20
sw $t3,40($sp) #write back id 1:32
lw $t0,40($sp) #load _1:32_ to$t0
lw $t0,0($t0) #de ref
lw $t1,44($sp) #load _1:28_ to$t1
lw $t2,40($sp) #load _1:32_ to$t2
sw $t2,0($t1) #write back via indirection
li $t3,12 #imm id _1:40_
# assign _1:40_ to _1:44_ in reg $t3
move $2,$t3
b EXIT_main
# End scope
# End scope
EXIT_main:
lw $31, 20($sp)
addiu $sp, $sp, 72
j $31
.end main


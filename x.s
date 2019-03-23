.globl testfor
.ent testfor
testfor:
.frame $fp,56,$31
addiu $sp, $sp, -56
sw $31, 20($sp)
li $t0,0 #imm id _8_
# assign _8_ to _4_ in reg $t0
li $t1,0 #imm id _12_
li $t2,0 #imm id _16_
li $t3,0 #imm id _20_
# assign _20_ to _12_ in reg $t3
ForStart_0_testfor:

beq $t2,$0,ForEnd_1_testfor
li $t1,1 #imm id _24_
addu $t4,$t0,$t1 #dst id _28_
# assign _28_ to _4_ in reg $t4
b ForStart_0_testfor
ForEnd_1_testfor:

# assign _4_ to _32_ in reg $t4
move $2,$t4
b EXIT_testfor
EXIT_testfor:
lw $31, 20($sp)
addiu $sp, $sp, 56
j $31
.end testfor


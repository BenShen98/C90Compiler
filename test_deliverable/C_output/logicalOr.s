.globl f
.ent f
f:
.frame $fp,56,$31
addiu $sp, $sp, -56
sw $31, 20($sp)
# Enter scope
# Enter scope
lw $t0,52($sp) #load _1:4_ to$t0
nop
li $t1,3 #imm id _1:8_
li $t2,2 #imm id _1:12_
slt $t3,$t2,$t1 #dst id _1:16_
bne $t3,$0,ORShort_0_f
li $t1,3 #imm id _1:20_
li $t2,2 #imm id _1:24_
slt $t4,$t1,$t2 #dst id _1:28_
bne $t4,$0,ORShort_0_f
move $t0,$0 #
sw $t0,52($sp) #write back id 1:4
b OREnd_1_f
ORShort_0_f:

li $t0,1 #
sw $t0,52($sp) #write back id 1:4
OREnd_1_f:

sw $t3,40($sp) #write back id 1:16
sw $t4,28($sp) #write back id 1:28
lw $t0,52($sp) #load _1:4_ to$t0
nop
# assign _1:4_ to _1:32_ in reg $t0
move $2,$t0
b EXIT_f
# End scope
# End scope
EXIT_f:
lw $31, 20($sp)
addiu $sp, $sp, 56
j $31
.end f


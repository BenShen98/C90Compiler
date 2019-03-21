.globl oneLif
.ent oneLif
oneLif:
.frame $fp,64,$31
addiu $sp, $sp, -64
sw $31, 20($sp)
li $t0,5 #imm id _8_
# assign _8_ to _4_ in reg $t0
li $t1,6 #imm id _20_
xor $t2,$t0,$t1 #dst id _24_
sltu $t2,$t2,0x1 #dst id _24_
beq $t2,$0,elseStart_0_oneLif
li $t1,6 #imm id _28_
# assign _28_ to _16_ in reg $t1
b elseEnd_1_oneLif
elseStart_0_oneLif:

li $t3,4 #imm id _32_
# assign _32_ to _16_ in reg $t3
elseEnd_1_oneLif:

# assign _16_ to _12_ in reg $t3
# assign _12_ to _36_ in reg $t3
move $2,$t3
b EXIT_oneLif
EXIT_oneLif:
lw $31, 20($sp)
addiu $sp, $sp, 64
j $31
.end oneLif


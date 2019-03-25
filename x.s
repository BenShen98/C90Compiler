.globl oneLif
.ent oneLif
oneLif:
.frame $fp,64,$31
addiu $sp, $sp, -64
sw $31, 20($sp)
# Enter scope
# Enter scope
li $t0,5 #imm id _1:8_
# assign _1:8_ to _1:4_ in reg $t0
li $t1,6 #imm id _1:20_
xor $t2,$t0,$t1 #dst id _1:24_
sltu $t2,$t2,0x1 #dst id _1:24_
sw $t0,60($sp) #write back id 1:4
sw $t2,40($sp) #write back id 1:24
lw $t0,40($sp) #load _1:24_ to$t0
beq $t0,$0,elseStart_0_oneLif
li $t1,6 #imm id _1:28_
# assign _1:28_ to _1:16_ in reg $t1
sw $t1,48($sp) #write back id 1:16
b elseEnd_1_oneLif
elseStart_0_oneLif:

li $t0,4 #imm id _1:32_
# assign _1:32_ to _1:16_ in reg $t0
sw $t0,48($sp) #write back id 1:16
elseEnd_1_oneLif:

lw $t0,48($sp) #load _1:16_ to$t0
# assign _1:16_ to _1:12_ in reg $t0
# assign _1:12_ to _1:36_ in reg $t0
move $2,$t0
b EXIT_oneLif
# End scope
# End scope
EXIT_oneLif:
lw $31, 20($sp)
addiu $sp, $sp, 64
j $31
.end oneLif


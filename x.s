.globl testforinc
.ent testforinc
testforinc:
.frame $fp,64,$31
addiu $sp, $sp, -64
sw $31, 20($sp)
li $t0,0 #imm id _8_
# assign _8_ to _4_ in reg $t0
li $t1,0 #imm id _12_
li $t2,0 #imm id _16_
li $t3,0 #imm id _20_
# assign _20_ to _12_ in reg $t3
ForStart_0_testforinc:

beq $t2,$0,ForEnd_1_testforinc
li $t1,1 #imm id _24_
addu $t4,$t3,$t1 #dst id _28_
# assign _28_ to _12_ in reg $t4
li $t1,1 #imm id _32_
# assign _32_ to _36_ in reg $t1
addu $t0,$t1,$t0 #+=32
b ForStart_0_testforinc
ForEnd_1_testforinc:

# assign _4_ to _40_ in reg $t0
move $2,$t0
b EXIT_testforinc
sw $t0,24($sp) #write back id 40
sw $t1,28($sp) #write back id 36
sw $t2,48($sp) #write back id 16
sw $t4,52($sp) #write back id 12
EXIT_testforinc:
lw $31, 20($sp)
addiu $sp, $sp, 64
j $31
.end testforinc


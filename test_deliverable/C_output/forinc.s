.globl testforinc
.ent testforinc
testforinc:
.frame $fp,64,$31
addiu $sp, $sp, -64
sw $31, 20($sp)
# Enter scope
# Enter scope
li $t0,0 #imm id _1:8_
sw $t0,56($sp) #write back id 1:8
lw $t0,56($sp) #load _1:8_ to$t0
nop
# assign _1:8_ to _1:4_ in reg $t0
li $t1,0 #imm id _1:12_
li $t2,0 #imm id _1:16_
sw $t0,60($sp) #write back id 1:4
sw $t1,52($sp) #write back id 1:12
sw $t2,48($sp) #write back id 1:16
lw $t0,48($sp) #load _1:16_ to$t0
nop
# assign _1:16_ to _1:12_ in reg $t0
sw $t0,52($sp) #write back id 1:12
ItrCondition_0_testforinc:

li $t0,0 #imm id _1:20_
beq $t0,$0,ItrEnd_1_testforinc
# Enter scope
sw $t0,44($sp) #write back id 1:20
li $t0,1 #imm id _2:4_
sw $t0,28($sp) #write back id 2:4
lw $t0,60($sp) #load _1:4_ to$t0
nop
lw $t1,28($sp) #load _2:4_ to$t1
nop
addu $t2,$t0,$t1 #dst id _2:8_
# assign _2:8_ to _1:4_ in reg $t2
conti_2_testforinc:

# End scope
sw $t2,60($sp) #write back id 1:4
li $t0,1 #imm id _1:24_
lw $t1,52($sp) #load _1:12_ to$t1
nop
addu $t2,$t1,$t0 #dst id _1:28_
sw $t2,36($sp) #write back id 1:28
lw $t0,36($sp) #load _1:28_ to$t0
nop
# assign _1:28_ to _1:12_ in reg $t0
sw $t0,52($sp) #write back id 1:12
b ItrCondition_0_testforinc
ItrEnd_1_testforinc:

lw $t0,60($sp) #load _1:4_ to$t0
nop
# assign _1:4_ to _1:32_ in reg $t0
move $2,$t0
b EXIT_testforinc
# End scope
# End scope
EXIT_testforinc:
lw $31, 20($sp)
addiu $sp, $sp, 64
j $31
.end testforinc


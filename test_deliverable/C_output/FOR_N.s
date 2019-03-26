.globl testfor
.ent testfor
testfor:
.frame $fp,88,$31
addiu $sp, $sp, -88
sw $31, 20($sp)
# Enter scope
# Enter scope
li $t0,0 #imm id _1:8_
sw $t0,80($sp) #write back id 1:8
lw $t0,80($sp) #load _1:8_ to$t0
nop
# assign _1:8_ to _1:4_ in reg $t0
li $t1,0 #imm id _1:12_
li $t2,5 #imm id _1:20_
sw $t0,84($sp) #write back id 1:4
sw $t1,76($sp) #write back id 1:12
sw $t2,68($sp) #write back id 1:20
lw $t0,68($sp) #load _1:20_ to$t0
nop
# assign _1:20_ to _1:16_ in reg $t0
li $t1,0 #imm id _1:24_
sw $t0,72($sp) #write back id 1:16
sw $t1,64($sp) #write back id 1:24
lw $t0,64($sp) #load _1:24_ to$t0
nop
# assign _1:24_ to _1:12_ in reg $t0
sw $t0,76($sp) #write back id 1:12
ItrCondition_0_testfor:

li $t0,0 #imm id _1:28_
beq $t0,$0,ItrEnd_1_testfor
# Enter scope
sw $t0,60($sp) #write back id 1:28
li $t0,1 #imm id _2:4_
sw $t0,32($sp) #write back id 2:4
lw $t0,84($sp) #load _1:4_ to$t0
nop
lw $t1,32($sp) #load _2:4_ to$t1
nop
addu $t2,$t0,$t1 #dst id _2:8_
# assign _2:8_ to _1:4_ in reg $t2
conti_2_testfor:

# End scope
sw $t2,84($sp) #write back id 1:4
b ItrCondition_0_testfor
ItrEnd_1_testfor:

li $t0,0 #imm id _1:32_
sw $t0,56($sp) #write back id 1:32
lw $t0,56($sp) #load _1:32_ to$t0
nop
# assign _1:32_ to _1:12_ in reg $t0
sw $t0,76($sp) #write back id 1:12
ItrCondition_3_testfor:

lw $t0,72($sp) #load _1:16_ to$t0
nop
beq $t0,$0,ItrEnd_4_testfor
# Enter scope
conti_5_testfor:

# End scope
lw $t0,72($sp) #load _1:16_ to$t0
nop
addi $t1,$t0,-1 #add, swap org copy & org
sw $t0,52($sp) #write back id 1:36
sw $t1,72($sp) #write back id 1:16
b ItrCondition_3_testfor
ItrEnd_4_testfor:

lw $t0,84($sp) #load _1:4_ to$t0
nop
lw $t1,72($sp) #load _1:16_ to$t1
nop
addu $t2,$t0,$t1 #dst id _1:40_
li $t3,6 #imm id _1:44_
addu $t4,$t2,$t3 #dst id _1:48_
sw $t4,40($sp) #write back id 1:48
lw $t0,40($sp) #load _1:48_ to$t0
nop
# assign _1:48_ to _1:52_ in reg $t0
move $2,$t0
b EXIT_testfor
# End scope
# End scope
EXIT_testfor:
lw $31, 20($sp)
addiu $sp, $sp, 88
j $31
.end testfor


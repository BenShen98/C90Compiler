.globl f
.ent f
f:
.frame $fp,144,$31
addiu $sp, $sp, -144
sw $31, 20($sp)
# Enter scope
# Enter scope
li $t0,0 #imm id _1:8_
sw $t0,136($sp) #write back id 1:8
lw $t0,136($sp) #load _1:8_ to$t0
nop
# assign _1:8_ to _1:4_ in reg $t0
lw $t1,132($sp) #load _1:12_ to$t1
nop
lw $t2,128($sp) #load _1:16_ to$t2
nop
lw $t3,124($sp) #load _1:20_ to$t3
nop
lw $t4,120($sp) #load _1:24_ to$t4
nop
lw $t5,116($sp) #load _1:28_ to$t5
nop
lw $t6,112($sp) #load _1:32_ to$t6
nop
lw $t7,108($sp) #load _1:36_ to$t7
nop
addi $t0,$t0,1 #per increment of id _1:4_
sw $t0,140($sp) #write back id 1:4
li $t0,3 #imm id _1:40_
lw $t1,140($sp) #load _1:4_ to$t1
nop
slt $t2,$t0,$t1 #dst id _1:44_
bne $t2,$0,ORShort_13_f
addi $t1,$t1,1 #per increment of id _1:4_
sw $t1,140($sp) #write back id 1:4
li $t0,3 #imm id _1:48_
lw $t1,140($sp) #load _1:4_ to$t1
nop
slt $t3,$t0,$t1 #dst id _1:52_
bne $t3,$0,ORShort_13_f
move $t7,$0 #
sw $t7,108($sp) #write back id 1:36
b OREnd_14_f
ORShort_13_f:

li $t7,1 #
sw $t7,108($sp) #write back id 1:36
OREnd_14_f:

bne $t7,$0,ORShort_11_f
addi $t1,$t1,1 #per increment of id _1:4_
sw $t1,140($sp) #write back id 1:4
li $t0,3 #imm id _1:56_
lw $t1,140($sp) #load _1:4_ to$t1
nop
slt $t4,$t0,$t1 #dst id _1:60_
bne $t4,$0,ORShort_11_f
move $t6,$0 #
sw $t6,112($sp) #write back id 1:32
b OREnd_12_f
ORShort_11_f:

li $t6,1 #
sw $t6,112($sp) #write back id 1:32
OREnd_12_f:

bne $t6,$0,ORShort_9_f
addi $t1,$t1,1 #per increment of id _1:4_
sw $t1,140($sp) #write back id 1:4
li $t0,3 #imm id _1:64_
lw $t1,140($sp) #load _1:4_ to$t1
nop
slt $t5,$t0,$t1 #dst id _1:68_
bne $t5,$0,ORShort_9_f
lw $t0,116($sp) #load _1:28_ to$t0
nop
move $t0,$0 #
sw $t0,116($sp) #write back id 1:28
b OREnd_10_f
ORShort_9_f:

li $t0,1 #
sw $t0,116($sp) #write back id 1:28
OREnd_10_f:

bne $t0,$0,ORShort_7_f
addi $t1,$t1,1 #per increment of id _1:4_
sw $t1,140($sp) #write back id 1:4
li $t1,3 #imm id _1:72_
lw $t6,140($sp) #load _1:4_ to$t6
nop
slt $t7,$t1,$t6 #dst id _1:76_
bne $t7,$0,ORShort_7_f
lw $t1,120($sp) #load _1:24_ to$t1
nop
move $t1,$0 #
sw $t1,120($sp) #write back id 1:24
b OREnd_8_f
ORShort_7_f:

li $t1,1 #
sw $t1,120($sp) #write back id 1:24
OREnd_8_f:

bne $t1,$0,ORShort_5_f
addi $t6,$t6,1 #per increment of id _1:4_
sw $t6,140($sp) #write back id 1:4
li $t6,3 #imm id _1:80_
sw $t2,100($sp) #spill reg
lw $t2,140($sp) #load _1:4_ to$t2
nop
sw $t3,92($sp) #spill reg
slt $t3,$t6,$t2 #dst id _1:84_
bne $t3,$0,ORShort_5_f
lw $t6,124($sp) #load _1:20_ to$t6
nop
move $t6,$0 #
sw $t6,124($sp) #write back id 1:20
b OREnd_6_f
ORShort_5_f:

li $t6,1 #
sw $t6,124($sp) #write back id 1:20
OREnd_6_f:

bne $t6,$0,ORShort_3_f
addi $t2,$t2,1 #per increment of id _1:4_
sw $t2,140($sp) #write back id 1:4
li $t2,3 #imm id _1:88_
sw $t4,84($sp) #spill reg
lw $t4,140($sp) #load _1:4_ to$t4
nop
sw $t5,76($sp) #spill reg
slt $t5,$t2,$t4 #dst id _1:92_
bne $t5,$0,ORShort_3_f
lw $t2,128($sp) #load _1:16_ to$t2
nop
move $t2,$0 #
sw $t2,128($sp) #write back id 1:16
b OREnd_4_f
ORShort_3_f:

li $t2,1 #
sw $t2,128($sp) #write back id 1:16
OREnd_4_f:

bne $t2,$0,ORShort_1_f
addi $t4,$t4,1 #per increment of id _1:4_
sw $t4,140($sp) #write back id 1:4
li $t4,3 #imm id _1:96_
lw $t0,140($sp) #load _1:4_ to$t0
nop
sw $t7,68($sp) #spill reg
slt $t7,$t4,$t0 #dst id _1:100_
bne $t7,$0,ORShort_1_f
lw $t4,132($sp) #load _1:12_ to$t4
nop
move $t4,$0 #
sw $t4,132($sp) #write back id 1:12
b OREnd_2_f
ORShort_1_f:

li $t4,1 #
sw $t4,132($sp) #write back id 1:12
OREnd_2_f:

sw $t3,60($sp) #write back id 1:84
sw $t5,52($sp) #write back id 1:92
sw $t7,44($sp) #write back id 1:100
lw $t0,132($sp) #load _1:12_ to$t0
nop
beq $t0,$0,elseStart_15_f
lw $t0,140($sp) #load _1:4_ to$t0
nop
# assign _1:4_ to _1:104_ in reg $t0
move $2,$t0
b EXIT_f
sw $t0,40($sp) #write back id 1:104
b ifEnd_0_f
elseStart_15_f:

li $t0,1 #imm id _1:108_
subu $t0,$0,$t0 #negating_1:108_
sw $t0,32($sp) #write back id 1:112
lw $t0,32($sp) #load _1:112_ to$t0
nop
# assign _1:112_ to _1:116_ in reg $t0
move $2,$t0
b EXIT_f
ifEnd_0_f:

sw $t0,28($sp) #write back id 1:116
# End scope
# End scope
EXIT_f:
lw $31, 20($sp)
addiu $sp, $sp, 144
j $31
.end f


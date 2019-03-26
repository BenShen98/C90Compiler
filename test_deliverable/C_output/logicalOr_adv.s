.globl f
.ent f
f:
.frame $fp,160,$31
addiu $sp, $sp, -160
sw $31, 20($sp)
# Enter scope
# Enter scope
li $t0,0 #imm id _1:4_
lw $t1,152($sp) #load _1:8_ to$t1
nop
lw $t2,148($sp) #load _1:12_ to$t2
nop
lw $t3,144($sp) #load _1:16_ to$t3
nop
lw $t4,140($sp) #load _1:20_ to$t4
nop
lw $t5,136($sp) #load _1:24_ to$t5
nop
lw $t6,132($sp) #load _1:28_ to$t6
nop
lw $t7,128($sp) #load _1:32_ to$t7
nop
sw $t0,156($sp) #spill reg
lw $t0,124($sp) #load _1:36_ to$t0
nop
lw $t1,120($sp) #load _1:40_ to$t1
nop
lw $t2,156($sp) #load _1:4_ to$t2
nop
addi $t2,$t2,1 #per increment of id _1:4_
sw $t2,156($sp) #write back id 1:4
li $t2,3 #imm id _1:44_
lw $t3,156($sp) #load _1:4_ to$t3
nop
slt $t4,$t2,$t3 #dst id _1:48_
bne $t4,$0,ORShort_17_f
addi $t3,$t3,1 #per increment of id _1:4_
sw $t3,156($sp) #write back id 1:4
li $t2,3 #imm id _1:52_
lw $t3,156($sp) #load _1:4_ to$t3
nop
slt $t5,$t2,$t3 #dst id _1:56_
bne $t5,$0,ORShort_17_f
move $t1,$0 #
sw $t1,120($sp) #write back id 1:40
b OREnd_18_f
ORShort_17_f:

li $t1,1 #
sw $t1,120($sp) #write back id 1:40
OREnd_18_f:

bne $t1,$0,ORShort_15_f
addi $t3,$t3,1 #per increment of id _1:4_
sw $t3,156($sp) #write back id 1:4
li $t2,3 #imm id _1:60_
lw $t3,156($sp) #load _1:4_ to$t3
nop
slt $t6,$t2,$t3 #dst id _1:64_
bne $t6,$0,ORShort_15_f
move $t0,$0 #
sw $t0,124($sp) #write back id 1:36
b OREnd_16_f
ORShort_15_f:

li $t0,1 #
sw $t0,124($sp) #write back id 1:36
OREnd_16_f:

bne $t0,$0,ORShort_13_f
addi $t3,$t3,1 #per increment of id _1:4_
sw $t3,156($sp) #write back id 1:4
li $t2,3 #imm id _1:68_
lw $t3,156($sp) #load _1:4_ to$t3
nop
slt $t7,$t2,$t3 #dst id _1:72_
bne $t7,$0,ORShort_13_f
lw $t2,128($sp) #load _1:32_ to$t2
nop
move $t2,$0 #
sw $t2,128($sp) #write back id 1:32
b OREnd_14_f
ORShort_13_f:

li $t2,1 #
sw $t2,128($sp) #write back id 1:32
OREnd_14_f:

bne $t2,$0,ORShort_11_f
addi $t3,$t3,1 #per increment of id _1:4_
sw $t3,156($sp) #write back id 1:4
li $t3,3 #imm id _1:76_
lw $t0,156($sp) #load _1:4_ to$t0
nop
slt $t1,$t3,$t0 #dst id _1:80_
bne $t1,$0,ORShort_11_f
lw $t3,132($sp) #load _1:28_ to$t3
nop
move $t3,$0 #
sw $t3,132($sp) #write back id 1:28
b OREnd_12_f
ORShort_11_f:

li $t3,1 #
sw $t3,132($sp) #write back id 1:28
OREnd_12_f:

bne $t3,$0,ORShort_9_f
addi $t0,$t0,1 #per increment of id _1:4_
sw $t0,156($sp) #write back id 1:4
li $t0,3 #imm id _1:84_
sw $t4,112($sp) #spill reg
lw $t4,156($sp) #load _1:4_ to$t4
nop
sw $t5,104($sp) #spill reg
slt $t5,$t0,$t4 #dst id _1:88_
bne $t5,$0,ORShort_9_f
lw $t0,136($sp) #load _1:24_ to$t0
nop
move $t0,$0 #
sw $t0,136($sp) #write back id 1:24
b OREnd_10_f
ORShort_9_f:

li $t0,1 #
sw $t0,136($sp) #write back id 1:24
OREnd_10_f:

bne $t0,$0,ORShort_7_f
addi $t4,$t4,1 #per increment of id _1:4_
sw $t4,156($sp) #write back id 1:4
li $t4,3 #imm id _1:92_
sw $t6,96($sp) #spill reg
lw $t6,156($sp) #load _1:4_ to$t6
nop
sw $t7,88($sp) #spill reg
slt $t7,$t4,$t6 #dst id _1:96_
bne $t7,$0,ORShort_7_f
lw $t4,140($sp) #load _1:20_ to$t4
nop
move $t4,$0 #
sw $t4,140($sp) #write back id 1:20
b OREnd_8_f
ORShort_7_f:

li $t4,1 #
sw $t4,140($sp) #write back id 1:20
OREnd_8_f:

bne $t4,$0,ORShort_5_f
addi $t6,$t6,1 #per increment of id _1:4_
sw $t6,156($sp) #write back id 1:4
li $t6,3 #imm id _1:100_
lw $t2,156($sp) #load _1:4_ to$t2
nop
sw $t1,80($sp) #spill reg
slt $t1,$t6,$t2 #dst id _1:104_
bne $t1,$0,ORShort_5_f
lw $t6,144($sp) #load _1:16_ to$t6
nop
move $t6,$0 #
sw $t6,144($sp) #write back id 1:16
b OREnd_6_f
ORShort_5_f:

li $t6,1 #
sw $t6,144($sp) #write back id 1:16
OREnd_6_f:

bne $t6,$0,ORShort_3_f
addi $t2,$t2,1 #per increment of id _1:4_
sw $t2,156($sp) #write back id 1:4
li $t2,3 #imm id _1:108_
lw $t3,156($sp) #load _1:4_ to$t3
nop
sw $t5,72($sp) #spill reg
slt $t5,$t2,$t3 #dst id _1:112_
bne $t5,$0,ORShort_3_f
lw $t2,148($sp) #load _1:12_ to$t2
nop
move $t2,$0 #
sw $t2,148($sp) #write back id 1:12
b OREnd_4_f
ORShort_3_f:

li $t2,1 #
sw $t2,148($sp) #write back id 1:12
OREnd_4_f:

bne $t2,$0,ORShort_1_f
addi $t3,$t3,1 #per increment of id _1:4_
sw $t3,156($sp) #write back id 1:4
li $t3,3 #imm id _1:116_
lw $t0,156($sp) #load _1:4_ to$t0
nop
sw $t7,64($sp) #spill reg
slt $t7,$t3,$t0 #dst id _1:120_
bne $t7,$0,ORShort_1_f
lw $t3,152($sp) #load _1:8_ to$t3
nop
move $t3,$0 #
sw $t3,152($sp) #write back id 1:8
b OREnd_2_f
ORShort_1_f:

li $t3,1 #
sw $t3,152($sp) #write back id 1:8
OREnd_2_f:

sw $t1,56($sp) #write back id 1:104
sw $t5,48($sp) #write back id 1:112
sw $t7,40($sp) #write back id 1:120
lw $t0,152($sp) #load _1:8_ to$t0
nop
beq $t0,$0,elseStart_19_f
lw $t0,156($sp) #load _1:4_ to$t0
nop
# assign _1:4_ to _1:124_ in reg $t0
move $2,$t0
b EXIT_f
sw $t0,36($sp) #write back id 1:124
b ifEnd_0_f
elseStart_19_f:

li $t0,88 #imm id _1:128_
sw $t0,32($sp) #write back id 1:128
lw $t0,32($sp) #load _1:128_ to$t0
nop
# assign _1:128_ to _1:132_ in reg $t0
move $2,$t0
b EXIT_f
ifEnd_0_f:

sw $t0,28($sp) #write back id 1:132
# End scope
# End scope
EXIT_f:
lw $31, 20($sp)
addiu $sp, $sp, 160
j $31
.end f


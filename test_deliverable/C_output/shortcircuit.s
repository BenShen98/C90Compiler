.globl f1
.ent f1
f1:
.frame $fp,56,$31
addiu $sp, $sp, -56
sw $31, 20($sp)
# Enter scope
# Enter scope
li $t0,0 #imm id _1:8_
sw $t0,48($sp) #write back id 1:8
lw $t0,48($sp) #load _1:8_ to$t0
nop
# assign _1:8_ to _1:4_ in reg $t0
lw $t1,44($sp) #load _1:12_ to$t1
nop
addi $t0,$t0,1 #per increment of id _1:4_
sw $t0,52($sp) #write back id 1:4
lw $t0,52($sp) #load _1:4_ to$t0
nop
bne $t0,$0,ORShort_0_f1
li $t2,6 #imm id _1:16_
bne $t2,$0,ORShort_0_f1
move $t1,$0 #
sw $t1,44($sp) #write back id 1:12
b OREnd_1_f1
ORShort_0_f1:

li $t1,1 #
sw $t1,44($sp) #write back id 1:12
OREnd_1_f1:

li $t3,2 #imm id _1:20_
sll $t4,$t1,$t3 #dst id _1:24_
addu $t3,$t4,$t0 #dst id _1:28_
sw $t2,40($sp) #write back id 1:16
sw $t3,28($sp) #write back id 1:28
lw $t0,28($sp) #load _1:28_ to$t0
nop
# assign _1:28_ to _1:32_ in reg $t0
move $2,$t0
b EXIT_f1
# End scope
# End scope
EXIT_f1:
lw $31, 20($sp)
addiu $sp, $sp, 56
j $31
.end f1

.globl f2
.ent f2
f2:
.frame $fp,56,$31
addiu $sp, $sp, -56
sw $31, 20($sp)
# Enter scope
# Enter scope
li $t0,0 #imm id _1:8_
sw $t0,48($sp) #write back id 1:8
lw $t0,48($sp) #load _1:8_ to$t0
nop
# assign _1:8_ to _1:4_ in reg $t0
lw $t1,44($sp) #load _1:12_ to$t1
nop
li $t2,6 #imm id _1:16_
bne $t2,$0,ORShort_2_f2
addi $t0,$t0,1 #per increment of id _1:4_
sw $t0,52($sp) #write back id 1:4
lw $t0,52($sp) #load _1:4_ to$t0
nop
bne $t0,$0,ORShort_2_f2
move $t1,$0 #
sw $t1,44($sp) #write back id 1:12
b OREnd_3_f2
ORShort_2_f2:

li $t1,1 #
sw $t1,44($sp) #write back id 1:12
OREnd_3_f2:

li $t3,2 #imm id _1:20_
sll $t4,$t1,$t3 #dst id _1:24_
addu $t3,$t4,$t0 #dst id _1:28_
sw $t2,40($sp) #write back id 1:16
sw $t3,28($sp) #write back id 1:28
lw $t0,28($sp) #load _1:28_ to$t0
nop
# assign _1:28_ to _1:32_ in reg $t0
move $2,$t0
b EXIT_f2
# End scope
# End scope
EXIT_f2:
lw $31, 20($sp)
addiu $sp, $sp, 56
j $31
.end f2

.globl f3
.ent f3
f3:
.frame $fp,56,$31
addiu $sp, $sp, -56
sw $31, 20($sp)
# Enter scope
# Enter scope
li $t0,1 #imm id _1:8_
sw $t0,48($sp) #write back id 1:8
lw $t0,48($sp) #load _1:8_ to$t0
nop
# assign _1:8_ to _1:4_ in reg $t0
addi $t0,$t0,1 #per increment of id _1:4_
sw $t0,52($sp) #write back id 1:4
lw $t0,52($sp) #load _1:4_ to$t0
nop
beq $t0,$0,ANDShort_4_f3
li $t2,0 #imm id _1:16_
beq $t2,$0,ANDShort_4_f3
li $t1,1 #
sw $t1,44($sp) #write back id 1:12
b ANDEnd_5_f3
ANDShort_4_f3:

move $t1,$0 #
sw $t1,44($sp) #write back id 1:12
ANDEnd_5_f3:

li $t3,2 #imm id _1:20_
sll $t4,$t1,$t3 #dst id _1:24_
addu $t3,$t4,$t0 #dst id _1:28_
sw $t2,40($sp) #write back id 1:16
sw $t3,28($sp) #write back id 1:28
lw $t0,28($sp) #load _1:28_ to$t0
nop
# assign _1:28_ to _1:32_ in reg $t0
move $2,$t0
b EXIT_f3
# End scope
# End scope
EXIT_f3:
lw $31, 20($sp)
addiu $sp, $sp, 56
j $31
.end f3

.globl f4
.ent f4
f4:
.frame $fp,56,$31
addiu $sp, $sp, -56
sw $31, 20($sp)
# Enter scope
# Enter scope
li $t0,1 #imm id _1:8_
sw $t0,48($sp) #write back id 1:8
lw $t0,48($sp) #load _1:8_ to$t0
nop
# assign _1:8_ to _1:4_ in reg $t0
li $t2,0 #imm id _1:16_
beq $t2,$0,ANDShort_6_f4
addi $t0,$t0,1 #per increment of id _1:4_
sw $t0,52($sp) #write back id 1:4
lw $t0,52($sp) #load _1:4_ to$t0
nop
beq $t0,$0,ANDShort_6_f4
li $t1,1 #
sw $t1,44($sp) #write back id 1:12
b ANDEnd_7_f4
ANDShort_6_f4:

move $t1,$0 #
sw $t1,44($sp) #write back id 1:12
ANDEnd_7_f4:

li $t3,2 #imm id _1:20_
sll $t4,$t1,$t3 #dst id _1:24_
addu $t3,$t4,$t0 #dst id _1:28_
sw $t2,40($sp) #write back id 1:16
sw $t3,28($sp) #write back id 1:28
lw $t0,28($sp) #load _1:28_ to$t0
nop
# assign _1:28_ to _1:32_ in reg $t0
move $2,$t0
b EXIT_f4
# End scope
# End scope
EXIT_f4:
lw $31, 20($sp)
addiu $sp, $sp, 56
j $31
.end f4


.globl recadd
.ent recadd
recadd:
.frame $fp,56,$31
addiu $sp, $sp, -56
sw $31, 20($sp)
# Enter scope
sw $a0,56($sp) #store parameter 0:0
# Enter scope
li $t0,1 #imm id _1:4_
lw $t1,56($sp) #load _0:0_ to$t1
nop
slt $t2,$t1,$t0 #dst id _1:8_
sw $t2,48($sp) #write back id 1:8
lw $t0,48($sp) #load _1:8_ to$t0
nop
beq $t0,$0,elseStart_1_recadd
# Enter scope
li $t0,0 #imm id _2:4_
sw $t0,44($sp) #write back id 2:4
lw $t0,44($sp) #load _2:4_ to$t0
nop
# assign _2:4_ to _2:8_ in reg $t0
move $2,$t0
b EXIT_recadd
# End scope
b ifEnd_0_recadd
elseStart_1_recadd:

# Enter scope
li $t0,1 #imm id _2:4_
lw $t1,56($sp) #load _0:0_ to$t1
nop
subu $t2,$t1,$t0 #dst id _2:8_
sw $t2,40($sp) #write back id 2:8
lw $a0,40($sp) #load first 4 arg
nop
jal recadd
move $t0,$v0 #mv return to tReg _2:12_
lw $t1,56($sp) #load _0:0_ to$t1
nop
addu $t2,$t1,$t0 #dst id _2:16_
sw $t2,32($sp) #write back id 2:16
lw $t0,32($sp) #load _2:16_ to$t0
nop
# assign _2:16_ to _2:20_ in reg $t0
move $2,$t0
b EXIT_recadd
# End scope
ifEnd_0_recadd:

# End scope
# End scope
EXIT_recadd:
lw $31, 20($sp)
addiu $sp, $sp, 56
j $31
.end recadd


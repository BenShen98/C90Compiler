.globl ifelset
.ent ifelset
ifelset:
.frame $fp,40,$31
addiu $sp, $sp, -40
sw $31, 20($sp)
# Enter scope
sw $a0,40($sp) #store parameter 0:0
sw $a1,44($sp) #store parameter 0:-4
# Enter scope
lw $t0,40($sp) #load _0:0_ to$t0
nop
lw $t1,44($sp) #load _0:-4_ to$t1
nop
slt $t2,$t1,$t0 #dst id _1:4_
sw $t2,36($sp) #write back id 1:4
lw $t0,36($sp) #load _1:4_ to$t0
nop
beq $t0,$0,elseStart_1_ifelset
# Enter scope
li $t0,0 #imm id _2:4_
sw $t0,32($sp) #write back id 2:4
lw $t0,32($sp) #load _2:4_ to$t0
nop
# assign _2:4_ to _2:8_ in reg $t0
move $2,$t0
b EXIT_ifelset
# End scope
b ifEnd_0_ifelset
elseStart_1_ifelset:

# Enter scope
li $t0,2 #imm id _2:4_
sw $t0,32($sp) #write back id 2:4
lw $t0,32($sp) #load _2:4_ to$t0
nop
# assign _2:4_ to _2:8_ in reg $t0
move $2,$t0
b EXIT_ifelset
# End scope
ifEnd_0_ifelset:

# End scope
# End scope
EXIT_ifelset:
lw $31, 20($sp)
addiu $sp, $sp, 40
j $31
.end ifelset


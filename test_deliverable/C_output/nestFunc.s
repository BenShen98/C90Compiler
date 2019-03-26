.globl f
.ent f
f:
.frame $fp,32,$31
addiu $sp, $sp, -32
sw $31, 20($sp)
# Enter scope
# Enter scope
li $t0,10 #imm id _1:4_
sw $t0,28($sp) #write back id 1:4
lw $t0,28($sp) #load _1:4_ to$t0
nop
# assign _1:4_ to _1:8_ in reg $t0
move $2,$t0
b EXIT_f
# End scope
# End scope
EXIT_f:
lw $31, 20($sp)
addiu $sp, $sp, 32
j $31
.end f

.globl third
.ent third
third:
.frame $fp,48,$31
addiu $sp, $sp, -48
sw $31, 20($sp)
# Enter scope
sw $a0,48($sp) #store parameter 0:0
# Enter scope
li $t0,20 #imm id _1:4_
lw $t1,48($sp) #load _0:0_ to$t1
nop
addu $t2,$t1,$t0 #dst id _1:8_
li $t0,30 #imm id _1:12_
xor $t3,$t2,$t0 #dst id _1:16_
sltu $t3,$t3,0x1 #dst id _1:16_
sw $t3,32($sp) #write back id 1:16
lw $t0,32($sp) #load _1:16_ to$t0
nop
beq $t0,$0,elseStart_1_third
# Enter scope
jal f
move $t0,$v0 #mv return to tReg _2:4_
sw $t0,28($sp) #write back id 2:4
lw $t0,28($sp) #load _2:4_ to$t0
nop
# assign _2:4_ to _2:8_ in reg $t0
move $2,$t0
b EXIT_third
# End scope
b ifEnd_0_third
elseStart_1_third:

# Enter scope
li $t0,999 #imm id _2:4_
sw $t0,28($sp) #write back id 2:4
lw $t0,28($sp) #load _2:4_ to$t0
nop
# assign _2:4_ to _2:8_ in reg $t0
move $2,$t0
b EXIT_third
# End scope
ifEnd_0_third:

# End scope
# End scope
EXIT_third:
lw $31, 20($sp)
addiu $sp, $sp, 48
j $31
.end third


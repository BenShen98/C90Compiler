.globl Fibonacci
.ent Fibonacci
Fibonacci:
.frame $fp,72,$31
addiu $sp, $sp, -72
sw $31, 20($sp)
# Enter scope
sw $a0,72($sp) #store parameter 0:0
# Enter scope
li $t0,0 #imm id _1:4_
lw $t1,72($sp) #load _0:0_ to$t1
nop
xor $t2,$t1,$t0 #dst id _1:8_
sltu $t2,$t2,0x1 #dst id _1:8_
sw $t2,64($sp) #write back id 1:8
lw $t0,64($sp) #load _1:8_ to$t0
nop
beq $t0,$0,elseStart_1_Fibonacci
# Enter scope
li $t0,0 #imm id _2:4_
sw $t0,52($sp) #write back id 2:4
lw $t0,52($sp) #load _2:4_ to$t0
nop
# assign _2:4_ to _2:8_ in reg $t0
move $2,$t0
b EXIT_Fibonacci
# End scope
b ifEnd_0_Fibonacci
elseStart_1_Fibonacci:

li $t0,1 #imm id _1:12_
lw $t1,72($sp) #load _0:0_ to$t1
nop
xor $t2,$t1,$t0 #dst id _1:16_
sltu $t2,$t2,0x1 #dst id _1:16_
sw $t2,56($sp) #write back id 1:16
lw $t0,56($sp) #load _1:16_ to$t0
nop
beq $t0,$0,elseStart_3_Fibonacci
# Enter scope
li $t0,1 #imm id _2:4_
sw $t0,52($sp) #write back id 2:4
lw $t0,52($sp) #load _2:4_ to$t0
nop
# assign _2:4_ to _2:8_ in reg $t0
move $2,$t0
b EXIT_Fibonacci
# End scope
b ifEnd_2_Fibonacci
elseStart_3_Fibonacci:

# Enter scope
li $t0,1 #imm id _2:4_
lw $t1,72($sp) #load _0:0_ to$t1
nop
subu $t2,$t1,$t0 #dst id _2:8_
sw $t2,48($sp) #write back id 2:8
lw $a0,48($sp) #load first 4 arg
nop
jal Fibonacci
move $t0,$v0 #mv return to tReg _2:12_
li $t1,2 #imm id _2:16_
lw $t2,72($sp) #load _0:0_ to$t2
nop
subu $t3,$t2,$t1 #dst id _2:20_
sw $t0,44($sp) #write back id 2:12
sw $t3,36($sp) #write back id 2:20
lw $a0,36($sp) #load first 4 arg
nop
jal Fibonacci
move $t0,$v0 #mv return to tReg _2:24_
lw $t1,44($sp) #load _2:12_ to$t1
nop
addu $t2,$t1,$t0 #dst id _2:28_
sw $t2,28($sp) #write back id 2:28
lw $t0,28($sp) #load _2:28_ to$t0
nop
# assign _2:28_ to _2:32_ in reg $t0
move $2,$t0
b EXIT_Fibonacci
# End scope
ifEnd_2_Fibonacci:

ifEnd_0_Fibonacci:

# End scope
# End scope
EXIT_Fibonacci:
lw $31, 20($sp)
addiu $sp, $sp, 72
j $31
.end Fibonacci


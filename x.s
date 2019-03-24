.globl Fibonacci
.ent Fibonacci
Fibonacci:
.frame $fp,72,$31
addiu $sp, $sp, -72
sw $31, 20($sp)
sw $a0,72($sp) #store parameter
li $t0,0 #imm id _4_
lw $t1,72($sp) #load _0_ to$t1
xor $t2,$t1,$t0 #dst id _8_
sltu $t2,$t2,0x1 #dst id _8_
sw $t2,64($sp) #write back id 8
lw $t0,64($sp) #load _8_ to$t0
beq $t0,$0,elseStart_0_Fibonacci
li $t0,0 #imm id _4_
# assign _4_ to _8_ in reg $t0
move $2,$t0
b EXIT_Fibonacci
b elseEnd_1_Fibonacci
elseStart_0_Fibonacci:

li $t0,1 #imm id _12_
lw $t1,68($sp) #load _4_ to$t1
xor $t2,$t1,$t0 #dst id _16_
sltu $t2,$t2,0x1 #dst id _16_
sw $t2,56($sp) #write back id 16
lw $t0,56($sp) #load _16_ to$t0
beq $t0,$0,elseStart_2_Fibonacci
li $t0,1 #imm id _4_
# assign _4_ to _8_ in reg $t0
move $2,$t0
b EXIT_Fibonacci
b elseEnd_3_Fibonacci
elseStart_2_Fibonacci:

li $t0,1 #imm id _4_
lw $t1,68($sp) #load _4_ to$t1
subu $t2,$t1,$t0 #dst id _8_
move $a0,$t2 #implicit call, int type
sw $t2,64($sp) #write back id 8
jal Fibonacci
move $t0,$v0 #mv return to tReg _12_
li $t1,2 #imm id _16_
lw $t2,68($sp) #load _4_ to$t2
subu $t3,$t2,$t1 #dst id _20_
move $a0,$t3 #implicit call, int type
sw $t0,60($sp) #write back id 12
sw $t3,52($sp) #write back id 20
jal Fibonacci
move $t0,$v0 #mv return to tReg _24_
lw $t1,60($sp) #load _12_ to$t1
addu $t2,$t1,$t0 #dst id _28_
# assign _28_ to _32_ in reg $t2
move $2,$t2
b EXIT_Fibonacci
elseEnd_3_Fibonacci:

elseEnd_1_Fibonacci:

EXIT_Fibonacci:
lw $31, 20($sp)
addiu $sp, $sp, 72
j $31
.end Fibonacci


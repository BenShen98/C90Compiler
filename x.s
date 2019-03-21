.globl main
.ent main
main:
.frame $fp,40,$31
addiu $sp, $sp, -40
sw $31, 20($sp)
li $t0,3 #imm id _4_
move $a0,$t0 #implicit call, int type
sw $t0,36($sp) #write back id 4
jal Fibonacci
move $t0,$v0 #mv return to tReg _8_
# assign _8_ to _12_ in reg $t0
move $2,$t0
b EXIT_main
EXIT_main:
lw $31, 20($sp)
addiu $sp, $sp, 40
j $31
.end main

.globl Fibonacci
.ent Fibonacci
Fibonacci:
.frame $fp,88,$31
addiu $sp, $sp, -88
sw $31, 20($sp)
sw $a0,88($sp) #store parameter
li $t0,0 #imm id _4_
lw $t1,88($sp) #load _0_ to$t1
xor $t2,$t1,$t0 #dst id _8_
sltu $t2,$t2,0x1 #dst id _8_
beq $t2,$0,elseStart_0_Fibonacci
li $t0,0 #imm id _12_
# assign _12_ to _16_ in reg $t0
move $2,$t0
b EXIT_Fibonacci
b elseEnd_1_Fibonacci
elseStart_0_Fibonacci:

li $t3,1 #imm id _20_
xor $t4,$t1,$t3 #dst id _24_
sltu $t4,$t4,0x1 #dst id _24_
beq $t4,$0,elseStart_2_Fibonacci
li $t3,1 #imm id _28_
# assign _28_ to _32_ in reg $t3
move $2,$t3
b EXIT_Fibonacci
b elseEnd_3_Fibonacci
elseStart_2_Fibonacci:

li $t5,1 #imm id _36_
sub $t6,$t1,$t5 #dst id _40_
move $a0,$t6 #implicit call, int type
sw $t0,72($sp) #write back id 16
sw $t2,80($sp) #write back id 8
sw $t3,56($sp) #write back id 32
sw $t4,64($sp) #write back id 24
sw $t6,48($sp) #write back id 40
jal Fibonacci
move $t0,$v0 #mv return to tReg _44_
li $t2,2 #imm id _48_
sub $t3,$t1,$t2 #dst id _52_
move $a0,$t3 #implicit call, int type
sw $t0,44($sp) #write back id 44
sw $t3,36($sp) #write back id 52
jal Fibonacci
move $t0,$v0 #mv return to tReg _56_
lw $t2,44($sp) #load _44_ to$t2
addu $t3,$t2,$t0 #dst id _60_
# assign _60_ to _64_ in reg $t3
move $2,$t3
b EXIT_Fibonacci
elseEnd_3_Fibonacci:

elseEnd_1_Fibonacci:

EXIT_Fibonacci:
lw $31, 20($sp)
addiu $sp, $sp, 88
j $31
.end Fibonacci


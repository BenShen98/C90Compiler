.globl main
.ent main
main:
.frame $fp,40,$31
addiu $sp, $sp, -40
sw $31, 20($sp)
li $t0,5 #imm id _4_
move $a0,$t0 #implicit call, int type
sw $t0,36($sp) #write back id 4
jal recadd
move $t0,$v0 #mv return to tReg _8_
# assign _8_ to _12_ in reg $t0
move $2,$t0
b EXIT_main
EXIT_main:
lw $31, 20($sp)
addiu $sp, $sp, 40
j $31
.end main

.globl recadd
.ent recadd
recadd:
.frame $fp,64,$31
addiu $sp, $sp, -64
sw $31, 20($sp)
sw $a0,64($sp) #store parameter
li $t0,1 #imm id _4_
lw $t1,64($sp) #load _0_ to$t1
slt $t2,$t1,$t0 #dst id _8_
beq $t2,$0,elseStart_0_recadd
li $t0,0 #imm id _12_
# assign _12_ to _16_ in reg $t0
move $2,$t0
b EXIT_recadd
b elseEnd_1_recadd
elseStart_0_recadd:

li $t3,1 #imm id _20_
sub $t4,$t1,$t3 #dst id _24_
move $a0,$t4 #implicit call, int type
sw $t0,48($sp) #write back id 16
sw $t2,56($sp) #write back id 8
sw $t4,40($sp) #write back id 24
jal recadd
move $t0,$v0 #mv return to tReg _28_
lw $t1,64($sp) #load _0_ to$t1
addu $t2,$t1,$t0 #dst id _32_
# assign _32_ to _36_ in reg $t2
# assign _36_ to _40_ in reg $t2
move $2,$t2
b EXIT_recadd
elseEnd_1_recadd:

EXIT_recadd:
lw $31, 20($sp)
addiu $sp, $sp, 64
j $31
.end recadd


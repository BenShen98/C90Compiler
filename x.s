.globl testifelse
.ent testifelse
testifelse:
.frame $fp,48,$31
addiu $sp, $sp, -48
sw $31, 20($sp)
li $t0,0 #imm id _4_
beq $t0,$0,elseStart_0_testifelse
li $t1,21 #imm id _8_
# assign _8_ to _12_ in reg $t1
move $2,$t1
b EXIT_testifelse
b elseEnd_1_testifelse
elseStart_0_testifelse:

li $t2,2 #imm id _16_
# assign _16_ to _20_ in reg $t2
move $2,$t2
b EXIT_testifelse
elseEnd_1_testifelse:

sw $t0,44($sp) #write back id 4
sw $t1,36($sp) #write back id 12
sw $t2,28($sp) #write back id 20
EXIT_testifelse:
lw $31, 20($sp)
addiu $sp, $sp, 48
j $31
.end testifelse


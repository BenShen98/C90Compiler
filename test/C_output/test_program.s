.globl f
.ent f
f:
.frame $fp,32,$31
addiu $sp, $sp, -32
sw $31, 20($sp)
li $t0,10 #imm id _4_
# assign _4_ to _8_ in reg $t0
move $2,$t0
b EXIT_f
sw $t0,24($sp) #write back id 8
EXIT_f:
lw $31, 20($sp)
addiu $sp, $sp, 32
j $31

.end f

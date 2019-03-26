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


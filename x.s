.globl f
.ent f
f:
.frame $fp,96,$31
addiu $sp, $sp, -96
sw $31, 20($sp)
# Enter scope
# Enter scope
lw $t0,32($sp) #load _1:64_ to$t0
nop
addiu $t0, $sp, 36 #addr of x
li $t1,60 #imm id _1:68_
sw $t0,32($sp) #write back id 1:64
sw $t1,28($sp) #write back id 1:68
lw $t0,28($sp) #load _1:68_ to$t0
nop
# assign _1:68_ to _1:72_ in reg $t0
move $2,$t0
b EXIT_f
# End scope
# End scope
EXIT_f:
lw $31, 20($sp)
addiu $sp, $sp, 96
j $31
.end f


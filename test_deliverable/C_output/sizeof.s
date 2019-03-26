.globl f
.ent f
f:
.frame $fp,144,$31
addiu $sp, $sp, -144
sw $31, 20($sp)
# Enter scope
# Enter scope
lw $t0,32($sp) #load _1:112_ to$t0
nop
addiu $t0, $sp, 36 #addr of x
li $t1,108 #imm id _1:116_
sw $t0,32($sp) #write back id 1:112
sw $t1,28($sp) #write back id 1:116
lw $t0,28($sp) #load _1:116_ to$t0
nop
# assign _1:116_ to _1:120_ in reg $t0
move $2,$t0
b EXIT_f
# End scope
# End scope
EXIT_f:
lw $31, 20($sp)
addiu $sp, $sp, 144
j $31
.end f


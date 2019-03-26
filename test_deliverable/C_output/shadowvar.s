.globl f
.ent f
f:
.frame $fp,48,$31
addiu $sp, $sp, -48
sw $31, 20($sp)
# Enter scope
# Enter scope
li $t0,5 #imm id _1:8_
sw $t0,40($sp) #write back id 1:8
lw $t0,40($sp) #load _1:8_ to$t0
nop
# assign _1:8_ to _1:4_ in reg $t0
# Enter scope
sw $t0,44($sp) #write back id 1:4
li $t0,6 #imm id _2:8_
sw $t0,28($sp) #write back id 2:8
lw $t0,28($sp) #load _2:8_ to$t0
nop
# assign _2:8_ to _2:4_ in reg $t0
# End scope
lw $t0,44($sp) #load _1:4_ to$t0
nop
# assign _1:4_ to _1:12_ in reg $t0
move $2,$t0
b EXIT_f
# End scope
# End scope
EXIT_f:
lw $31, 20($sp)
addiu $sp, $sp, 48
j $31
.end f


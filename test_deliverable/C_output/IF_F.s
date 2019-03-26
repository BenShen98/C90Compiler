.globl testif_f
.ent testif_f
testif_f:
.frame $fp,48,$31
addiu $sp, $sp, -48
sw $31, 20($sp)
# Enter scope
# Enter scope
li $t0,0 #imm id _1:4_
sw $t0,44($sp) #write back id 1:4
lw $t0,44($sp) #load _1:4_ to$t0
nop
beq $t0,$0,ifEnd_0_testif_f
# Enter scope
li $t0,21 #imm id _2:4_
sw $t0,32($sp) #write back id 2:4
lw $t0,32($sp) #load _2:4_ to$t0
nop
# assign _2:4_ to _2:8_ in reg $t0
move $2,$t0
b EXIT_testif_f
# End scope
ifEnd_0_testif_f:

li $t0,6 #imm id _1:8_
sw $t0,40($sp) #write back id 1:8
lw $t0,40($sp) #load _1:8_ to$t0
nop
# assign _1:8_ to _1:12_ in reg $t0
move $2,$t0
b EXIT_testif_f
# End scope
# End scope
EXIT_testif_f:
lw $31, 20($sp)
addiu $sp, $sp, 48
j $31
.end testif_f


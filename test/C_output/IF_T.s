.globl testif_t
.ent testif_t
testif_t:
.frame $fp,48,$31
addiu $sp, $sp, -48
sw $31, 20($sp)
li $t0,1 #imm id _4_
beq $t0,$0,ifEnd_0_testif_t
# true case for ifEnd_0_testif_t
li $t1,21 #imm id _8_
# assign _8_ to _12_ in reg $t1
move $2,$t1
b EXIT_testif_t
ifEnd_0_testif_t:

li $t2,6 #imm id _16_
# assign _16_ to _20_ in reg $t2
move $2,$t2
b EXIT_testif_t
sw $t0,44($sp) #write back id 4
sw $t1,36($sp) #write back id 12
sw $t2,28($sp) #write back id 20
EXIT_testif_t:
lw $31, 20($sp)
addiu $sp, $sp, 48
j $31
.end testif_t


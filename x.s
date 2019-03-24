.globl addflow
.ent addflow
addflow:
.frame $fp,48,$31
addiu $sp, $sp, -48
sw $31, 20($sp)
li $t0,4294967295 #imm id _8_
# assign _8_ to _4_ in reg $t0
li $t1,1 #imm id _16_
# assign _16_ to _12_ in reg $t1
addu $t2,$t0,$t1 #dst id _20_
# assign _20_ to _24_ in reg $t2
move $2,$t2
b EXIT_addflow
EXIT_addflow:
lw $31, 20($sp)
addiu $sp, $sp, 48
j $31
.end addflow


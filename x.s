.globl f
.ent f
f:
.frame $fp,40,$31
addiu $sp, $sp, -40
sw $31, 20($sp)
jal f1
move $t0,$v0 #mv return to tReg _4_
sw $t0,36($sp) #write back id 4
jal f2
move $t0,$v0 #mv return to tReg _8_
lw $t1,36($sp) #load _4_ to$t1
addu $t2,$t1,$t0 #dst id _12_
# assign _12_ to _16_ in reg $t2
move $2,$t2
b EXIT_f
sw $t2,24($sp) #write back id 16
EXIT_f:
lw $31, 20($sp)
addiu $sp, $sp, 40
j $31
.end f

.globl f1
.ent f1
f1:
.frame $fp,32,$31
addiu $sp, $sp, -32
sw $31, 20($sp)
li $t0,1 #imm id _4_
# assign _4_ to _8_ in reg $t0
move $2,$t0
b EXIT_f1
sw $t0,24($sp) #write back id 8
EXIT_f1:
lw $31, 20($sp)
addiu $sp, $sp, 32
j $31
.end f1

.globl f2
.ent f2
f2:
.frame $fp,40,$31
addiu $sp, $sp, -40
sw $31, 20($sp)
li $t0,5 #imm id _8_
# assign _8_ to _4_ in reg $t0
# assign _4_ to _12_ in reg $t0
move $2,$t0
b EXIT_f2
sw $t0,28($sp) #write back id 12
EXIT_f2:
lw $31, 20($sp)
addiu $sp, $sp, 40
j $31
.end f2


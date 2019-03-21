.globl f1
.ent f1
f1:
.frame $fp,32,$31
addiu $sp, $sp, -32
sw $31, 20($sp)
sw $a0,32($sp) #store parameter
lw $t0,32($sp) #load _0_ to$t0
addu $t1,$t0,$t0 #dst id _4_
# assign _4_ to _8_ in reg $t1
move $2,$t1
b EXIT_f1
sw $t1,24($sp) #write back id 8
EXIT_f1:
lw $31, 20($sp)
addiu $sp, $sp, 32
j $31
.end f1

.globl f3
.ent f3
f3:
.frame $fp,40,$31
addiu $sp, $sp, -40
sw $31, 20($sp)
sw $a0,40($sp) #store parameter
sw $a1,44($sp) #store parameter
sw $a2,48($sp) #store parameter
li $t0,1 #imm id _4_
move $a0,$t0 #implicit call, int type
sw $t0,36($sp) #write back id 4
jal f
move $t0,$v0 #mv return to tReg _8_
# assign _8_ to _12_ in reg $t0
move $2,$t0
b EXIT_f3
sw $t0,28($sp) #write back id 12
EXIT_f3:
lw $31, 20($sp)
addiu $sp, $sp, 40
j $31
.end f3


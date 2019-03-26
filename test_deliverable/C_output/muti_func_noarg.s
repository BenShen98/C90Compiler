.globl f
.ent f
f:
.frame $fp,40,$31
addiu $sp, $sp, -40
sw $31, 20($sp)
# Enter scope
# Enter scope
jal f1
move $t0,$v0 #mv return to tReg _1:4_
sw $t0,36($sp) #write back id 1:4
jal f2
move $t0,$v0 #mv return to tReg _1:8_
lw $t1,36($sp) #load _1:4_ to$t1
nop
addu $t2,$t1,$t0 #dst id _1:12_
sw $t2,28($sp) #write back id 1:12
lw $t0,28($sp) #load _1:12_ to$t0
nop
# assign _1:12_ to _1:16_ in reg $t0
move $2,$t0
b EXIT_f
# End scope
# End scope
EXIT_f:
lw $31, 20($sp)
addiu $sp, $sp, 40
j $31
.end f

.globl f1
.ent f1
f1:
.frame $fp,40,$31
addiu $sp, $sp, -40
sw $31, 20($sp)
# Enter scope
# Enter scope
li $t0,1 #imm id _1:4_
sw $t0,36($sp) #write back id 1:4
lw $t0,36($sp) #load _1:4_ to$t0
nop
# assign _1:4_ to _1:8_ in reg $t0
move $2,$t0
b EXIT_f1
# End scope
# End scope
EXIT_f1:
lw $31, 20($sp)
addiu $sp, $sp, 40
j $31
.end f1

.globl f2
.ent f2
f2:
.frame $fp,40,$31
addiu $sp, $sp, -40
sw $31, 20($sp)
# Enter scope
# Enter scope
li $t0,5 #imm id _1:8_
sw $t0,32($sp) #write back id 1:8
lw $t0,32($sp) #load _1:8_ to$t0
nop
# assign _1:8_ to _1:4_ in reg $t0
sw $t0,36($sp) #write back id 1:4
lw $t0,36($sp) #load _1:4_ to$t0
nop
# assign _1:4_ to _1:12_ in reg $t0
move $2,$t0
b EXIT_f2
# End scope
# End scope
EXIT_f2:
lw $31, 20($sp)
addiu $sp, $sp, 40
j $31
.end f2


.globl f1
.ent f1
f1:
.frame $fp,32,$31
addiu $sp, $sp, -32
sw $31, 20($sp)
# Enter scope
sw $a0,32($sp) #store parameter 0:0
# Enter scope
lw $t0,32($sp) #load _0:0_ to$t0
nop
addu $t1,$t0,$t0 #dst id _1:4_
sw $t1,28($sp) #write back id 1:4
lw $t0,28($sp) #load _1:4_ to$t0
nop
# assign _1:4_ to _1:8_ in reg $t0
move $2,$t0
b EXIT_f1
# End scope
# End scope
EXIT_f1:
lw $31, 20($sp)
addiu $sp, $sp, 32
j $31
.end f1

.globl f3
.ent f3
f3:
.frame $fp,32,$31
addiu $sp, $sp, -32
sw $31, 20($sp)
# Enter scope
sw $a0,32($sp) #store parameter 0:0
sw $a1,36($sp) #store parameter 0:-4
sw $a2,40($sp) #store parameter 0:-8
# Enter scope
lw $a0,36($sp) #load first 4 arg
nop
jal f1
move $t0,$v0 #mv return to tReg _1:4_
sw $t0,28($sp) #write back id 1:4
lw $t0,28($sp) #load _1:4_ to$t0
nop
# assign _1:4_ to _1:8_ in reg $t0
move $2,$t0
b EXIT_f3
# End scope
# End scope
EXIT_f3:
lw $31, 20($sp)
addiu $sp, $sp, 32
j $31
.end f3


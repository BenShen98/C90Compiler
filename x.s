.globl f
.ent f
f:
.frame $fp,56,$31
addiu $sp, $sp, -56
sw $31, 20($sp)
# Enter scope
# Enter scope
li $t0,5 #imm id _1:8_
sw $t0,48($sp) #write back id 1:8
lw $t0,48($sp) #load _1:8_ to$t0
nop
# assign _1:8_ to _1:4_ in reg $t0
li $t1,0 #imm id _1:12_
sw $t0,52($sp) #write back id 1:4
addiu $t0, $sp, 52 #get ref
sw $t0,36($sp) #write back id 1:20
sw $t1,44($sp) #write back id 1:12
lw $t0,36($sp) #load _1:20_ to$t0
nop
# assign _1:20_ to _1:16_ in reg $t0
sw $t0,40($sp) #write back id 1:16
lw $t0,40($sp) #load _1:16_ to$t0
nop
lw $t0,0($t0) #de ref
nop
# assign _1:24_ to _1:12_ in reg $t0
sw $t0,44($sp) #write back id 1:12
lw $t0,44($sp) #load _1:12_ to$t0
nop
# assign _1:12_ to _1:28_ in reg $t0
move $2,$t0
b EXIT_f
# End scope
# End scope
EXIT_f:
lw $31, 20($sp)
addiu $sp, $sp, 56
j $31
.end f


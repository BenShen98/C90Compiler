.globl f
.ent f
f:
.frame $fp,56,$31
addiu $sp, $sp, -56
sw $31, 20($sp)
# Enter scope
# Enter scope
li $t0,5 #imm id _1:8_
# assign _1:8_ to _1:4_ in reg $t0
sw $t0,52($sp) #write back id 1:4
addiu $t0, $0, 52 #get ref
# assign _1:16_ to _1:12_ in reg $t0
li $t1,10 #imm id _1:20_
sw $t0,44($sp) #write back id 1:12
sw $t1,36($sp) #write back id 1:20
lw $t0,44($sp) #load _1:12_ to$t0
nop
lw $t1,36($sp) #load _1:20_ to$t1
nop
sw $t1,0($t0) #write back via indirection
lw $t2,52($sp) #load _1:4_ to$t2
nop
# assign _1:4_ to _1:24_ in reg $t2
move $2,$t2
b EXIT_f
# End scope
# End scope
EXIT_f:
lw $31, 20($sp)
addiu $sp, $sp, 56
j $31
.end f


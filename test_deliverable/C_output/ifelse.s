.globl testifelse
.ent testifelse
testifelse:
.frame $fp,48,$31
addiu $sp, $sp, -48
sw $31, 20($sp)
# Enter scope
# Enter scope
li $t0,1 #imm id _1:4_
sw $t0,44($sp) #write back id 1:4
lw $t0,44($sp) #load _1:4_ to$t0
nop
beq $t0,$0,elseStart_1_testifelse
# Enter scope
li $t0,1 #imm id _2:4_
sw $t0,40($sp) #write back id 2:4
lw $t0,40($sp) #load _2:4_ to$t0
nop
beq $t0,$0,elseStart_3_testifelse
# Enter scope
li $t0,1 #imm id _3:4_
sw $t0,32($sp) #write back id 3:4
lw $t0,32($sp) #load _3:4_ to$t0
nop
# assign _3:4_ to _3:8_ in reg $t0
move $2,$t0
b EXIT_testifelse
# End scope
b ifEnd_2_testifelse
elseStart_3_testifelse:

# Enter scope
li $t0,2 #imm id _3:4_
sw $t0,32($sp) #write back id 3:4
lw $t0,32($sp) #load _3:4_ to$t0
nop
# assign _3:4_ to _3:8_ in reg $t0
move $2,$t0
b EXIT_testifelse
# End scope
ifEnd_2_testifelse:

# End scope
b ifEnd_0_testifelse
elseStart_1_testifelse:

# Enter scope
li $t0,3 #imm id _2:4_
sw $t0,40($sp) #write back id 2:4
lw $t0,40($sp) #load _2:4_ to$t0
nop
# assign _2:4_ to _2:8_ in reg $t0
move $2,$t0
b EXIT_testifelse
# End scope
ifEnd_0_testifelse:

# End scope
# End scope
EXIT_testifelse:
lw $31, 20($sp)
addiu $sp, $sp, 48
j $31
.end testifelse


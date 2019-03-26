.globl testnegate
.ent testnegate
testnegate:
.frame $fp,40,$31
addiu $sp, $sp, -40
sw $31, 20($sp)
# Enter scope
# Enter scope
li $t0,1 #imm id _1:8_
sw $t0,32($sp) #write back id 1:8
lw $t0,32($sp) #load _1:8_ to$t0
nop
# assign _1:8_ to _1:4_ in reg $t0
sw $t0,36($sp) #save dirty re _1:4_ before negation
sltu $t0,$t0,1 #sltu_1:4_
and $t0,$t0,0x00ff #andi_0x00ff1:4_
sw $t0,28($sp) #write back id 1:12
lw $t0,28($sp) #load _1:12_ to$t0
nop
# assign _1:12_ to _1:16_ in reg $t0
move $2,$t0
b EXIT_testnegate
# End scope
# End scope
EXIT_testnegate:
lw $31, 20($sp)
addiu $sp, $sp, 40
j $31
.end testnegate


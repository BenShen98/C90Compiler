.globl testwhile
.ent testwhile
testwhile:
.frame $fp,40,$31
addiu $sp, $sp, -40
sw $31, 20($sp)
# Enter scope
# Enter scope
li $t0,2 #imm id _1:8_
sw $t0,32($sp) #write back id 1:8
lw $t0,32($sp) #load _1:8_ to$t0
nop
# assign _1:8_ to _1:4_ in reg $t0
sw $t0,36($sp) #write back id 1:4
ItrCondition_0_testwhile:

lw $t0,36($sp) #load _1:4_ to$t0
nop
beq $t0,$0,ItrEnd_1_testwhile
# Enter scope
lw $t0,36($sp) #load _1:4_ to$t0
nop
addi $t0,$t0,-1 #per increment of id _1:4_
sw $t0,36($sp) #write back id 1:4
conti_2_testwhile:

# End scope
b ItrCondition_0_testwhile
ItrEnd_1_testwhile:

lw $t0,36($sp) #load _1:4_ to$t0
nop
# assign _1:4_ to _1:12_ in reg $t0
move $2,$t0
b EXIT_testwhile
# End scope
# End scope
EXIT_testwhile:
lw $31, 20($sp)
addiu $sp, $sp, 40
j $31
.end testwhile


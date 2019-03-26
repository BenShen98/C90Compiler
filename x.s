.globl main
.ent main
main:
.frame $fp,56,$31
addiu $sp, $sp, -56
sw $31, 20($sp)
# Enter scope
# Enter scope
li $t0,0 #imm id _1:8_
sw $t0,48($sp) #write back id 1:8
lw $t0,48($sp) #load _1:8_ to$t0
nop
# assign _1:8_ to _1:4_ in reg $t0
li $t1,0 #imm id _1:12_
sw $t0,52($sp) #write back id 1:4
sw $t1,44($sp) #write back id 1:12
ItrCondition_0_main:

li $t0,100 #imm id _1:16_
lw $t1,52($sp) #load _1:4_ to$t1
nop
slt $t2,$t1,$t0 #dst id _1:20_
beq $t2,$0,ItrEnd_1_main
# Enter scope
sw $t2,36($sp) #write back id 1:20
lw $t0,44($sp) #load _1:12_ to$t0
nop
addi $t1,$t0,-1 #add, swap org copy & org
b conti_2_main
conti_2_main:

# End scope
sw $t1,44($sp) #write back id 1:12
lw $t0,52($sp) #load _1:4_ to$t0
nop
addi $t1,$t0,1 #add, swap org copy & org
sw $t0,32($sp) #write back id 1:24
sw $t1,52($sp) #write back id 1:4
b ItrCondition_0_main
ItrEnd_1_main:

lw $t0,44($sp) #load _1:12_ to$t0
nop
# assign _1:12_ to _1:28_ in reg $t0
move $2,$t0
b EXIT_main
# End scope
# End scope
EXIT_main:
lw $31, 20($sp)
addiu $sp, $sp, 56
j $31
.end main


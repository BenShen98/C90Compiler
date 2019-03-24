.globl f2
.ent f2
f2:
.frame $fp,64,$31
addiu $sp, $sp, -64
sw $31, 20($sp)
# Enter scope
# Enter scope
li $t0,0 #imm id _1:4_
li $t1,6 #imm id _1:8_
addi $t0,$t0,1 #per increment of id _1:4_
beq $t1,$0,ORShort_0_f2
beq $t0,$0,ORShort_0_f2
li $t2,1 #
b OREnd_1_f2
ORShort_0_f2:

move $t2,$0 #
OREnd_1_f2:

# assign _1:12_ to _1:16_ in reg $t2
li $t1,2 #imm id _1:20_
sll $t3,$t2,$t1 #dst id _1:24_
# assign _1:24_ to _1:28_ in reg $t3
addu $t1,$t3,$t0 #dst id _1:32_
# assign _1:32_ to _1:36_ in reg $t1
move $2,$t1
b EXIT_f2
# End scope
# End scope
EXIT_f2:
lw $31, 20($sp)
addiu $sp, $sp, 64
j $31
.end f2


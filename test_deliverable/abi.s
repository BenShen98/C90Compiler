.globl abi_setup
.ent abi_setup
abi_setup:
.frame $fp,0,$31

#random input for non-preserved register

li $3, 934211120
li $4, 901824223
li $5 , 673867188
li $6, 599184494
li $7, 571370065
li $8, 553873935
li $9, 490117604
li $10, 308315379
li $11, 132282980
li $12, 63245471
li $13, 140742602
li $14, 422608299
li $15, 431915919

li $24, 891037555
li $25, 942640566

move $2, $29 #return stack pointer

j $31
.end abi_setup


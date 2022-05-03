	.file	"To_Upper.s"
	.text
	.globl	To_Upper
	.type	To_Upper, @function

/* **********************
    Name: Agastya Asthana
    Wisc ID Number: 9082088338
    Wisc Email: aasthana3@wisc.edu
************************ */


To_Upper:

# C version
/* **********************
    Write the equivalent C code to this function here (in the comment block)
    void To_Upper(char *string){
        int i = 0;
        while(string[i] != '\0'){
            char letter = string[i];
            if(string[i] >= 97){
                if(string[i] <= 122){
                    letter -= 32;
                    string[i] = letter;
                }
                else{
                    NOTHING
                }
            }
            else{
                NOTHING
            }
            i++;
        }
    }

************************ */


# Memory Layout
/* ************************ 
    Make a table showing the stack frame for your function (in the comment block)
    The first column should have a memory address (e.g. 8(%rsp))
    The second column should be the name of the C variable used above
    Update the example below with your variables and memory addresses
        -4(%rbp)  |  int i
        -6(%rbp)  |  char letter
        -16(%rbp) |  char *string
************************ */


# Prologue
	pushq %rbp
	movq %rsp, %rbp
	sub $16, %rsp

# This code prints the letter 'a' (ascii value 97)
# Use this for debugging
# Comment out when finished - your function should not print anything
# Note putchar overwrites all caller saved registers including argument registers
	#movl	$97, %eax
	#movl	%eax, %edi
	#call	putchar@PLT


# Body of function
	movq 	%rdi, -16(%rbp) # save rdi
	movl	$0, -4(%rbp) # save the value 0 in location of i
	jmp	LOOP_CONDITION # hop into evaluating the loop

LOOP_BODY:
	cmpb	$97, -6(%rbp) # compare against 'a'
	jle	INCREMENT # move on, as my friend should
	cmpb	$122, -6(%rbp) # compare against 'z'
	jg	INCREMENT # move on, she's talking to other dudes Zach
	movslq	-4(%rbp), %rax # move i to eax
	movq	-16(%rbp), %rdx # move arr ptr into rdx
	addq	%rax, %rdx # arr[i] mem location
	movzbl	(%rdx), %edx # arr[i] actual value
	add	$-32, %edx
	movl	%edx, %ecx
	movq	-16(%rbp), %rdx # get arr ptr back
	addq	%rax, %rdx # arr[i] mem location
	movb	%cl, (%rdx) # update char in arr[i] location	
	

INCREMENT:
	movl	-4(%rbp), %edx # load i into edx
	addl	$1, %edx # increment by one
	movl	%edx, -4(%rbp) # save i back into mem

LOOP_CONDITION:
	movl	-4(%rbp), %edx # load i into edx
	movq	-16(%rbp), %rax # load arr ptr in rax
	addq	%rdx, %rax # arr[i] mem location
	movzbl	(%rax), %eax # arr[i] acutal value
	movb	%al, -6(%rbp) # save the char in memeory
	cmpb	$0, %al # check if the char was a terminating char
	jne	LOOP_BODY # execute the loop since we're not at the end



# Epilogue
	addq	$16, %rsp
	popq	%rbp 	
	ret

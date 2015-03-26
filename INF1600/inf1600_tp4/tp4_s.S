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

.global  _ZN7Canevas13assignerPixelEiij

_ZN7Canevas13assignerPixelEiij:
	push %ebp
	mov %esp, %ebp
	
	mov 8(%ebp), %ecx 		#ecx = this 
	
	cmpl $0, 12(%ebp) 
	jb elseFin			# x < 0

	movl 4(%ecx), %edx
	cmpl %edx, 12(%ebp)
	ja elseFin			# x > this->w_

	cmpl $0, 16(%ebp)
	jb elseFin			# y < 0
	
	movl 8(%ecx), %edx
	cmpl %edx, 16(%ebp)
	ja elseFin			# y > this->h_
	
	movl 16(%ebp), %eax		# eax = y
	mull 4(%ecx)	   		# eax = y * this->w_
	addl 12(%ebp), %eax		# eax = eax + x => y * this->w_ + x
	
	movl 0(%ecx), %ecx		# ecx = this->canevas_[]
	movl 20(%ebp), %edx		# edx = couleur
	movl %edx, (%ecx, %eax, 4)	# this->canevas_[y * this->w_ + x] = couleur
	
elseFin:
	movl %ebp, %esp
	popl %ebp
	ret

.global _ZN7Canevas13assignerPixelE5Coordj

_ZN7Canevas13assignerPixelE5Coordj:
	push %ebp
	mov %esp, %ebp

	pushl 20(%ebp)	# couleur
	pushl 16(%ebp)	# coord.y
	pushl 12(%ebp)	# coord.x
	pushl 8(%ebp)	# this

	call _ZN7Canevas13assignerPixelEiij

	movl %ebp, %esp
	popl %ebp
	ret
	
	

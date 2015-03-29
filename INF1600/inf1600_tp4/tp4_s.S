#include "tp4.hpp"

.global _Z13nouveauCercle5Coordjj

_Z13nouveauCercle5Coordjj:
	push %ebp
	mov %esp, %ebp
	sub $0x4, %esp			# aloue 4 bytes pour variable locale
	
	pushl $32			# sizeof(Cercle)
	call _Znwj			# call operateur new
	mov %eax, -4(%ebp) 		# nouveau =
	
	add $0x4, (%esp) 		# pop esp

	pushl 20(%ebp)			# couleur
	pushl 16(%ebp)			# rayon
	pushl 12(%ebp)			# centre.y
	pushl 8(%ebp)			# centre.x
	pushl -4(%ebp)			# this = nouveau
	call _ZN6CercleC1E5Coordjj	# call du constructeur
	addl $20, %esp			# pop this, centre.x, centre.y, rayon, couleur

	# nouveau = new Cercle(centre, rayon, couleur)
	
	movl -4(%ebp), %eax		# retorune ptr nouveau cercle
	
	add $0x4, %esp
	leave
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
	leave
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

	leave
	ret
	
.global _Z15desallouerFormeP5Forme

_Z15desallouerFormeP5Forme:
	push %ebp
	mov %esp, %ebp

	pushl 8(%ebp) 		# pointeur sur le stack
	call _ZN5FormeD1Ev	# appel destructeur

	pushl 8(%ebp)		# remet le pointeur sur le stack
	call _ZdlPv		# delete

	addl $8, %esp		# depile
	
	leave
	ret
	
.global _ZN7Canevas13dessinerFormeEP5Forme

_ZN7Canevas13dessinerFormeEP5Forme:
	push %ebp
	mov %esp, %ebp
	
	movl 8(%ebp), %eax 	# this
	push %eax		# on place this comme 1erParam sur le stack
	
	movl 12(%ebp), %ecx	# forme
	push %ecx		# this de la mthd virt, forme
	movl (%ecx), %ecx	# on se met en table virtuelle
	call *8(%ecx)		# appel la seconde fonction virtuelle
	
	addl $8, %esp		# on depile apres l'appel
	
	
	leave
	ret
	
.global _Z11faireDessinPP5Formej

_Z11faireDessinPP5Formej:
	push %ebp
	mov %esp, %ebp
	
	subl $8, %esp		# On fait de la place pour Canevas
	
	push $COULEUR_CANEVAS	
	push $HAUTEUR_CANEVAS
	push $LARGEUR_CANEVAS
	pushl $12		# sizeof(Canevas)
	call _Znwj		# call operateur new
	mov %eax, -8(%ebp) 	# on range le pointeur canevas
	
	push $COULEUR_CANEVAS	# On le passe au construct
	push $HAUTEUR_CANEVAS	
	push $LARGEUR_CANEVAS
	push %eax		
	call _ZN7CanevasC1Ejjj	# call constructeur
	addl $16, %esp	 	# depilage
	
	# On initialise notre boucle
	
	movl $0, -4(%ebp)	# initialise i
	
	
loopDessin:
	
	movl 12(%ebp), %eax	# on place n dans eax
	movl -4(%ebp), %ecx	# on place i dans ecx
	cmp %ecx, %eax		# on verifie cond acces avec n - i de la boucle
	jbe finDessin		
	
	movl 8(%ebp), %eax	# on place le pointeur du tableau de formes
	pushl (%eax, %ecx, 4)	# on range le pointeur forme comme 1er param
	pushl -8(%ebp)		# addr du canevas comme this
	call _ZN7Canevas13dessinerFormeEP5Forme
	addl $8, %esp		# on depile le stack
	
	incl -4(%ebp)		# incremente i
	
	jmp loopDessin	
	
finDessin:

	#destruction des variables globales

	push -8(%ebp)		# push l`addr de canevas
	call _Z11ecrireFramePK7Canevas
	addl $4, %esp		# on depile

	# supression
	pushl -8(%ebp) 		# pointeur sur le stack
	call _ZN7CanevasD1Ev	# appel destructeur

	pushl -8(%ebp)		# remet le pointeur sur le stack
	call _ZdlPv		# delete

	addl $8, %esp		# depile les deux addresses
	
	leave
	ret

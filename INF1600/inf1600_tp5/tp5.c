
#include <stdio.h>

unsigned int Decryption_fct(unsigned int le)
{
	unsigned int be;

	/*
	 * Remplacez le code suivant par de l'assembleur en ligne
	 * en utilisant le moins d'instructions possible
	*/ 
	//be = (le & 0xff000000) | (le&0xff) << 16  | (le & 0xff00) | (le & 0xff0000) >> 16;
	 

	asm volatile (
		"movl %1, %%eax\n\t"
		"andl $0xff000000, %%eax\n\t"
		"movl %%eax, %%edx\n\t"

		"movl %1, %%eax\n\t"
		"andl $0xff, %%eax\n\t"
		"shll $16, %%eax\n\t"
		"orl %%eax, %%edx\n\t"

		"movl %1, %%eax\n\t"
		"andl $0xff00, %%eax\n\t"
		"orl %%eax, %%edx\n\t"

		"movl %1, %%eax\n\t"
		"andl $0xff0000, %%eax\n\t"
		"shrl $16, %%eax\n\t"
		"orl %%eax, %%edx\n\t"

		"movl %%edx, %0\n\t"
		: "=r"(be)
		: "g"(le) // input
		: "%eax", "%edx"
	);

	return be;
}

int main()
{
	unsigned int data = 0xeeaabbff;

	printf("Représentation crypte en little-endian:   %08x\n"
	       "Représentation decrypte en big-endian:    %08x\n",
	       data,
	       Decryption_fct(data));

	return 0;
}

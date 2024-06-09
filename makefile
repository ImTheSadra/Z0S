CC = i686-elf-gcc
ASM = i686-elf-as

IASM = ./source/boot.s
OASM = ./output/boot.o

IKERNEL = ./source/kernel.cpp
OKERNEL = ./output/kernel.o

LINKER = ./source/link.ld

LD = i686-elf-gcc

OUTPUT = ./output/kernel.elf

MACHINE = qemu-system-i386

all: compile run

compile:
	$(ASM) $(IASM) -o $(OASM)
	$(CC) -c -o $(OKERNEL) $(IKERNEL)
	$(LD) -T $(LINKER) -o $(OUTPUT) $(OKERNEL) $(OASM) -lgcc -ffreestanding -O2 -nostdlib 

run:
	@$(MACHINE) -kernel $(OUTPUT)
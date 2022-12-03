CC=clang
CFLAGS=-std=c11 -g -Wall -O2 --target=x86_64-pc-win32-coff -nostdlibinc -fno-stack-protector -mno-red-zone -Wno-incompatible-library-redeclaration -Wno-invalid-noreturn
LD=lld-link
LDFLAGS=-subsystem:efi_application -nodefaultlib -entry:efi_main
OBJ=main.o globals.o print.o exit.o status.o
TARGET=loader
.PHONY: all clean
all: $(TARGET)
$(TARGET): $(OBJ)
	$(LD) $(LDFLAGS) $(OBJ) -out:$(TARGET)
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@
clean:
	rm -f $(OBJ) $(TARGET)

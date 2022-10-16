CC = gcc
# compiling flags
CFLAGS = -Wall -I.

# directories
SRCDIR = .
OBJDIR = .

SOURCES  := $(wildcard $(SRCDIR)/*.c)
INCLUDES := $(wildcard $(SRCDIR)/*.h)
OBJECTS  := $(SOURCES:$(SRCDIR)/%.c=$(OBJDIR)/%.o)

$(OBJDIR)/%.o: $(SRCDIR)/%.c $(INCLUDES)
		@$(CC) -c -o $@ $< $(CFLAGS)
		@echo "Compilation done"

problema2: $(OBJECTS)
		@$(CC) -o $@ $^ $(CFLAGS) $(LIBS)
		@echo "Linking done"

clean:
	@rm $(OBJDIR)/*.o 
	@echo "Clean up done."


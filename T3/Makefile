CC = gcc
# compiling flags
CFLAGS = -Wall -I.
LIBS += -lm

# directories
SRCDIR = .
OBJDIR = .

SOURCES  := $(wildcard $(SRCDIR)/*.c)
INCLUDES := $(wildcard $(SRCDIR)/*.h)
OBJECTS  := $(SOURCES:$(SRCDIR)/%.c=$(OBJDIR)/%.o)

$(OBJDIR)/%.o: $(SRCDIR)/%.c $(INCLUDES)
		@$(CC) -c -o $@ $< $(CFLAGS)
		@echo "Compilation done"

problema1: $(OBJECTS)
		@$(CC) -o $@ $^ $(CFLAGS) $(LIBS)
		@echo "Linking done"

clean:
	@rm $(OBJDIR)/*.o 
	@echo "Clean up done."


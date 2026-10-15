NAME=pascal
CFLAGS=-Wall -std=c99
INCLUDE=-I./include
SRCS=src/main.c src/triangle.c src/printer.c

OBJS=$(SRCS:.c=.o)

$(NAME): $(OBJS)
	@echo "Making executable: "$@
	@$(CC) $^ -o build/$@

%.o : %.c
	@echo "Compiling: "$<
	@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

.PHONY: clean

clean:
	@rm -f src/*.o $(NAME)
	@rm -f build/$(NAME)
	@echo "Removed object files and executable..."

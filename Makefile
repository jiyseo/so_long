.PHONY: clean

all:
	make -C so_long_bonus
	make -C so_long_mandatory

clean:
	make clean -C so_long_bonus
	make clean -C so_long_mandatory

fclean:
	make fclean -C so_long_bonus
	make fclean -C so_long_mandatory
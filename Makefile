NAME = bingchiling
zibil = g++
jiv = main.cpp
aaa = -o 
all:
	$(zibil) -std=c++23 -fsanitize=address $(jiv) $(aaa) $(NAME)
clean: 
	rm -rf $(NAME)

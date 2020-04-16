

ft_printf:  ft_printf.o main.o
		gcc -o ft_printf ft_printf.o main.o

ft_printf.o: ft_printf.c libft/libft.a
		gcc -o ft_printf.o -c ft_printf.c -L./libft -llibft.a -Wall -Wextra -Werror

main.o: main.c ft_printf.h
		gcc -o main.o -c main.c -Wall -Wextra -Werror


#
#
#
#
#
# Hello !
#
# D'abord desole pour les accents, je suis sur un xubuntu de fortune et je n'ai pas pris le temps de faire les configs clavier
#
# Donc en fait j'ai cree dans une projet precedent une libraire dans le dossier libft
#
# Cette librairie est deja compilee en libft.a
#
# J'ai refait des tests apres notre discussion, et en fait le probleme est en amont de mon Makefile
#
# Mais je ne trouves toujours pas pourquoi
#
# Lorsque je lance la commande de compilation
#
# 				gcc -Wall main.c ft_printf.c -L./libft -llibft.a
#
# Ca me renvoi
#
# 				/usr/bin/ld: cannot find -llibft
# 				collect2: error: ld returned 1 exit status
#
# J'ai egalement tente plusieurs variantes
#
# 				gcc -Wall main.c ft_printf.c -L./libft -llibft
#
# 				gcc -Wall main.c ft_printf.c -L./libft/libft -llibft.a
#
# 				gcc -Wall main.c ft_printf.c -L./libft -l libft.a
#
# Et d'autres encore, mais sans succes, je suis bloque dessus depuis pas mal de temps
#
# Merci de ton aide, et si je n'ai pas de solution, je ferais un ft_printf.h qui rappelle manuellement les fonctions de la lib dont j'ai besoin
#
# Ce sera moins propre, mais fonctionnel, donc ne te casse pas la tete non plus !

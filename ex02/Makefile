NAME = PmergeMe
FLAGS = -Wall -Wextra -Werror -std=c++98 
SRC = src/main.cpp src/PmergeMe.cpp
CC = c++
HEADER = includes/PmergeMe.hpp
RM = rm -rf


%.o: %.cpp
	$(CC) $(FLAGS) -c -o $@ $<

OBJ = $(SRC:%.cpp=%.o)

all: ${NAME}

${NAME} : ${OBJ} ${HEADER}
	${CC} ${FLAGS} ${OBJ} -o ${NAME}  

clean:
	${RM} ${OBJ}
	
fclean: clean
	${RM} ${NAME}

re : fclean all
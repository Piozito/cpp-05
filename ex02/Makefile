# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aaleixo- <aaleixo-@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/21 15:49:57 by aaleixo-          #+#    #+#              #
#    Updated: 2025/12/02 13:18:23 by aaleixo-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = moreForms
SOURCES = \
	main.cpp Bureaucrat.cpp AForm.cpp PresidentialPardonForm.cpp \
	ShrubberyCreationForm.cpp RobotomyRequestForm.cpp
OBJECTS = $(SOURCES:.cpp=.o)

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME): $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(OBJECTS) -o $(NAME)

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
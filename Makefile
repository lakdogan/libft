# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lakdogan <lakdogan@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/09 22:03:15 by lakdogan          #+#    #+#              #
#    Updated: 2025/02/20 17:35:23 by lakdogan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# compiler and flags
CC := cc
CFLAGS := -Wall -Wextra -Werror $(INCLUDES)
INCLUDES := -I./inc -I./ft_printf -I./get_next_line
MAKEFLAGS += -s

# paths
SRCSDIR := srcs/
FTPFDIR := ft_printf/
GNLDIR := get_next_line/
OFILESDIR := ofiles/

# files
LIBFT_CFILES := \
	ft_bzero.c \
	ft_isalnum.c \
	ft_isalpha.c \
	ft_isascii.c \
	ft_isdigit.c \
	ft_isprint.c \
	ft_memcpy.c \
	ft_memmove.c \
	ft_memset.c \
	ft_strlcpy.c \
	ft_strlen.c \
	ft_strlcat.c \
	ft_toupper.c \
	ft_tolower.c \
	ft_strchr.c \
	ft_strrchr.c \
	ft_strncmp.c \
	ft_memchr.c \
	ft_memcmp.c \
	ft_strnstr.c \
	ft_atoi.c \
	ft_calloc.c \
	ft_strdup.c \
	ft_substr.c \
	ft_strjoin.c \
	ft_strtrim.c \
	ft_split.c \
	ft_itoa.c \
	ft_strmapi.c \
	ft_striteri.c \
	ft_putchar_fd.c \
	ft_putendl_fd.c \
	ft_putnbr_fd.c \
	ft_putstr_fd.c \
	ft_lstnew_bonus.c \
	ft_lstadd_front_bonus.c \
	ft_lstsize_bonus.c \
	ft_lstlast_bonus.c \
	ft_lstadd_back_bonus.c \
	ft_lstdelone_bonus.c \
	ft_lstclear_bonus.c \
	ft_lstiter_bonus.c \
	ft_lstmap_bonus.c \
	ft_compute_cross_product.c \
	ft_dot_product.c \
	ft_getdeg.c \
	ft_getdif.c \
	ft_getrad.c \
	ft_isometric_x.c \
	ft_isometric_y.c \
	ft_magnitude.c \
	ft_newxy.c \
	ft_newxz.c \
	ft_newyx.c \
	ft_newyz.c \
	ft_newzx.c \
	ft_newzy.c \
	ft_normalize.c \
	ft_normalized_cross_product.c \
	ft_tiltang.c \
	ft_unit_vector.c \
	ft_vector_angle_deg.c \
	ft_vector_angle_rad.c \

FT_PRINTF_CFILES := \
	/ft_printf.c \
	print/ft_print_char.c \
	print/ft_print_hex.c \
	print/ft_print_id.c \
	print/ft_print_p.c \
	print/ft_print_str.c \
	print/ft_print_uint.c \
	parse/ft_formatcheck.c

GET_NEXT_LINE_CFILES := \
	get_next_line.c \
	get_next_line_bonus.c

# paths to the object files
LIBFT_OBJS = $(LIBFT_CFILES:%.c=$(OFILESDIR)srcs/%.o)
FTPF_OBJS = $(FT_PRINTF_CFILES:%.c=$(OFILESDIR)ft_printf/%.o)
GNL_OBJS = $(GET_NEXT_LINE_CFILES:%.c=$(OFILESDIR)get_next_line/%.o)

# libraryname
NAME := libft_ftpf_gnl.a

# Build target
all: check $(NAME)

# Check if build is necessary
check:
	@echo "\033[38;5;11m🛠️  Checking build status... \033[0m"
	@if [ -f $(NAME) ]; then \
		CHANGES=false; \
		for obj in $(LIBFT_OBJS) $(FTPF_OBJS) $(GNL_OBJS); do \
			if [ $$obj -nt $(NAME) ]; then \
				CHANGES=true; \
				break; \
			fi; \
		done; \
		if [ $$CHANGES = false ]; then \
			echo "\033[38;5;1m❌ No changes detected. Nothing to build.\033[0m"; \
		else \
			echo "\033[38;5;2m⚙️  Changes detected. Starting build...\033[0m"; \
		fi; \
	else \
		echo "\033[38;5;2m⚙️  No previous build found. Starting build...\033[0m"; \
	fi

# Create the static library
$(NAME): $(LIBFT_OBJS) $(FTPF_OBJS) $(GNL_OBJS)
	@ar -rcs $@ $^
	@echo "\033[38;5;46m⏳ Build process in action...\033[0m"
	@echo "\033[38;5;15m╔══════════════════════════════════════════════════════════════╗\033[0m"
	@echo "\033[38;5;10m📁  Directory: \033[0m\033[38;5;2m$(OFILESDIR)\033[0m"
	@echo "\033[38;5;15m╚══════════════════════════════════════════════════════════════╝\033[0m"
	@echo "\033[38;5;196m🔧  Object Files Summary:\033[0m"
	@echo "\033[38;5;2m   ➤ LIBFT:        \033[0m$(words $(LIBFT_OBJS)) objects created."
	@echo "\033[38;5;2m   ➤ FT_PRINTF:    \033[0m$(words $(FTPF_OBJS)) objects created."
	@echo "\033[38;5;2m   ➤ GET_NEXT_LINE: \033[0m$(words $(GNL_OBJS)) objects created."
	@echo "\033[38;5;46m🧩 Combining all parts into the final library... \033[0m"
	@echo "\033[38;5;4m━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\033[0m"
	@echo "\033[38;5;46m🎉  $(NAME) file successfully created! 🎉 \033[0m"
	@echo "\033[38;5;4m━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\033[0m"

# Compile object files from source
$(OFILESDIR)srcs/%.o: $(SRCSDIR)%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

$(OFILESDIR)ft_printf/%.o: $(FTPFDIR)%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

$(OFILESDIR)get_next_line/%.o: $(GNLDIR)%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

# Clean object files
clean:
	@if [ -d $(OFILESDIR) ]; then \
		rm -rf $(OFILESDIR); \
		echo "\033[38;5;196m🧹 Cleaning up object files... \033[0m"; \
		echo "\033[38;5;46m💨 Cleaning completed.\033[0m"; \
	else \
		echo "\033[38;5;46m✅ No object files to remove. \033[0m"; \
	fi

# Remove compiled library
fclean: clean
	@if [ -f $(NAME) ]; then \
		rm -f $(NAME); \
		echo "\033[38;5;196m🧹 Removing Library... \033[0m"; \
		echo "\033[38;5;46m💨 Library removed.\033[0m"; \
	else \
		echo "\033[38;5;46m✅ No library to remove. \033[0m"; \
	fi
	@echo ""

# Rebuild everything from scratch
re:
	@echo "\033[38;5;33m🔄 Rebuilding from scratch... \033[0m"
	@echo "\033[38;5;4m━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\033[0m"
	@$(MAKE) fclean
	@$(MAKE) all
	@echo "\033[38;5;4m━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\033[0m"
	@echo "\033[38;5;46m✨ Build process completed successfully! ✨\033[0m"

.PHONY: all clean fclean re check

# Ansi colors for output

# BLUE   = "\033[38;5;4m"
# GREEN  = "\033[38;5;2m"
# ORG    = "\033[38;5;214m"
# RED    = "\033[38;5;196m"
# RESET  = "\033[0m"
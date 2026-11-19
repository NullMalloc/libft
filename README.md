*This project has been created as part of the 42 curriculum by sahassou.*

# Libft

## Description

Libft is my first C library at 42. The goal: recode a set of standard C functions from scratch, add some extra string tools, and build a small linked-list toolkit. No shortcuts: the only external functions allowed are `malloc`, `free` and `write`.

This library will follow me in the next projects (ft_printf, get_next_line, push_swap...), so every function had to be solid, leak-free and norm-compliant.

The library contains **43 functions**, split into 3 parts:

- **Part 1 – Libc functions**: my own versions of classic functions from `<ctype.h>`, `<string.h>` and `<stdlib.h>`.
- **Part 2 – Additional functions**: string tools that the libc doesn't have, or not in this form (split, trim, join, itoa...).
- **Part 3 – Linked list**: functions to create and manipulate a simple linked list (`t_list`).

## Instructions

### Compilation

```bash
make        # builds libft.a
make clean  # removes the object files (.o)
make fclean # removes the object files and libft.a
make re     # fclean + all
```

Everything is compiled with `cc -Wall -Wextra -Werror`. The Makefile does not relink: running `make` twice does nothing the second time.

### Using the library in a project

```c
#include "libft.h"

int	main(void)
{
	ft_putendl_fd("Hello from my libft", 1);
	return (0);
}
```

```bash
cc -Wall -Wextra -Werror main.c -L. -lft
```

## Library overview

### Part 1 – Libc functions

| Function | What it does |
|---|---|
| `ft_isalpha` / `ft_isdigit` / `ft_isalnum` / `ft_isascii` / `ft_isprint` | Check the type of a character |
| `ft_toupper` / `ft_tolower` | Convert a letter to upper / lower case |
| `ft_strlen` | Length of a string |
| `ft_memset` / `ft_bzero` | Fill a memory area with a byte / with zeros |
| `ft_memcpy` | Copy memory (areas must not overlap) |
| `ft_memmove` | Copy memory, safe even when the areas overlap |
| `ft_memchr` / `ft_memcmp` | Search a byte / compare two memory areas |
| `ft_strchr` / `ft_strrchr` | First / last occurrence of a character in a string |
| `ft_strncmp` | Compare two strings, up to `n` characters |
| `ft_strlcpy` / `ft_strlcat` | Size-bounded copy / concatenation (BSD style) |
| `ft_strnstr` | Find a string inside another, searching at most `len` characters |
| `ft_atoi` | Convert a string to an `int` |
| `ft_calloc` | Allocate memory set to zero, with an overflow check |
| `ft_strdup` | Allocate and return a copy of a string |

### Part 2 – Additional functions

| Function | What it does |
|---|---|
| `ft_substr` | Return a new substring of `s`, from `start`, of max `len` characters |
| `ft_strjoin` | Return a new string: `s1` + `s2` |
| `ft_strtrim` | Remove the characters of `set` from the start and the end of `s1` |
| `ft_split` | Split a string with a delimiter into a NULL-terminated array of strings |
| `ft_itoa` | Convert an `int` to a new string |
| `ft_strmapi` | Create a new string by applying `f` to each character |
| `ft_striteri` | Apply `f` to each character of a string, in place |
| `ft_putchar_fd` / `ft_putstr_fd` / `ft_putendl_fd` / `ft_putnbr_fd` | Write a char / string / string + newline / number on a file descriptor |

### Part 3 – Linked list

```c
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;
```

Each node carries some data (`content`) and the address of the next node (`next`). The last node points to `NULL`.

| Function | What it does |
|---|---|
| `ft_lstnew` | Create a new node |
| `ft_lstadd_front` | Add a node at the beginning of the list |
| `ft_lstadd_back` | Add a node at the end of the list |
| `ft_lstsize` | Count the nodes |
| `ft_lstlast` | Return the last node |
| `ft_lstdelone` | Free one node and its content (with `del`) |
| `ft_lstclear` | Free the whole list and set the list pointer to `NULL` |
| `ft_lstiter` | Apply `f` to the content of each node |
| `ft_lstmap` | Build a new list by applying `f` to each content |

### A few technical choices

- **`ft_split`** is built from 4 small helpers: `count_words` (how many boxes to allocate), `word_dup` (copy one word), `free_all` (if one `malloc` fails, free everything already allocated) and `ft_split` itself, which walks the string once: skip delimiters, copy the word, jump over it.
- **`ft_itoa`** works with negative numbers internally, so `INT_MIN` never overflows. Digits come out in reverse order, so the buffer is filled from the end.
- **`ft_calloc`** checks `nmemb > SIZE_MAX / size` before allocating, so the multiplication can't overflow.
- **`ft_strtrim`** moves a `start` index forward and an `end` index backward while the characters are in `set`, then reuses `ft_substr`.
- **`ft_lstclear`** saves the address of the next node *before* freeing the current one, otherwise the rest of the list would be lost.
- **`ft_lstsize`** returns an `unsigned int`, as required by version 19.3 of the subject.

## Resources

- The **man pages**: `man 3 strlcpy`, `man 3 memmove`, `man 3 strnstr`, `man 3 qsort` (for function pointers)...
- **Beej's Guide to C Programming**: https://beej.us/guide/bgc/
  - Ch. 8 *Structs* (the arrow operator `->`)
  - Ch. 12 *Manual Memory Allocation*
  - Ch. 20 *structs II* (self-referential structs, the base of a linked list)
  - Ch. 23.1 *Pointers to Pointers* and 23.7 *Pointers to Functions*
- A YouTube walkthrough of `ft_split`, to visualize the algorithm. Here's the link :) [https://www.youtube.com/watch?v=rn0B-ALufrw]
- **Norminette** and **c_formatter_42** (to fix tabs and alignment).
- **libft_tester** and AddressSanitizer (`-fsanitize=address`) to test the functions and find memory leaks.

### How I used AI

I used **Claude** (Anthropic) as a **private tutor**, not as a code generator. Being honest about what it did and what I did:

**What Claude did:**
- Explained the concepts I struggled with: address vs content, `size_t` wraparound, pointers to pointers (`**`), function pointers, linked lists, `malloc`/`free` rules.
- Gave me **pseudocode** and step-by-step plans, especially for `ft_split`, `ft_strtrim`, `ft_strmapi` / `ft_striteri` and the linked-list functions. For the list functions, the pseudocode was very close to the final code.
- Reviewed my code and pointed out my bugs, explaining *why* my reasoning led to them (my most common one: a loop variable that never moves, or a `return` placed inside a loop).
- Ran tests on my functions (AddressSanitizer, comparison with the real libc, simulated `malloc` failures).
- Helped me fix my `libft.h` (missing `#ifndef`, typos, missing prototypes) and the `SRCS` list of my Makefile.
- Helped me draft this README.

**What I did:**
- Wrote the C code of every function myself, from the explanations and pseudocode.
- Traced the algorithms by hand (variable tables) before coding, for example `count_words` in `ft_split`.
- Fixed my own bugs after each review, and rewrote several functions from memory (`ft_strdup`, `ft_strnstr`, and the `ft_split` helpers) to make sure I could do them alone, as in an exam.
- Ran norminette and the testers on my own machine.

AI saved me a lot of time on explanations, but understanding came from writing, breaking and fixing the code myself. My rule: if I can't explain a function, it's not done.
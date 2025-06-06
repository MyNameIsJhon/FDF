#ifndef ARENA_ALLOCATOR_H
# define ARENA_ALLOCATOR_H

#include <stddef.h>

typedef struct s_arena {
	char	*data;
	size_t	offset;
	size_t	size;
}				t_arena;

void	arena_init(t_arena *a, size_t size);
void	*arena_alloc(t_arena *a, size_t size, size_t alignment);
void	arena_free(t_arena *a);

#endif

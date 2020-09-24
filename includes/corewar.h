#ifndef VM_H
# define VM_H

# include "../libft/includes/libft.h"
# include <inttypes.h>
# include <errno.h>
# include "op.h"

# define MODA(x)         (x % MEM_SIZE < 0 ? x % MEM_SIZE + MEM_SIZE : x % MEM_SIZE)
# define MODX(x)         (x % IDX_MOD)

# define USAGE          -1
# define DUMP           FT_BIT(0)
# define NUM            FT_BIT(1)
# define VIS            FT_BIT(2)
# define EXT            ".core"

/*
** struct arena
*/

typedef struct      s_op
{
    char            *name;
    int             args_num;
    int             args_type[3];
    int             code;
    int             cycles;
    char            *description;
    int             args_type_code;
    int             carry;
}                   t_op;

typedef struct      s_cursor
{
    int             id;
    int             carry;
    int             op_code;
    int             last_live;
    int             cycles_to_exec;
    int             pc;
    int             step;
    int             reg[REG_NUMBER];
    int             args_type[3];
    struct s_cursor *next;
}                   t_cursor;

typedef struct      s_player
{
    char            name[PROG_NAME_LENGTH + 1];
    char            comment[COMMENT_LENGTH + 1];
    uint8_t         instr[CHAMP_MAX_SIZE];
    int             isntr_size;
    int             id;
    int             location;
    struct s_player *next;
}                   t_player;

typedef struct      s_vm
{
    uint8_t         arena[MEM_SIZE];
    t_player        *players[MAX_PLAYERS];
    t_cursor        *cursor;
    int             players_num;
    int             flags;
    int             dump;
    int             id;
    int             last_alive;
    int             total_cycles;
    int             nbr_live;
    int             nbr_checks;
    int             cycles_to_die;
    int             cycles_to_check;
    t_op            op_tab[17];

}                   t_vm;


/*
** Initialization functions
*/

void        init_vm(t_vm *vm);
void        set_op_tab(t_vm *vm);
t_player    *creat_champion(int id);
void        init_arena(t_vm *vm);
void        init_cursor(t_vm *vm);

/*
** Parse functions
*/

void        ft_parse_champion(t_vm *vm, char *file, int id);
void        add_champion(t_vm *vm, t_player *player);
void        ft_parse_args(t_vm *vm, char **argv);
void        ft_parse_dump(t_vm *vm, char ***av);
int         ft_parse_num(t_vm *vm, char *av);
int         is_number(char *str);

/*
** Playing corewar
*/

void        cw_to_playing(t_vm *vm);
int         get_operation(t_vm *vm, t_cursor *cursor);
int8_t      get_byte(t_vm *vm, int index);

/*
** Error processing & print functions
*/

int			print_usage();
void        intro_player(t_vm *vm);
void		ft_error(t_vm *vm, int code);

#endif
#include "../../includes/corewar.h"

void        init_arena(t_vm *vm)
{
    int         location;
    int         i;

    i = 0;
    while (i < vm->players_num)
    {
        location = MEM_SIZE / vm->players_num * i;
        vm->players[i]->location = location;
        ft_memcpy(vm->arena[location], vm->players[i]->instr, \
        vm->players[i]->isntr_size);
        i++;
    }
}

t_player    *creat_champion(int id)
{
    t_player *player;

    if (!(player = malloc(sizeof(t_player))))
        return (NULL);
    player->id = id;
    player->isntr_size = 0;
    ft_bzero(player->name, sizeof(char) * PROG_NAME_LENGTH);
    ft_bzero(player->comment, sizeof(char) * COMMENT_LENGTH);
    ft_bzero(player->instr, sizeof(char) * CHAMP_MAX_SIZE);
    player->next = NULL;
}

void        init_vm(t_vm *vm)
{
    vm->cursor = NULL;
    vm->cycles_to_die = CYCLE_TO_DIE;
    vm->dump = -1;
    vm->flags = 0;
    vm->id = 0;
    vm->last_alive = NULL;
    vm->nbr_checks = 0;
    vm->nbr_live = 0;
    vm->players_num = 0;
    vm->cursors_num = 0;
    vm->total_cycles = 0;
    vm->cycles_to_check = 0;
    ft_bzero(vm->arena, sizeof(uint8_t) * MEM_SIZE);
    ft_bzero(vm->players, sizeof(t_player *) * 4);
}
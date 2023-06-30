#include "push_swap.h"

int main (int argc, char *argv[])
{
	t_list	*lsts[2];
	

	//actually, no need to parse at all... -.-
	/*if (argc != 3 && argc != 2)
	{
		printf("nope");
		return (0);
	}*/
	lsts[0] = parse_int(argv);
	
	
	lsts[1] = NULL;

	//lst_log(lsts);

	if (argc == 3)
		parse_ps(argv[2], lsts);
	//lsts[0] = rotate(lsts[0]);
	//lst_log(lsts);
	//lsts[0] = rotate(lsts[0]);
	//lst_log(lsts);
	//lsts[0] = rotate(lsts[0]);
	
	sort(lsts);
	//rrr(lsts);
	
	//lst_log(lsts);
	//printf("\nsortet? %d", is_sortet(lsts));
	lst_free(lsts);
	return (0);
}

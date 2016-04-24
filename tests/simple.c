#include <oca.h>

int main(void)
{
	struct oca_can *can;

	can = oca_init(NULL);

	oca_destroy(&can);

	return 0;
}

#include <oca.h>
#include <stdlib.h>

struct oca_can *oca_init(const char *serial)
{
	(void)serial;
	return NULL;
}

void oca_destroy(struct oca_can **ctx)
{
	*ctx = NULL;
}

enum oca_ret oca_can_read(struct oca_can_msg *msg)
{
	(void)msg;
	return OCA_OK;
}

enum oca_ret oca_can_write(struct oca_can_msg *msg)
{
	(void)msg;
	return OCA_OK;
}

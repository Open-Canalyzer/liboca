#include <oca.h>
#include <stdlib.h>
#include <libusb.h>

struct oca_can *oca_init(const char *serial)
{
	(void)serial;
	return NULL;
}

void oca_destroy(struct oca_can **ctx)
{
	*ctx = NULL;
}

enum oca_ret oca_can_read(struct oca_can_msg **msg)
{
	*msg = NULL;
	return OCA_OK;
}

enum oca_ret oca_can_write(struct oca_can_msg *msg)
{
	(void)msg;
	return OCA_OK;
}

void oca_can_msg_free(struct oca_can_msg **msg)
{
	*msg = NULL;
}

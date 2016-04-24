#ifndef OCA_H_
#define OCA_H_

#include <stdlib.h>
#include <stdint.h>

enum oca_ret {
	OCA_OK
};

struct oca_can {
	const char *serial;
};

struct oca_can_msg {
	uint32_t id;      /**< 11/29-bit message id */
	uint8_t dlc;      /**< Data Length Code (DLE), 0..8 bytes */
	uint8_t __pad[3]; /**< Struct padding */
	uint8_t data[8];  /**< Data payload */
};

struct oca_can *oca_init(const char *serial);
void oca_destroy(struct oca_can **ctx);

enum oca_ret oca_can_read(struct oca_can_msg **msg);
enum oca_ret oca_can_write(struct oca_can_msg *msg);
void oca_can_msg_free(struct oca_can_msg **msg);

#endif /* OCA_H_ */

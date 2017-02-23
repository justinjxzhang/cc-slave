#ifndef CC_MSG_H
#define CC_MSG_H

#ifdef __cplusplus
extern "C"
{
#endif

/*
****************************************************************************************************
*       INCLUDE FILES
****************************************************************************************************
*/

#include <stdint.h>


/*
****************************************************************************************************
*       MACROS
****************************************************************************************************
*/

#define CC_MSG_HEADER_SIZE  4


/*
****************************************************************************************************
*       CONFIGURATION
****************************************************************************************************
*/


/*
****************************************************************************************************
*       DATA TYPES
****************************************************************************************************
*/

enum cc_cmd_t {CC_CMD_CHAIN_SYNC, CC_CMD_HANDSHAKE, CC_CMD_DEV_CONTROL, CC_CMD_DEV_DESCRIPTOR,
               CC_CMD_ASSIGNMENT, CC_CMD_DATA_UPDATE, CC_CMD_UNASSIGNMENT, CC_NUM_COMMANDS};

typedef struct cc_msg_t {
    int device_id, command;
    uint16_t data_size, data_idx;
    uint8_t *header, *data;
} cc_msg_t;


/*
****************************************************************************************************
*       FUNCTION PROTOTYPES
****************************************************************************************************
*/

cc_msg_t *cc_msg_new(void);

int cc_msg_parser(const cc_msg_t *msg, void *data_struct);
int cc_msg_builder(int command, const void *data_struct, cc_msg_t *msg);


/*
****************************************************************************************************
*       CONFIGURATION ERRORS
****************************************************************************************************
*/

#ifdef __cplusplus
}
#endif

#endif

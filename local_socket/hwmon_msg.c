
#include "devm_msg.h"
#include "hwmon_msg.h"

int hwmon_msg_proc(DEVM_MSG_S *rx_msg, DEVM_MSG_S *tx_msg)
{
    HWMON_MSG_S *hwmon_msg;

    if (!rx_msg) return VOS_ERR;

    hwmon_msg = (HWMON_MSG_S *)rx_msg->msg_payload;
    printf("hwmon_msg_proc: %d(%s) fault %d\n", hwmon_msg->node_id, hwmon_msg->node_desc, hwmon_msg->fault_state);

//todo

    return VOS_OK;
}



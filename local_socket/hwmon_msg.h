
#ifndef _HWMON_MSG_H_
#define _HWMON_MSG_H_

#ifndef fault_severity_t
typedef enum fault_severityT {
    NO_FAULT,
    CRITICAL = 1,
    MAJOR,
    MINOR,
    WARNING
} fault_severity_t;
#endif

typedef struct {
    char node_desc[64]; //reserved
    int  node_id;
    int  fault_state;   //fault_severity_t
}HWMON_MSG_S;

/*******************************************************************************************************
 * FAULT ID LIST
 *******************************************************************************************************/
/*
source: CPU //fault_source_t
affect: "cpu"   
text  : CRITICAL-"High cpu occupy", NO_FAULT-"null"
*/
#define NODE_ID_CPU_OCCUPY          0x0001

/*
source: CPU //fault_source_t
affect: "cpu"   
text  : MINOR-"Unit temperature is high", CRITICAL-"Unit Dangerously overheating", NO_FAULT-"null"
*/
#define NODE_ID_CPU_TEMP            0x0002

/*
source: CPU //fault_source_t
affect: "cpu"   
text  : CRITICAL-"High mem occupy", NO_FAULT-"null"
*/
#define NODE_ID_MEM_OCCUPY          0x0003

/*
source: PA //fault_source_t
affect: "PA"   
text  : MINOR-"Unit temperature is high", CRITICAL-"Unit Dangerously overheating", NO_FAULT-"null"
*/
#define NODE_ID_BOARD_TEMP          0x0010

/*
source: todo //fault_source_t
affect: todo
text  : todo
*/
#define NODE_ID_POWER_CHECK         0x0011

/*
source: todo //fault_source_t
affect: todo
text  : todo
*/
#define NODE_ID_FAN_SPEED           0x0012

/*
source: todo //fault_source_t
affect: todo
text  : todo
*/
#define NODE_ID_GNSS_LOCKED         0x0013

/*
source: todo //fault_source_t
affect: todo
text  : todo
*/
#define NODE_ID_AD9544_REG          0x0020

/*
source: todo //fault_source_t
affect: todo
text  : todo
*/
#define NODE_ID_AD9544_PLL          0x0021

/*
source: todo //fault_source_t
affect: todo
text  : todo
*/
#define NODE_ID_AD9528_REG          0x0022

/*
source: todo //fault_source_t
affect: todo
text  : todo
*/
#define NODE_ID_AD9528_PLL          0x0023

/*
source: todo //fault_source_t
affect: todo
text  : todo
*/
#define NODE_ID_9FGV100_REG         0x0024

/*
source: todo //fault_source_t
affect: todo
text  : todo
*/
#define NODE_ID_FPGA_REG            0x0030

/*
source: todo //fault_source_t
affect: todo
text  : todo
*/
#define NODE_ID_AD9009_REG          0x0040

/*
source: todo //fault_source_t
affect: todo
text  : todo
*/
#define NODE_ID_AD9009A_PLL         0x0041

/*
source: todo //fault_source_t
affect: todo
text  : todo
*/
#define NODE_ID_AD9009B_PLL         0x0042

/*******************************************************************************************************
 * END
 *******************************************************************************************************/


#endif

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<sys/un.h>
#include<errno.h>

typedef enum fault_severityT {
    NO_FAULT,
    CRITICAL = 1,
    MAJOR,
    MINOR,
    WARNING
} fault_severity_t;

typedef struct {
    char node_desc[64]; //reserved
    int  node_id;
    int  fault_state;   //fault_severity_t
}HWMON_MSG_S;

typedef struct {
    int  serial_num;
    int  msg_type;
    int  ack_value;
    int  need_ack;

    int  payload_len;
    char msg_payload[256];
}DEVM_MSG_S;

static struct sockaddr *ncxname;
static int ncxsock;
static struct sockaddr_un ncxname_unix;
static struct sockaddr_in ncxname_inet;

static int set_msg(DEVM_MSG_S *msg, HWMON_MSG_S *alarm_msg)
{
	(*msg).serial_num = 1;
	(*msg).msg_type = 2; //alarm
	(*msg).ack_value = 0;
	(*msg).need_ack = 0;

	//strncpy((*msg).msg_payload, &alarm_msg, sizeof(HWMON_MSG_S));
	memcpy((*msg).msg_payload, alarm_msg, sizeof(HWMON_MSG_S));
	(*msg).payload_len = sizeof(HWMON_MSG_S)+1;
}

static int init_socket()
{
    ncxsock = -1;
    int name_size;
    int ret;

    ncxsock = socket(PF_LOCAL, SOCK_STREAM, 0);
    if(ncxsock<0){
        printf("Error: ncxsock create failed\n");
        return -1;
    }
    ncxname_unix.sun_family = AF_LOCAL;
    strncpy(ncxname_unix.sun_path, "/tmp/oran.mp", sizeof(ncxname_unix.sun_path));
    name_size = SUN_LEN(&ncxname_unix);
    ncxname = (struct sockaddr *)&ncxname_unix;

    ret = connect(ncxsock, ncxname, name_size);
    if(ret != 0){
        printf("Error: ncx socket connect failed\n");
        return -1;
    }
    return 0;
}

static int send_buff (int fd, const char *buffer, size_t cnt)
{
    size_t sent, left;
    ssize_t  retsiz;
    int   retry_cnt;

    retry_cnt = 1000;
    sent = 0;
    left = cnt;

    while (sent < cnt) {
        retsiz = write(fd, buffer, left);
        if (retsiz < 0) {
            switch (errno) {
            case EAGAIN:
            case EBUSY:
                if (--retry_cnt) {
                    break;
                } /* else fall through */
            default:
                return -1;
            }
        } else {
            sent += (size_t)retsiz;
            buffer += retsiz;
            left -= (size_t)retsiz;
        }
    }

    return 0;
}

#if 1
static int
    send_msg (DEVM_MSG_S *msg)
{
    int res;
    res = send_buff(ncxsock, (char*)msg, sizeof(DEVM_MSG_S));
    return res;
}
#endif

static int print_msg(DEVM_MSG_S *msg)
{
	HWMON_MSG_S *hwmon_msg;
    if (!msg) return -1;

    hwmon_msg = (HWMON_MSG_S *)msg->msg_payload;
    printf("hwmon_msg_proc: %d(%s) fault %d\n",
    	hwmon_msg->node_id, hwmon_msg->node_desc, hwmon_msg->fault_state);
}

int main()
{
	DEVM_MSG_S msg;
	HWMON_MSG_S alarm_msg;
    HWMON_MSG_S alarm_msg1;
//	memset(&alarm_msg, 0, sizeof(alarm_msg));
	strcpy(alarm_msg.node_desc, "cpu temperature high");
	strcpy(alarm_msg1.node_desc, "pa temperature high");
	alarm_msg.node_id = 1101;
	alarm_msg.fault_state = 0;

	alarm_msg1.node_id = 1102;
	alarm_msg1.fault_state = 2;


	init_socket();
	while(1){
        set_msg(&msg, &alarm_msg);
	    print_msg(&msg);
		send_msg(&msg);

        set_msg(&msg, &alarm_msg1);
	    print_msg(&msg);
		send_msg(&msg);

		sleep(3);
	}
	return 0;
}

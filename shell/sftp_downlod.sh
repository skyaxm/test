#!/bin/bash

SCRIPT_NAME=`basename $0`
CURRENT_DIR=$(cd "$(dirname "$0")";pwd)

execute_sftp_cmd()
{
    local host_ip=$1
    local user_name=$2
    local user_password=$3
    local file_name=$4
    local file_dir=$5
    local cmd=$6
 
    local log_file=${CURRENT_DIR}/execute_sftp_cmd.log
    user_password=`echo ${user_password} | sed 's/\\$/\\\\$/g'`

    /usr/bin/expect <<EOF > ${log_file}
    set timeout -1
    spawn sftp ${user_name}@${host_ip}:${file_dir}
    expect {
        "(yes/no)?"
        {
            send "yes\n"
            expect "*password:" { send "${user_password}\n"}
        }
        "*assword:"
        {
            send "${user_password}\n"
        }
    }
    expect "Changing to:*"
    send "${cmd} -r ${file_name}\n"
    #expect "100%"
    send "exit\n"
    expect eof
EOF
#   cat ${log_file} | grep -iE "denied|error|failed|not found|No such file or directory" >/dev/null 
   cat ${log_file} | grep -iE "denied" >/dev/null 
   if [ $? -eq 0 ];then
       echo "Download not allowed"
        return 1
   fi

   cat ${log_file} | grep -iE "error" >/dev/null 
   if [ $? -eq 0 ];then
       echo "Unknown error"
        return 2
   fi
   
   cat ${log_file} | grep -iE "No such file or directory" >/dev/null 
   if [ $? -eq 0 ];then
       echo "File may be moved"
        return 3
   fi

   cat ${log_file} | grep -iE "failed" >/dev/null 
   if [ $? -eq 0 ];then
       echo "Download failed"
       return 4
   fi

   cat ${log_file} | grep -iE "not found" >/dev/null 
   if [ $? -eq 0 ];then
       echo "File not exist"
        return 5
   fi   

   return 0
}
execute_sftp_cmd "$@"

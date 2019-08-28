#!/bin/bash
echo "getting the *** files shell script"
#ssh thongng@10.38.13.21
#cd /projects/hcm/quicksilver/users
FILENAME="user.cfg"
find . -type f -iname $FILENAME | tee ./user_cfg_list
echo "finding finished"
```sh
[pturtle@mephi ~]$ sudo nano /etc/pam.d/su
[pturtle@mephi ~]$ man useradd
[pturtle@mephi ~]$ sudo useradd -G wheel user1
[pturtle@mephi ~]$ sudo passwd user1
Changing password for user user1.
New password:
Retype new password:
passwd: all authentication tokens updated successfully
[pturtle@mephi ~]$ su - user1
Password:
[user1@mephi ~]$ whoami
user1
[user1@mephi ~]$ su
Password:
sh: Permission denied
[user1@mephi ~]$ exit
logout
[pturtle@mephi ~]$ sudo nano /etc/pam.d/su
[pturtle@mephi ~]$ su - user1
Password:
[user1@mephi user1]$ su
Password:
[root@mephi user1]$ whoami
root
[root@mephi user1]$ exit
exit
[user1@mephi ~]$ exit
logout
[pturtle@mephi ~]$ man pam_pwquality
[pturtle@mephi ~]$ sudo nano /etc/security/pwquality.conf
[pturtle@mephi ~]$ sudo nano /etc/pam.d/system-auth
[pturtle@mephi ~]$ sudo passwd user1
Changing password for user user1.
New password:
BAD PASSWORD: The password is shorter than 12 characters
[pturtle@mephi ~]$ wget https://raw.githubusercontent.com/linux-pam/linux-pam/master/examples/check_user.c
[pturtle@mephi ~]$ sudo yum install pam-devel
[pturtle@mephi ~]$ gcc check_user.c -o check_user -lpam -lpam_misc
[pturtle@mephi ~]$ sudo nano /etc/pam.d/check
[pturtle@mephi ~]$ ./check_user pturtle
Password:
Authenticated
[pturtle@mephi ~]$ su -
Password:
[root@mephi ~]$ passwd -e pturtle
Expiring password for user pturtle.
passwd: Success
[root@mephi ~]$ exit
logout
[pturtle@mephi ~]$ ./check_user pturtle
Password:
Not Authenticated
error code: Authentication token is no longer valid; new one required
```

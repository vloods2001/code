import paramiko
import time


def connect_start(ip,opengear,user = "root:port",password = "Myriad20!6"):
    global client
    client = paramiko.SSHClient()
    client.set_missing_host_key_policy(paramiko.AutoAddPolicy())
    client.connect(ip, 22 , user + opengear, password)
    global commands
    commands = client.invoke_shell()

def openssh_con(decision,user, password):
    global commands
    if decision == 'Yes':
        commands.send('root\n')
        time.sleep(2)
    if decision== 'No':
        commands.send(user + '\n')
        time.sleep(2)
        commands.send(password + '\n')
        time.sleep(1)
    print("------------------Login Successful-------------------------")


##########################RAW CODE STARTS###########################################################

print(" --This Program Is Under the Impression You have a File With Your Choice of Show Commands Named 'Commands'----")
      
decision = input("Is this for Work or Home:")
device_type = input("Juniper or Cisco or N/A:")
decision_2 = input("Type 'Config' For Just Sticking Config, 'Show' For Pulling Show Outputs, 'Both' For Both In One:")
device_user = input("Is this Device Fresh Out of Box, 'Yes' or 'No':")
reboot_user = input("Insert User of Device, After Reboot:")
reboot_pass = input("Password Of Device, After Reboot:")
opengear_ip = input("Enter IP:")
config_file = input("Insert The Name Of Config File:")
output_file = input("Insert Name of Output File:")
fileobj1 = open(config_file + '.txt', 'r')
fileobj2 = open("Commands.txt", 'r')
fileobj3 = open(output_file + '.txt', 'w')

if decision == 'Work':
    conport = input("Enter Console Port:")
    if device_type == 'Juniper':
        if decision_2 == 'Both':
            print('-----------------Connecting to Device--------------------')
            connect_start(opengear_ip,conport)
            print('-----------------Connection Established via SSH----------')
####################################STARTING CODE FOR BOTH OPTION#####################################
            if device_user == 'Yes':
                openssh_con(device_user,reboot_user, reboot_pass)
                commands.send("\n")
                time.sleep(1.5)
                commands.send("start shell\n")
                time.sleep(1.5)
                commands.send("cli\n")
                time.sleep(1.5)
                commands.send("set cli screen-length 0\n")
                time.sleep(1.5)
                commands.send("configure\n")
                time.sleep(1)
                commands.send("delete chassis auto-image-upgrade\n")
                time.sleep(1.5)
                commands.send("delete")
                time.sleep(1)
                print('-----------------Deleting StartUp Config-------------------------')
                commands.send("yes\n")
                time.sleep(1)
                print('-----------------Starting Config----------------------------------')
                for x in fileobj1:
                    commands.send(x + '\n')
                    time.sleep(3)
                    output = commands.recv(65535)
                    output = output.decode("utf-8")
                    print(output)
                commands.send("commit\n")
                time.sleep(17)
                commands.send("run request system reboot at now \n")
                time.sleep(3)
                commands.send("yes\n")
                time.sleep(275)
                client.close()
                #STARTING THE REBOOT FOR THE SHOW COMMANDS#
                time.sleep(4)
                connect_start(opengear_ip,conport)
                time.sleep(2)
                openssh_con(device_user,reboot_user,reboot_pass)
                time.sleep(2)
                commands.send('\n')
                time.sleep(2)
                commands.send("start shell\n")
                time.sleep(2)
                commands.send("cli\n")
                time.sleep(2)
                commands.send("set cli screen-length 0\n")
                for x in fileobj2:
                    commands.send(x + '\n')
                    time.sleep(3)
                    output = commands.recv(65535)
                    output = output.decode("utf-8")
                    print(output)
                    fileobj3.write(output)
                fileobj1.close()
                fileobj2.close()
                fileobj3.close()
                print("Done!")
####################CODE FOR IF NO PASSWORD REQUIRED IS/ FRESH OUT OF BOX FINISHED################################
            if device_user == 'No':
                openssh_con(device_user,reboot_user,reboot_pass)
                time.sleep(3)
                commands.send("start shell\n")
                time.sleep(1)
                commands.send("cli\n")
                time.sleep(1.5)
                commands.send("set cli screen-length 0\n")
                time.sleep(1.5)
                commands.send("configure\n")
                time.sleep(1)
                commands.send("delete chassis auto-image-upgrade\n")
                time.sleep(1.5)
                commands.send("delete\n")
                time.sleep(1)
                print('-----------------Deleting StartUp Config-------------------------')
                commands.send("yes\n")
                time.sleep(1)
                print('-----------------Starting Config----------------------------------')
                for x in fileobj1:
                        commands.send(x + '\n')
                        time.sleep(3)
                        output = commands.recv(65535)
                        output = output.decode("utf-8")
                        print(output)
                commands.send("commit\n")
                time.sleep(17)
                commands.send("run request system reboot at now \n")
                time.sleep(3)
                commands.send("yes\n")
                time.sleep(275)
                #STARTING THE REBOOT FOR THE SHOW COMMANDS#
                client.close()
                time.sleep(4)
                connect_start(opengear_ip,conport)
                time.sleep(2)
                openssh_con(device_user,reboot_user,reboot_pass)
                time.sleep(2)
                commands.send("\n")
                time.sleep(1)
                commands.send("start shell\n")
                time.sleep(2)
                commands.send("cli\n")
                time.sleep(5)
                commands.send("set cli screen-length 0\n")
                time.sleep(5)
                for x in fileobj2:
                    commands.send(x + '\n')
                    time.sleep(6)
                    output = commands.recv(65535)
                    output = output.decode("utf-8")
                    print(output)
                    fileobj3.write(output)
                fileobj3.close()
                fileobj2.close()
                fileobj1.close()
                print("Done!")
#########################################ENDING CODE FOR BOTH OPTION AND FOR NON FRESH DEVICE LOGIN###########################################################
##############################################################################################################################################################
#########################################STARTING CODE FOR 'CONFIG' OPTION STARTING###########################################################################
        if decision = 'Config':
            print('-----------------Connecting to Device--------------------')
            connect_start(opengear_ip,conport)
            print('-----------------Connection Established via SSH----------')
            if device_user = "Yes":
                openssh_con(device_user,reboot_user, reboot_pass)
                commands.send("\n")
                time.sleep(1.5)
                commands.send("start shell\n")
                time.sleep(1.5)
                commands.send("cli\n")
                time.sleep(1.5)
                commands.send("set cli screen-length 0\n")
                time.sleep(1.5)
                commands.send("configure\n")
                time.sleep(1)
                commands.send("delete chassis auto-image-upgrade\n")
                time.sleep(1.5)
                commands.send("delete")
                time.sleep(1)
                print('-----------------Deleting StartUp Config-------------------------')
                commands.send("yes\n")
                time.sleep(1)
                print('-----------------Starting Config----------------------------------')
                for x in fileobj1:
                    commands.send(x + '\n')
                    time.sleep(3)
                    output = commands.recv(65535)
                    output = output.decode("utf-8")
                    print(output)
                commands.send("commit\n")
                time.sleep(17)
                commands.send("run request system reboot at now \n")
                time.sleep(3)
                commands.send("yes\n")
                time.sleep(275)
                client.close()
                time.sleep(4)
                fileobj1.close()
                fileobj2.close()
                fileobj3.close()
            if device_user = "No":
                openssh_con(device_user,reboot_user,reboot_pass)
                time.sleep(3)
                commands.send("start shell\n")
                time.sleep(1)
                commands.send("cli\n")
                time.sleep(1.5)
                commands.send("set cli screen-length 0\n")
                time.sleep(1.5)
                commands.send("configure\n")
                time.sleep(1)
                commands.send("delete chassis auto-image-upgrade\n")
                time.sleep(1.5)
                commands.send("delete\n")
                time.sleep(1)
                print('-----------------Deleting StartUp Config-------------------------')
                commands.send("yes\n")
                time.sleep(1)
                print('-----------------Starting Config----------------------------------')
                for x in fileobj1:
                        commands.send(x + '\n')
                        time.sleep(3)
                        output = commands.recv(65535)
                        output = output.decode("utf-8")
                        print(output)
                commands.send("commit\n")
                time.sleep(17)
                commands.send("run request system reboot at now \n")
                time.sleep(3)
                commands.send("yes\n")
                time.sleep(15)
                client.close()
                time.sleep(4)
                fileobj1.close()
                fileobj2.close()
                fileobj3.close()
##########################################ENDING CODE FOR 'CONFIG' OPTION##########################################################
        if decision = 'Show':
            print('-----------------Connecting to Device--------------------')
            connect_start(opengear_ip,conport)
            print('-----------------Connection Established via SSH----------')
            if device_user == 'Yes':
                openssh_con(device_user,reboot_user,reboot_pass)
                time.sleep(2)
                commands.send('\n')
                time.sleep(2)
                commands.send("start shell\n")
                time.sleep(2)
                commands.send("cli\n")
                time.sleep(2)
                commands.send("set cli screen-length 0\n")
                for x in fileobj2:
                    commands.send(x + '\n')
                    time.sleep(3)
                    output = commands.recv(65535)
                    output = output.decode("utf-8")
                    print(output)
                    fileobj3.write(output)
                fileobj1.close()
                fileobj2.close()
                fileobj3.close()
                print("Done!")
            if device_user = 'No':
                if device_user == 'Yes':
                openssh_con(device_user,reboot_user,reboot_pass)
                time.sleep(2)
                commands.send('\n')
                time.sleep(2)
                commands.send("start shell\n")
                time.sleep(2)
                commands.send("cli\n")
                time.sleep(2)
                commands.send("set cli screen-length 0\n")
                for x in fileobj2:
                    commands.send(x + '\n')
                    time.sleep(3)
                    output = commands.recv(65535)
                    output = output.decode("utf-8")
                    print(output)
                    fileobj3.write(output)
                fileobj1.close()
                fileobj2.close()
                fileobj3.close()
                print("Done!")
                  
    if device_type == 'Cisco':
        pass
                  
###########################END CODE FOR 'SHOW' OUTPUT###########################################################                  
#######ABOVE CODE IS ONLY FOR WORK PURPOSES #####################################################################

        

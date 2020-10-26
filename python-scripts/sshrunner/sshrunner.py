import paramiko
import os
import platform
import argparse


class SSHRunner(object):

    def __init__(self, ssh_host, user_name, password=None, key_file=None):
        self.__ssh_host = ssh_host
        self.__ssh_command = None
        self.__ssh_username = user_name
        self.__password = password
        self.__key_file = key_file
        self.__ssh_client = paramiko.SSHClient()
        self.__ssh_client.set_missing_host_key_policy(paramiko.AutoAddPolicy())

        # configure the SSHClient
        if not self.__ssh_username:
            raise ValueError("SSH username is mandatory")

        default_key_file_location = None
        if not self.__password:
            if not self.__key_file:
                if platform.system() == "Windows":
                    default_key_file_location = os.path.join(os.getenv("USERPROFILE"),".ssh/id_rsa")
                else:
                    default_key_file_location = os.path.join(os.getenv("HOME",".ssh/id_rsa"))
                # no password no key no connection bye!
                if default_key_file_location is None:
                    raise ValueError("Can't find the key and password is blank")

        self.__key_file = default_key_file_location

    def connect_and_run(self, executable=None, *args):
        if self.__password:
            self.__ssh_client.connect(username=self.__ssh_username, password=self.__password)
        else:
            self.__ssh_client.connect(username=self.__ssh_username)

        command = list(args)
        if executable:
            command.insert(0,executable)
        command_string = " ".join(command)
        stdin, stdout, stderr = self.__ssh_client.exec_command(command_string)
        return stdout, stderr

class JumpHost(object):
    def __init__(self, host_name, user_name, password=None, key_file=None):
        self.host_name = host_name
        self.__runner = SSHRunner(host_name,user_name, password, key_file)

    def run_command(self, executable=None, *args):
        return self.__runner.connect_and_run(executable, args)

class Environment(object):
    @staticmethod
    def get_db(env_file="env.yml"):
        environments = {
            "production": "somename.net",
            "staging": ""
        }
        return environments

    def __init__(self, chef_environment):
        env_db = Environment.get_db()


class App(object):
    @staticmethod
    def run_ssh_command_on_host(host, executable=None, *args):
        pass

    @staticmethod
    def run_shell_script_on_host(script_path, *args):
        pass



    @staticmethod
    def main():
        parser = argparse.ArgumentParser()
        parser.add_rgsacorgument("-jh", "--jump-host-list", help="host name list", type=list,
                            dest="jump_host_list", required=True)

        command_group = parser.add_mutually_exclusive_group()
        command_group.add_argument("-c", "--command", help="command string you want to run ", type=list,
                                   dest="command_args", required=True)
        script_group = command_group.add_argument_group("script file and script interpreter")
        script_group.add_argument_group("-si","--script-interpreter", type=str, help="Script interpreter",
                                        dest="script_interpreter", required=True)
        script_group.add_argument("-sf","--script-file",
                                   help="script location, script executable will be determined using the extension",
                                   dest="script_location", required=True)

        args = parser.parse_args()

        if hasattr(args, "command"):
            App.run_ssh_command()






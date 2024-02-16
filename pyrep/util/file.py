import os
from pyrep.config import file_config as f_cfg
from json import dump, load


def write_json_file(data: list, file_name=f_cfg.json_file_name):
    file = f_cfg.json_file_path + file_name
    if len(data) == 0:
        return
    # if file is not exist， create file
    if not (os.path.exists(file)):
        f = open(file, 'w')
        f.close()
        print("file is not exist")
        return False
    with open(file, 'a') as f:
        # save data into json file
        dump(data, f, indent=f_cfg.intend)
    print("target:" + file + ". write success!")
    return True


def read_json_file(file_name=f_cfg.json_file_name) -> list:
    file = f_cfg.json_file_path + file_name
    json_data: list
    # if file is not exist， create file
    if not (os.path.exists(file)):
        f = open(file, 'w')
        f.close()
        print("file is not exist")
        return []
    with open(file, 'r') as f:
        # read data from json file
        try:
            json_data = load(f)
        except TypeError:  # if read value's type is not list
            print("Error reading json, value is not a list")
        finally:
            print(type(json_data))
    return json_data


def delete_json_file(file_name=f_cfg.json_file_name) -> bool:
    file = f_cfg.json_file_path + file_name
    if os.path.exists(file):
        os.remove(file)
    return True


def delete_json_file_data(file_name=f_cfg.json_file_name) -> bool:
    file = f_cfg.json_file_path + file_name
    if os.path.exists(file):
        with open(file, 'a+') as f:
            f.truncate(0)
    else:
        f = open(file, 'w')
        f.close()
        print("file is not exist")
    return True

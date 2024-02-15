import os
from pyrep.config import file_config as f_cfg
from json import dump, load
json_file_save = f_cfg.json_file_path + f_cfg.json_file_name


def write_json_file(data: list):
    if len(data) == 0:
        return
    # if file is not exist， create file
    if not (os.path.exists(json_file_save)):
        f = open(json_file_save, 'w')
        f.close()
        print("file is not exist")
        return False
    with open(json_file_save, 'a') as f:
        # save data into json file
        dump(data, f, indent=f_cfg.intend)
        print(json_file_save, type(data))
    return True


def read_json_file() -> list:
    json_data: list
    # if file is not exist， create file
    if not (os.path.exists(json_file_save)):
        f = open(json_file_save, 'w')
        f.close()
        print("file is not exist")
        return []
    with open(json_file_save, 'r') as f:
        # read data from json file
        try:
            json_data = load(f)
        except TypeError:  # if read value's type is not list
            print("Error reading json, value is not a list")
        finally:
            print(type(json_data))
    return json_data

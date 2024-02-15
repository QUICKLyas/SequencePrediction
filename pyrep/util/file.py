import os
import file_config as f_cfg
from typing import Any
from json import dump, load
json_file_save = f_cfg.json_file_path + f_cfg.json_file_name


def write_json_file(data: list):
    if len(data) == 0:
        return
    # if file is not exist， create file
    if not (os.path.exists(json_file_save)):
        os.mknod(json_file_save)
        return False
    with open(json_file_save, 'a') as f:
        # save data into json file
        dump(data, f, intend=f_cfg.intend)
        print(type(data))
    return True


def read_json_file() -> list:
    json_data: list
    # if file is not exist， create file
    if not (os.path.exists(json_file_save)):
        os.mknod(json_file_save)
        return []
    with open(json_file_save, 'r') as f:
        # read data from json file
        json_data = load(f)
        print(type(json_data))
    return json_data

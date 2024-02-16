import os
from pyrep.util.note import create_dict_note as c_note
from pyrep.config import file_config as f_cfg
from json import dump, load

dict_return: dict = {}


def write_json_file(data: list, file_name=f_cfg.json_file_name) -> dict:
    global dict_return
    file = f_cfg.json_file_path + file_name
    if len(data) == 0:
        dict_return = c_note(False, "No data to write")
    # if file is not exist， create file
    elif not (os.path.exists(file)):
        f = open(file, 'w')
        f.close()
        dict_return = c_note(False, "file is not exist")
    elif os.path.exists(file):
        with open(file, 'a') as f:
            # save data into json file
            dump(data, f, indent=f_cfg.intend)
        dict_return = c_note(True, "target:" + file + ". write success!")
    return dict_return


def read_json_file(file_name=f_cfg.json_file_name) -> dict:
    file = f_cfg.json_file_path + file_name
    json_data: list
    global dict_return
    # if file is not exist， create file
    if not (os.path.exists(file)):
        f = open(file, 'w')
        f.close()
        dict_return = c_note(False, "file is not exist")
    else:
        with open(file, 'r') as f:
            # read data from json file
            try:
                json_data = load(f)
            except TypeError:  # if read value's type is not list
                dict_return = c_note(False, "Error reading json, value is not a list")
            finally:
                dict_return = c_note(True, "target:" + file + ". read success!", json_data)
    return dict_return


def delete_json_file(file_name=f_cfg.json_file_name) -> dict:
    file = f_cfg.json_file_path + file_name
    global dict_return
    if os.path.exists(file):
        os.remove(file)
        dict_return = c_note(True, "target:" + file + ". remove success!")
    return dict_return


def delete_json_file_data(file_name=f_cfg.json_file_name) -> dict:
    file = f_cfg.json_file_path + file_name
    global dict_return
    if os.path.exists(file):
        with open(file, 'a+') as f:
            f.truncate(0)
        dict_return = c_note(True, "target:" + file + ". data erase success!")
    else:
        f = open(file, 'w')
        f.close()
        dict_return = c_note(True, "target:" + file + ". data erase success!")
    return dict_return

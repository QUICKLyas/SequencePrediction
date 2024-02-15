import requests
from bs4 import BeautifulSoup
import config as cfg
import json
import time
req_url = cfg.general
# (0~33)
index =while index < 34:
    url = req_url.get('Request URL') + str(req_url.get('pageNum')+index) + req_url.get('pageSize')+req_url.get('end')
    response = requests.get(url, headers=cfg.request_header)
    soup = BeautifulSoup(response.text, features='html.parser')
    index = index + 1
    # 获取response报文中的内容
    string_res = response.text

    # 切分字符串，获取字典类型模式的字符串
    string_json = string_res[string_res.index('(')+1:len(string_res)-1]
    print(string_json)

    dict_data = json.loads(string_json)
    list_data = dict_data['data']

    for data in list_data:
        print(data['frontWinningNum'])
        print(data['backWinningNum'])

    time.sleep(10)
# 数据获取成功
# 进行数据的保存处理
# 对数据进行整理
# 上面多个步骤建议使用多线程实现
